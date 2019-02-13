#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

ll d[N];

ll div(ll a) {
    return d[a];
//    vi va;
//    forn(i, 1, a) {
//        if (i * i > a) break;
//        if (a % i != 0) continue;
//        va.pb(i);
//        if (i * i != a) va.pb(a / i);
//    }
//    return va;
}

//ll slow(ll a, ll b, ll c) {
//    vi va = div(a), vb = div(b), vc = div(c);
//    set <vi> st;
//    for (auto x : va)
//        for (auto y : vb)
//            for (auto z : vc) {
//                vi t = {x, y, z};
//                sort(t.begin(), t.end());
//                st.insert(t);
//            }
////    for (auto v : st) {
////        for (auto x : v) cerr << x << " ";
////        cerr << "\n";
////    }
//    return st.size();
//}

inline ll c2(ll x) {
    return x * (x + 1) / 2;
}

ll c3(ll x) {
    return x * (x + 1) * (x + 2) / 6;
}

ll fast(ll a, ll b, ll c) {
    ll abc = div(__gcd(a, __gcd(b, c)));
    ll ab = div(__gcd(a, b)) - abc;
    ll bc = div(__gcd(b, c)) - abc;
    ll ac = div(__gcd(a, c)) - abc;
    a = div(a) - ab - ac - abc;
    b = div(b) - ab - bc - abc;
    c = div(c) - bc - ac - abc;
    ll sum = 0;
    sum += a * b * c;

    sum += a * b * abc;
    sum += a * b * ac;
    sum += a * b * bc;

    sum += a * c * abc;
    sum += a * c * ab;
    sum += a * c * bc;

    sum += b * c * abc;
    sum += b * c * ab;
    sum += b * c * ac;

    sum += a * c2(bc);
    sum += a * c2(abc);
    sum += a * ab * bc;
    sum += a * ab * ac;
    sum += a * ac * bc;
    sum += a * ab * abc;
    sum += a * bc * abc;
    sum += a * ac * abc;

    sum += b * c2(ac);
    sum += b * c2(abc);
    sum += b * ab * bc;
    sum += b * ab * ac;
    sum += b * ac * bc;
    sum += b * ab * abc;
    sum += b * bc * abc;
    sum += b * ac * abc;

    sum += c * c2(ab);
    sum += c * c2(abc);
    sum += c * ab * bc;
    sum += c * ab * ac;
    sum += c * ac * bc;
    sum += c * ab * abc;
    sum += c * bc * abc;
    sum += c * ac * abc;

    sum += ab * bc * ac;

    sum += c2(ab) * ac;
    sum += c2(ab) * bc;
    sum += c2(ab) * abc;

    sum += c2(bc) * ac;
    sum += c2(bc) * ab;
    sum += c2(bc) * abc;

    sum += c2(ac) * ab;
    sum += c2(ac) * bc;
    sum += c2(ac) * abc;

    sum += ab * bc * abc;
    sum += ab * ac * abc;
    sum += bc * ac * abc;

    sum += ab * c2(abc);
    sum += bc * c2(abc);
    sum += ac * c2(abc);

    sum += c3(abc);
    return sum;
    //a * b + (a + b) * g + g * (g + 1) / 2;
}

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    forn(i, 1, 1e5)
        for (ll j = i; j <= 1e5; j += i) ++d[j];

    ll t;
    cin >> t;
    forn(it, 1, t) {
        ll a, b, c;
        cin >> a >> b >> c;
        cout << fast(a, b, c) << "\n";
    }
    //cerr << fast(2, 3, 6) << "\n"; return 0;
//    forn(i, 1, 20) {
//        forn(j, 1, 20) {
//            forn(k, 1, 20) {
//                ll x = slow(i, j, k), y = fast(i, j, k);
//                if (x != y)
//                    cerr << i << " " << j << " " << k << ": " << x << " " << y << "\n";
//                assert(x == y);
//            }
//        }
//    }

    return 0;
}
