// name = messy_c_ok.c, type = c.gcc

#include "messy_c.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int nn;
char* address;

void helper(int length, int w) {
	memset(address, '1', nn);
	for (int i = w; i < nn; i += (1 << length)) {
		address[i] = '0';
	}
	int j = w;
	for (int i = 0; i < (nn / (1 << length)); i++) {
		address[j] = '1';
		if (i % 2 == 1) {
			add_element(address);
		}
		address[j] = '0';
		j += 1 << length;
	}
}

void doWrites(int n_) {
	nn = n_;
	address = malloc(nn + 1);
	address[nn] = 0;
	for (int i = 0; i < nn; i++) {
		memset(address, '0', nn);
		address[i] = '1';
		if (i % 2 == 1) {
			add_element(address);
		}
	}
	int x = 1;
	int log = 0;
	while (x < nn) {
		x *= 2;
		log++;
	}
	for (int length = 1; length < log; length++) {
		for (int i = 0; i < (1 << length); i++) {
			helper(length, i);
		}
	}
}

void read(int* t, int tSize, int* answer, int step, int w) {
	if (tSize == 1) {
		answer[t[0]] = w;
		return;
	}
	int* t0 = malloc(tSize / 2 * sizeof(int));
	int* t1 = malloc(tSize / 2 * sizeof(int));
	int at0 = 0;
	int at1 = 0;
	memset(address, '1', nn);
	for (int j = 0; j < tSize; j++) {
		address[t[j]] = '0';
	}
	for (int i = 0; i < tSize; i++) {
		int j = t[i];
		address[j] = '1';
		if (!check_element(address)) {
			t0[at0++] = j;
		}
		else {
			t1[at1++] = j;
		}
		address[j] = '0';
	}
	read(t0, tSize / 2, answer, step + 1, w);
	read(t1, tSize / 2, answer, step + 1, w + (1 << step));
}

void doReads(int n, int* answer) {
	int* order = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		order[i] = i;
	}
	read(order, n, answer, 0, 0);
}

void restore_permutation(int n, int w, int r, int* answer) {
	doWrites(n);
	compile_set();
	doReads(n, answer);
}


