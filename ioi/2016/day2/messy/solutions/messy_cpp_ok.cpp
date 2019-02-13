#include <vector>
#include <cstdio>
#include <string>
#include <set>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;
// BEGIN CUT
	vector<int> restore_permutation(int, int, int);

	namespace variables {
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

	using namespace variables;

	int main() {
		n = readInt();
		w = readInt();
		r = readInt();
		p = vector<int>(n);
		for (int i = 0; i < n; i++) {
			p[i] = readInt();
		}
		vector<int> answer = restore_permutation(n, w, r);
		printf("098d134608c94f7413faac591054ee35\n");
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

	int nn;
	string address;

	void helper(int length, int w) {
		fill(address.begin(), address.end(), '1');
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
		address = string(nn, '0');
		for (int i = 0; i < nn; i++) {
			fill(address.begin(), address.end(), '0');
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

	void read(const vector<int> &t, vector<int>& answer, int step, int w) {
		if (t.size() == 1) {
			answer[t[0]] = w;
			return;
		}
		vector<int> t0;
		vector<int> t1;
		fill(address.begin(), address.end(), '1');
		for (int j : t) {
			address[j] = '0';
		}
		for (int j : t) {
			address[j] = '1';
			if (!check_element(address)) {
				t0.push_back(j);
			}
			else {
				t1.push_back(j);
			}
			address[j] = '0';
		}
		read(t0, answer, step + 1, w);
		read(t1, answer, step + 1, w + (1 << step));
	}

	void doReads(int nn, vector<int>& answer) {
		vector<int> order = vector<int>(nn);
		for (int i = 0; i < nn; i++) {
			order[i] = i;
		}
		read(order, answer, 0, 0);
	}

	vector<int> restore_permutation(int nn, int w, int r) {
		doWrites(nn);
		compile_set();
		vector<int> answer(nn);
		doReads(nn, answer);
		return answer;
	}
