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
  string s; cin >> s;
  vector<int> dp(n + 1, 0); dp[0] = 1;
  for(int i = n - 2; i > -1; i--) {
    vector<int> next_dp(n + 1, 0);
    if(s[i] == '<') {
      for(int l = 0; l < n - i; l++) {
        next_dp[0] += dp[l];
        next_dp[0] %= MOD;
      }

      for(int l = 1; l < n - i; l++) {
        next_dp[l] = next_dp[l-1];
        next_dp[l] = (next_dp[l] - dp[l-1] + MOD) % MOD;
      }
    } else {
      for(int l = 1; l < n - i; l++) {
        next_dp[l] = next_dp[l-1];
        next_dp[l] += dp[l-1];
        next_dp[l] %= MOD;
      }
    }
    dp = next_dp;
  }

  int ret = 0;
  for(int x : dp) {
    ret += x;
    ret %= MOD;
  }

  cout << ret;
}
