// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/MP0117.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[3]; 
volatile int atom_1_r1_1; 
volatile int atom_1_r6_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;

  vars[1] = 1;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v2_r1 = vars[1];
  int v4_r3 = vars[1];
  int v6_r4 = vars[2];
  int v7_cmpeq = (v6_r4 == v6_r4);
  if (v7_cmpeq)  goto lbl_LC00; else goto lbl_LC00;
lbl_LC00:;

  int v9_r6 = vars[0];
  int v13 = (v2_r1 == 1);
  atom_1_r1_1 = v13;
  int v14 = (v9_r6 == 0);
  atom_1_r6_0 = v14;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[0] = 0;
  vars[2] = 0;
  vars[1] = 0;
  atom_1_r1_1 = 0;
  atom_1_r6_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v10 = atom_1_r1_1;
  int v11 = atom_1_r6_0;
  int v12_conj = v10 & v11;
  if (v12_conj == 1) assert(0);
  return 0;
}
