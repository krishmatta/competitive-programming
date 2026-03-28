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

  string k; cin >> k;
  int d; cin >> d;
  vector<vector<int>> dp(2, vector<int>(d, 0)); dp[0][0] = 1; dp[1][0] = 1;
  for(int i = sz(k) - 1; i > -1; i--) {
    vector<vector<int>> next_dp(2, vector<int>(d, 0));
    for(int j = 0; j < d; j++) {
      for(int l = 0; l < 10; l++) {
        int n = (j + l) % d;

        next_dp[0][j] += dp[0][n];
        next_dp[0][j] %= MOD;

        if(l < k[i] - '0') {
          next_dp[1][j] += dp[0][n];
          next_dp[1][j] %= MOD;
        } else if (l == k[i] - '0') {
          next_dp[1][j] += dp[1][n];
          next_dp[1][j] %= MOD;
        }
      }
    }
    dp = next_dp;
  }
  cout << (dp[1][0] - 1 + MOD) % MOD;
}
