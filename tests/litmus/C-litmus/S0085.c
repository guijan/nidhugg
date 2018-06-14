// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/S0085.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[4]; 
volatile int atom_1_r1_1; 

void *t0(void *arg){
label_1:;
  vars[0] = 2;

  vars[1] = 1;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v2_r1 = vars[1];
  vars[2] = 1;
  int v4_r5 = vars[3];
  int v5_r7 = v4_r5 ^ v4_r5;
  vars[0+v5_r7] = 1;
  int v10 = (v2_r1 == 1);
  atom_1_r1_1 = v10;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[2] = 0;
  vars[3] = 0;
  vars[0] = 0;
  vars[1] = 0;
  atom_1_r1_1 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v6 = vars[0];
  int v7 = (v6 == 2);
  int v8 = atom_1_r1_1;
  int v9_conj = v7 & v8;
  if (v9_conj == 1) assert(0);
  return 0;
}
