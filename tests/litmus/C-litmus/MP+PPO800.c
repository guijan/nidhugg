// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/MP+PPO800.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[2]; 
volatile int atom_1_r1_1; 
volatile int atom_1_r10_1; 

void *t0(void *arg){
label_1:;
  vars[0] = 2;

  vars[1] = 1;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v2_r1 = vars[1];
  vars[1] = 2;
  int v4_r4 = vars[1];
  int v5_r5 = v4_r4 ^ v4_r4;
  int v8_r6 = vars[0+v5_r5];
  int v10_r8 = vars[0];
  vars[0] = 1;
  int v12_r10 = vars[0];
  int v22 = (v2_r1 == 1);
  atom_1_r1_1 = v22;
  int v23 = (v12_r10 == 1);
  atom_1_r10_1 = v23;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[0] = 0;
  vars[1] = 0;
  atom_1_r1_1 = 0;
  atom_1_r10_1 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v13 = vars[0];
  int v14 = (v13 == 2);
  int v15 = vars[1];
  int v16 = (v15 == 2);
  int v17 = atom_1_r1_1;
  int v18 = atom_1_r10_1;
  int v19_conj = v17 & v18;
  int v20_conj = v16 & v19_conj;
  int v21_conj = v14 & v20_conj;
  if (v21_conj == 1) assert(0);
  return 0;
}
