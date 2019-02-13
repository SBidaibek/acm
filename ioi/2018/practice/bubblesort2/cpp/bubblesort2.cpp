#include "bubblesort2.h"

std::vector<int> count_scans(std::vector<int> A,std::vector<int> X,std::vector<int> V){
	int Q=X.size();
	std::vector<int> answer(Q);
	for (int j=0;j<Q;j++) {
		answer[j]=X[j];
	}
	return answer;
}
