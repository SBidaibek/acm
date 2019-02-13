#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    while (s.size() > 1) {
        bool ok = 0;
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == s[i + 1]) {
                s.erase(i, 2);
                ok = 1;
                break;
            }
        }
        if (!ok) break;
    }
    if (s.size() == 0)
        s = "Empty String";
    cout << s;
    return 0;
}
