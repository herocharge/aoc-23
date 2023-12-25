#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main(){
	vector<string> a;
	while(true){
		string x;
		cin>>x;
		if(x.length() == 0)
			break;
		a.push_back(x);
	}
	int n = a.size();
	int m = a[0].length();
	int ans = 0;
	for(int j = 0; j < m; j++){
		int curr = 0;
		int p = -1;
		int r = 0;
		for(int i = 0; i< n; i++){
			if(a[i][j] == '#'){
				int kk = n - (p+1);
				curr += (kk * (kk + 1)) / 2;
				kk -= r;
				curr -= (kk * (kk + 1))/2;
				p = i;
				r = 0;
				continue;
			}
			if(a[i][j] == 'O')
				r++;
			
		}
		if(r > 0){
			int kk = n - (p+1);
			curr += (kk * (kk + 1)) / 2;
			kk -= r;
			curr -= (kk * (kk + 1))/2;
			r = 0;
		}
		cout<<curr<<endl;
		ans += curr;
	}
	cout<<ans<<endl;
	return 0;
}
