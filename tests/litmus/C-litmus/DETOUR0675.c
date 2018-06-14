// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/DETOUR0675.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[3]; 
volatile int atom_1_r1_1; 
volatile int atom_1_r4_0; 
volatile int atom_1_r7_1; 
volatile int atom_1_r8_0; 

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
  int v6_r4 = vars[2+v3_r3];
  vars[2] = 1;
  int v8_r7 = vars[2];
  int v9_cmpeq = (v8_r7 == v8_r7);
  if (v9_cmpeq)  goto lbl_LC00; else goto lbl_LC00;
lbl_LC00:;

  int v11_r8 = vars[0];
  int v19 = (v2_r1 == 1);
  atom_1_r1_1 = v19;
  int v20 = (v6_r4 == 0);
  atom_1_r4_0 = v20;
  int v21 = (v8_r7 == 1);
  atom_1_r7_1 = v21;
  int v22 = (v11_r8 == 0);
  atom_1_r8_0 = v22;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[1] = 0;
  vars[0] = 0;
  vars[2] = 0;
  atom_1_r1_1 = 0;
  atom_1_r4_0 = 0;
  atom_1_r7_1 = 0;
  atom_1_r8_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v12 = atom_1_r1_1;
  int v13 = atom_1_r4_0;
  int v14 = atom_1_r7_1;
  int v15 = atom_1_r8_0;
  int v16_conj = v14 & v15;
  int v17_conj = v13 & v16_conj;
  int v18_conj = v12 & v17_conj;
  if (v18_conj == 1) assert(0);
  return 0;
}
