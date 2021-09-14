package init_screen;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

import game.client.ClientMainFrame;

public class StartScreen extends JFrame implements ActionListener {

	JButton bStart,bRank;
	JPanel fp = null;
	JLabel lTitle;
	String id;
	public StartScreen(String id) {
		this.id = id;
		setTitle("시작 페이지");
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setLayout(new BorderLayout());
		
		bStart = new JButton("시작");
		bRank = new JButton("랭킹");
		fp = new JPanel();
		lTitle = new JLabel("타자 연습 게임");
		lTitle.setFont(new Font("궁서", Font.BOLD, 50));
		lTitle.setHorizontalAlignment(JLabel.CENTER);
		
		bRank.setPreferredSize(new Dimension(150, 50));
		bStart.setPreferredSize(new Dimension(150, 50));
		
		bRank.addActionListener(this);
		bStart.addActionListener(this);
		
		fp.add(bRank);
		fp.add(bStart);
		add(fp,"South");
		add(lTitle,"Center");
		
		
		
		int x = 0, y = 0 , w = 400, h = 300;
		
		Toolkit t = Toolkit.getDefaultToolkit();
		Dimension d = t.getScreenSize();
		int sw = (int) d.getWidth();
		int sh = (int) d.getHeight();
		
		x = (int)((0.5)*(sw-w));
		y = (int)((0.5)*(sh-h));
		
		setBounds(x,y,w,h);
		setVisible(true);
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
			if(e.getSource() == bRank) {
				new ShowRank(id);
			}
			else {
				dispose();
				new ClientMainFrame(id);
			}

	}
	


}
