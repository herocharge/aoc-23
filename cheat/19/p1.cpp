#include <bits/stdc++.h>

using namespace std;

#define int long long

bool A(int x, int m, int a, int s){return true;}
bool R(int x, int m, int a, int s){return false;}

bool px(int x, int m, int a, int s);
bool pv(int x, int m, int a, int s);
bool lnx(int x, int m, int a, int s);
bool rfg(int x, int m, int a, int s);
bool qs(int x, int m, int a, int s);
bool qkq(int x, int m, int a, int s);
bool crn(int x, int m, int a, int s);
bool in(int x, int m, int a, int s);
bool qqz(int x, int m, int a, int s);
bool gd(int x, int m, int a, int s);
bool hdj(int x, int m, int a, int s);

bool px(int x, int m, int a, int s){if(a<2006){return qkq(x,m,a,s);}else if(m>2090){return A(x,m,a,s);}return rfg(x, m, a, s);}
bool pv(int x, int m, int a, int s){if(a>1716){return R(x,m,a,s);}return A(x, m, a, s);}
bool lnx(int x, int m, int a, int s){if(m>1548){return A(x,m,a,s);}return A(x, m, a, s);}
bool rfg(int x, int m, int a, int s){if(s<537){return gd(x,m,a,s);}else if(x>2440){return R(x,m,a,s);}return A(x, m, a, s);}
bool qs(int x, int m, int a, int s){if(s>3448){return A(x,m,a,s);}return lnx(x, m, a, s);}
bool qkq(int x, int m, int a, int s){if(x<1416){return A(x,m,a,s);}return crn(x, m, a, s);}
bool crn(int x, int m, int a, int s){if(x>2662){return A(x,m,a,s);}return R(x, m, a, s);}
bool in(int x, int m, int a, int s){if(s<1351){return px(x,m,a,s);}return qqz(x, m, a, s);}
bool qqz(int x, int m, int a, int s){if(s>2770){return qs(x,m,a,s);}else if(m<1801){return hdj(x,m,a,s);}return R(x, m, a, s);}
bool gd(int x, int m, int a, int s){if(a>3333){return R(x,m,a,s);}return R(x, m, a, s);}

bool hdj(int x, int m, int a, int s){if(m>838){return A(x,m,a,s);}return pv(x, m, a, s);}

int32_t main(){
	vector<vector<int>> parts = {{787,2655,1222,2876},
	{1679,44,2067,496},
	{2036,264,79,2244},
	{2461,1339,466,291},
	{2127,1623,2188,1013}};
	int ans = 0;
	for(auto part : parts){
		if(in(part[0], part[1], part[2], part[3])){
			for(auto p : part)cout<<p<<" ";cout<<endl;
			ans += part[0] + part[1] + part[2] + part[3];
		}
	}
	cout<<ans<<endl;
	
}
