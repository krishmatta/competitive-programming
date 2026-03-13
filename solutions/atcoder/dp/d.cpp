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

  int n, w; cin >> n >> w;
  vector<ll> dp(w+1, 0);
  for(int i = 0; i < n; i++) {
    vector<ll> next_dp(w+1, 0);
    int wi, vi; cin >> wi >> vi;
    for(int j = 0; j < w+1; j++) {
      next_dp[j] = dp[j];
      if(j >= wi) {
        next_dp[j] = max(next_dp[j], vi + dp[j-wi]);
      }
    }
    dp = next_dp;
  }
  cout << dp[w];
}
