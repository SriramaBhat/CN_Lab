import java.net.*;
import java.io.*;

public class TCPServer {
    public static void main(String args[]) throws Exception { // establishing the connection with the server
        ServerSocket sersock = new ServerSocket(4000);
        System.out.println("Server ready for connection");
        Socket sock = sersock.accept(); // binding with port: 4000
        System.out.println("Connection is successful and waiting for chatting");
        // reading the file name from client
        InputStream istream = sock.getInputStream();
        BufferedReader fileRead = new BufferedReader(new InputStreamReader(istream));
        String fname = fileRead.readLine();
        // reading file contents
        BufferedReader contentRead = new BufferedReader(new FileReader(fname));
        // keeping output stream ready to send the contents
        OutputStream ostream = sock.getOutputStream();
        PrintWriter pwrite = new PrintWriter(ostream, true);
        String str;
        // reading line-by-line from file
        while ((str = contentRead.readLine()) != null) {
            pwrite.println(str); // sending each line to client
        }
        sock.close();
        sersock.close(); // closing network sockets
        pwrite.close();
        fileRead.close();
        contentRead.close();
    }
}