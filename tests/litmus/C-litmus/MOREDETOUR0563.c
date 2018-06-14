// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/MOREDETOUR0563.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[3]; 
volatile int atom_0_r5_2; 
volatile int atom_1_r6_0; 
volatile int atom_2_r1_2; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;

  vars[1] = 1;

  int v2_r5 = vars[1];
  int v18 = (v2_r5 == 2);
  atom_0_r5_2 = v18;
  return NULL;
}

void *t1(void *arg){
label_2:;
  vars[1] = 2;
  vars[1] = 4;
  int v4_r4 = vars[2];
  int v5_cmpeq = (v4_r4 == v4_r4);
  if (v5_cmpeq)  goto lbl_LC00; else goto lbl_LC00;
lbl_LC00:;

  int v7_r6 = vars[0];
  int v19 = (v7_r6 == 0);
  atom_1_r6_0 = v19;
  return NULL;
}

void *t2(void *arg){
label_3:;
  int v9_r1 = vars[1];
  vars[1] = 3;
  int v20 = (v9_r1 == 2);
  atom_2_r1_2 = v20;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 

  vars[2] = 0;
  vars[1] = 0;
  vars[0] = 0;
  atom_0_r5_2 = 0;
  atom_1_r6_0 = 0;
  atom_2_r1_2 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  int v10 = atom_0_r5_2;
  int v11 = atom_1_r6_0;
  int v12 = vars[1];
  int v13 = (v12 == 4);
  int v14 = atom_2_r1_2;
  int v15_conj = v13 & v14;
  int v16_conj = v11 & v15_conj;
  int v17_conj = v10 & v16_conj;
  if (v17_conj == 1) assert(0);
  return 0;
}
