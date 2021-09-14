package init_screen;

import java.awt.BorderLayout;
import java.awt.Dimension;
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
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

import db.ExDB;

public class SignUpScreen extends JFrame implements ActionListener {

	JButton bCancel,bSignUp;
	JTextField tId, tEmail;
	JPasswordField tPass;
	JLabel lId, lPass,lEmail ,lTitle;
	JPanel pId,pPass, pEmail ,pBtn, pSign;
	boolean logini = false;
	
	public SignUpScreen() {
		setTitle("ȸ������ ������");
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setLayout(new BorderLayout(10,20));
		int x = 0, y = 0 , w = 400, h = 300;
		
		
		
		bCancel = new JButton("���");
		bSignUp = new JButton("ȸ������");
		
		tId = new JTextField(20);
		tPass = new JPasswordField(20);
		tEmail = new JTextField(20);
		
		lId = new JLabel("���̵�");
		lPass = new JLabel("��й�ȣ");
		lEmail = new JLabel("�̸���");
		lTitle = new JLabel("ȸ������");
		
		pId = new JPanel();
		pPass = new JPanel();
		pBtn = new JPanel();		
		pSign = new JPanel();
		pEmail = new JPanel();
		
		pId.add(lId);
		pId.add(tId);
		pPass.add(lPass);
		pPass.add(tPass);
		pBtn.add(bCancel);
		pBtn.add(bSignUp);
		pEmail.add(lEmail);
		pEmail.add(tEmail);
		
		pSign.add(pId);
		pSign.add(pPass);
		pSign.add(pEmail);
		
		lTitle.setFont(new Font("�ü�", Font.BOLD, 35));
		lTitle.setHorizontalAlignment(JLabel.CENTER);
		
		lId.setFont(new Font("����",Font.PLAIN , 17));
		lPass.setFont(new Font("����",Font.PLAIN, 17));
		lEmail.setFont(new Font("����",Font.PLAIN, 17));
		
		tId.setFont(new Font("����",Font.PLAIN, 17));
		tPass.setFont(new Font("����",Font.PLAIN, 17));
		tEmail.setFont(new Font("����",Font.PLAIN, 17));
		
		bCancel.setPreferredSize(new Dimension(120, 40));
		bSignUp.setPreferredSize(new Dimension(120, 40));
		
		add(lTitle,"North");
		add(pSign, "Center");
		add(pBtn, "South");
		
		
		bCancel.addActionListener(this);
		bSignUp.addActionListener(this);

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
		if(e.getSource() == bSignUp) {
			signUpAction();
			dispose();
			new LoginScreen();
		}
		else {
			dispose();
			new LoginScreen();
		}

	}

	public static void main(String[] args) {
		new SignUpScreen();
	}
	
	public void signUpAction() {
			Connection con = ExDB.getConnection();
			PreparedStatement pstmt = null;
			ResultSet rs = null;
			
			
			try {
				String sql = "select id from user where id like ?";	
				
				pstmt = con.prepareStatement(sql);
				pstmt.setString(1, tId.getText());
				
				rs = pstmt.executeQuery();
				
				if (rs.next()){
					JOptionPane.showMessageDialog(null, "�ߺ� ���̵� �Դϴ�.");
					return;

				
				}
				sql = "insert into user values(?, ?, ?, 10, 0 , 0)";	
				
				pstmt = con.prepareStatement(sql);
				pstmt.setString(1, tId.getText());
				pstmt.setString(2, tPass.getText());
				pstmt.setString(3, tEmail.getText());
				
				pstmt.executeUpdate();
				
				
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}

		

	}
}
