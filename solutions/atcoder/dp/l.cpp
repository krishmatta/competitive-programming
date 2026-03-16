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
  vector<ll> a(n, 0);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<ll> dp(n, 0);
  for(int i = 0; i < n; i++) {
    if(n & 1) {
      dp[i] = a[i];
    } else {
      dp[i] = -a[i];
    }
  }

  for(int i = 2; i <= n; i++) {
    vector<ll> next_dp(n - i + 1, 0);
    for(int j = 0; j < sz(next_dp); j++) {
      int l = j;
      int r = j + i - 1;

      if((n - i) & 1) {
        next_dp[j] = min(dp[j] - a[r], dp[j+1] - a[l]);
      } else {
        next_dp[j] = max(dp[j] + a[r], dp[j+1] + a[l]);
      }
    }

    dp = next_dp;
  }

  cout << dp[0];
}
