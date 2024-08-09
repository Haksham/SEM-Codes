import java.net.*;
import java.io.*;

// Change the ip addres to yout pc ip
// Goto new terminal -> enter "ifconfig" -> under "enp3o or eno1" -> "inet" -> check the ip just after inet (ex. 172.1.31.177)
// No changes in Port

public class Client {
  public static void main(String[] args) throws Exception {
    Socket sock = new Socket("192.168.56.1", 4000);
    System.out.println("Enter the filename");
    BufferedReader keyRead = new BufferedReader(new InputStreamReader(System.in));
    String fname = keyRead.readLine();
    OutputStream ostream = sock.getOutputStream();
    PrintWriter pwrite = new PrintWriter(ostream, true);
    pwrite.println(fname);
    InputStream istream = sock.getInputStream();
    BufferedReader socketRead = new BufferedReader(new InputStreamReader(istream));
    String str;
    while ((str = socketRead.readLine()) != null) {
      System.out.println(str);
    }
    pwrite.close();
    socketRead.close();
    keyRead.close();
  }
}