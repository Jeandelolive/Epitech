/*
** EPITECH PROJECT, 2019
** tek_2
** File description:
** ex00
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

static char nb = 48;
static pthread_mutex_t lock;


void display_trip(int *trip, char tmp)
{
    pthread_mutex_lock(&lock);
    int i = 0;

    write(1, &tmp, 1);
    while (i < 17) {
        if (trip[i] == 0)
            write(1, "#", 1);
        if (trip[i] == 1)
            write(1, "=", 1);
        if (trip[i] == 2)
            write(1, "|", 1);
        if (trip[i] == 3)
            write(1, "-", 1);
        if (trip[i] == 4)
            write(1, "\n", 1);
        i = i + 1;
    }
    pthread_mutex_unlock(&lock);
}

int move_forward(int *tab_int, int i)
{
    static int test = 0;
    if (tab_int[i + 1] == 2 && test == 0) {
        pthread_mutex_lock(&lock);
        tab_int[i] = 1;
        tab_int[i + 2] = 0;
        // while(tab_int[i+1]!=)

        return (1);
    }
    if (tab_int[i + 1] == 2 && test == 1) {
        test = 0;
        tab_int[i] = 3;
        tab_int[i + 2] = 0;
        return (1);
    }
    if (tab_int[i + 1] == 3) {
        tab_int[i] = 3;
        tab_int[i + 1] = 0;    
    } else {
        tab_int[i] = 1;
        tab_int[i + 1] = 0;
    }
    return (0);
}

void travel_bridge()
{

}

void *travel_loop(void *trip)
{
    int i = 0;
    char tmp = 48;
    int *tab_int = (int *)trip;
    nb = nb + 1;
    tmp = nb;
    while (i < 16) {
        display_trip(tab_int, tmp);
        sleep(1);
        i = i + move_forward(tab_int, i);
        i = i + 1;
    }
    
}

int main(void)
{
    pthread_t tab_train[3];
    int i = 0;
    char *trip = "#====|----|=====\n";
    int trip_1[17] = {0, 1, 1, 1, 1, 2, 3, 3, 3, 3, 2, 1, 1, 1, 1, 1, 4};
    int trip_2[17] = {0, 1, 1, 1, 1, 2, 3, 3, 3, 3, 2, 1, 1, 1, 1, 1, 4};
    int trip_3[17] = {0, 1, 1, 1, 1, 2, 3, 3, 3, 3, 2, 1, 1, 1, 1, 1, 4};

    // while (i < 3) {
        pthread_create(&tab_train[i], NULL, travel_loop, trip_1);
        pthread_create(&tab_train[i], NULL, travel_loop, trip_2);
        // pthread_create(&tab_train[i], NULL, travel_loop, trip_3);
    //     i = i + 1;
    // }

    pthread_join(tab_train[0], NULL);
    pthread_join(tab_train[1], NULL);
    // pthread_join(tab_train[2], NULL);
}