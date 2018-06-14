// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/LB+PPO0427.litmus

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
  int v21 = (v2_r1 == 1);
  atom_0_r1_1 = v21;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v6_r1 = vars[1];
  int v8_r3 = vars[1];
  vars[1] = 2;
  int v10_r5 = vars[1];
  int v11_r6 = v10_r5 ^ v10_r5;
  int v12_r6 = v11_r6 + 1;
  vars[2] = v12_r6;
  int v14_r8 = vars[2];
  vars[0] = 1;
  int v22 = (v6_r1 == 1);
  atom_1_r1_1 = v22;
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

  int v15 = vars[1];
  int v16 = (v15 == 2);
  int v17 = atom_0_r1_1;
  int v18 = atom_1_r1_1;
  int v19_conj = v17 & v18;
  int v20_conj = v16 & v19_conj;
  if (v20_conj == 1) assert(0);
  return 0;
}
