#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include <mpi.h>

#define beta 0.3
#define N 1024
#define delt 0.01
#define pi 3.1415

void init(double *masas);
double * Newton(double * masas);

int main(){

  int i, j;
  int iter=1000*N;
  double *osc;
  osc=malloc(N*sizeof(double));
  double *osc_p;
  osc_p=malloc(N*sizeof(double));
  double *vels;
  vels=malloc(N*sizeof(double));
  double *vels_p;
  vels_p=malloc(N*sizeof(double));
  double *acc;
  acc=malloc(N*sizeof(double));
  init(osc_p);
  acc=Newton(osc_p);
  for(j=0;j<N;j++){
    vels[j]=0.0;
    vels_p[j]=0.0;
  }
  for(j=1;j<N-1;j++){
    vels[j]=acc[j]*delt/2.0;
  }

  for (i=0;i<iter;i++){
    for(j=1;j<N-1;j++){
      osc[j]=osc_p[j]+vels[j]*delt;
    }
    acc=Newton(osc);
    for(j=1;j<N-1;j++){
      vels_p[j]=vels[j];
    }
    for(j=1;j<N-1;j++){
      vels[j]=vels_p[j]+acc[j]*delt;
    }
    for(j=1;j<N-1;j++){
      osc_p[j]=osc[j];
    }
    if(i%1000==0){
      for(j=0;j<N;j++){
        printf("%lf ", osc[j]);
      }
      printf("\n");
    }
  }
}

void init(double *masas){
  int i;
  for (i=0;i<N;i++){
    masas[i]=sin(2*pi*i/(N-1));
  }
}
double * Newton(double * masas){
  int i;
  double *temp;
  temp=malloc(N*sizeof(double));
  temp[0]=0.0; temp[N-1]=0.0;
  for(i=1;i<N-1;i++){
    temp[i]=masas[i+1]-2*masas[i]+masas[i-1]+beta*(pow(masas[i+1]-masas[i],3)-pow(masas[i]-masas[i-1],3));
  }
  return temp;
}
