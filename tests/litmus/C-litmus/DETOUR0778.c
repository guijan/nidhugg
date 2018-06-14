// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/DETOUR0778.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[2]; 
volatile int atom_1_r1_1; 
volatile int atom_1_r3_2; 
volatile int atom_1_r6_2; 

void *t0(void *arg){
label_1:;
  vars[0] = 3;

  vars[1] = 1;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v2_r1 = vars[1];
  int v4_r3 = vars[1];
  int v5_cmpeq = (v4_r3 == v4_r3);
  if (v5_cmpeq)  goto lbl_LC00; else goto lbl_LC00;
lbl_LC00:;
  vars[0] = 1;
  int v7_r6 = vars[0];
  int v16 = (v2_r1 == 1);
  atom_1_r1_1 = v16;
  int v17 = (v4_r3 == 2);
  atom_1_r3_2 = v17;
  int v18 = (v7_r6 == 2);
  atom_1_r6_2 = v18;
  return NULL;
}

void *t2(void *arg){
label_3:;
  vars[1] = 2;
  return NULL;
}

void *t3(void *arg){
label_4:;
  vars[0] = 2;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 
  pthread_t thr3; 

  vars[0] = 0;
  vars[1] = 0;
  atom_1_r1_1 = 0;
  atom_1_r3_2 = 0;
  atom_1_r6_2 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);
  pthread_create(&thr3, NULL, t3, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);
  pthread_join(thr3, NULL);

  int v8 = vars[0];
  int v9 = (v8 == 3);
  int v10 = atom_1_r1_1;
  int v11 = atom_1_r3_2;
  int v12 = atom_1_r6_2;
  int v13_conj = v11 & v12;
  int v14_conj = v10 & v13_conj;
  int v15_conj = v9 & v14_conj;
  if (v15_conj == 1) assert(0);
  return 0;
}
