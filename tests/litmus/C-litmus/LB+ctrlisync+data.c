// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/LB+ctrlisync+data.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[2]; 
volatile int atom_0_r1_1; 
volatile int atom_1_r1_1; 

void *t0(void *arg){
label_1:;
  int v2_r1 = vars[0];
  int v3_cmpeq = (v2_r1 == v2_r1);
  if (v3_cmpeq)  goto lbl_LC00; else goto lbl_LC00;
lbl_LC00:;

  vars[1] = 1;
  int v11 = (v2_r1 == 1);
  atom_0_r1_1 = v11;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v5_r1 = vars[1];
  int v6_r3 = v5_r1 ^ v5_r1;
  int v7_r3 = v6_r3 + 1;
  vars[0] = v7_r3;
  int v12 = (v5_r1 == 1);
  atom_1_r1_1 = v12;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[1] = 0;
  vars[0] = 0;
  atom_0_r1_1 = 0;
  atom_1_r1_1 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v8 = atom_0_r1_1;
  int v9 = atom_1_r1_1;
  int v10_conj = v8 & v9;
  if (v10_conj == 1) assert(0);
  return 0;
}
