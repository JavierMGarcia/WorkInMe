#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

 int variable=0;
 int avgdelay;

 void * hilo (void *arg) {
 	while (1) {
 		variable++;
		usleep ( get_rand_delay() );
 		variable--;
 		usleep ( get_rand_delay() );
 		}
 }

 int get_rand_delay( void) {

 return avgdelay - avgdelay/10 + (rand() % avgdelay) / 5;
 }
 
 int main( int argc, char* argv[]) {

 int i, nthreads;
 pthread_t * th;

 avgdelay = atoi( argv[1]);
 nthreads = atoi( argv[2]);

 th = (pthread_t *) calloc( nthreads, sizeof( pthread_t)); 

 for( i = 0; i < nthreads; i++)
 	pthread_create(&th[i], NULL, hilo, NULL);

 	while( 1){
 		printf("variable=%d\n", variable);
 		usleep(500000);
 	}
 }
