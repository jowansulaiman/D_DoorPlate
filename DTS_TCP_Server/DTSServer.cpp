#include <winsock2.h>
#include <windows.h>
#include <iostream>
#include <string.h>
#include <locale>
#pragma comment(lib,"ws2_32.lib")
using namespace std;

string website_HTML;
locale local;


void get_Website(char* url);

int main()
{
    //open website
    get_Website("www.google.com");

    //format website HTML
    for (size_t i = 0; i < website_HTML.length(); ++i)
        website_HTML[i] = tolower(website_HTML[i], local);


    //display HTML
    cout << website_HTML;

    cout << "\n\n";



    return 0;
}



//***************************
void get_Website(char* url)
{
    WSADATA wsaData;
    SOCKET Socket;
    SOCKADDR_IN SockAddr;


    int lineCount = 0;
    int rowCount = 0;

    struct hostent* host;
    char* get_http = new char[256];

    memset(get_http, ' ', sizeof(get_http));
    strcpy(get_http, "GET / HTTP/1.1\r\nHost: ");
    strcat(get_http, url);
    strcat(get_http, "\r\nConnection: close\r\n\r\n");

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        cout << "WSAStartup failed.\n";
        system("pause");
        //return 1;
    }

    Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    host = gethostbyname(url);

    SockAddr.sin_port = htons(80);
    SockAddr.sin_family = AF_INET;
    SockAddr.sin_addr.s_addr = *((unsigned long*)host->h_addr);

    cout << "Connecting to " << url << " ...\n";

    if (connect(Socket, (SOCKADDR*)(&SockAddr), sizeof(SockAddr)) != 0)
    {
        cout << "Could not connect";
        system("pause");
        //return 1;
    }

    cout << "Connected.\n";
    send(Socket, get_http, strlen(get_http), 0);

    char buffer[10000];

    int nDataLength;
    while ((nDataLength = recv(Socket, buffer, 10000, 0)) > 0)
    {
        int i = 0;

        while (buffer[i] >= 32 || buffer[i] == '\n' || buffer[i] == '\r')
        {
            website_HTML += buffer[i];
            i += 1;
        }
    }
    closesocket(Socket);
    WSACleanup();

    delete[] get_http;
}