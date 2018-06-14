// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/DETOUR1030.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[2]; 
volatile int atom_0_r3_2; 
volatile int atom_2_r3_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;
  int v2_r3 = vars[0];
  int v3_cmpeq = (v2_r3 == v2_r3);
  if (v3_cmpeq)  goto lbl_LC00; else goto lbl_LC00;
lbl_LC00:;
  vars[1] = 1;
  vars[1] = 2;
  int v12 = (v2_r3 == 2);
  atom_0_r3_2 = v12;
  return NULL;
}

void *t1(void *arg){
label_2:;
  vars[0] = 2;
  return NULL;
}

void *t2(void *arg){
label_3:;
  vars[1] = 3;

  int v5_r3 = vars[0];
  int v13 = (v5_r3 == 0);
  atom_2_r3_0 = v13;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 

  vars[0] = 0;
  vars[1] = 0;
  atom_0_r3_2 = 0;
  atom_2_r3_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  int v6 = vars[1];
  int v7 = (v6 == 3);
  int v8 = atom_0_r3_2;
  int v9 = atom_2_r3_0;
  int v10_conj = v8 & v9;
  int v11_conj = v7 & v10_conj;
  if (v11_conj == 1) assert(0);
  return 0;
}
