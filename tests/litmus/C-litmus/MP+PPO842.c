// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/MP+PPO842.litmus

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
  int v3_r3 = v2_r1 ^ v2_r1;
  int v6_r4 = vars[2+v3_r3];
  vars[2] = 1;
  int v8_r7 = vars[2];
  int v9_r8 = v8_r7 ^ v8_r7;
  int v12_r9 = vars[0+v9_r8];
  int v14_r11 = vars[0];
  int v18 = (v2_r1 == 1);
  atom_1_r1_1 = v18;
  int v19 = (v14_r11 == 0);
  atom_1_r11_0 = v19;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[2] = 0;
  vars[1] = 0;
  vars[0] = 0;
  atom_1_r1_1 = 0;
  atom_1_r11_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v15 = atom_1_r1_1;
  int v16 = atom_1_r11_0;
  int v17_conj = v15 & v16;
  if (v17_conj == 1) assert(0);
  return 0;
}
