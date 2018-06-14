// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/ppoa-v4.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[3]; 
volatile int atom_0_r1_1; 
volatile int atom_1_r1_1; 
volatile int atom_1_r5_1; 
volatile int atom_1_r7_0; 

void *t0(void *arg){
label_1:;
  int v2_r1 = vars[0];

  vars[1] = 1;
  int v19 = (v2_r1 == 1);
  atom_0_r1_1 = v19;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v4_r1 = vars[1];
  int v5_cmpeq = (v4_r1 == v4_r1);
  if (v5_cmpeq)  goto lbl_LC00; else goto lbl_LC00;
lbl_LC00:;
  vars[2] = 1;
  int v7_r5 = vars[2];
  int v8_r6 = v7_r5 ^ v7_r5;
  int v11_r7 = vars[0+v8_r6];
  int v20 = (v4_r1 == 1);
  atom_1_r1_1 = v20;
  int v21 = (v7_r5 == 1);
  atom_1_r5_1 = v21;
  int v22 = (v11_r7 == 0);
  atom_1_r7_0 = v22;
  return NULL;
}

void *t2(void *arg){
label_3:;
  vars[0] = 1;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 

  vars[1] = 0;
  vars[2] = 0;
  vars[0] = 0;
  atom_0_r1_1 = 0;
  atom_1_r1_1 = 0;
  atom_1_r5_1 = 0;
  atom_1_r7_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  int v12 = atom_0_r1_1;
  int v13 = atom_1_r1_1;
  int v14 = atom_1_r5_1;
  int v15 = atom_1_r7_0;
  int v16_conj = v14 & v15;
  int v17_conj = v13 & v16_conj;
  int v18_conj = v12 & v17_conj;
  if (v18_conj == 1) assert(0);
  return 0;
}
