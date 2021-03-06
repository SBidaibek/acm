// name = messy_tourist.cpp, type = cpp.g++11

#include "messy.h"


#include <bits/stdc++.h>

//#include "messy.h"

using namespace std;

int N;

void put(int i, int j) {
  string s(N, '0');
  s[i] = s[j] = '1';
  add_element(s);
}

void put(int i, int j, int k) {
  string s(N, '0');
  s[i] = s[j] = s[k] = '1';
  add_element(s);
}

bool check(int i, int j) {
  string s(N, '0');
  s[i] = s[j] = '1';
  return check_element(s);
}

bool check(int i, int j, int k) {
  string s(N, '0');
  s[i] = s[j] = s[k] = '1';
  return check_element(s);
}

bool g[1234][1234];

vector<int> restore_permutation(int nnn, int w, int r) {
  N = nnn;
  int k = 0;
  while ((1 << k) != N) {
    k++;
  }
  if (k < 4) {
    string s(N, '0');
    for (int i = 0; i < N; i++) {
      s[i] = '1';
      add_element(s);
    }
    compile_set();
    string t(N, '0');
    vector <int> ans(N);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (t[j] != '0') {
          continue;
        }
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
  for (int i = 0; i < k; i++) {
    put(i, i);
  }
  put(0, 1);
  put(0, 2);
  put(1, 2);
  for (int i = 2; i + 1 < k; i++) {
    put(i, i + 1);
  }
  put(1, 2, 3);
  for (int i = k; i < N; i++) {
    for (int j = 0; j < k; j++) {
      if (i & (1 << j)) {
        put(i, j);
      }
    }
  }
  compile_set();
  vector <int> imp;
  for (int i = 0; i < N; i++) {
    if (check(i, i)) {
      imp.push_back(i);
    }
  }
  assert(imp.size() == k);
  for (int i = 0; i < k; i++) {
    for (int j = i + 1; j < k; j++) {
      g[imp[i]][imp[j]] = g[imp[j]][imp[i]] = check(imp[i], imp[j]);
    }
  }
  bool found = false;
  do {
    if (!g[imp[0]][imp[1]] || !g[imp[0]][imp[2]] || !g[imp[1]][imp[2]]) {
      continue;
    }
    bool ok = true;
    for (int i = 2; i + 1 < k; i++) {
      if (!g[imp[i]][imp[i + 1]]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      if (!check(imp[1], imp[2], imp[3])) {
        continue;
      }
      found = true;
      break;
    }
  } while (next_permutation(imp.begin(), imp.end()));
  assert(found);
  vector <int> ans(N, -1);
  vector <bool> used(N, false);
  for (int i = 0; i < k; i++) {
    ans[imp[i]] = i;
    used[i] = true;
  }
  for (int i = 0; i < N; i++) {
    if (ans[i] != -1) {
      continue;
    }
    int u = 0;
    for (int j = k - 1; j >= 0; j--) {
      int options = 0;
      int any = -1;
      for (int z = u; z < u + (1 << (j + 1)); z++) {
        if (!used[z]) {
          options++;
          any = z;
        }
      }
      if (options == 1) {
        u = any;
        break;
      }
      if (check(i, imp[j])) {
        u |= (1 << j);
      }
    }
    ans[i] = u;
    used[u] = true;
  }
  return ans;
}
