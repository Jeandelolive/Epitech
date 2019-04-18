/*
** EPITECH PROJECT, 2019
** tek_2
** File description:
** step1
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>

int main(void)
{
    int my_socket1 = socket(AF_INET, SOCK_STREAM, 0);
    int my_socket2 = socket(AF_INET, SOCK_STREAM, 0);
    struct timeval tv;
    int return_value = 0;
    fd_set *v_write;
    fd_set *v_read;
    struct sockaddr_in myaddr;
    struct sockaddr_in myaddr2;

    tv.tv_sec = 5;
    tv.tv_usec = 0;
    myaddr.sin_family = AF_INET;
    myaddr.sin_port = htons(4242);
    bind(my_socket1, (struct sockaddr *)&myaddr, sizeof(myaddr));
    listen(my_socket1, 50);
    int len = sizeof(myaddr);
    while(1){
        return_value = select(my_socket1, v_read, v_write, NULL, &tv);
        my_socket2 = accept(my_socket1, (struct sockaddr *)&myaddr2, &len);
        if (my_socket2 == -1)
            write(1, "Ca marche pas\n", 15);
        else
        {
            printf("Adresse: %u\n", myaddr2.sin_addr);
            printf("Port: %u\n", myaddr2.sin_port);
            write(my_socket2, "COUCOU\n", 7);
        }
        close(my_socket2);
    }
    close(my_socket1);
}