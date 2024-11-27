#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
const int INF = 1e9;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int> > dp;
    vector<int> first(2, 1);
    dp.push_back(first);
    for(int i = 1; i < 1000001; i++) {
      vector<int> curr;
      int no_merge = dp[i-1][0];
      no_merge += dp[i-1][1];
      no_merge %= MOD;
      no_merge += dp[i-1][0];
      no_merge %= MOD;
      no_merge += dp[i-1][0];
      no_merge %= MOD;
      no_merge += dp[i-1][0];
      no_merge %= MOD;

      int merge = dp[i - 1][0];
      merge += dp[i - 1][1];
      merge %= MOD;
      merge += dp[i-1][1];
      merge %= MOD;

      curr.push_back(no_merge);
      curr.push_back(merge);
      dp.push_back(curr);
    }

    int t; cin >> t;
    while(t--) {
      int n; cin >> n;
      cout << (dp[n-1][0] + dp[n-1][1]) % MOD << "\n";
    }
}
