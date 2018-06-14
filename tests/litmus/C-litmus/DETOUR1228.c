// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/DETOUR1228.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[3]; 
volatile int atom_1_r6_2; 

void *t0(void *arg){
label_1:;
  vars[0] = 2;

  vars[1] = 1;
  return NULL;
}

void *t1(void *arg){
label_2:;
  vars[1] = 2;
  vars[2] = 1;
  vars[2] = 2;
  int v2_r6 = vars[2];
  int v3_r7 = v2_r6 ^ v2_r6;
  vars[0+v3_r7] = 1;
  int v11 = (v2_r6 == 2);
  atom_1_r6_2 = v11;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[0] = 0;
  vars[1] = 0;
  vars[2] = 0;
  atom_1_r6_2 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v4 = vars[1];
  int v5 = (v4 == 2);
  int v6 = vars[0];
  int v7 = (v6 == 2);
  int v8 = atom_1_r6_2;
  int v9_conj = v7 & v8;
  int v10_conj = v5 & v9_conj;
  if (v10_conj == 1) assert(0);
  return 0;
}
