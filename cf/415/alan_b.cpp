#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define F first
#define S second

#define fo(i, n) for(int i = 1; i <= n; ++i)
#define rep(i, a, b) for(int (i) = (a); (i) < (b); ++(i))

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 200200;
const int mod = 1e9 + 7;
const ll INF = 1e18;
string s;
int n, k;

inline void flush()
{
	fflush(stdout);
}

inline int find_first(int l, int r)
{
	if(l > r) return 0;
	if(l == 0 || r == 0) return 0;
	if(l > n || r > n) return 0;
	if(l == r) return l;
	int k = (l + r) / 2;
	cout << 1 << ' ' << k << ' ' << k + 1 << endl;
	flush();
	cin >> s;
	if(s == "TAK")
		r = k;
	else
		l = k + 1;
	return find_first(l, r);
}

inline bool check(int pos2, int pos)
{
	cout << "1 " << pos2 <<' ' <<pos << endl;
	flush();
	cin >> s;
	if(s == "TAK")
		return true;
	else
		return false;
}

int main()
{
    cin >> n >> k;
    if(n == k)
    {
    	cout << 2 <<' ' << 1 << ' '<< 2 <<endl;
    	flush();
    	return 0;
    }
	int pos = find_first(1, n);
	cerr << pos << "\n";
	int pos2 = find_first(1, pos - 1);
	if(pos2 && check(pos2, pos))
	{
		cout << 2 <<' '<<pos2 << ' ' <<pos <<endl;
		flush();
		return 0;
	}
	pos2 = find_first(pos + 1, n);
	if(pos2 && check(pos2, pos))
	{
		cout << 2 <<' '<<pos2<<' '<<pos<<endl;
		flush();
		return 0;
	}
	assert(0);
	return 0;
}
