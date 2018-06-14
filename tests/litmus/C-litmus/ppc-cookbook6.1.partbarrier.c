// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/ppc-cookbook6.1.partbarrier.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[2]; 
volatile int atom_0_r6_0; 
volatile int atom_1_r5_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 55;

  int v2_r6 = vars[1];
  int v8 = (v2_r6 == 0);
  atom_0_r6_0 = v8;
  return NULL;
}

void *t1(void *arg){
label_2:;
  vars[1] = 66;
  int v4_r5 = vars[0];
  int v9 = (v4_r5 == 0);
  atom_1_r5_0 = v9;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[0] = 0;
  vars[1] = 0;
  atom_0_r6_0 = 0;
  atom_1_r5_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v5 = atom_0_r6_0;
  int v6 = atom_1_r5_0;
  int v7_conj = v5 & v6;
  if (v7_conj == 1) assert(0);
  return 0;
}
