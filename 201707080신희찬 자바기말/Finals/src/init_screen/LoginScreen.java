package init_screen;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;
import javax.swing.JOptionPane; 

import db.ExDB;

public class LoginScreen extends JFrame implements ActionListener {
	
	JButton bLogin,bSignUp;
	JTextField tId;
	JPasswordField tPass;
	JLabel lId, lPass, lTitle;
	JPanel pId,pPass,pBtn, pSign;
	
	public LoginScreen() {
		setTitle("로그인 페이지");
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setLayout(new BorderLayout(10,40));
		int x = 0, y = 0 , w = 400, h = 300;
		
		Toolkit t = Toolkit.getDefaultToolkit();
		Dimension d = t.getScreenSize();
		int sw = (int) d.getWidth();
		int sh = (int) d.getHeight();
		
		x = (int)((0.5)*(sw-w));
		y = (int)((0.5)*(sh-h));
		
		bLogin = new JButton("로그인");
		bSignUp = new JButton("회원가입");
		tId = new JTextField(20);
		tPass = new JPasswordField(20);
		lId = new JLabel("아이디");
		lPass = new JLabel("비밀번호");
		lTitle = new JLabel("타자 연습 게임");
		
		pId = new JPanel();
		pPass = new JPanel();
		pBtn = new JPanel();		
		pSign = new JPanel();
		
		pId.add(lId);
		pId.add(tId);
		pPass.add(lPass);
		pPass.add(tPass);
		pBtn.add(bLogin);
		pBtn.add(bSignUp);
		
		pSign.add(pId);
		pSign.add(pPass);
		
		lTitle.setFont(new Font("궁서", Font.BOLD, 35));
		lTitle.setHorizontalAlignment(JLabel.CENTER);
		lId.setFont(new Font("돋움",Font.PLAIN , 17));
		lPass.setFont(new Font("돋움",Font.PLAIN, 17));
		tId.setFont(new Font("돋움",Font.PLAIN, 17));
		tPass.setFont(new Font("돋움",Font.PLAIN, 17));
		
		bLogin.setPreferredSize(new Dimension(120, 40));
		bSignUp.setPreferredSize(new Dimension(120, 40));
		
		add(lTitle,"North");
		add(pSign, "Center");
		add(pBtn, "South");
		
		
		bLogin.addActionListener(this);
		bSignUp.addActionListener(this);

		setBounds(x,y,w,h);
		setVisible(true);
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		if(e.getSource() == bLogin) {
				
			
			if(actionLogin()) {
					dispose();
					new StartScreen(tId.getText());
				}
			}
		else {
			dispose();
			new SignUpScreen();
		}

	}
	
	
	public boolean actionLogin() {
		Connection con = ExDB.getConnection();
		PreparedStatement pstmt = null;
		ResultSet rs = null;
		
		
		try {
			String sql = "select * from user where id like ? and pass like ?";	
			
			pstmt = con.prepareStatement(sql);
			pstmt.setString(1, tId.getText());
			pstmt.setString(2, tPass.getText());
			
			rs = pstmt.executeQuery();
			
			if (rs.next()){
				JOptionPane.showMessageDialog(null, "로그인 성공");
				return true;
			}
			else{
				JOptionPane.showMessageDialog(null, "로그인 실패");
				return false;
			}
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return false;
	}
}
