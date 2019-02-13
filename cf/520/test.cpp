#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b,int &x1,int &y1){
    if (b==0){
        x1=1,y1=0;
        return a;
    }
    int q=gcd(b,a%b,y1,x1);
    y1-=a/b*x1;
    return q;
}

typedef long long ll;
typedef pair <ll, ll> pll;
ll area(vector <pll> a) {
    int n = a.size();
    a.push_back(a[0]);
    ll ans = 0;
    for (int i = 0; i < n; ++i)
        ans += (a[i].second + a[i + 1].second) * (a[i + 1].first - a[i].first);
    return ans;
}

int main(){
	int n;
	int x,y,x1,y1;
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&x,&y);
		if(x<=50000||y<=50000){
		printf("3\n0 0\n%d %d\n",x,y);
		if(x<y)
			printf("0 1\n");
		else
			printf("1 0\n");}
		else
			{
			int z = gcd(x,y,x1,y1);
			int xx = x/z,yy = y/z;
			int ans = (xx+yy);
			if(ans<=50000){
				printf("4\n0 0\n%d %d\n%d %d\n%d %d\n",x-1,y,xx,yy,x,y-1);
				cout << area({  {0, 0}, {xx, yy}, {x - 1, y}, {x, y - 1}}) << "\n";
				continue;
				}
			printf("3\n");
			printf("0 0\n");
			printf("%d %d\n",x,y);
			while(x1>0&&y1>0){
				x1 -= yy;
				y1 -= xx;
			}
			printf("%d %d\n",abs(y1),abs(x1));
		}
	}
}
