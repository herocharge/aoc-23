#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<int> p[200][200][4][10];
	int dp[200][200][4][10];


int32_t main(){
	vector<vector<int>> inp;
	while(true){
		string x;
		cin>>x;
		if(x.length() == 0){
			break;
		}
		vector<int> tmp;
		for(auto c : x){
			tmp.push_back(c - '0');
		}
		inp.push_back(tmp);
	}
	int n = inp.size();
	int m = inp[0].size();
	cout<<n<<" "<<m<<endl;
	// 0 -> up, 1-> down, 2-> left, 3->right
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			for(int k = 0; k < 4; k++){
				for(int l = 0; l < 10; l++){
					dp[i][j][k][l] = INT_MAX;
					if(i + j == 0)
						dp[i][j][k][l] = inp[i][j];
				}
			}
		}
	}
	int epochs = 100;
	while(epochs--){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				for(int k = 0; k < 4; k++){
					for(int l = 3; l < 10; l++){
						for(int k2 = 0; k2 < 4; k2++){
							if((k2 == 0 || k2 == 1) && (k == 0 || k == 1))continue;
							if((k2 == 2 || k2 == 3) && (k == 2 || k == 3))continue;
							if(k2 == 0){
								// up
								if(i < 4){
									continue;
								}

								int ti = i-1, tj = j;
								int l2 = 0;
								int sum = 0;
								while(l2 < 3){
									sum += inp[ti][tj];
									ti--;
									l2++;
								}
								while(ti >= 0 && l2 < 10){
									sum += inp[ti][tj];
									if(dp[ti][tj][k2][l2] > sum + dp[i][j][k][l]){
										p[ti][tj][k2][l2] = vector<int>({i, j, k, l});
									}
									dp[ti][tj][k2][l2] = min(dp[ti][tj][k2][l2], sum + dp[i][j][k][l]);
									ti--;
									l2++;
								}
							}
							if(k2 == 1){
								// down
								if(i > n - 5){
									continue;
								}
								int ti = i+1, tj = j;
								int l2 = 0;
								int sum = 0;
								while(l2 < 3){
									sum += inp[ti][tj];
									ti++;
									l2++;
								}
								while(ti < n && l2 < 10){
									sum += inp[ti][tj];
									if(dp[ti][tj][k2][l2] > sum + dp[i][j][k][l]){
										p[ti][tj][k2][l2] = vector<int>({i, j, k, l});
									}
									dp[ti][tj][k2][l2] = min(dp[ti][tj][k2][l2], sum + dp[i][j][k][l]);
									ti++;
									l2++;
								}
							}
							if(k2 == 2){
								// left
								if(j < 4){
									continue;
								}
								int ti = i, tj = j-1;
								int l2 = 0;
								int sum = 0;
								while(l2 < 3){
									sum += inp[ti][tj];
									tj--;
									l2++;
								}
								while(tj >= 0 && l2 < 10){
									sum += inp[ti][tj];
									if(dp[ti][tj][k2][l2] > sum + dp[i][j][k][l]){

										p[ti][tj][k2][l2] = vector<int>({i, j, k, l});
									}
									dp[ti][tj][k2][l2] = min(dp[ti][tj][k2][l2], sum + dp[i][j][k][l]);
									tj--;
									l2++;
								}
							}
							if(k2 == 3){
								// right
								if(j > m - 5){
									continue;
								}

								int ti = i, tj = j+1;
								int l2 = 0;
								int sum = 0;
								while(l2 < 3){
									sum += inp[ti][tj];
									tj++;
									l2++;
								}
								while(tj < m && l2 < 10){
									sum += inp[ti][tj];
									if(dp[ti][tj][k2][l2] > sum + dp[i][j][k][l]){
										p[ti][tj][k2][l2] = vector<int>({i, j, k, l});
									}
									dp[ti][tj][k2][l2] = min(dp[ti][tj][k2][l2], sum + dp[i][j][k][l]);
									tj++;
									l2++;
								}
							}
						}
					}
				}
			}
		}
		// for(int i = 0; i < n; i++){
		// 	for(int j = 0; j < m; j++){
		// 		int mans = INT_MAX;
		// 		for(int k = 0; k < 4; k++){
		// 			for(int l = 3; l < 10; l++){
		// 				mans = min(mans, dp[i][j][k][l]);
		// 			}
		// 		}
		// 		cout<<mans<<"\t";
		// 	}
		// 	cout<<endl;
		// }
		// cout<<endl;
	}
	int min_ans = INT_MAX;
	int kk, ll;
	for(int k = 0; k < 4; k++){
		for(int l = 3; l < 10; l++){
			if(min_ans > dp[n-1][m-1][k][l]){
				kk = k;
				ll = l;
			}
			min_ans = min(min_ans, dp[n-1][m-1][k][l]);
		}
	}
	// auto curr = vector<int>({n-1, m-1, kk, ll});
	// int limit = 100;
	// while(!(curr[0] == 0 && curr[1] == 0) && limit--){
	// 	cout<<"("<<curr[0]<<", "<<curr[1]<<")"<<endl;
	// 	curr = p[curr[0]][curr[1]][curr[2]][curr[3]];
	// }
	cout<<min_ans - inp[0][0]<<endl;
	return 0;
}
