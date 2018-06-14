// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/MOREDETOUR0484.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[3]; 
volatile int atom_1_r1_1; 
volatile int atom_1_r6_0; 
volatile int atom_2_r1_1; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;

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
  vars[2] = 3;
  int v5_r6 = vars[0];
  int v16 = (v2_r1 == 1);
  atom_1_r1_1 = v16;
  int v17 = (v5_r6 == 0);
  atom_1_r6_0 = v17;
  return NULL;
}

void *t2(void *arg){
label_3:;
  int v7_r1 = vars[2];
  vars[2] = 2;
  int v18 = (v7_r1 == 1);
  atom_2_r1_1 = v18;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 

  vars[1] = 0;
  vars[2] = 0;
  vars[0] = 0;
  atom_1_r1_1 = 0;
  atom_1_r6_0 = 0;
  atom_2_r1_1 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  int v8 = atom_1_r1_1;
  int v9 = atom_1_r6_0;
  int v10 = vars[2];
  int v11 = (v10 == 3);
  int v12 = atom_2_r1_1;
  int v13_conj = v11 & v12;
  int v14_conj = v9 & v13_conj;
  int v15_conj = v8 & v14_conj;
  if (v15_conj == 1) assert(0);
  return 0;
}
