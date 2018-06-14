// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/WW+WW+WR+WW+RW+RR+sync+sync+sync+lwsync+sync+lwsync.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[6]; 
volatile int atom_2_r3_0; 
volatile int atom_4_r1_1; 
volatile int atom_5_r1_1; 
volatile int atom_5_r3_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;

  vars[1] = 1;
  return NULL;
}

void *t1(void *arg){
label_2:;
  vars[1] = 2;

  vars[2] = 1;
  return NULL;
}

void *t2(void *arg){
label_3:;
  vars[2] = 2;

  int v2_r3 = vars[3];
  int v22 = (v2_r3 == 0);
  atom_2_r3_0 = v22;
  return NULL;
}

void *t3(void *arg){
label_4:;
  vars[3] = 1;

  vars[4] = 1;
  return NULL;
}

void *t4(void *arg){
label_5:;
  int v4_r1 = vars[4];

  vars[5] = 1;
  int v23 = (v4_r1 == 1);
  atom_4_r1_1 = v23;
  return NULL;
}

void *t5(void *arg){
label_6:;
  int v6_r1 = vars[5];

  int v8_r3 = vars[0];
  int v24 = (v6_r1 == 1);
  atom_5_r1_1 = v24;
  int v25 = (v8_r3 == 0);
  atom_5_r3_0 = v25;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 
  pthread_t thr3; 
  pthread_t thr4; 
  pthread_t thr5; 

  vars[0] = 0;
  vars[3] = 0;
  vars[1] = 0;
  vars[5] = 0;
  vars[4] = 0;
  vars[2] = 0;
  atom_2_r3_0 = 0;
  atom_4_r1_1 = 0;
  atom_5_r1_1 = 0;
  atom_5_r3_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);
  pthread_create(&thr3, NULL, t3, NULL);
  pthread_create(&thr4, NULL, t4, NULL);
  pthread_create(&thr5, NULL, t5, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);
  pthread_join(thr3, NULL);
  pthread_join(thr4, NULL);
  pthread_join(thr5, NULL);

  int v9 = vars[1];
  int v10 = (v9 == 2);
  int v11 = vars[2];
  int v12 = (v11 == 2);
  int v13 = atom_2_r3_0;
  int v14 = atom_4_r1_1;
  int v15 = atom_5_r1_1;
  int v16 = atom_5_r3_0;
  int v17_conj = v15 & v16;
  int v18_conj = v14 & v17_conj;
  int v19_conj = v13 & v18_conj;
  int v20_conj = v12 & v19_conj;
  int v21_conj = v10 & v20_conj;
  if (v21_conj == 1) assert(0);
  return 0;
}
