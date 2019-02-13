#include "bubblesort2.h"
#include "c.cpp"

#include <cstdio>
#include <cstdlib>
#include <vector>

int readInt(){
	int i;
	if(scanf("%d",&i)!=1){
		fprintf(stderr,"Error while reading input\n");
		exit(1);
	}
	return i;
}

int main(){
    freopen("in", "r", stdin);
	int N,Q;
	N=readInt();
	Q=readInt();

	std::vector<int> A(N);
	for(int i=0;i<N;i++)
		A[i]=readInt();

	std::vector<int> X(Q),V(Q);
	for(int j=0;j<Q;j++){
		X[j]=readInt();
		V[j]=readInt();
	}

	std::vector<int> res=count_scans(A,X,V);

	for(int j=0;j<int(res.size());j++)
		printf("%d\n",res[j]);
}
