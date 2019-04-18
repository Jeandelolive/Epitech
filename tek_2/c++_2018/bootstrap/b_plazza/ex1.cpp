/*
** EPITECH PROJECT, 2019
** tek_2
** File description:
** ex1
*/

#include <pthread.h>

void incrementCounter(int &i)
{
    int n = 0;

    while (n < 5) {
        i = i + 1;
        n = n + 1;
    }
}

int main(void)
{
    int t = 0;

    return (0);
}