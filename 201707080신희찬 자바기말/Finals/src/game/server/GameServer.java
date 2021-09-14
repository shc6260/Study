package game.server;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

import db.ExDB;
import init_screen.StartScreen;

public class GameServer {
	String [] word = {"멱부리", "부룩소", "부룩송아지" , "서리 병아리" , "센둥이", "송치" , "솥밭이" , "씰개" , "자귀", "둔덕", "멧뿌리", "모롱이", "잿길", "둔치"
			,"목새", "배래", "복찻다리", "서덜", "섟", "널다리", "실골목", "도래솔", "문실문실", "벋나다", "샛검불" , "희나리" , "각다귀판", "거풀거리다", "고섶"
			,"널음새","밥쇠","어슬어슬","대거리","마뜩하다","불퉁거리다","삭신","푸새","조짐머리","투레질"};
	String answer;
	ServerSocket ss;
	Socket s;
	ArrayList<Thread> aList;
	int i = 0;
	
	public GameServer() {
		aList = new ArrayList<Thread>();
		System.out.println("채팅 서버 시작");
	}
	
	public void giveAndTake() {
		try {
			ss = new ServerSocket(7777);
			ss.setReuseAddress(true);
			while(true) {
				s = ss.accept();
				GameSocketThread sst = new GameSocketThread(this, s);
				addClient(sst);
				sst.start();
			}
			
		} catch (IOException e) {
			
		}
	}
	
	public synchronized void makeQuiz() {
		int i = (int)(Math.random()*word.length);
		answer = word[i];
		broadCasting("3");
		try {
			Thread.sleep(1000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		broadCasting("2");
		try {
			Thread.sleep(1000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		broadCasting("1");
		try {
			Thread.sleep(1000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		broadCasting("시작");
		broadCasting("---------------문제 :" + answer + "---------------");
	}
	

	public synchronized void addClient(Thread t) {
		aList.add(t);
		System.out.println("클라이언트 1명 입장, 총 " + aList.size() + "명");
	}
	
	public synchronized void removeClient(Thread t) {
		aList.remove(t);
		System.out.println("클라이언트 1명 퇴장, 총 " + aList.size() + "명");
	}
	
	 public synchronized void broadCasting(String str) {
		 for(int i = 0 ; i < aList.size() ; i++) {
			 GameSocketThread sst = (GameSocketThread)aList.get(i);
			 sst.sendMessage(str);
		 }
	 }
	 
		public synchronized void winAction(String id) {
			Connection con = ExDB.getConnection();
			PreparedStatement pstmt = null;
			ResultSet rs = null;
			
			
			try {
				String sql = "update user set point = point + 1, win = win + 1 where id = ?";	
				
				pstmt = con.prepareStatement(sql);		
				pstmt.setString(1, id);
				pstmt.executeUpdate();
				
				
				
				
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}//승리자 관련 작업
			
			//패배자 관련 작업
			GameSocketThread sst = null;
			 for(int i = 0 ; i < aList.size() ; i++) {
				 sst = (GameSocketThread)aList.get(i);
				 if(sst.score != 99) {
					 break;
				 }
			 }
			
			 try {
					String sql = "update user set point = point - 1, lose = lose + 1 where id = ?";	
					
					pstmt = con.prepareStatement(sql);		
					pstmt.setString(1, sst.name);
					pstmt.executeUpdate();
				
					
				} catch (SQLException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			 removeClient(sst);
			 i--;
			 new StartScreen(sst.name);
			 sst.sendMessage("나가세용");
			 try {
				sst.s.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			 
			
		}
		
		
}


