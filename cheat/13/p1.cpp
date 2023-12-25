#include <bits/stdc++.h>

using namespace std;

#define int long long

int vert(vector<string>& a, int n, int m){
	int ans = 0;
	for(int j = 0; j < m-1; j++){
		bool ok = true;
		for(int i = 0; i < n; i++){
			int l = j;
			int r = j+1;
			while(l >= 0 && r <= m-1){
				if(a[i][l] != a[i][r]){
					ok = false;
					break;
				}
				l--;
				r++;
			}
			if(!ok)
				break;
		}
		if(ok){
			ans += j+1;
			cout<<"[VERTICAL]"<<j+1<<endl;
		}
	}
	return ans;
}
int hor(vector<string>& a, int n, int m){
	int ans = 0;
	for(int i = 0; i < n-1; i++){
		bool ok = true;
		for(int j = 0; j < m; j++){
			int l = i;
			int r = i+1;
			while(l >= 0 && r <= n-1){
				if(a[l][j] != a[r][j]){
					ok = false;
					break;
				}
				l--;
				r++;
			}
			if(!ok)
				break;
		}
		if(ok){
			ans += i+1;
			cout<<"[HORIZONTAL]"<<i+1<<endl;
		}
	}
	return ans;
}

int solve(vector<string>& a){
	int n = a.size();
	int m = a[0].length();
	int ans = 0;
	ans += vert(a, n, m);
	ans += 100 * hor(a, n, m);
	return ans;
}



int32_t main(){
	int ans = 0; 
	while(true){
		vector<string> inp;
		while(true){
			string x;
			getline(cin, x);
			if(x.length() == 0 || x[0] == ' ')
				break;
			inp.push_back(x);
		}
		if(inp.size() == 0)
			break;
		cout<<"[inp]"<<inp.size()<<endl;
		ans += solve(inp);

	}
	cout<<ans<<endl;
}
