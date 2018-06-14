// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/MP+PPO073.litmus

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
  int v10_r8 = vars[3];
  int v11_cmpeq = (v10_r8 == v10_r8);
  if (v11_cmpeq)  goto lbl_LC00; else goto lbl_LC00;
lbl_LC00:;
  vars[4] = 1;
  int v13_r11 = vars[4];
  int v14_r12 = v13_r11 ^ v13_r11;
  int v17_r13 = vars[0+v14_r12];
  int v21 = (v2_r1 == 1);
  atom_1_r1_1 = v21;
  int v22 = (v17_r13 == 0);
  atom_1_r13_0 = v22;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[3] = 0;
  vars[4] = 0;
  vars[0] = 0;
  vars[1] = 0;
  vars[2] = 0;
  atom_1_r1_1 = 0;
  atom_1_r13_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v18 = atom_1_r1_1;
  int v19 = atom_1_r13_0;
  int v20_conj = v18 & v19;
  if (v20_conj == 1) assert(0);
  return 0;
}
