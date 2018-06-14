// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/2+2W0027.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[4]; 

void *t0(void *arg){
label_1:;
  vars[0] = 2;

  vars[1] = 1;
  return NULL;
}

void *t1(void *arg){
label_2:;
  vars[1] = 2;
  vars[2] = 1;
  int v2_r5 = vars[3];
  int v3_cmpeq = (v2_r5 == v2_r5);
  if (v3_cmpeq)  goto lbl_LC00; else goto lbl_LC00;
lbl_LC00:;
  vars[0] = 1;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[1] = 0;
  vars[0] = 0;
  vars[3] = 0;
  vars[2] = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v4 = vars[0];
  int v5 = (v4 == 2);
  int v6 = vars[1];
  int v7 = (v6 == 2);
  int v8_conj = v5 & v7;
  if (v8_conj == 1) assert(0);
  return 0;
}
