// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/MOREDETOUR0278.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[2]; 
volatile int atom_0_r3_2; 
volatile int atom_0_r4_0; 
volatile int atom_1_r1_1; 

void *t0(void *arg){
label_1:;
  vars[0] = 2;
  int v2_r3 = vars[0];
  int v3_cmpeq = (v2_r3 == v2_r3);
  if (v3_cmpeq)  goto lbl_LC00; else goto lbl_LC00;
lbl_LC00:;
  int v5_r4 = vars[1];
  vars[1] = 1;
  int v18 = (v2_r3 == 2);
  atom_0_r3_2 = v18;
  int v19 = (v5_r4 == 0);
  atom_0_r4_0 = v19;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v7_r1 = vars[1];
  int v8_r3 = v7_r1 ^ v7_r1;
  int v9_r3 = v8_r3 + 1;
  vars[0] = v9_r3;
  int v20 = (v7_r1 == 1);
  atom_1_r1_1 = v20;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[1] = 0;
  vars[0] = 0;
  atom_0_r3_2 = 0;
  atom_0_r4_0 = 0;
  atom_1_r1_1 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v10 = atom_0_r3_2;
  int v11 = atom_0_r4_0;
  int v12 = vars[0];
  int v13 = (v12 == 2);
  int v14 = atom_1_r1_1;
  int v15_conj = v13 & v14;
  int v16_conj = v11 & v15_conj;
  int v17_conj = v10 & v16_conj;
  if (v17_conj == 1) assert(0);
  return 0;
}
