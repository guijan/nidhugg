// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/WRC+addr-bigdetour-addr+addr.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[4]; 
volatile int atom_2_r1_1; 
volatile int atom_2_r3_0; 
volatile int atom_2_r4_1; 
volatile int atom_3_r1_1; 
volatile int atom_3_r3_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;
  return NULL;
}

void *t1(void *arg){
label_2:;
  vars[1] = 1;

  vars[2] = 1;
  return NULL;
}

void *t2(void *arg){
label_3:;
  int v2_r1 = vars[0];
  int v3_r2 = v2_r1 ^ v2_r1;
  int v6_r3 = vars[1+v3_r2];
  int v8_r4 = vars[2];
  int v9_r5 = v8_r4 ^ v8_r4;
  int v10_r5 = v9_r5 + 1;
  vars[3] = v10_r5;
  int v26 = (v2_r1 == 1);
  atom_2_r1_1 = v26;
  int v27 = (v6_r3 == 0);
  atom_2_r3_0 = v27;
  int v28 = (v8_r4 == 1);
  atom_2_r4_1 = v28;
  return NULL;
}

void *t3(void *arg){
label_4:;
  int v12_r1 = vars[3];
  int v13_r2 = v12_r1 ^ v12_r1;
  int v16_r3 = vars[0+v13_r2];
  int v29 = (v12_r1 == 1);
  atom_3_r1_1 = v29;
  int v30 = (v16_r3 == 0);
  atom_3_r3_0 = v30;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 
  pthread_t thr3; 

  vars[3] = 0;
  vars[2] = 0;
  vars[1] = 0;
  vars[0] = 0;
  atom_2_r1_1 = 0;
  atom_2_r3_0 = 0;
  atom_2_r4_1 = 0;
  atom_3_r1_1 = 0;
  atom_3_r3_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);
  pthread_create(&thr3, NULL, t3, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);
  pthread_join(thr3, NULL);

  int v17 = atom_2_r1_1;
  int v18 = atom_2_r3_0;
  int v19 = atom_2_r4_1;
  int v20 = atom_3_r1_1;
  int v21 = atom_3_r3_0;
  int v22_conj = v20 & v21;
  int v23_conj = v19 & v22_conj;
  int v24_conj = v18 & v23_conj;
  int v25_conj = v17 & v24_conj;
  if (v25_conj == 1) assert(0);
  return 0;
}
