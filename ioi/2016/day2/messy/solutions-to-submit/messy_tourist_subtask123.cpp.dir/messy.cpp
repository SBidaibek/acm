// name = messy_tourist_subtask123.cpp, type = cpp.g++11

#include "messy.h"
// n writes, n^2/2 reads worst case, n^2/4 reads average case
// (ok for "n = 32, r = 320" subtask)



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
