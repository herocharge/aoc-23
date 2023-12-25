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
	vector<int> nums = {1, 2006, 2090, 1716, 1548, 537, 2440, 3448, 1416, 2662, 1351, 2770, 1801, 3333, 838, 4000};
	sort(nums.begin(), nums.end());
	vector<int> test;
	vector<int> val;
	for(int i = 0; i < nums.size(); i++){
		if(i){
			test.push_back((nums[i] + nums[i-1])/2);
			val.push_back(nums[i] - nums[i-1] - 1);
		}
		test.push_back(nums[i]);
		val.push_back(1);
	}
	int ans = 0;
	for(int x = 0; x < test.size(); x++){
		for(int m = 0; m < test.size(); m++){
			for(int a = 0; a < test.size(); a++){
				for(int s = 0; s < test.size(); s++){
					if(in(test[x], test[m], test[a], test[s])){
						ans += val[x] * val[m] * val[a] * val[s];
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	
}
