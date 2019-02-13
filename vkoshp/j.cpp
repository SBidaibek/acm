/*
ID: 5ak0
PROG:
LANG: C++11
*/

#include <bits/stdc++.h>
#define fr first
#define sc second
#define pb push_back
#define mpr make_pair
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;

int f(int x){
    string s = "";
    while(x){
        s += x % 10 + '0';
        x /= 10;
    }
    return sz(s);
}
string f2(int x){
    string s = "";
    while(x){
        s += x % 10 + '0';
        x /= 10;
    }
    reverse(all(s));
    return s;
}
int n, pos, cnt, l;
string s, t;
vector <string> g;
int main(){
    //#ifndef SAKO
    //freopen(".in", "r", stdin);
    freopen("output.txt", "w", stdout);
    //#endif // SAKO
    ios_base::sync_with_stdio(0);

    getline(cin, s);
    for(auto to : s){
        n *= 10;
        n += to - '0';
    }
    int x = f(n);
    //cout << endl;
    for(int i = 1;i <= n; ++ i){
        getline(cin, s);
        //cout << s << endl;
        for(int j = 0;j < sz(s) - 4 - x - f(i); ++ j)t += s[j];
        if(i < n)t += ' ';
    }
    while(l < sz(t)){
        ++cnt;
        for(int i = l;i <= l + 280 - 4 - f(cnt) - 1; ++ i){
            if(i == sz(t)){
                pos = i;
                break;
            }
            if(t[i] == ' ')pos = i;
        }
        g.pb(t.substr(l, pos - l) + " (" + f2(cnt) + "/" + "0)");
        l = pos + 1;
    }
    if(cnt <= 9){
        cout << cnt << endl;
        string y = f2(cnt);
        for(auto to : g){
            to[sz(to) - 2] = y[0];
            cout << to << endl;
        }
        return 0;
    }
    l = 0;
    cnt = 0;
    g.clear();
    while(l < sz(t)){
        ++cnt;
        for(int i = l;i <= l + 280 - 4 - f(cnt) - 2; ++ i){
            if(i == sz(t)){
                pos = i;
                break;
            }
            if(t[i] == ' ')pos = i;
        }
        g.pb(t.substr(l, pos - l) + " (" + f2(cnt) + "/" + "00)");
        l = pos + 1;
    }
    if(cnt <= 99){
        cout << cnt << endl;
        string y = f2(cnt);
        for(auto to : g){
            to[sz(to) - 3] = y[0];
            to[sz(to) - 2] = y[1];
            cout << to << endl;
        }
        return 0;
    }
    l = 0;
    cnt = 0;
    g.clear();
    while(l < sz(t)){
        ++cnt;
        for(int i = l;i <= l + 280 - 4 - f(cnt) - 3; ++ i){
            if(i == sz(t)){
                pos = i;
                break;
            }
            if(t[i] == ' ')pos = i;
        }
        g.pb(t.substr(l, pos - l) + " (" + f2(cnt) + "/" + "000)");
        l = pos + 1;
    }
    if(cnt <= 999){
        cout << cnt << endl;
        string y = f2(cnt);
        for(auto to : g){
            to[sz(to) - 4] = y[0];
            to[sz(to) - 3] = y[1];
            to[sz(to) - 2] = y[2];
            cout << to << endl;
        }
        return 0;
    }
    l = 0;
    cnt = 0;
    g.clear();
    while(l < sz(t)){
        ++cnt;
        for(int i = l;i <= l + 280 - 4 - f(cnt) - 4; ++ i){
            if(i == sz(t)){
                pos = i;
                break;
            }
            if(t[i] == ' ')pos = i;
        }
        g.pb(t.substr(l, pos - l) + " (" + f2(cnt) + "/" + "0000)");
        l = pos + 1;
    }
    if(cnt <= 9999){
        cout << cnt << endl;
        string y = f2(cnt);
        for(auto to : g){
            to[sz(to) - 5] = y[0];
            to[sz(to) - 4] = y[1];
            to[sz(to) - 3] = y[2];
            to[sz(to) - 2] = y[3];
            cout << to << endl;
        }
    }
    return 0;
}
