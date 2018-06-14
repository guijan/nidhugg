// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/MP+PPO247.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[5]; 
volatile int atom_1_r1_1; 
volatile int atom_1_r13_0; 

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
  int v6_r4 = vars[2+v3_r3];
  int v7_r6 = v6_r4 ^ v6_r4;
  int v8_r6 = v7_r6 + 1;
  vars[3] = v8_r6;
  vars[3] = 2;
  int v10_r9 = vars[3];
  int v11_r10 = v10_r9 ^ v10_r9;
  int v14_r11 = vars[4+v11_r10];
  int v15_cmpeq = (v14_r11 == v14_r11);
  if (v15_cmpeq)  goto lbl_LC00; else goto lbl_LC00;
lbl_LC00:;

  int v17_r13 = vars[0];
  int v24 = (v2_r1 == 1);
  atom_1_r1_1 = v24;
  int v25 = (v17_r13 == 0);
  atom_1_r13_0 = v25;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[0] = 0;
  vars[3] = 0;
  vars[1] = 0;
  vars[2] = 0;
  vars[4] = 0;
  atom_1_r1_1 = 0;
  atom_1_r13_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v18 = vars[3];
  int v19 = (v18 == 2);
  int v20 = atom_1_r1_1;
  int v21 = atom_1_r13_0;
  int v22_conj = v20 & v21;
  int v23_conj = v19 & v22_conj;
  if (v23_conj == 1) assert(0);
  return 0;
}
