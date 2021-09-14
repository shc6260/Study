package game.server;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

import java.awt.Window.*;

import init_screen.StartScreen;

public class GameSocketThread extends Thread {
	GameServer cs;
	Socket s;
	String threadName = "thread";
	PrintWriter pw;	
	BufferedReader br;
	String name;
	int score = 99;
		
	
	public GameSocketThread(GameServer cs, Socket s) {
		this.cs = cs;
		this.s = s; 
		threadName = getName();
		System.out.println(s.getInetAddress() + "에서 접속했습니다.");
		System.out.println("Thread Name" + threadName);
	}
	
	public void sendMessage(String str) {
		pw.println(str);
	}
	
	@Override
	public void run() {
		try {
			br  = new BufferedReader(new InputStreamReader(s.getInputStream()));
			pw = new PrintWriter(s.getOutputStream(),true);
			name = br.readLine();
			
			sendMessage(" ");
			cs.broadCasting("[" + name + "]님 입장.");
			cs.broadCasting("점수는 10점내기");
			
			if(cs.i >= 2) {
				sendMessage("대기중");
			}
			while(cs.i >= 2) {	
				System.out.printf("");
				
			}
			
			
			cs.i++;
			score = 0;
			if(cs.i == 2){				
				cs.makeQuiz();
			}
			
			while(true) {
				
				
				
				
				String in = br.readLine();
				cs.broadCasting("[" + name + "] :" +in);	
				
				if(cs.answer.equals(in.replace("\n", ""))) {
					cs.broadCasting(name + "정답");
					score++;
					cs.broadCasting(name + " score : " + score);
					
					
					if(score >= 10) {
						cs.broadCasting(name + "승리");
						sendMessage("나가세용");
						score=99;
						cs.winAction(name);
						cs.removeClient(this);
						new StartScreen(name);
						while(true) {}
					}
					
					
					cs.makeQuiz();
				}
				
				
			}
		} catch (IOException e) {
			System.out.println(threadName + "님 퇴장");
			cs.i--;
			cs.removeClient(this);
		}finally {
			try {
				s.close();
			} catch (IOException e) {
				System.out.println(e);
			}
		}
	}
}
