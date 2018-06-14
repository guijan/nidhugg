// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/W+RWC+sync+addr-fri-rfi-addr+rfi-addr.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[4]; 
volatile int atom_1_r1_1; 
volatile int atom_1_r4_0; 
volatile int atom_1_r7_1; 
volatile int atom_1_r9_0; 
volatile int atom_2_r3_1; 
volatile int atom_2_r5_0; 

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
  vars[2] = 1;
  int v8_r7 = vars[2];
  int v9_r8 = v8_r7 ^ v8_r7;
  int v12_r9 = vars[3+v9_r8];
  int v30 = (v2_r1 == 1);
  atom_1_r1_1 = v30;
  int v31 = (v6_r4 == 0);
  atom_1_r4_0 = v31;
  int v32 = (v8_r7 == 1);
  atom_1_r7_1 = v32;
  int v33 = (v12_r9 == 0);
  atom_1_r9_0 = v33;
  return NULL;
}

void *t2(void *arg){
label_3:;
  vars[3] = 1;
  int v14_r3 = vars[3];
  int v15_r4 = v14_r3 ^ v14_r3;
  int v18_r5 = vars[0+v15_r4];
  int v34 = (v14_r3 == 1);
  atom_2_r3_1 = v34;
  int v35 = (v18_r5 == 0);
  atom_2_r5_0 = v35;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 

  vars[2] = 0;
  vars[0] = 0;
  vars[3] = 0;
  vars[1] = 0;
  atom_1_r1_1 = 0;
  atom_1_r4_0 = 0;
  atom_1_r7_1 = 0;
  atom_1_r9_0 = 0;
  atom_2_r3_1 = 0;
  atom_2_r5_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  int v19 = atom_1_r1_1;
  int v20 = atom_1_r4_0;
  int v21 = atom_1_r7_1;
  int v22 = atom_1_r9_0;
  int v23 = atom_2_r3_1;
  int v24 = atom_2_r5_0;
  int v25_conj = v23 & v24;
  int v26_conj = v22 & v25_conj;
  int v27_conj = v21 & v26_conj;
  int v28_conj = v20 & v27_conj;
  int v29_conj = v19 & v28_conj;
  if (v29_conj == 1) assert(0);
  return 0;
}
