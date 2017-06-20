#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define NUM_THREADS 10

//
// Created by Emmanuel Massaquoi on 6/19/17.
//

int shared_var = 0;
int resource_use;
int num_reader = 0;

int reading = 0;
int writing = 1;

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t read_phase = PTHREAD_COND_INITIALIZER;
pthread_cond_t write_phase = PTHREAD_COND_INITIALIZER;

void *reader (void *param);
void *writer (void *param);


int main(int argc, char *argv[]) {

    pthread_t tid[NUM_THREADS];

    for (int i = 0; i < 5; i++) {

        printf("Create Reader\n");
        if(pthread_create(&tid[i], NULL, reader, NULL) != 0) {
            fprintf(stderr, "Unable to create reader thread");
            exit(1);
        }

        printf("Create Writer\n");
        if(pthread_create(&tid[i+5], NULL, writer, NULL) != 0) {
            fprintf(stderr, "Unable to create writer thread");
            exit(1);
        }
    }

    for (int j = 0; j < NUM_THREADS; ++j) {
        pthread_join(tid[j], NULL);
    }

    printf("Parent quiting\n");

    return 0;
}

void *reader(void *param) {

    for (int i = 1; i <=20; i++) {

        pthread_mutex_lock(&m);

            while (resource_use == writing) {
                pthread_cond_wait(&read_phase, &m);
            }

            printf("Reader Value: %d\n", shared_var);
            printf("Number of Readers Present: %d\n", num_reader);

        resource_use = reading;
        pthread_cond_broadcast(&write_phase);

        pthread_mutex_unlock(&m);
    }

    return 0;
}

void *writer(void *param) {

    for (int i = 1; i <= 20; ++i) {
        pthread_mutex_lock(&m);

            while (resource_use == reading || num_reader != 0) {
                pthread_cond_wait(&write_phase, &m);
            }

        shared_var = i;
        printf("Written Value: %d\n", shared_var);
        printf("Number of Readers Present: %d\n", num_reader);

        resource_use = writing;
        pthread_cond_broadcast(&read_phase);

        pthread_mutex_unlock(&m);
    }

}