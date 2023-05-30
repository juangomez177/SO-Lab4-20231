#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>

int main(void)
{
    char cadena[100];
    int sockfd;
    struct sockaddr_in servaddr;
    FILE *myf = fopen("Conversación_cliente.txt", "a");

    time_t t;
    struct tm *tm;
    char hora[100];
    char *tmp;
    char sendline[100] = "Usando el puerto 2200\n";

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(2200);

    inet_pton(AF_INET, "127.0.0.1", &(servaddr.sin_addr));
    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    if (sockfd >= 0)
    {
        printf("\nConexión exitosa al servidor!\n");
        fputs("\nConexión exitosa al servidor!\n", myf);
    }
    else
    {
        printf("\nError al establecer la conexión con el servidor.\n");
        exit(0);
    }

    printf("\n\n\t\t------Se inició el chat CLIENTE------\n\n");
    fputs("\n\n\t\t------Se inició el chat CLIENTE------\n\n", myf);

    while (!strstr(cadena, "adios") && !strstr(sendline, "adios"))
    {
        bzero(cadena, 100);
        t = time(NULL);
        tm = localtime(&t);
        strftime(hora, 100, "\n(%H:%M): Cliente -> ", tm);
        printf("%s", hora);

        fgets(sendline, sizeof(sendline), stdin);
        sendline[strcspn(sendline, "\n")] = '\0';

        tmp = strcat(hora, sendline);
        fputs(tmp, myf);
        write(sockfd, sendline, strlen(sendline) + 1);

        strcpy(cadena, tmp);

        if (!strstr(cadena, "adios"))
        {
            strftime(hora, 100, "\n(%H:%M): Servidor -> ", tm);
            read(sockfd, cadena, 100);
            tmp = strcat(hora, cadena);
            printf("%s", tmp);
            fputs(tmp, myf);
        }
    }
    printf("\n\n\t\t------Conversación finalizada!------\n\n");
    printf("\n Se generó el archivo conversacion_cliente.txt\n");
    fclose(myf);
    close(sockfd);

    return 0;
}