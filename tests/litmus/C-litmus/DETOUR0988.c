// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/DETOUR0988.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[2]; 
volatile int atom_0_r3_2; 
volatile int atom_0_r5_3; 
volatile int atom_2_r3_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;
  int v2_r3 = vars[0];
  vars[0] = 3;
  int v4_r5 = vars[0];
  int v5_r6 = v4_r5 ^ v4_r5;
  int v6_r6 = v5_r6 + 1;
  vars[1] = v6_r6;
  int v17 = (v2_r3 == 2);
  atom_0_r3_2 = v17;
  int v18 = (v4_r5 == 3);
  atom_0_r5_3 = v18;
  return NULL;
}

void *t1(void *arg){
label_2:;
  vars[0] = 2;
  return NULL;
}

void *t2(void *arg){
label_3:;
  vars[1] = 2;

  int v8_r3 = vars[0];
  int v19 = (v8_r3 == 0);
  atom_2_r3_0 = v19;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 

  vars[1] = 0;
  vars[0] = 0;
  atom_0_r3_2 = 0;
  atom_0_r5_3 = 0;
  atom_2_r3_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  int v9 = vars[1];
  int v10 = (v9 == 2);
  int v11 = atom_0_r3_2;
  int v12 = atom_0_r5_3;
  int v13 = atom_2_r3_0;
  int v14_conj = v12 & v13;
  int v15_conj = v11 & v14_conj;
  int v16_conj = v10 & v15_conj;
  if (v16_conj == 1) assert(0);
  return 0;
}
