#include "traffic.h"
#include <stdio.h>
#include "a.cpp"

static int N,P[1000000],S[1000000],D[1000000];

int main(){
   freopen("grader.in.4", "r", stdin);
   int i;
   scanf("%d",&N);
   for (i=0;i<N;i++) scanf("%d",&P[i]);
   for (i=0;i<N-1;i++) scanf("%d%d",&S[i],&D[i]);
   int r = LocateCentre(N,P,S,D);
   printf("%d\n",r);
   return 0;
}
