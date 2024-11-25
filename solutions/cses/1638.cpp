#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
const int INF = 1e9;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<int> > grid;
    for(int i = 0; i < n; i++) {
      vector<int> curr(n, 0);
      string s; cin >> s;
      for(int j = 0; j < n; j++) {
	curr[j] = int(s[j] == '*');
      }
      grid.push_back(curr);
    }

    vector<int> dp(n, 0);
    dp[0] = 1;
    for(int i = 0; i < n; i++) {
      vector<int> nxt;
      if(grid[i][0] == 1) {
	nxt.push_back(0);
      } else {
	nxt.push_back(dp[0]);
      }
      for(int j = 1; j < n; j++) {
	if(grid[i][j] == 1) {
	  nxt.push_back(0);
	} else {
	  nxt.push_back((dp[j] + nxt[j - 1]) % MOD);
	}
      }
      dp = nxt;
    }
    cout << dp[n - 1];
}
