#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <semaphore.h>
 
#define NUM_THREADS     2
int balance = 1000;
sem_t locker;
sem_t locker2;
void* deduct(void* argument) {
    sem_wait(&locker);
      printf("The previous balance before deducting was %i \n",balance);    
        balance = balance-400;
    sem_post(&locker2);
    pthread_exit(NULL);
}
    
void* getmore(void* argument) {
    sem_wait(&locker2);
    printf("The previous balance before multiplying was %i \n",balance);
    balance = balance*2;
    sem_post (&locker);
    pthread_exit(NULL);
}

 
int main(int argc, char** argv) {
   pthread_t threads[NUM_THREADS];
   int thread_args[NUM_THREADS];
   int result_code, index;
   sem_init(&locker,0,1);
   sem_init(&locker2,0,0);
  
   // create all threads one by one

    //  printf("In main: creating thread 1\n");
      result_code = pthread_create(&threads[0], NULL, deduct, NULL);
      assert(0 == result_code);
   //   printf("In main: creating thread 2\n");
      result_code = pthread_create(&threads[1], NULL, getmore, NULL);
      assert(0 == result_code);
         // wait for each thread to complete
   for (index = 0; index < NUM_THREADS; ++index) {
      // block until thread 'index' completes
      result_code = pthread_join(threads[index], NULL);
   //   printf("In main: thread %d has completed\n", index);
      assert(0 == result_code);
   }
 
   

 
   printf("In main: All threads completed successfully\n");
   printf("The total balance is now %i\n",balance);
   return 0;
 }