// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/S+PPO467.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[3]; 
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
  vars[1] = 2;
  int v4_r4 = vars[1];
  int v5_cmpeq = (v4_r4 == v4_r4);
  if (v5_cmpeq)  goto lbl_LC00; else goto lbl_LC00;
lbl_LC00:;
  vars[2] = 1;
  vars[2] = 2;
  int v7_r8 = vars[2];
  int v8_r9 = v7_r8 ^ v7_r8;
  int v9_r9 = v8_r9 + 1;
  vars[0] = v9_r9;
  int v20 = (v2_r1 == 1);
  atom_1_r1_1 = v20;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[0] = 0;
  vars[1] = 0;
  vars[2] = 0;
  atom_1_r1_1 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v10 = vars[0];
  int v11 = (v10 == 2);
  int v12 = vars[1];
  int v13 = (v12 == 2);
  int v14 = vars[2];
  int v15 = (v14 == 2);
  int v16 = atom_1_r1_1;
  int v17_conj = v15 & v16;
  int v18_conj = v13 & v17_conj;
  int v19_conj = v11 & v18_conj;
  if (v19_conj == 1) assert(0);
  return 0;
}
