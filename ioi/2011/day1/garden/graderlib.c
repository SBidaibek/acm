#include "grader.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_M  1000000
#define MAX_Q  2000

static int N, M, P, Q;
static int R[MAX_M][2];
static int G[MAX_Q];

void read_input()
{
  int i;
  scanf("%d %d %d",&N,&M,&P);
  for(i=0; i<M; i++)
    scanf("%d %d",&R[i][0],&R[i][1]);
  scanf("%d",&Q);
  for(i=0; i<Q; i++)
    scanf("%d",&G[i]);
}

void answer(int x)
{
  printf("%d ", x);
}

int _main(count_routesFunction count_routes)
{
  freopen("01", "r", stdin);
  read_input();
  count_routes(N,M,P,R,Q,G);
  return 0;
}
