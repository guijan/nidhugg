// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/MP+PPO875.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[4]; 
volatile int atom_1_r1_1; 
volatile int atom_1_r13_1; 

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
  int v4_r3 = v3_r3 + 1;
  vars[2] = v4_r3;
  int v6_r5 = vars[2];
  int v7_r6 = v6_r5 ^ v6_r5;
  int v10_r7 = vars[3+v7_r6];
  int v11_r9 = v10_r7 ^ v10_r7;
  vars[0+v11_r9] = 1;
  int v13_r12 = vars[0];
  int v15_r13 = vars[0];
  int v22 = (v2_r1 == 1);
  atom_1_r1_1 = v22;
  int v23 = (v15_r13 == 1);
  atom_1_r13_1 = v23;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[1] = 0;
  vars[3] = 0;
  vars[0] = 0;
  vars[2] = 0;
  atom_1_r1_1 = 0;
  atom_1_r13_1 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v16 = vars[0];
  int v17 = (v16 == 2);
  int v18 = atom_1_r1_1;
  int v19 = atom_1_r13_1;
  int v20_conj = v18 & v19;
  int v21_conj = v17 & v20_conj;
  if (v21_conj == 1) assert(0);
  return 0;
}
