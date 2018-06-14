// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/S+PPO321.litmus

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
  int v3_r3 = v2_r1 ^ v2_r1;
  int v6_r4 = vars[2+v3_r3];
  vars[2] = 1;
  vars[2] = 2;
  int v8_r8 = vars[2];
  int v9_r9 = v8_r8 ^ v8_r8;
  int v12_r10 = vars[3+v9_r9];
  int v13_r12 = v12_r10 ^ v12_r10;
  int v14_r12 = v13_r12 + 1;
  vars[0] = v14_r12;
  int v22 = (v2_r1 == 1);
  atom_1_r1_1 = v22;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[2] = 0;
  vars[0] = 0;
  vars[1] = 0;
  vars[3] = 0;
  atom_1_r1_1 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v15 = vars[0];
  int v16 = (v15 == 2);
  int v17 = vars[2];
  int v18 = (v17 == 2);
  int v19 = atom_1_r1_1;
  int v20_conj = v18 & v19;
  int v21_conj = v16 & v20_conj;
  if (v21_conj == 1) assert(0);
  return 0;
}
