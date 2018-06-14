// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/Z6.0+sync+lwsync+rfi-addr.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[3]; 
volatile int atom_1_r1_1; 
volatile int atom_2_r3_2; 
volatile int atom_2_r5_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;

  vars[1] = 1;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v2_r1 = vars[1];

  vars[2] = 1;
  int v17 = (v2_r1 == 1);
  atom_1_r1_1 = v17;
  return NULL;
}

void *t2(void *arg){
label_3:;
  vars[2] = 2;
  int v4_r3 = vars[2];
  int v5_r4 = v4_r3 ^ v4_r3;
  int v8_r5 = vars[0+v5_r4];
  int v18 = (v4_r3 == 2);
  atom_2_r3_2 = v18;
  int v19 = (v8_r5 == 0);
  atom_2_r5_0 = v19;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 

  vars[0] = 0;
  vars[2] = 0;
  vars[1] = 0;
  atom_1_r1_1 = 0;
  atom_2_r3_2 = 0;
  atom_2_r5_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  int v9 = vars[2];
  int v10 = (v9 == 2);
  int v11 = atom_1_r1_1;
  int v12 = atom_2_r3_2;
  int v13 = atom_2_r5_0;
  int v14_conj = v12 & v13;
  int v15_conj = v11 & v14_conj;
  int v16_conj = v10 & v15_conj;
  if (v16_conj == 1) assert(0);
  return 0;
}
