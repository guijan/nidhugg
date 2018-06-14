// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/LB+PPO0138.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[3]; 
volatile int atom_0_r1_1; 
volatile int atom_1_r1_1; 

void *t0(void *arg){
label_1:;
  int v2_r1 = vars[0];
  int v3_r3 = v2_r1 ^ v2_r1;
  int v4_r3 = v3_r3 + 1;
  vars[1] = v4_r3;
  int v20 = (v2_r1 == 1);
  atom_0_r1_1 = v20;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v6_r1 = vars[1];
  int v8_r3 = vars[1];
  vars[1] = 2;
  int v10_r5 = vars[1];
  int v12_r6 = vars[1];
  int v13_r7 = v12_r6 ^ v12_r6;
  vars[2+v13_r7] = 1;
  vars[0] = 1;
  int v21 = (v6_r1 == 1);
  atom_1_r1_1 = v21;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[2] = 0;
  vars[1] = 0;
  vars[0] = 0;
  atom_0_r1_1 = 0;
  atom_1_r1_1 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v14 = vars[1];
  int v15 = (v14 == 2);
  int v16 = atom_0_r1_1;
  int v17 = atom_1_r1_1;
  int v18_conj = v16 & v17;
  int v19_conj = v15 & v18_conj;
  if (v19_conj == 1) assert(0);
  return 0;
}
