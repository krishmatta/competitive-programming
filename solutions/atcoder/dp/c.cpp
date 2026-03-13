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
  vector<int> dp(3, 0);
  for(int i = 0; i < n; i++) {
    vector<int> next_dp(3, 0);
    cin >> next_dp[0] >> next_dp[1] >> next_dp[2];
    for(int j = 0; j < 3; j++) {
      int mx = 0;
      for(int k = 0; k < 3; k++) {
        if(j != k) {
          mx = max(mx, dp[k]);
        }
      }
      next_dp[j] += mx;
    }
    dp = next_dp;
  }

  int mx = max(dp[0], max(dp[1], dp[2]));
  cout << mx;
}
