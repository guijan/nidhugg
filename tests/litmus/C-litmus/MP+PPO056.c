// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/MP+PPO056.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[4]; 
volatile int atom_1_r1_1; 
volatile int atom_1_r12_0; 

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
  int v5_r4 = v4_r3 ^ v4_r3;
  int v8_r5 = vars[2+v5_r4];
  int v10_r7 = vars[2];
  int v11_r8 = v10_r7 ^ v10_r7;
  int v12_r8 = v11_r8 + 1;
  vars[3] = v12_r8;
  int v14_r10 = vars[3];
  int v15_r11 = v14_r10 ^ v14_r10;
  int v18_r12 = vars[0+v15_r11];
  int v22 = (v2_r1 == 1);
  atom_1_r1_1 = v22;
  int v23 = (v18_r12 == 0);
  atom_1_r12_0 = v23;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[0] = 0;
  vars[1] = 0;
  vars[2] = 0;
  vars[3] = 0;
  atom_1_r1_1 = 0;
  atom_1_r12_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v19 = atom_1_r1_1;
  int v20 = atom_1_r12_0;
  int v21_conj = v19 & v20;
  if (v21_conj == 1) assert(0);
  return 0;
}
