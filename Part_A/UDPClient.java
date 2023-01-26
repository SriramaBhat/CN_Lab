import java.net.*;
import java.io.*;

public class UDPClient {
    public static void main(String[] args) {
        try {
            InetAddress acceptorHost = InetAddress.getByName(args[0]);
            int serverPortNum = Integer.parseInt(args[1]);
            Socket clientSocket = new Socket(acceptorHost, serverPortNum);
            BufferedReader br = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            System.out.println(br.readLine());
            clientSocket.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
