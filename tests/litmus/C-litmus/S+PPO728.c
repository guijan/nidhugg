// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/S+PPO728.litmus

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
  int v4_r3 = vars[1];
  int v5_r4 = v4_r3 ^ v4_r3;
  int v8_r5 = vars[2+v5_r4];
  int v9_r7 = v8_r5 ^ v8_r5;
  vars[3+v9_r7] = 1;
  vars[3] = 2;
  int v11_r11 = vars[3];
  int v12_cmpeq = (v11_r11 == v11_r11);
  if (v12_cmpeq)  goto lbl_LC00; else goto lbl_LC00;
lbl_LC00:;
  vars[0] = 1;
  int v20 = (v2_r1 == 1);
  atom_1_r1_1 = v20;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[2] = 0;
  vars[0] = 0;
  vars[1] = 0;
  vars[3] = 0;
  atom_1_r1_1 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v13 = vars[3];
  int v14 = (v13 == 2);
  int v15 = vars[0];
  int v16 = (v15 == 2);
  int v17 = atom_1_r1_1;
  int v18_conj = v16 & v17;
  int v19_conj = v14 & v18_conj;
  if (v19_conj == 1) assert(0);
  return 0;
}
