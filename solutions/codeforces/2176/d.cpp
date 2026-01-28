#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 998244353;
const int INF = 1e9;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;

    vector<pair<long long, int>> a;
    for(int i = 0; i < n; i++) {
      long long ai; cin >> ai;
      a.push_back(make_pair(ai, i));
    }
    sort(all(a));
    vector<long long> a_idx(n, 0);
    for(int i = 0; i < n; i++) {
      a_idx[a[i].second] = i;
    }

    vector<vector<int>> adj;
    for(int i = 0; i < n; i++) {
      vector<int> curr;
      adj.push_back(curr);
    }

    for(int i = 0; i < m; i++) {
      int u, v; cin >> u >> v; u--; v--;
      adj[a_idx[u]].push_back(a_idx[v]);
    }

    // dp[u][x] -> how many strictly increasing fibonacci sequences exist, starting w u and has x as second value
    vector<map<long long, int>> dp;
    for(int i = 0; i < n; i++) {
      map<long long, int> curr;
      dp.push_back(curr);
    }
    for(int u = n - 1; u > -1; u--) {
      for(int v : adj[u]) {
        long long x = a[v].first;
        if(x > a[u].first) {
          if(dp[u].find(x) == dp[u].end()) {
            dp[u][x] = 0;
          }
          dp[u][x] += 1; // for the len 2
          dp[u][x] %= MOD;
          dp[u][x] += dp[v][a[u].first+x];
          dp[u][x] %= MOD;
        }
      }
    }

    int ret = 0;
    for(int u = 0; u < n; u++) {
      // first, just add up sorted stuff
      for(const auto& [key, value] : dp[u]) {
        ret += value;
        ret %= MOD;
      }

      // now let's consider neighbors
      for(int v : adj[u]) {
        long long x = a[v].first;
        if(x <= a[u].first) {
          ret += dp[v][a[u].first+x] + 1;
          ret %= MOD;
        }
      }
    }
    cout << ret << "\n";
  }
}
