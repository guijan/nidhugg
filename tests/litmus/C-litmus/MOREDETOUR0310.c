// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/MOREDETOUR0310.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[2]; 
volatile int atom_1_r4_4; 
volatile int atom_1_r1_2; 
volatile int atom_2_r5_2; 
volatile int atom_2_r1_1; 

void *t0(void *arg){
label_1:;
  vars[0] = 2;
  vars[0] = 4;
  vars[0] = 5;
  vars[1] = 1;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v2_r1 = vars[0];
  vars[0] = 3;

  int v4_r4 = vars[0];
  int v18 = (v4_r4 == 4);
  atom_1_r4_4 = v18;
  int v19 = (v2_r1 == 2);
  atom_1_r1_2 = v19;
  return NULL;
}

void *t2(void *arg){
label_3:;
  int v6_r1 = vars[1];
  int v7_r3 = v6_r1 ^ v6_r1;
  int v8_r3 = v7_r3 + 1;
  vars[0] = v8_r3;

  int v10_r5 = vars[0];
  int v20 = (v10_r5 == 2);
  atom_2_r5_2 = v20;
  int v21 = (v6_r1 == 1);
  atom_2_r1_1 = v21;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 

  vars[0] = 0;
  vars[1] = 0;
  atom_1_r4_4 = 0;
  atom_1_r1_2 = 0;
  atom_2_r5_2 = 0;
  atom_2_r1_1 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  int v11 = atom_1_r4_4;
  int v12 = atom_1_r1_2;
  int v13 = atom_2_r5_2;
  int v14 = atom_2_r1_1;
  int v15_conj = v13 & v14;
  int v16_conj = v12 & v15_conj;
  int v17_conj = v11 & v16_conj;
  if (v17_conj == 1) assert(0);
  return 0;
}
