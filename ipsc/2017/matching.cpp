#include <bits/stdc++.h>

#if defined(__MINGW32__)
#define __MSVCRT_VERSION__ 0x800
#define _WIN32_WINNT 0x0500
#endif
#include "cimg/CImg.h"

using namespace std;
using namespace cimg_library;

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
const ll INF = 1e18 + 9;
const int B = 1e9 + 7;


int main() {
    #ifdef black
    freopen("in", "r", stdin);
    #endif // black
    ios_base :: sync_with_stdio(0);
    cin.tie(0);


  CImg<float> image("kek.png");
  CImgDisplay main_disp(image);
  float pixvalR = image(10,10,0,0); // read red val at coord 10,10
  float pixvalG = image(10,10,0,1); // read green val at coord 10,10
  float pixvalB = image(10,10,0,2); // read blue val at coord 10,10
  cout << "R = " << pixvalR << ", G = " << pixvalG << ", B = " << pixvalB;

    return 0;
}
