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

  int a, b; cin >> a >> b;
  vector<vector<int>> dp(a + 1, vector<int>(b + 1, INF));
  for(int i = 1; i < a + 1; i++) {
    for(int j = 1; j < b + 1; j++) {
      if(i == j) {
        dp[i][j] = 0;
      }

      for(int k = 1; k < i; k++) {
        dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i-k][j]);
      }
      for(int k = 1; k < j; k++) {
        dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j-k]);
      }
    }
  }

  cout << dp[a][b];
}
