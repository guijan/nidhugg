// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/bb.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[2]; 
volatile int atom_1_r1_1; 
volatile int atom_1_r2_0; 
volatile int atom_2_r1_1; 
volatile int atom_2_r2_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;
  vars[1] = 1;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v2_r1 = vars[1];
  int v4_r2 = vars[0];
  int v16 = (v2_r1 == 1);
  atom_1_r1_1 = v16;
  int v17 = (v4_r2 == 0);
  atom_1_r2_0 = v17;
  return NULL;
}

void *t2(void *arg){
label_3:;
  int v6_r1 = vars[1];
  int v8_r2 = vars[0];
  int v18 = (v6_r1 == 1);
  atom_2_r1_1 = v18;
  int v19 = (v8_r2 == 0);
  atom_2_r2_0 = v19;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 

  vars[0] = 0;
  vars[1] = 0;
  atom_1_r1_1 = 0;
  atom_1_r2_0 = 0;
  atom_2_r1_1 = 0;
  atom_2_r2_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  int v9 = atom_1_r1_1;
  int v10 = atom_1_r2_0;
  int v11_conj = v9 & v10;
  int v12 = atom_2_r1_1;
  int v13 = atom_2_r2_0;
  int v14_conj = v12 & v13;
  int v15_disj = v11_conj | v14_conj;
  if (v15_disj == 1) assert(0);
  return 0;
}
