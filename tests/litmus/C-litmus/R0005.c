// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/R0005.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[4]; 
volatile int atom_1_r8_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;

  vars[1] = 1;
  return NULL;
}

void *t1(void *arg){
label_2:;
  vars[1] = 2;
  vars[2] = 1;
  int v2_r5 = vars[3];
  int v3_r7 = v2_r5 ^ v2_r5;
  int v6_r8 = vars[0+v3_r7];
  int v11 = (v6_r8 == 0);
  atom_1_r8_0 = v11;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[2] = 0;
  vars[3] = 0;
  vars[1] = 0;
  vars[0] = 0;
  atom_1_r8_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v7 = vars[1];
  int v8 = (v7 == 2);
  int v9 = atom_1_r8_0;
  int v10_conj = v8 & v9;
  if (v10_conj == 1) assert(0);
  return 0;
}
