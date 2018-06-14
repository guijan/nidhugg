// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/MP0199.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[4]; 
volatile int atom_1_r1_1; 
volatile int atom_1_r7_0; 

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
  int v5_r5 = vars[3];
  int v7_r7 = vars[0];
  int v11 = (v2_r1 == 1);
  atom_1_r1_1 = v11;
  int v12 = (v7_r7 == 0);
  atom_1_r7_0 = v12;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[2] = 0;
  vars[0] = 0;
  vars[3] = 0;
  vars[1] = 0;
  atom_1_r1_1 = 0;
  atom_1_r7_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v8 = atom_1_r1_1;
  int v9 = atom_1_r7_0;
  int v10_conj = v8 & v9;
  if (v10_conj == 1) assert(0);
  return 0;
}
