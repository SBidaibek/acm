#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// BEGIN CUT
void add_element(char* x);
int check_element(char* x);
void compile_set();

void restore_permutation(int n, int w, int r, int* answer);
// END CUT

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

// BEGIN CUT

typedef struct {
	void* zero;
	void* one;
} node;

node* set;
int compiled = 0;
int n;
int* p;
int w;
int r;

int readInt() {
	int x;
	scanf("%d", &x);
	return x;
}

node* create() {
	node* result = malloc(sizeof(node));
	result->zero = 0;
	result->one = 0;
	return result;
}

int main() {
	set = create();
	n = readInt();
	w = readInt();
	r = readInt();
	p = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		p[i] = readInt();
	}
	int* answer = malloc(n * sizeof(int));
	restore_permutation(n, w, r, answer);
	int ok = 1;
	for (int i = 0; i < n; i++) {
		if (p[i] != answer[i]) {
			ok = 0;
		}
	}
	printf("098d134608c94f7413faac591054ee35\n");
	if (ok) {
		printf("OK\n");
	}
	else {
		printf("WA\n");
	}
	printf("%d", answer[0]);
	for (int i = 1; i < n; i++) {
		printf(" %d", answer[i]);
	}
	printf("\n");
	return 0;
}

int check(char* x) {
	if (strlen(x) != n) {
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (x[i] != '0' && x[i] != '1') {
			return 0;
		}
	}
	return 1;
}

void addImpl(node* set, char* x, int at) {
	if (at == n) {
		return;
	}
	if (x[at] == '0') {
		if (set->zero == 0) {
			set->zero = create();
		}
		addImpl(set->zero, x, at + 1);
	}
	else {
		if (set->one == 0) {
			set->one = create();
		}
		addImpl(set->one, x, at + 1);
	}
}

void add_element(char* x) {
	if (--w < 0 || compiled || !check(x)) {
		printf("WA\n");
		exit(0);
	}
	addImpl(set, x, 0);
}

int check_element(char* x) {
	if (--r < 0 || !compiled || !check(x)) {
		printf("WA\n");
		exit(0);
	}
	node* current = set;
	for (int i = 0; i < n; i++) {
		if (x[i] == '0') {
			if (current->zero == 0) {
				return 0;
			}
			current = current->zero;
		}
		else {
			if (current->one == 0) {
				return 0;
			}
			current = current->one;
		}
	}
	return 1;
}

void compile(node* set, int at, node* compiledSet, char* element, char* compiled) {
	if (at == n) {
		for (int i = 0; i < n; i++) {
			compiled[i] = element[p[i]];
		}
		addImpl(compiledSet, compiled, 0);
		return;
	}
	if (set->zero != 0) {
		element[at] = '0';
		compile(set->zero, at + 1, compiledSet, element, compiled);
	}
	if (set->one != 0) {
		element[at] = '1';
		compile(set->one, at + 1, compiledSet, element, compiled);
	}
}

void compile_set() {
	if (compiled) {
		printf("WA\n");
		exit(0);
	}
	compiled = 1;
	node* compiledSet = create();
	char* element = malloc(n + 1);
	element[n] = 0;
	char* compiled = malloc(n + 1);
	compiled[n] = 0;
	compile(set, 0, compiledSet, element, compiled);
	set = compiledSet;
}

// END CUT
