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

  int n; cin >> n;
  vector<vector<int>> dp(n+1, vector<int>((n*(n+1))/2+1, 0)); 
  dp[0][0] = 1;
  for(int i = 1; i < n+1; i++) {
    for(int j = 0; j < (i*(i+1))/2+1; j++) {
      dp[i][j] = dp[i-1][j];
      if(j >= i) {
        dp[i][j] += dp[i-1][j-i];
        dp[i][j] %= MOD;
      }
    }
  }

  if((n*(n+1)/2) % 2) {
    cout << 0;
  } else {
    ll inv2 = (MOD + 1) / 2;
    cout << (1LL * dp[n][n*(n+1)/4] % MOD * inv2) % MOD;
  }
}
