// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/MOREDETOUR0557.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[2]; 
volatile int atom_0_r5_2; 
volatile int atom_1_r4_5; 
volatile int atom_1_r6_0; 
volatile int atom_2_r4_4; 
volatile int atom_2_r1_2; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;

  vars[1] = 1;

  int v2_r5 = vars[1];
  int v22 = (v2_r5 == 2);
  atom_0_r5_2 = v22;
  return NULL;
}

void *t1(void *arg){
label_2:;
  vars[1] = 2;
  vars[1] = 4;
  int v4_r4 = vars[1];
  int v5_r5 = v4_r4 ^ v4_r4;
  int v8_r6 = vars[0+v5_r5];
  int v23 = (v4_r4 == 5);
  atom_1_r4_5 = v23;
  int v24 = (v8_r6 == 0);
  atom_1_r6_0 = v24;
  return NULL;
}

void *t2(void *arg){
label_3:;
  int v10_r1 = vars[1];
  vars[1] = 3;

  int v12_r4 = vars[1];
  int v25 = (v12_r4 == 4);
  atom_2_r4_4 = v25;
  int v26 = (v10_r1 == 2);
  atom_2_r1_2 = v26;
  return NULL;
}

void *t3(void *arg){
label_4:;
  vars[1] = 5;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 
  pthread_t thr3; 

  vars[1] = 0;
  vars[0] = 0;
  atom_0_r5_2 = 0;
  atom_1_r4_5 = 0;
  atom_1_r6_0 = 0;
  atom_2_r4_4 = 0;
  atom_2_r1_2 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);
  pthread_create(&thr3, NULL, t3, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);
  pthread_join(thr3, NULL);

  int v13 = atom_0_r5_2;
  int v14 = atom_1_r4_5;
  int v15 = atom_1_r6_0;
  int v16 = atom_2_r4_4;
  int v17 = atom_2_r1_2;
  int v18_conj = v16 & v17;
  int v19_conj = v15 & v18_conj;
  int v20_conj = v14 & v19_conj;
  int v21_conj = v13 & v20_conj;
  if (v21_conj == 1) assert(0);
  return 0;
}
