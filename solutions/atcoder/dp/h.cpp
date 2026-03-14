#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int h, w; cin >> h >> w;
  vector<vector<bool>> grid(h, vector<bool>(w, false));
  for(int i = 0; i < h; i++) {
    string s; cin >> s;
    for(int j = 0; j < w; j++) {
      grid[i][j] = (s[j] == '#');
    }
  }

  vector<int> dp(w, 0); dp[w-1] = 1;
  for(int i = w - 2; i > -1; i--) {
    if(grid[h-1][i]) {
      dp[i] = 0;
    } else {
      dp[i] = dp[i+1];
    }
  }

  for(int i = h - 2; i > -1; i--) {
    vector<int> next_dp(w, 0);
    for(int j = w - 1; j > -1; j--) {
      if(grid[i][j]) {
        next_dp[j] = 0;
      } else {
        if(j + 1 < w) {
          next_dp[j] += next_dp[j+1];
          next_dp[j] %= MOD;
        }
        next_dp[j] += dp[j];
        next_dp[j] %= MOD;
      }
    }
    dp = next_dp;
  }

  cout << dp[0];
}
