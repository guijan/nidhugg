// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/MP+PPO325.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[4]; 
volatile int atom_1_r1_1; 
volatile int atom_1_r9_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;

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
  int v8_r6 = v7_r6 + 1;
  vars[3] = v8_r6;
  int v10_r8 = vars[3];
  int v11_cmpeq = (v10_r8 == v10_r8);
  if (v11_cmpeq)  goto lbl_LC00; else goto lbl_LC00;
lbl_LC00:;

  int v13_r9 = vars[0];
  int v17 = (v2_r1 == 1);
  atom_1_r1_1 = v17;
  int v18 = (v13_r9 == 0);
  atom_1_r9_0 = v18;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[3] = 0;
  vars[1] = 0;
  vars[0] = 0;
  vars[2] = 0;
  atom_1_r1_1 = 0;
  atom_1_r9_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v14 = atom_1_r1_1;
  int v15 = atom_1_r9_0;
  int v16_conj = v14 & v15;
  if (v16_conj == 1) assert(0);
  return 0;
}
