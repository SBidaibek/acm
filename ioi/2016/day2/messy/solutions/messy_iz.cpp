// BEGIN CUT

#include <vector>
#include <cstdio>
#include <string>
#include <set>
#include <cstdlib>
#include <iostream>
//#include "messy.h"

using namespace std;

namespace helper {

	set<string> set_;
	bool compiled = false;
	int n;
	vector<int> p;
	int w;
	int r;

	int readInt() {
		int x;
		cin >> x;
		return x;
	}

}

using namespace helper;

vector<int> restore_permutation(int, int, int);

int main() {
	n = readInt();
	w = readInt();
	r = readInt();
	p = vector<int>(n);
	for (int i = 0; i < n; i++) {
		p[i] = readInt();
	}
	vector<int> answer = restore_permutation(n, w, r);
	puts("098d134608c94f7413faac591054ee35");
	if (p == answer) {
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

bool check(const string& x) {
	if (x.length() != n) {
		return false;
	}
	for (int i = 0; i < n; i++) {
		if (x[i] != '0' && x[i] != '1') {
			return false;
		}
	}
	return true;
}

void add_element(string x) {
	if (--w < 0 || compiled || !check(x)) {
		printf("WA\n");
		exit(0);
	}
	set_.insert(x);
}

bool check_element(string x) {
	if (--r < 0 || !compiled || !check(x)) {
		printf("WA\n");
		exit(0);
	}
	return set_.count(x);
}

void compile_set() {
	if (compiled) {
		printf("WA\n");
		exit(0);
	}
	compiled = true;
	set<string> compiledSet;
	string compiledElement = string(n, ' ');
	for (const string& s : set_) {
		for (int i = 0; i < n; i++) {
			compiledElement[i] = s[p[i]];
		}
		compiledSet.insert(compiledElement);
	}
	set_ = compiledSet;
}

// END CUT

#include <vector>
#include <string>

//#include "messy.h"

using namespace std;

std::vector<int> restore_permutation(int n, int w, int r) {
    for (int len = n / 2; len >= 1; len >>= 1) {
        for (int s = 0; s < n; s += 2 * len) {
            string a = "";
            for (int i = 0; i < n; i++) a += '1';
            for (int i = 0; i < len * 2; i++) a[s + i] = '0';
            for (int i = 0; i < len; i++) {
                string ss = a;
                ss[s + i] = '1';
                add_element(ss);
            }
        }
    }
    compile_set();
    vector<vector<int> > can(n);
    for (int i = 0; i < n; i++) can[0].push_back(i);
    for (int len = n / 2; len >= 1; len >>= 1) {
        for (int s = 0; s < n; s += 2 * len) {
            string a = "";
            for (int i = 0; i < n; i++) a += '1';
            for (int i = 0; i < (int)can[s].size(); i++) a[can[s][i]] = '0';
            vector<int> c1, c2;
            for (int i = 0; i < (int)can[s].size(); i++) {
                string ss = a;
                ss[can[s][i]] = '1';
                if (check_element(ss)) {
                    c1.push_back(can[s][i]);
                } else {
                    c2.push_back(can[s][i]);
                }
            }
            can[s] = c1;
            can[s + len] = c2;
        }
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) ans[can[i][0]] = i;
    return ans;
}
