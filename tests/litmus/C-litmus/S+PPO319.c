// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/S+PPO319.litmus

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
  int v7_cmpeq = (v6_r4 == v6_r4);
  if (v7_cmpeq)  goto lbl_LC00; else goto lbl_LC00;
lbl_LC00:;
  vars[3] = 1;
  vars[3] = 2;
  int v9_r9 = vars[3];
  int v10_r10 = v9_r9 ^ v9_r9;
  int v13_r11 = vars[4+v10_r10];
  int v14_r13 = v13_r11 ^ v13_r11;
  int v15_r13 = v14_r13 + 1;
  vars[0] = v15_r13;
  int v23 = (v2_r1 == 1);
  atom_1_r1_1 = v23;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[2] = 0;
  vars[1] = 0;
  vars[3] = 0;
  vars[4] = 0;
  vars[0] = 0;
  atom_1_r1_1 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v16 = vars[3];
  int v17 = (v16 == 2);
  int v18 = vars[0];
  int v19 = (v18 == 2);
  int v20 = atom_1_r1_1;
  int v21_conj = v19 & v20;
  int v22_conj = v17 & v21_conj;
  if (v22_conj == 1) assert(0);
  return 0;
}
