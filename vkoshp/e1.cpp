#include <bits/stdc++.h>
#define fr first
#define sc second
#define pb push_back
#define mpr make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;

string s;

string f(string s){
    if (s[s.size() - 1] == '9'){
        for (int i = s.size() - 1; i >= 0; --i){
            if (s[i] == '9')
                s[i] = '0';
            else{
                ++s[i];
                break;
            }
        }
        if (s[0] == '0')
            s = '1' + s;
    }
    else
        ++s[s.size() - 1];
    return s;
}

bool ok(ll x) {
    for (int k = -1; x; x /= 10)
        if (k == x % 10) return 0;
        else k = x % 10;
    return 1;
}

ll slow(ll x) {
    for (++x;!ok(x);++x);
    return x;
}

string i2s(int x) {
    string s;
    if (!x) s.pb('0');
    for (;x; x /= 10) s.pb('0' + x % 10);
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    #ifndef SAKO
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    #endif // SAKO
    ios_base::sync_with_stdio(0);

    //int x;
    //cin >> x;
    //s = i2s(x);
    //cerr << s << "\n";
    cin >> s;
    s = f(s);
    for (bool repeat = 1; repeat;) {
        repeat = 0;
        for (int i = 0; i < s.size() - 1; ++i){
            if (s[i] != s[i + 1]) continue;
            if (s[i] == '9'){
                if (i == 0){
                    s[i] = '0', s[i + 1] = '1';
                    s = '1' + s;
                    --i;
                }
                else{
                    ++s[i - 1];
                    s[i] = '0', s[i + 1] = '1';
                }
            }
            else{
                ++s[i + 1];
            }
            for (int j = i + 2; j < s.size(); ++j) s[j] = '0';
            repeat = 1;
            break;
        }
    }
    cout << s << "\n";
    //cerr << s << " " << slow(x) << "\n";
    //assert(i2s(slow(x)) == s);
    return 0;
}
