#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e3 + 10;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

//int d[N][N];

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vi p(2 * n + 1);
    vector <pii> a;
    vector <pair <int, pii>> b;
    forn(i, 1, 2 * n)
        cin >> p[i];

    vi used(2 * n + 1);
    vector <pii> Q(m + 1);
    forn(i, 1, m)
        cin >> Q[i].F >> Q[i].S;

    int turn;
    cin >> turn;

    //used[shit] = 1;
    forn(i, 1, m) {
        int x = Q[i].F, y = Q[i].S;/*
        if (shit == x || shit == y) {
            cout << (shit == x ? y : x) << endl;
            continue;
        }*/
        b.emplace_back(abs(p[x] - p[y]), p[x] >= p[y] ? pii(x, y) : pii(y, x));
        used[x] = 1;
        used[y] = 1;
    }

    forn(i, 1, n * 2)
        if (!used[i])
            a.pb({p[i], i});
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int del, id = 0;
    forn(it, 1, n) {
        //cerr << a.size() + b.size() << "\n";
        if (turn == 2) {
            cin >> del;
            id = 0;
            forn(i, 0, a.size() - 1)
                if (a[i].S == del) a.erase(a.begin() + i);
            forn(i, 0, b.size() - 1)
                if (b[i].S.F == del || b[i].S.S == del) {
                    id = (b[i].S.F == del ? b[i].S.S : b[i].S.F);
                    b.erase(b.begin() + i);
                }
            if (id) {
                cout << id << endl;
                continue;
            }
            if (!a.size() || !b.size()) {
                if (a.size())
                    {id = a.back().S; a.pop_back();}
                else
                    {id = b.back().S.F; b.pop_back();}
            }
            else
                {id = b.back().S.F; b.pop_back();}
            cout << id << endl;
        }
        else {
            if (!id) {
                if (!a.size() || !b.size()) {
                    if (a.size())
                        {id = a.back().S; a.pop_back();}
                    else
                        {id = b.back().S.F; b.pop_back();}
                }
                else
                    {id = b.back().S.F; b.pop_back();}
            }
            cout << id << endl;

            cin >> del;
            id = 0;
            forn(i, 0, a.size() - 1)
                if (a[i].S == del) a.erase(a.begin() + i);
            forn(i, 0, b.size() - 1)
                if (b[i].S.F == del || b[i].S.S == del) {
                    b.erase(b.begin() + i);
                    id = b[i].S.F == del ? b[i].S.S : b[i].S.F;
                }
        }
        //cerr << a.size() + b.size() << "\n";
        //cerr << "-\n";
    }

    /*a.insert(a.begin(), 0);
    b.insert(b.begin(), 0);
    forn(i, 1, a.size()) {
        forn(j, 1, b.size()) {
            d[i][j] = max(-d[i - 1][j] + a[i], -d[i][j - 1] + b[j]);
        }
    }*/

    return 0;
}

