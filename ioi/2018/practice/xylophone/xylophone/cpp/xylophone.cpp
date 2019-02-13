#include "xylophone.h"

static int A[5000];

void detect_pitch(int N) {

	int value = ask(0, N - 1);

	for(int i = 0; i < N; i++) {
		answer(i, i);
	}

}
