// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/WRR+2W+addr+po.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[2]; 
volatile int atom_1_r1_2; 
volatile int atom_1_r4_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 2;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v2_r1 = vars[0];
  int v3_r3 = v2_r1 ^ v2_r1;
  int v6_r4 = vars[1+v3_r3];
  int v13 = (v2_r1 == 2);
  atom_1_r1_2 = v13;
  int v14 = (v6_r4 == 0);
  atom_1_r4_0 = v14;
  return NULL;
}

void *t2(void *arg){
label_3:;
  vars[1] = 1;
  vars[0] = 1;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 

  vars[0] = 0;
  vars[1] = 0;
  atom_1_r1_2 = 0;
  atom_1_r4_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  int v7 = vars[0];
  int v8 = (v7 == 2);
  int v9 = atom_1_r1_2;
  int v10 = atom_1_r4_0;
  int v11_conj = v9 & v10;
  int v12_conj = v8 & v11_conj;
  if (v12_conj == 1) assert(0);
  return 0;
}
