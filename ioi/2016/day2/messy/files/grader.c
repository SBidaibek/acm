#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "messy_c.h"

typedef struct node {
    struct node* zero;
    struct node* one;
} node ; 

struct node* set;
int compiled = 0;
int n;
int* p;
int w;
int r;

// BEGIN SECRET
static const int CIPHER_KEY_LENGTH = 16;
static const char* const xor_cipher = "\x0d\x08\x08\x1a\x79\x74\x23\x36\x45\x5a\x63\x3d\x23\x39\x7d\x10";
// END SECRET

int read_int() {
    int x;
    assert(1 == scanf("%d", &x));
    return x;
}

// A convenience function.
int get_p(int i) {
    int ret = p[i];
    // BEGIN SECRET
    ret ^= xor_cipher[i & 15];
    // END SECRET
    return ret;
}

struct node* create() {
    struct node* result = (struct node*)malloc(sizeof(node));
    result->zero = 0;
    result->one = 0;
    return result;
}

int main() {
    set = create();
    n = read_int();
    w = read_int();
    r = read_int();
    p = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        p[i] = read_int();
        // BEGIN SECRET
        p[i] ^= xor_cipher[i & 15];
        // END SECRET
    }
    int* answer = (int*)malloc(n * sizeof(int));
    restore_permutation(n, w, r, answer);
    
    // BEGIN SECRET
    int ok = compiled;
    for (int i = 0; i < n; i++) {
        if (get_p(i) != answer[i]) {
            ok = 0;
        }
    }

    puts("098d134608c94f7413faac591054ee35");
    if (ok) {
        printf("OK\n");
    }
    else {
        printf("WA\n");
    }
    // END SECRET
    
    printf("%d", answer[0]);
    for (int i = 1; i < n; i++) {
        printf(" %d", answer[i]);
    }
    printf("\n");
    return 0;
}

int check(const char* x) {
    if ((int)strlen(x) != n) {
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (x[i] != '0' && x[i] != '1') {
            return 0;
        }
    }
    return 1;
}

void add_impl(struct node* set, const char* x, int at) {
    if (at == n) {
        return;
    }
    if (x[at] == '0') {
        if (set->zero == 0) {
            set->zero = create();
        }
        add_impl(set->zero, x, at + 1);
    } else {
        if (set->one == 0) {
            set->one = create();
        }
        add_impl(set->one, x, at + 1);
    }
}

void wa() {
    // BEGIN SECRET
    puts("098d134608c94f7413faac591054ee35");
    // END SECRET
    printf("WA\n");
    exit(0);
}

void add_element(char* x) {
    if (--w < 0 || compiled || !check(x)) {
        wa();
    }
    add_impl(set, x, 0);
}

int check_element(char* x) {
    if (--r < 0 || !compiled || !check(x)) {
        wa();
    }
    struct node* current = set;
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

void compile(struct node* set, int at, struct node* compiledSet, char* element, char* compiled) {
    if (at == n) {
        for (int i = 0; i < n; i++) {
            compiled[i] = element[get_p(i)];
        }
        add_impl(compiledSet, compiled, 0);
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
        wa();
    }
    compiled = 1;
    struct node* compiledSet = create();
    char* element = (char*)malloc(n + 1);
    element[n] = 0;
    char* compiled = (char*)malloc(n + 1);
    compiled[n] = 0;
    compile(set, 0, compiledSet, element, compiled);
    set = compiledSet;
}
