package db;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;


public class ExDB {
	
	public static Connection getConnection() {
		Connection con = null;
		
		try {
			Class.forName("com.mysql.jdbc.Driver");
			String url= "jdbc:mysql://localhost:3306/typing?serverTimezone=UTC";
			String user ="root";
			String pwd = "1q2w3e4r";
			con = DriverManager.getConnection(url, user, pwd);
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}catch(SQLException e) {
			getConnection();
		}
		return con;
	}
	
	public static void main(String[] args) {
		getConnection();
	}
}
