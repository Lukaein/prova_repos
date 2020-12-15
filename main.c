#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(){
    struct sockaddr_in server, client;
    int sd, fd;
    sd = socket(AF_INET, SOCK_STREAM, 0);
    if(sd < 0)
        printf("Errore della socket");
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(1234);

    if((bind(sd, (struct sockaddr*)&server, sizeof(server))) < 0){
        printf("Errore");
    }

    listen(sd, 3);
    unsigned int client_len = sizeof(client);
    fd = accept(sd, (struct sockaddr*)&client, &client_len);
    if(fd < 0)
        printf("Errore di accept");

    printf("ip client: %s", inet_ntoa(client.sin_addr));
    printf("port: %d", client.sin_port);
    return 0;
}

