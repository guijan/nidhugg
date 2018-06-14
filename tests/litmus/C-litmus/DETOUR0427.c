// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/DETOUR0427.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[3]; 
volatile int atom_0_r5_2; 
volatile int atom_2_r1_1; 

void *t0(void *arg){
label_1:;
  vars[0] = 2;
  vars[1] = 1;
  int v2_r5 = vars[1];
  int v3_r6 = v2_r5 ^ v2_r5;
  int v4_r6 = v3_r6 + 1;
  vars[2] = v4_r6;
  int v15 = (v2_r5 == 2);
  atom_0_r5_2 = v15;
  return NULL;
}

void *t1(void *arg){
label_2:;
  vars[1] = 2;
  return NULL;
}

void *t2(void *arg){
label_3:;
  int v6_r1 = vars[2];
  int v7_r3 = v6_r1 ^ v6_r1;
  int v8_r3 = v7_r3 + 1;
  vars[0] = v8_r3;
  int v16 = (v6_r1 == 1);
  atom_2_r1_1 = v16;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 

  vars[0] = 0;
  vars[2] = 0;
  vars[1] = 0;
  atom_0_r5_2 = 0;
  atom_2_r1_1 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  int v9 = atom_0_r5_2;
  int v10 = vars[0];
  int v11 = (v10 == 2);
  int v12 = atom_2_r1_1;
  int v13_conj = v11 & v12;
  int v14_conj = v9 & v13_conj;
  if (v14_conj == 1) assert(0);
  return 0;
}
