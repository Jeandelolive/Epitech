/*
** EPITECH PROJECT, 2019
** tek_2
** File description:
** step1
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include "struct.h"

int main(void)
{
    int my_socket = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);
    char buff[4096];
    char *message = "Olivier\n";
    struct sockaddr_in my_insocket;
    struct iphdr *my_ip = malloc(sizeof(struct iphdr));
    struct udphdr *my_udp = malloc(sizeof(struct udphdr));

    memset(buff, 0, 4096);

    my_insocket.sin_family = AF_INET;
	my_insocket.sin_port = htons(80);
	my_insocket.sin_addr.s_addr = inet_addr ("192.168.1.1");

    my_ip->ihl = 5;
    my_ip->version = 4;
    my_ip->tos = 0;
    my_ip->tot_len = sizeof(struct iphdr) + sizeof(struct udphdr) + strlen(message);
    my_ip->id = htons(getuid());
    my_ip->frag_off = 0;
    my_ip->ttl = 255;
    my_ip->protocol = IPPROTO_UDP;
    my_ip->check = 0;
    my_ip->saddr = inet_addr("192.168.1.2");
    my_ip->daddr = my_insocket.sin_addr.s_addr;

    my_udp->check = 0;
    my_udp->source = htons(4242);
    my_udp->dest = htons(4243);
    my_udp->len = htons(8 + strlen(message));
}