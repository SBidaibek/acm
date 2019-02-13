#include "grader.h"
#include "lang.h"
#include "a.cpp"

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define N 100

static char lang[20], lan[100][20];
static int lnum, i,j,k,n,nl, uni[N], rght, tot;
int language(int L) {
   if (L < 0 || L >= 56) exit(92);
   rght += (L == lnum);
   tot++;
   return lnum;
}

int main(){
  freopen("grader.in.1", "r", stdin);
   for (n= 0; n < 500 && 1 == scanf("%s",lang); n++) {
      for (i=0;i<nl && strcmp(lang,lan[i]);i++);
      strcpy(lan[i],lang);
      if (i == nl) {
         nl++;
      }
      lnum = i;
      for (i=0;i<N;i++) scanf("%d,",&uni[i]);
      scanf("%*[^\n]");
      excerpt(uni);
   }
   printf("OK %0.2f%%\n",100.0*rght/tot);
   return 0;
}
