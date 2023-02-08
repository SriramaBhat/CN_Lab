import java.net.*;
import java.io.*;

public class UDPClient {
    public static void main(String[] args) {
        DatagramSocket client = new DatagramSocket();
        byte[] b = "request".getBytes();
        InetAddress ip = InetAddress.getByName("127.0.0.1");
        DatagramPacket req = new DatagramPacket(b, b.length, ip, 3000);
        byte[] buffer = new byte[1024];
        client.send(req);
        DatagramPacket reply = new DatagramPacket(buffer, buffer.length);
        client.receive(reply);
        System.out.println("Received message is: ");
        System.out.println(new String(reply.getData()));
        client.close();
    }
}
