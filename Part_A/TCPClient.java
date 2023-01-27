package practice_programs;

import java.net.*;
import java.io.*;

public class TCPClient {
    public static void main(String[] args) throws Exception {
        Socket sock = new Socket("127.0.0.1", 4000);
        System.out.println("Enter the file name:\n");
        BufferedReader nameRead = new BufferedReader(new InputStreamReader(System.in));
        String fname = nameRead.readLine();
        OutputStream ostream = sock.getOutputStream();
        PrintWriter pwrite = new PrintWriter(ostream, true);
        pwrite.println(fname);

        InputStream istream = sock.getInputStream();
        BufferedReader contentRead = new BufferedReader(new InputStreamReader(istream));
        String str;
        while ((str = contentRead.readLine()) != null) {
            System.out.println(str);
        }
        contentRead.close();
        pwrite.close();
        sock.close();
        nameRead.close();
    }
}
