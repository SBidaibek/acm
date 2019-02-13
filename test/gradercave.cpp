#include "graderlib.c"
#include "ioi2013Dcave.cpp"

int main() {
    int N;
	N = init();
	exploreCave(N);
    printf("INCORRECT\nYour solution did not call answer().\n");
	return 0;
}
