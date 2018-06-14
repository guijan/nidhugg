// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/ppc-iwp2.4-amd9.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[2]; 
volatile int atom_0_r7_0; 
volatile int atom_1_r7_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 55;
  int v2_r6 = vars[0];
  int v4_r7 = vars[1];
  int v12 = (v4_r7 == 0);
  atom_0_r7_0 = v12;
  return NULL;
}

void *t1(void *arg){
label_2:;
  vars[1] = 55;
  int v6_r6 = vars[1];
  int v8_r7 = vars[0];
  int v13 = (v8_r7 == 0);
  atom_1_r7_0 = v13;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[0] = 0;
  vars[1] = 0;
  atom_0_r7_0 = 0;
  atom_1_r7_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v9 = atom_0_r7_0;
  int v10 = atom_1_r7_0;
  int v11_conj = v9 & v10;
  if (v11_conj == 1) assert(0);
  return 0;
}
