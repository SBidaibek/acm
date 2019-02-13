// name = messy_tourist_subtask1234.cpp, type = cpp.g++11

#include "messy.h"
// w = n log n
// r = 2 n log n



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
