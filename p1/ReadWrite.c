#include <stdio.h>
#include <string.h>
#include <pthread.h>

//
// Created by Emmanuel Massaquoi on 6/19/17.
//

int shared_var = 0;
int resource_use = 0;

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t read_phase = PTHREAD_COND_INITIALIZER;
pthread_cond_t write_phase = PTHREAD_COND_INITIALIZER;

void *reader (void *param);
void *writer (void *param);


int main(int argc, char *argv[]) {

    printf("Hello World/m");
    return 0;
}

void *reader(void *param) {

    for (int i = 1; i <=20; i++) {

        pthread_mutex_lock(&m);

            while (resource_use == 1) {
                pthread_cond_wait(&read_phase, &m);
            }

        pthread_mutex_unlock(&m);
    }
}