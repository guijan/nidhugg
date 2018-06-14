// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/co2.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[1]; 
volatile int atom_2_r1_1; 
volatile int atom_2_r2_2; 
volatile int atom_3_r1_2; 
volatile int atom_3_r2_1; 
volatile int atom_2_r1_2; 
volatile int atom_2_r2_1; 
volatile int atom_3_r1_1; 
volatile int atom_3_r2_2; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;
  return NULL;
}

void *t1(void *arg){
label_2:;
  vars[0] = 2;
  return NULL;
}

void *t2(void *arg){
label_3:;
  int v2_r1 = vars[0];
  int v4_r2 = vars[0];
  int v24 = (v2_r1 == 1);
  atom_2_r1_1 = v24;
  int v25 = (v4_r2 == 2);
  atom_2_r2_2 = v25;
  int v28 = (v2_r1 == 2);
  atom_2_r1_2 = v28;
  int v29 = (v4_r2 == 1);
  atom_2_r2_1 = v29;
  return NULL;
}

void *t3(void *arg){
label_4:;
  int v6_r1 = vars[0];
  int v8_r2 = vars[0];
  int v26 = (v6_r1 == 2);
  atom_3_r1_2 = v26;
  int v27 = (v8_r2 == 1);
  atom_3_r2_1 = v27;
  int v30 = (v6_r1 == 1);
  atom_3_r1_1 = v30;
  int v31 = (v8_r2 == 2);
  atom_3_r2_2 = v31;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 
  pthread_t thr3; 

  vars[0] = 0;
  atom_2_r1_1 = 0;
  atom_2_r2_2 = 0;
  atom_3_r1_2 = 0;
  atom_3_r2_1 = 0;
  atom_2_r1_2 = 0;
  atom_2_r2_1 = 0;
  atom_3_r1_1 = 0;
  atom_3_r2_2 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);
  pthread_create(&thr3, NULL, t3, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);
  pthread_join(thr3, NULL);

  int v9 = atom_2_r1_1;
  int v10 = atom_2_r2_2;
  int v11 = atom_3_r1_2;
  int v12 = atom_3_r2_1;
  int v13_conj = v11 & v12;
  int v14_conj = v10 & v13_conj;
  int v15_conj = v9 & v14_conj;
  int v16 = atom_2_r1_2;
  int v17 = atom_2_r2_1;
  int v18 = atom_3_r1_1;
  int v19 = atom_3_r2_2;
  int v20_conj = v18 & v19;
  int v21_conj = v17 & v20_conj;
  int v22_conj = v16 & v21_conj;
  int v23_disj = v15_conj | v22_conj;
  if (v23_disj == 1) assert(0);
  return 0;
}
