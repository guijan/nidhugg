// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/S+PPO107.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[5]; 
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
  int v8_r6 = vars[2];
  int v9_r7 = v8_r6 ^ v8_r6;
  int v12_r8 = vars[3+v9_r7];
  int v13_r10 = v12_r8 ^ v12_r8;
  int v14_r10 = v13_r10 + 1;
  vars[4] = v14_r10;
  int v16_r12 = vars[4];
  int v17_r13 = v16_r12 ^ v16_r12;
  vars[0+v17_r13] = 1;
  int v22 = (v2_r1 == 1);
  atom_1_r1_1 = v22;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[0] = 0;
  vars[3] = 0;
  vars[4] = 0;
  vars[1] = 0;
  vars[2] = 0;
  atom_1_r1_1 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v18 = vars[0];
  int v19 = (v18 == 2);
  int v20 = atom_1_r1_1;
  int v21_conj = v19 & v20;
  if (v21_conj == 1) assert(0);
  return 0;
}
