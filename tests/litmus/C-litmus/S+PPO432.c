// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/S+PPO432.litmus

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
  int v3_cmpeq = (v2_r1 == v2_r1);
  if (v3_cmpeq)  goto lbl_LC00; else goto lbl_LC00;
lbl_LC00:;
  vars[2] = 1;
  vars[2] = 2;
  int v5_r6 = vars[2];
  int v6_cmpeq = (v5_r6 == v5_r6);
  if (v6_cmpeq)  goto lbl_LC01; else goto lbl_LC01;
lbl_LC01:;
  vars[3] = 1;
  int v8_r9 = vars[3];
  int v9_r10 = v8_r9 ^ v8_r9;
  int v10_r10 = v9_r10 + 1;
  vars[0] = v10_r10;
  int v18 = (v2_r1 == 1);
  atom_1_r1_1 = v18;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[0] = 0;
  vars[2] = 0;
  vars[3] = 0;
  vars[1] = 0;
  atom_1_r1_1 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v11 = vars[0];
  int v12 = (v11 == 2);
  int v13 = vars[2];
  int v14 = (v13 == 2);
  int v15 = atom_1_r1_1;
  int v16_conj = v14 & v15;
  int v17_conj = v12 & v16_conj;
  if (v17_conj == 1) assert(0);
  return 0;
}
