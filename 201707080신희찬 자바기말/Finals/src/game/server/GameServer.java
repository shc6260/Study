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
	String [] word = {"��θ�", "�η��", "�η�۾���" , "���� ���Ƹ�" , "������", "��ġ" , "�ܹ���" , "����" , "�ڱ�", "�д�", "��Ѹ�", "�����", "���", "��ġ"
			,"���", "�跡", "�����ٸ�", "����", "��", "�δٸ�", "�ǰ��", "������", "���ǹ���", "������", "���˺�" , "�񳪸�" , "���ٱ���", "��Ǯ�Ÿ���", "��"
			,"������","���","��","��Ÿ�","�����ϴ�","�����Ÿ���","���","Ǫ��","�����Ӹ�","������"};
	String answer;
	ServerSocket ss;
	Socket s;
	ArrayList<Thread> aList;
	int i = 0;
	
	public GameServer() {
		aList = new ArrayList<Thread>();
		System.out.println("ä�� ���� ����");
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
		broadCasting("����");
		broadCasting("---------------���� :" + answer + "---------------");
	}
	

	public synchronized void addClient(Thread t) {
		aList.add(t);
		System.out.println("Ŭ���̾�Ʈ 1�� ����, �� " + aList.size() + "��");
	}
	
	public synchronized void removeClient(Thread t) {
		aList.remove(t);
		System.out.println("Ŭ���̾�Ʈ 1�� ����, �� " + aList.size() + "��");
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
			}//�¸��� ���� �۾�
			
			//�й��� ���� �۾�
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
			 sst.sendMessage("��������");
			 try {
				sst.s.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			 
			
		}
		
		
}


