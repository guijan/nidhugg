// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/DETOUR0946.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[2]; 
volatile int atom_1_r3_2; 
volatile int atom_1_r5_0; 
volatile int atom_1_r7_1; 

void *t0(void *arg){
label_1:;
  vars[0] = 2;

  vars[1] = 1;
  return NULL;
}

void *t1(void *arg){
label_2:;
  vars[1] = 2;
  int v2_r3 = vars[1];
  int v3_r4 = v2_r3 ^ v2_r3;
  int v6_r5 = vars[0+v3_r4];
  int v8_r7 = vars[0];
  int v20 = (v2_r3 == 2);
  atom_1_r3_2 = v20;
  int v21 = (v6_r5 == 0);
  atom_1_r5_0 = v21;
  int v22 = (v8_r7 == 1);
  atom_1_r7_1 = v22;
  return NULL;
}

void *t2(void *arg){
label_3:;
  vars[0] = 1;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 

  vars[1] = 0;
  vars[0] = 0;
  atom_1_r3_2 = 0;
  atom_1_r5_0 = 0;
  atom_1_r7_1 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  int v9 = vars[1];
  int v10 = (v9 == 2);
  int v11 = vars[0];
  int v12 = (v11 == 2);
  int v13 = atom_1_r3_2;
  int v14 = atom_1_r5_0;
  int v15 = atom_1_r7_1;
  int v16_conj = v14 & v15;
  int v17_conj = v13 & v16_conj;
  int v18_conj = v12 & v17_conj;
  int v19_conj = v10 & v18_conj;
  if (v19_conj == 1) assert(0);
  return 0;
}
