// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/MP+PPO168.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[3]; 
volatile int atom_1_r1_1; 
volatile int atom_1_r11_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;

  vars[1] = 1;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v2_r1 = vars[1];
  vars[1] = 2;
  int v4_r4 = vars[1];
  int v6_r5 = vars[1];
  int v7_r6 = v6_r5 ^ v6_r5;
  int v10_r7 = vars[2+v7_r6];
  int v12_r9 = vars[2];
  int v13_r10 = v12_r9 ^ v12_r9;
  int v16_r11 = vars[0+v13_r10];
  int v23 = (v2_r1 == 1);
  atom_1_r1_1 = v23;
  int v24 = (v16_r11 == 0);
  atom_1_r11_0 = v24;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[1] = 0;
  vars[2] = 0;
  vars[0] = 0;
  atom_1_r1_1 = 0;
  atom_1_r11_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v17 = vars[1];
  int v18 = (v17 == 2);
  int v19 = atom_1_r1_1;
  int v20 = atom_1_r11_0;
  int v21_conj = v19 & v20;
  int v22_conj = v18 & v21_conj;
  if (v22_conj == 1) assert(0);
  return 0;
}
