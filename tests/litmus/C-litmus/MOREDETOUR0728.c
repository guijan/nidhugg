// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/MOREDETOUR0728.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[3]; 
volatile int atom_1_r1_1; 
volatile int atom_1_r3_0; 
volatile int atom_1_r5_1; 

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
  int v5_r3 = vars[2];
  int v7_r5 = vars[2];
  int v8_r6 = v7_r5 ^ v7_r5;
  int v9_r6 = v8_r6 + 1;
  vars[0] = v9_r6;
  int v18 = (v2_r1 == 1);
  atom_1_r1_1 = v18;
  int v19 = (v5_r3 == 0);
  atom_1_r3_0 = v19;
  int v20 = (v7_r5 == 1);
  atom_1_r5_1 = v20;
  return NULL;
}

void *t2(void *arg){
label_3:;
  vars[2] = 1;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 

  vars[0] = 0;
  vars[2] = 0;
  vars[1] = 0;
  atom_1_r1_1 = 0;
  atom_1_r3_0 = 0;
  atom_1_r5_1 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  int v10 = vars[0];
  int v11 = (v10 == 2);
  int v12 = atom_1_r1_1;
  int v13 = atom_1_r3_0;
  int v14 = atom_1_r5_1;
  int v15_conj = v13 & v14;
  int v16_conj = v12 & v15_conj;
  int v17_conj = v11 & v16_conj;
  if (v17_conj == 1) assert(0);
  return 0;
}
