package init_screen;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.TextArea;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;

import db.ExDB;

public class ShowRank extends JFrame implements ActionListener {

	TextArea aRank;
	JButton bExit;
	String id;
	
	public ShowRank(String id) {
		this.id = id;
		setTitle("·©Å· µî·Ï");
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setLayout(new BorderLayout());
		
		aRank = new TextArea();
		bExit = new JButton("³ª°¡±â");
		
		add(aRank,"Center");	
		add(bExit,"South");
		
		aRank.setEditable(false);
		aRank.setText("·©Å· |     ID     | Á¡¼ö | ½Â  | ÆÐ  | ½Â·ü"+"\n");
		printRank();
		
		bExit.addActionListener(this);
		
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
	
	public void printRank() {
		Connection con = ExDB.getConnection();
		PreparedStatement pstmt = null;
		ResultSet rs = null;
		
		
		try {
			String sql = "select * from user order by point desc";	
			
			pstmt = con.prepareStatement(sql);			
			rs = pstmt.executeQuery();
			
			
			for (int i = 1 ; i < 11 ; i++) {				
				int Odds = 0;
				if(rs.next()) {
					if(rs.getInt("win") == 0 ) {
						Odds = 0;
					}
					else {
						double o = rs.getInt("win") + rs.getInt("lose");
						Odds = (int)(rs.getInt("win") / o * 100);
					}
					
					aRank.append(" "+ i + "    |" + rs.getString("id")+ "     |" + rs.getInt("point") + "       |" 
								+ rs.getInt("win") + "    |" + rs.getInt("lose") + "     |" + Odds + "% \n");
				}
				else {
					break;
				}
			}
			
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
				dispose();
	}
	
	public static void main(String[] args) {
	}

}
