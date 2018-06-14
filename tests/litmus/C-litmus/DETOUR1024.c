// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/DETOUR1024.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[2]; 
volatile int atom_0_r3_0; 
volatile int atom_1_r3_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;
  int v2_r3 = vars[1];
  vars[1] = 1;
  vars[1] = 2;
  int v11 = (v2_r3 == 0);
  atom_0_r3_0 = v11;
  return NULL;
}

void *t1(void *arg){
label_2:;
  vars[1] = 3;

  int v4_r3 = vars[0];
  int v12 = (v4_r3 == 0);
  atom_1_r3_0 = v12;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[1] = 0;
  vars[0] = 0;
  atom_0_r3_0 = 0;
  atom_1_r3_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v5 = vars[1];
  int v6 = (v5 == 3);
  int v7 = atom_0_r3_0;
  int v8 = atom_1_r3_0;
  int v9_conj = v7 & v8;
  int v10_conj = v6 & v9_conj;
  if (v10_conj == 1) assert(0);
  return 0;
}
