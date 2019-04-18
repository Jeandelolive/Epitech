/*
** EPITECH PROJECT, 2019
** tek_2
** File description:
** step2
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>

int main(void)
{
    int my_socket1 = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in myaddr;
    char *buff;

    myaddr.sin_family = AF_INET;
    myaddr.sin_port = htons(4242);
    inet_pton(AF_INET, "127.0.0.1", &myaddr.sin_addr);
    int len = sizeof(myaddr);
    connect(my_socket1, (struct sockaddr *)&myaddr, len);
    write(my_socket1, "test\n", 5);
    read(my_socket1, buff, 7);
    while (1) {
        write(1, buff, 7);
    }
}