// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/DETOUR1105.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[3]; 
volatile int atom_1_r1_1; 
volatile int atom_1_r5_1; 

void *t0(void *arg){
label_1:;
  vars[0] = 2;

  vars[1] = 1;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v2_r1 = vars[1];
  int v3_r3 = v2_r1 ^ v2_r1;
  int v4_r3 = v3_r3 + 1;
  vars[2] = v4_r3;
  int v6_r5 = vars[2];
  int v7_r6 = v6_r5 ^ v6_r5;
  int v8_r6 = v7_r6 + 1;
  vars[0] = v8_r6;
  int v15 = (v2_r1 == 1);
  atom_1_r1_1 = v15;
  int v16 = (v6_r5 == 1);
  atom_1_r5_1 = v16;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[2] = 0;
  vars[0] = 0;
  vars[1] = 0;
  atom_1_r1_1 = 0;
  atom_1_r5_1 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v9 = vars[0];
  int v10 = (v9 == 2);
  int v11 = atom_1_r1_1;
  int v12 = atom_1_r5_1;
  int v13_conj = v11 & v12;
  int v14_conj = v10 & v13_conj;
  if (v14_conj == 1) assert(0);
  return 0;
}
