// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/MOREDETOUR0547.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[2]; 
volatile int atom_1_r1_1; 
volatile int atom_1_r4_4; 
volatile int atom_1_r5_0; 
volatile int atom_2_r4_3; 
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
  vars[1] = 3;
  int v4_r4 = vars[1];
  int v5_cmpeq = (v4_r4 == v4_r4);
  if (v5_cmpeq)  goto lbl_LC00; else goto lbl_LC00;
lbl_LC00:;
  int v7_r5 = vars[0];
  int v21 = (v2_r1 == 1);
  atom_1_r1_1 = v21;
  int v22 = (v4_r4 == 4);
  atom_1_r4_4 = v22;
  int v23 = (v7_r5 == 0);
  atom_1_r5_0 = v23;
  return NULL;
}

void *t2(void *arg){
label_3:;
  int v9_r1 = vars[1];
  vars[1] = 2;

  int v11_r4 = vars[1];
  int v24 = (v11_r4 == 3);
  atom_2_r4_3 = v24;
  int v25 = (v9_r1 == 1);
  atom_2_r1_1 = v25;
  return NULL;
}

void *t3(void *arg){
label_4:;
  vars[1] = 4;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 
  pthread_t thr3; 

  vars[1] = 0;
  vars[0] = 0;
  atom_1_r1_1 = 0;
  atom_1_r4_4 = 0;
  atom_1_r5_0 = 0;
  atom_2_r4_3 = 0;
  atom_2_r1_1 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);
  pthread_create(&thr3, NULL, t3, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);
  pthread_join(thr3, NULL);

  int v12 = atom_1_r1_1;
  int v13 = atom_1_r4_4;
  int v14 = atom_1_r5_0;
  int v15 = atom_2_r4_3;
  int v16 = atom_2_r1_1;
  int v17_conj = v15 & v16;
  int v18_conj = v14 & v17_conj;
  int v19_conj = v13 & v18_conj;
  int v20_conj = v12 & v19_conj;
  if (v20_conj == 1) assert(0);
  return 0;
}
