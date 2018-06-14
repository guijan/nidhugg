// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/S+rfi-addr+sync.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[2]; 
volatile int atom_0_r3_2; 
volatile int atom_1_r1_1; 

void *t0(void *arg){
label_1:;
  vars[0] = 2;
  int v2_r3 = vars[0];
  int v3_r4 = v2_r3 ^ v2_r3;
  vars[1+v3_r4] = 1;
  int v12 = (v2_r3 == 2);
  atom_0_r3_2 = v12;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v5_r1 = vars[1];

  vars[0] = 1;
  int v13 = (v5_r1 == 1);
  atom_1_r1_1 = v13;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[0] = 0;
  vars[1] = 0;
  atom_0_r3_2 = 0;
  atom_1_r1_1 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v6 = vars[0];
  int v7 = (v6 == 2);
  int v8 = atom_0_r3_2;
  int v9 = atom_1_r1_1;
  int v10_conj = v8 & v9;
  int v11_conj = v7 & v10_conj;
  if (v11_conj == 1) assert(0);
  return 0;
}
