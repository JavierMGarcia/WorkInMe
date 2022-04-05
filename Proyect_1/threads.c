#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 
 

void * periodic (void *arg) { 
 
int period; 
 
period = *((int *)arg); 
 
	 while (1) { 
	 	printf("En tarea con periodo %d\n", period); 
	 sleep (period); 
	 } 
 } 


void main() { 
 
	 pthread_t th1, th2; 
 	int period1=2, period2=3; 
 
	 pthread_create(&th1, NULL, periodic, &period1); 
	 pthread_create(&th2, NULL, periodic, &period2); 
 
	 sleep(30); 
	 printf("Salida del hilo principal\n"); 
	 exit(0); 
 }
