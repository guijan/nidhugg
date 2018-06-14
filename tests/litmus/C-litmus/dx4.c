// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/dx4.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[2]; 
volatile int atom_0_r2_2; 
volatile int atom_1_r2_1; 

void *t0(void *arg){
label_1:;
  int v2_r2 = vars[1];
  int v3_r9 = v2_r2 ^ v2_r2;
  vars[0+v3_r9] = 1;
  int v13 = (v2_r2 == 2);
  atom_0_r2_2 = v13;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v5_r2 = vars[0];
  int v6_r9 = v5_r2 ^ v5_r2;
  vars[1+v6_r9] = 1;
  int v14 = (v5_r2 == 1);
  atom_1_r2_1 = v14;
  return NULL;
}

void *t2(void *arg){
label_3:;
  vars[1] = 2;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 

  vars[1] = 0;
  vars[0] = 0;
  atom_0_r2_2 = 0;
  atom_1_r2_1 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  int v7 = atom_0_r2_2;
  int v8 = atom_1_r2_1;
  int v9 = vars[1];
  int v10 = (v9 == 2);
  int v11_conj = v8 & v10;
  int v12_conj = v7 & v11_conj;
  if (v12_conj == 1) assert(0);
  return 0;
}
