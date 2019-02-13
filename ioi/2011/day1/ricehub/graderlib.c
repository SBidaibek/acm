#include "grader.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_R  1000000

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif


static int R, L;
static long long B;
static int X[MAX_R];

static void read_input()
{
  int i;
  scanf("%d %d "LLD,&R,&L,&B);
  for(i=0; i<R; i++)
    scanf("%d",&X[i]);
}

int _main(besthubFunction besthub)
{
  int ans;
  read_input();
  ans = besthub(R,L,X,B);
  printf("%d\n", ans);
  return 0;
}
