// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/DETOUR0061.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[2]; 
volatile int atom_0_r3_1; 
volatile int atom_0_r5_2; 
volatile int atom_1_r1_1; 
volatile int atom_1_r4_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;
  int v2_r3 = vars[0];
  vars[0] = 2;
  int v4_r5 = vars[0];
  int v5_r6 = v4_r5 ^ v4_r5;
  int v6_r6 = v5_r6 + 1;
  vars[1] = v6_r6;
  int v20 = (v2_r3 == 1);
  atom_0_r3_1 = v20;
  int v21 = (v4_r5 == 2);
  atom_0_r5_2 = v21;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v8_r1 = vars[1];
  int v9_r3 = v8_r1 ^ v8_r1;
  int v12_r4 = vars[0+v9_r3];
  int v22 = (v8_r1 == 1);
  atom_1_r1_1 = v22;
  int v23 = (v12_r4 == 0);
  atom_1_r4_0 = v23;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[1] = 0;
  vars[0] = 0;
  atom_0_r3_1 = 0;
  atom_0_r5_2 = 0;
  atom_1_r1_1 = 0;
  atom_1_r4_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v13 = atom_0_r3_1;
  int v14 = atom_0_r5_2;
  int v15 = atom_1_r1_1;
  int v16 = atom_1_r4_0;
  int v17_conj = v15 & v16;
  int v18_conj = v14 & v17_conj;
  int v19_conj = v13 & v18_conj;
  if (v19_conj == 1) assert(0);
  return 0;
}
