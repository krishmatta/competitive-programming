#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

int popcount(int x) {
  int ret = 0;
  while(x) {
    if(x & 1) {
      ret++;
    }
    x >>= 1;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<vector<int>> adj(n, vector<int>());
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      int aij; cin >> aij;
      if(aij) {
        adj[i].push_back(j);
      }
    }
  }

  vector<int> dp(1 << n, 0); dp[0] = 1;
  for(int i = 0; i < n; i++) {
    vector<int> next_dp(1 << n, 0);
    for(int j = 0; j < 1 << n; j++) {
      if(popcount(j) != i + 1) {
        continue;
      }

      for(int k : adj[i]) {
        int mask = 1 << k;
        if(j & mask) {
          next_dp[j] += dp[j ^ mask];
          next_dp[j] %= MOD;
        }
      }
    }
    dp = next_dp;
  }
  cout << dp[(1 << n) - 1];
}
