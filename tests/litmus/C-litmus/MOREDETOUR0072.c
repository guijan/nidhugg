// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/MOREDETOUR0072.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[3]; 
volatile int atom_0_r5_0; 
volatile int atom_2_r1_2; 
volatile int atom_2_r4_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;
  int v2_r3 = vars[1];
  int v3_cmpeq = (v2_r3 == v2_r3);
  if (v3_cmpeq)  goto lbl_LC00; else goto lbl_LC00;
lbl_LC00:;
  int v5_r5 = vars[2];
  vars[2] = 2;
  int v20 = (v5_r5 == 0);
  atom_0_r5_0 = v20;
  return NULL;
}

void *t1(void *arg){
label_2:;
  vars[2] = 1;
  return NULL;
}

void *t2(void *arg){
label_3:;
  int v7_r1 = vars[2];
  int v8_r3 = v7_r1 ^ v7_r1;
  int v11_r4 = vars[0+v8_r3];
  int v21 = (v7_r1 == 2);
  atom_2_r1_2 = v21;
  int v22 = (v11_r4 == 0);
  atom_2_r4_0 = v22;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 

  vars[2] = 0;
  vars[1] = 0;
  vars[0] = 0;
  atom_0_r5_0 = 0;
  atom_2_r1_2 = 0;
  atom_2_r4_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  int v12 = atom_0_r5_0;
  int v13 = vars[2];
  int v14 = (v13 == 2);
  int v15 = atom_2_r1_2;
  int v16 = atom_2_r4_0;
  int v17_conj = v15 & v16;
  int v18_conj = v14 & v17_conj;
  int v19_conj = v12 & v18_conj;
  if (v19_conj == 1) assert(0);
  return 0;
}
