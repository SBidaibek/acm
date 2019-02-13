#include <bits/stdc++.h>

using namespace std;

int lastdiv2 (vector <int> &s) {
    return s[s.size() - 1] / 2;
}

void Reverse(vector <int> &s) {
    for (int i = 0; i <= s.size() / 2; ++i)
        swap(s[i], s[s.size() - 1 - i]);
}

int f (int n, vector <char> a) {
    vector <int> s;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 'S') {
            s.push_back (i);
        }
    }
    if (s.size() == 0) return n;

    vector <int> g (s.size() + 1);
    g[0] = s[0];
    g[s.size()] = n - s.back() - 1;
    for (int i = 1; i < s.size(); ++i) {
        g[i] = s[i] - s[i - 1] - 1;
    }
    int t = g[0] + g[1];
    for (int i = 1; i < s.size(); ++i) {
        if ((g[i] + g[i + 1]) > t) t = g[i] + g[i + 1];
    }

    if ((n - s.size()) > t)
        t = t + 1;

    return t;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector <char> a(n);
    for (int i = 0; i < n;++i)
        cin >> a[i];
    cout << f (n, a);

    return 0;
}
