// w = n log n
// r = 2 n log n

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

int nn;

void put(int a = nn, int b = nn, int c = nn) {
  string s(nn + 1, '0');
  s[a] = s[b] = s[c] = '1';
  add_element(s.substr(0, nn));
}

bool get(int a = nn, int b = nn, int c = nn) {
  string s(nn + 1, '0');
  s[a] = s[b] = s[c] = '1';
  return check_element(s.substr(0, nn));
}

vector<int> restore_permutation(int n, int w, int r) {
  nn = n;
  int k = 0;
  while ((1 << k) != n) {
    k++;
  }
  put(0, 0);
  for (int i = 0; i < k - 1; i++) {
    put(i, i + 1);
  }
  for (int i = k; i < n; i++) {
    for (int j = 0; j < k; j++) {
      if (i & (1 << j)) {
        put(i, j, (j + 1) % k);
      }
    }
  }
  compile_set();
  vector <int> ans(n, -1);
  vector <int> imp(k);
  for (int i = 0; i < n; i++) {
    if (get(i)) {
      ans[i] = 0;
      imp[0] = i;
    }
  }
  for (int j = 1; j < k; j++) {
    int new_last = -1;
    for (int i = 0; i < n; i++) {
      if (ans[i] == -1 && get(i, imp[j - 1])) {
        ans[i] = j;
        imp[j] = i;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (ans[i] == -1) {
      int u = 0;
      for (int j = 0; j < k; j++) {
        if (get(i, imp[j], imp[(j + 1) % k])) {
          u += (1 << j);
        }
      }
      ans[i] = u;
    }
  }
  return ans;
}
