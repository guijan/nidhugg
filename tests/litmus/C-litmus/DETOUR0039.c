// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/DETOUR0039.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[3]; 
volatile int atom_0_r6_2; 
volatile int atom_1_r1_1; 
volatile int atom_1_r4_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;
  vars[1] = 1;
  vars[1] = 2;
  int v2_r6 = vars[1];
  int v3_r7 = v2_r6 ^ v2_r6;
  vars[2+v3_r7] = 1;
  int v15 = (v2_r6 == 2);
  atom_0_r6_2 = v15;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v5_r1 = vars[2];
  int v6_r3 = v5_r1 ^ v5_r1;
  int v9_r4 = vars[0+v6_r3];
  int v16 = (v5_r1 == 1);
  atom_1_r1_1 = v16;
  int v17 = (v9_r4 == 0);
  atom_1_r4_0 = v17;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[1] = 0;
  vars[0] = 0;
  vars[2] = 0;
  atom_0_r6_2 = 0;
  atom_1_r1_1 = 0;
  atom_1_r4_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v10 = atom_0_r6_2;
  int v11 = atom_1_r1_1;
  int v12 = atom_1_r4_0;
  int v13_conj = v11 & v12;
  int v14_conj = v10 & v13_conj;
  if (v14_conj == 1) assert(0);
  return 0;
}
