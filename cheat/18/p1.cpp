#include <bits/stdc++.h>

using namespace std;

#define int long long

int dfs(int i, int j, int mini, int minj, int maxi, int maxj, map<pair<int,int>, int>& vis, map<pair<int,int>, int>& vis2){
	if(i < mini || i > maxi || j < minj || j > maxj || vis[make_pair(i, j)] == 1)
		return 0;
	if(vis2[make_pair(i, j)] == 1)
		return 0;
	vis2[make_pair(i, j)] = 1;
	return 1 + dfs(i-1, j, mini, minj, maxi, maxj, vis, vis2)
	       + dfs(i+1, j, mini, minj, maxi, maxj, vis, vis2)
	       + dfs(i, j-1, mini, minj, maxi, maxj, vis, vis2)
	       + dfs(i, j+1, mini, minj, maxi, maxj, vis, vis2);
}
int dfs_iterative(int i, int j, int mini, int minj, int maxi, int maxj, map<pair<int, int>, int>& vis, map<pair<int, int>, int>& vis2, int col) {
    stack<pair<int, int>> s;
    s.push(make_pair(i, j));

    int count = 0;

    while (!s.empty()) {
        pair<int, int> current = s.top();
        s.pop();

        int ci = current.first;
        int cj = current.second;

        if (ci < mini || ci > maxi || cj < minj || cj > maxj || vis[make_pair(ci, cj)] == 1) {
            continue;
        }

        if (vis2[make_pair(ci, cj)] != 0) {
            continue;
        }

        vis2[make_pair(ci, cj)] = col;
        count++;

        // Push neighbors onto the stack
        s.push({ci - 1, cj});
        s.push({ci + 1, cj});
        s.push({ci, cj - 1});
        s.push({ci, cj + 1});
    }

    return count;
}

int32_t main(){
	map<pair<int,int>, int> vis;
	map<pair<int,int>, int> vis2;
	map<pair<int,int>, string> col;
	vis[make_pair(0, 0)] = 1;
	int wall = 0;
	int curri = 0, currj = 0, mini = 0, minj = 0, maxi = 0, maxj = 0;
	while(true){
		string dir;
		cin>>dir;
		if(dir.length() == 0)break;
		int len; cin>>len;
		string color;
		cin>>color;
		if(dir == "R"){
			while(len--){
				currj++;
				maxj = max(maxj, currj);
				vis[make_pair(curri, currj)] = 1;
				col[make_pair(curri, currj)] = color;
			}
		}
		if(dir == "L"){
			while(len--){
				currj--;
				minj = min(minj, currj);
				vis[make_pair(curri, currj)] = 1;
				col[make_pair(curri, currj)] = color;
			}
		}
		if(dir == "D"){
			while(len--){
				curri++;
				maxi = max(maxi, curri);
				vis[make_pair(curri, currj)] = 1;
				col[make_pair(curri, currj)] = color;
			}
		}
		if(dir == "U"){
			while(len--){
				curri--;
				mini = min(mini, curri);
				vis[make_pair(curri, currj)] = 1;
				col[make_pair(curri, currj)] = color;
			}
		}
		
	}
	for(auto x : vis){
		wall++;
	}
	for(int i = mini; i <= maxi; i++){
		for(int j = minj; j <= maxj; j++){
			if(vis[make_pair(i, j)] == 1){
				cout<<"#";
			}
			else
				cout<<".";
		}
		cout<<endl;
	}
	cout<<"Wall: "<<wall<<endl;
	vector<int> vals;
	int color = 1;
	for(int i = mini; i <= maxi; i++){
		for(int j = minj; j <= maxj; j++){
			if(vis2[make_pair(i, j)] != 0 || vis[make_pair(i, j)] == 1)
				continue;
			int tmp;
			cout << (tmp = dfs_iterative(i, j, mini, minj, maxi, maxj, vis, vis2, color)) << endl;
			vals.push_back(tmp);
			color++;
		}
	}
	for(int i = mini; i <= maxi; i++){
		for(int j = minj; j <= maxj; j++){
			if(vis[make_pair(i, j)] == 1){
				cout<<"#";
			}
			else
				cout<<vis2[make_pair(i, j)];
		}
		cout<<endl;
	}
	cout<<"Wall: "<<wall<<endl;
	for(int i = 0; i < vals.size(); i++){
		cout<<i+1<<" "<<vals[i]<<endl;
	}	
	return 0;
}
