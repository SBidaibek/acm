#include "prize.h"
#include "a1.cpp"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M = 100;

static const int max_q = 10000;
static int n;
static int query_count = 0;
static vector<int> g;
static vector<vector<int> > rank_count;

vector<int> ask(int i) {
	query_count++;
	if(query_count > max_q) {
		cerr << "Query limit exceeded" << endl;
		exit(0);
	}

	if(i < 0 || i >= n) {
		cerr << "Bad index: " << i << endl;
		exit(0);
	}

	vector<int> res(2);
	res[0] = rank_count[g[i] - 1][i + 1];
	res[1] = rank_count[g[i] - 1][n] - res[0];
	return res;
}

vi gen() {
    vi ans, c(6);
    c[1] = 1;
    //forn(i, 2, 5) c[i] = c[i - 1] * c[i - 1] + 1 + rand() % 10;

    return ans;
}

int main() {
    freopen("in", "r", stdin);
	cin >> n;

	g.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> g[i];
		if(g[i] < 1) {
			cerr << "Invalid rank " << g[i] << " at index " << i << endl;
			exit(0);
		}
	}

	int max_rank = *max_element(g.begin(), g.end());

	rank_count.resize(max_rank + 1, vector<int>(n + 1, 0));
	for(int r = 0; r <= max_rank; r++) {
		for(int i = 1; i <= n; i++) {
			rank_count[r][i] = rank_count[r][i - 1];
			if(g[i - 1] == r)
			  rank_count[r][i]++;
		}
	}

	for(int i = 0; i <= n; i++)
		for(int r = 1; r <= max_rank; r++)
			rank_count[r][i] += rank_count[r - 1][i];

	assert(rank_count[1][n] == 1);
	int res = Solve::find_best(n);
	assert(g[res] == 1);
	cout << res << endl << "Query count: " << query_count << endl;

	return 0;
}
