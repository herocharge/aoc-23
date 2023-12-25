#include <bits/stdc++.h>

using namespace std;

#define int long long
vector<pair<int,char>> getNextUp(int i, int j, char op, int n, int m){
	char dir = '^';
	int newi = -1;
	int newj = -1;
	char newdir = '*';
	switch(op){
		case '\\': j--;
			   dir = '<';
			   break;
		case '/':  j++;
			   dir = '>';
			   break;
		case '.':
		case '|':  i--;
			   break;
		case '-':  newi = i;
			   newj = j-1;
			   newdir = '<';
			   j = j + 1;
			   dir = '>';
			   break;
			  
	}
	if(i < 0 || j < 0 || i >= n || j >= m)
		dir = '*';
	if(newi < 0 || newj < 0
		|| newi >= n || newj >= m)
		newdir = '*';
	return {make_pair(i * m + j, dir), make_pair(newi * m + newj, newdir)};
}
vector<pair<int,char>> getNextDown(int i, int j, char op, int n, int m){
	char dir = 'v';
	int newi = -1;
	int newj = -1;
	char newdir = '*';
	switch(op){
		case '\\': j++;
			   dir = '>';
			   break;
		case '/':  j--;
			   dir = '<';
			   break;
		case '.':
		case '|':  i++;
			   break;
		case '-':  newi = i;
			   newj = j-1;
			   newdir = '<';
			   j = j + 1;
			   dir = '>';
			   break;
			  
	}
	if(i < 0 || j < 0 || i >= n || j >= m)
		dir = '*';
	if(newi < 0 || newj < 0
		|| newi >= n || newj >= m)
		newdir = '*';
	return {make_pair(i * m + j, dir), make_pair(newi * m + newj, newdir)};
}
vector<pair<int,char>> getNextLeft(int i, int j, char op, int n, int m){
	char dir = '<';
	int newi = -1;
	int newj = -1;
	char newdir = '*';
	switch(op){
		case '\\': i--;
			   dir = '^';
			   break;
		case '/':  i++;
			   dir = 'v';
			   break;
		case '.':
		case '-':  j--;
			   break;
		case '|':  newj = j;
			   newi = i-1;
			   newdir = '^';
			   i = i + 1;
			   dir = 'v';
			   break;
			  
	}
	if(i < 0 || j < 0 || i >= n || j >= m)
		dir = '*';
	if(newi < 0 || newj < 0
		|| newi >= n || newj >= m)
		newdir = '*';
	return {make_pair(i * m + j, dir), make_pair(newi * m + newj, newdir)};
}
vector<pair<int,char>> getNextRight(int i, int j, char op, int n, int m){
	char dir = '>';
	int newi = -1;
	int newj = -1;
	char newdir = '*';
	switch(op){
		case '\\': i++;
			   dir = 'v';
			   break;
		case '/':  i--;
			   dir = '^';
			   break;
		case '.':
		case '-':  j++;
			   break;
		case '|':  newj = j;
			   newi = i-1;
			   newdir = '^';
			   i = i + 1;
			   dir = 'v';
			   break;
	}
	if(i < 0 || j < 0 || i >= n || j >= m)
		dir = '*';
	if(newi < 0 || newj < 0
		|| newi >= n || newj >= m)
		newdir = '*';
	return {make_pair(i * m + j, dir), make_pair(newi * m + newj, newdir)};
}

vector<pair<int,char>> getNextDir(pair<int,char> curr, char op, int n, int m){
	int i = curr.first/m;
	int j = curr.first%m;
	char dir = curr.second;
	switch(dir){
		case '^' : return getNextUp(i, j, op, n, m);
		case 'v': return getNextDown(i, j, op, n, m);
		case '<' : return getNextLeft(i, j, op, n, m);
		case '>' : return getNextRight(i, j, op, n, m);
	}
	return {};
}

int32_t main(){
	vector<string> a;
	while(true){
		string s;
		cin>>s;
		if(s.length() == 0)
			break;
		a.push_back(s);
	}
	int n = a.size();
	int m = a[0].length();
	vector<pair<int,char>> init_tips;
	for(int i = 0; i < n; i++){
		init_tips.push_back(make_pair(i * m + 0, '>'));
	}
	for(int i = 0; i < n; i++){
		init_tips.push_back(make_pair(i * m + m-1, '<'));
	}
	for(int i = 0; i < m; i++){
		init_tips.push_back(make_pair(0 * m + i, 'v'));
	}
	for(int i = 0; i < m; i++){
		init_tips.push_back(make_pair((n-1) * m + i, '^'));
	}
	int mx_ans = 0;
	for(auto init_tip : init_tips){
		vector<pair<int,char>> tips;
		vector<vector<map<char, int>>> mp(n, vector<map<char,int>>(m));
		tips.push_back(init_tip);
		while(tips.size() > 0){
			vector<pair<int,char>> nxt;
			for(auto tip : tips){
				int i = tip.first/m;
				int j = tip.first%m;
				char dir = tip.second;
				if(mp[i][j][dir] == 1){
					continue;	
				}
				mp[i][j][dir] = 1;
				// cout<<"Curr: ("<<i<<", "<<j<<", "<<dir<<") ";
				vector<pair<int, char>> nxtmvs = getNextDir(tip, a[i][j], n, m);
				for(auto mv : nxtmvs){
					if(mv.second == '*')
						continue;
					int i = mv.first/m;
					int j = mv.first%m;
					int dir = mv.second;
					// cout<<"Next : ("<<i<<", "<<j<<", "<<dir<<") ";
					nxt.push_back(mv);
				}
				//cout<<endl;
			}
			tips = nxt;
		}
		int ans = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				map<char,int> lmao = mp[i][j];
				if(lmao['<'] + lmao['>'] + lmao['^'] + lmao['v'] > 0)
					ans++;
			}
		}
		cout<<ans<<endl;
		mx_ans = max(mx_ans, ans);
	}
	cout<<mx_ans<<endl;
	return 0;
}
