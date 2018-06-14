// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/ISA2+sync+addr+addr-fri-rfi-addr.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[4]; 
volatile int atom_1_r1_1; 
volatile int atom_2_r1_1; 
volatile int atom_2_r4_0; 
volatile int atom_2_r7_1; 
volatile int atom_2_r9_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;

  vars[1] = 1;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v2_r1 = vars[1];
  int v3_r3 = v2_r1 ^ v2_r1;
  vars[2+v3_r3] = 1;
  int v25 = (v2_r1 == 1);
  atom_1_r1_1 = v25;
  return NULL;
}

void *t2(void *arg){
label_3:;
  int v5_r1 = vars[2];
  int v6_r3 = v5_r1 ^ v5_r1;
  int v9_r4 = vars[3+v6_r3];
  vars[3] = 1;
  int v11_r7 = vars[3];
  int v12_r8 = v11_r7 ^ v11_r7;
  int v15_r9 = vars[0+v12_r8];
  int v26 = (v5_r1 == 1);
  atom_2_r1_1 = v26;
  int v27 = (v9_r4 == 0);
  atom_2_r4_0 = v27;
  int v28 = (v11_r7 == 1);
  atom_2_r7_1 = v28;
  int v29 = (v15_r9 == 0);
  atom_2_r9_0 = v29;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 

  vars[0] = 0;
  vars[1] = 0;
  vars[3] = 0;
  vars[2] = 0;
  atom_1_r1_1 = 0;
  atom_2_r1_1 = 0;
  atom_2_r4_0 = 0;
  atom_2_r7_1 = 0;
  atom_2_r9_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  int v16 = atom_1_r1_1;
  int v17 = atom_2_r1_1;
  int v18 = atom_2_r4_0;
  int v19 = atom_2_r7_1;
  int v20 = atom_2_r9_0;
  int v21_conj = v19 & v20;
  int v22_conj = v18 & v21_conj;
  int v23_conj = v17 & v22_conj;
  int v24_conj = v16 & v23_conj;
  if (v24_conj == 1) assert(0);
  return 0;
}
