#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9;

const int MAXV = 1e3;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, w; cin >> n >> w;
  vector<int> dp(MAXV * n + 1, INF + 1); dp[0] = 0;
  for(int i = 0; i < n; i++) {
    vector<int> next_dp(sz(dp), INF + 1); next_dp[0] = 0;
    int wi, vi; cin >> wi >> vi;
    for(int j = 0; j < sz(dp); j++) {
      next_dp[j] = dp[j];
      next_dp[j] = min(next_dp[j], wi + dp[max(0, j - vi)]);
    }
    dp = next_dp;
  }

  int ret = 0;
  for(int i = 0; i < sz(dp); i++) {
    if(dp[i] <= w) {
      ret = i;
    } else {
      break;
    }
  }
  cout << ret << "\n";
}
