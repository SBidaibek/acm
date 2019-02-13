#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef long double ld;
typedef vector <ll> vi;

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

string to_string(int x) {
    string ans;
    for (; x || ans.size() == 0; x /= 10) ans.pb(x % 10);
    reverse(ans.begin(), ans.end());
    return ans;
}

struct Circle
{
  float radius;
  void resize(float factor) { radius *= factor; }
  string str()
  {
    return string("A circle of radius") + to_string(radius);
  }
};

template <typename T> struct ColoredShape : T
{
  string color;
  string str()
  {
    return T::str() + " which is colored " + color;
  }
};

int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    // usage:
    ColoredShape<Circle> red_circle{"red"};
    cout << red_circle.str() << endl;
    // and this is legal
    red_circle.resize(1.2);

    return 0;
}
