// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/MOREDETOUR0800.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[2]; 
volatile int atom_1_r1_1; 
volatile int atom_1_r4_0; 
volatile int atom_2_r3_2; 

void *t0(void *arg){
label_1:;
  vars[0] = 3;

  vars[1] = 1;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v2_r1 = vars[1];
  vars[1] = 2;
  int v4_r4 = vars[0];
  vars[0] = 2;
  int v15 = (v2_r1 == 1);
  atom_1_r1_1 = v15;
  int v16 = (v4_r4 == 0);
  atom_1_r4_0 = v16;
  return NULL;
}

void *t2(void *arg){
label_3:;
  vars[0] = 1;

  int v6_r3 = vars[0];
  int v17 = (v6_r3 == 2);
  atom_2_r3_2 = v17;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 

  vars[0] = 0;
  vars[1] = 0;
  atom_1_r1_1 = 0;
  atom_1_r4_0 = 0;
  atom_2_r3_2 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  int v7 = vars[0];
  int v8 = (v7 == 3);
  int v9 = atom_1_r1_1;
  int v10 = atom_1_r4_0;
  int v11 = atom_2_r3_2;
  int v12_conj = v10 & v11;
  int v13_conj = v9 & v12_conj;
  int v14_conj = v8 & v13_conj;
  if (v14_conj == 1) assert(0);
  return 0;
}
