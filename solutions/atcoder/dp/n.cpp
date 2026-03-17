#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<ll> a(n, 0);
  vector<ll> prefix(n + 1, 0);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    prefix[i+1] = prefix[i] + a[i];
  }

  vector<vector<ll>> dp(n, vector<ll>(n, INF));
  for(int j = 0; j < n; j++) {
    dp[j][j] = 0;
  }
  for(int i = 2; i <= n; i++) {
    for(int j = 0; j + i - 1 < n; j++) {
      for(int k = j; k < j + i - 1; k++) {
        dp[j][j+i-1] = min(dp[j][j+i-1], dp[j][k] + dp[k+1][j+i-1] + (prefix[j+i] - prefix[k+1]) + (prefix[k+1] - prefix[j]));
      }
    }
  }

  cout << dp[0][n-1];
}
