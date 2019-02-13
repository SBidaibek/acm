// name = messy_iz.cpp, type = cpp.g++11

#include "messy.h"


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
