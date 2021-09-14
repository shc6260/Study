package game.client;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.concurrent.locks.Condition;

import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class ClientGUI extends JPanel implements Runnable, ActionListener {
	Socket s;
	JTextArea ta;
	JTextField tf;
	PrintWriter pw;
	BufferedReader br;
	String id;
	
	public ClientGUI(String ip, int port, String id) {
		this.id = id;
		System.out.println(this.getClass().getName() + "1. start => ");
		initLayout();
		
		try {
			s = new Socket(ip,port);
		} catch (IOException e) {
			System.out.println("서버와의 연결을 위한 소켓 생성 실패!");
		} 
		
		 System.out.println(this.getClass().getName() + "2. Socket => ");
	}
	
	public void initLayout() {
		setLayout(new BorderLayout());
		ta = new JTextArea(10,20);
		tf = new JTextField(50);
		JScrollPane tas = new JScrollPane(ta); //textArea에 스크롤을 만들어준다.
		
		add(tas,"Center");
		add(tf,"South");
		
		tf.addActionListener(this);
		ta.setEditable(false);
		
		tf.requestFocus();
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		tf.requestFocus();
		String str = tf.getText();
		pw.println(str);
		tf.setText("");

	}

	public void giveAndTake() {
		System.out.println(this.getClass().getName() + "3. InputOutput =>");
		try {
			pw = new PrintWriter(s.getOutputStream(),true);
			br = new BufferedReader(new InputStreamReader(s.getInputStream()));
			Thread t1 = new Thread(this);
			t1.start();
			pw.println(id); // id 를 보낸다.
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	@Override
	public void run() {
		System.out.println(this.getClass().getName() + "4. run =>");
		String line = null;
		
		try {
			int i = 0;
			
			while ((line = br.readLine()) != null) {
				i++;
				if(i == 1) {
					continue;
				}
				ta.append(line+"\n");
				
				ta.setCaretPosition(ta.getDocument().getLength()); //스크롤을 가장 밑으로 내려줌
			}
		} catch (IOException e) {
			e.printStackTrace();
		}finally {
			try {
				s.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}

}
