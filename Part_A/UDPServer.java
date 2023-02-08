import java.net.*;
import java.io.*;

public class UDPServer {
    public static void main(String[] args) throws Exception {
        DatagramSocket sersock = new DatagramSocket(3000);
        byte[] buffer = new byte[1024];
        System.out.println("Server ready waiting for client");
        DatagramPacket req = new DatagramPacket(buffer, buffer.length);
        sersock.receive(req);
        System.out.println("Enter the message to be transmitted: ");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String message = br.readLine();
        byte[] msg = message.getBytes();
        DatagramPacket reply = new DatagramPacket(msg, msg.length, req.getAddress(), req.getPort());
        sersock.send(reply);
        sersock.close();
    }
}
