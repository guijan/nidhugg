// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/MOREDETOUR0672.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[3]; 
volatile int atom_0_r6_0; 
volatile int atom_1_r3_2; 
volatile int atom_2_r3_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;
  int v2_r3 = vars[1];
  int v3_r5 = v2_r3 ^ v2_r3;
  int v6_r6 = vars[2+v3_r5];
  vars[2] = 2;
  int v19 = (v6_r6 == 0);
  atom_0_r6_0 = v19;
  return NULL;
}

void *t1(void *arg){
label_2:;
  vars[2] = 1;

  int v8_r3 = vars[2];
  int v20 = (v8_r3 == 2);
  atom_1_r3_2 = v20;
  return NULL;
}

void *t2(void *arg){
label_3:;
  vars[2] = 3;

  int v10_r3 = vars[0];
  int v21 = (v10_r3 == 0);
  atom_2_r3_0 = v21;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 

  vars[2] = 0;
  vars[0] = 0;
  vars[1] = 0;
  atom_0_r6_0 = 0;
  atom_1_r3_2 = 0;
  atom_2_r3_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  int v11 = vars[2];
  int v12 = (v11 == 3);
  int v13 = atom_0_r6_0;
  int v14 = atom_1_r3_2;
  int v15 = atom_2_r3_0;
  int v16_conj = v14 & v15;
  int v17_conj = v13 & v16_conj;
  int v18_conj = v12 & v17_conj;
  if (v18_conj == 1) assert(0);
  return 0;
}
