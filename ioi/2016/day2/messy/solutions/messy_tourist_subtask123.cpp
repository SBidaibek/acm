// n writes, n^2/2 reads worst case, n^2/4 reads average case
// (ok for "n = 32, r = 320" subtask)

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

#include <bits/stdc++.h>

//#include "messy.h"

using namespace std;

vector<int> restore_permutation(int n, int w, int r) {
  string s(n, '0');
  for (int i = 0; i < n; i++) {
    s[i] = '1';
    add_element(s);
  }
  compile_set();
  string t(n, '0');
  vector <int> ans(n);
  for (int i = 0; i < n; i++) {
    vector <int> all;
    for (int j = 0; j < n; j++) {
      if (t[j] != '0') {
        continue;
      }
      all.push_back(j);
    }
    random_shuffle(all.begin(), all.end());
    for (int id = 0; id < (int) all.size(); id++) {
      int j = all[id];
      t[j] = '1';
      if (check_element(t)) {
        ans[j] = i;
        break;
      }
      t[j] = '0';
    }
  }
  return ans;
}
