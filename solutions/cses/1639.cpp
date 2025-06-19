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

  string x, y; cin >> x >> y;
  vector<vector<int>> dp(sz(x) + 1, vector<int>(sz(y) + 1, 0));
  for(int i = sz(x); i > -1; i--) {
    for(int j = sz(y); j > -1; j--) {
      if(i == sz(x)) {
        dp[i][j] = sz(y) - j;
      } else if(j == sz(y)) {
        dp[i][j] = sz(x) - i;
      } else {
        dp[i][j] = dp[i+1][j+1] + int(x[i] != y[j]);
        dp[i][j] = min(dp[i][j], dp[i+1][j] + 1);
        dp[i][j] = min(dp[i][j], dp[i][j+1] + 1);
      }
    }
  }
  cout << dp[0][0];
}
