package game.client;

import java.awt.Dimension;
import java.awt.Toolkit;

import javax.swing.JFrame;

public class ClientMainFrame extends JFrame {
	
	public ClientMainFrame(String id) {
		setTitle("Client Chatting Frame");
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		int x = 0, y = 0 , w = 400, h = 300;
		
		Toolkit t = Toolkit.getDefaultToolkit();
		Dimension d = t.getScreenSize();
		int sw = (int) d.getWidth();
		int sh = (int) d.getHeight();
		
		x = (int)((0.5)*(sw-w));
		y = (int)((0.5)*(sh-h));
		
		
		ClientGUI client = new ClientGUI("127.0.0.1", 7777, id);
		client.giveAndTake();
		add(client,"Center");
		
		setBounds(x,y,w,h);
		setVisible(true);
	}
	


}
