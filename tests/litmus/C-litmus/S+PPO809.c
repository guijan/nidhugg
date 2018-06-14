// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/S+PPO809.litmus

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
  int v5_r5 = vars[2];
  int v6_r6 = v5_r5 ^ v5_r5;
  vars[3+v6_r6] = 1;
  int v8_r9 = vars[3];
  int v10_r10 = vars[3];
  int v11_cmpeq = (v10_r10 == v10_r10);
  if (v11_cmpeq)  goto lbl_LC01; else goto lbl_LC01;
lbl_LC01:;
  vars[0] = 1;
  int v16 = (v2_r1 == 1);
  atom_1_r1_1 = v16;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[2] = 0;
  vars[1] = 0;
  vars[0] = 0;
  vars[3] = 0;
  atom_1_r1_1 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v12 = vars[0];
  int v13 = (v12 == 2);
  int v14 = atom_1_r1_1;
  int v15_conj = v13 & v14;
  if (v15_conj == 1) assert(0);
  return 0;
}
