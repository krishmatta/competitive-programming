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
  vector<vector<int>> adj(n, vector<int>());
  for(int i = 0; i < n - 1; i++) {
    int xi, yi; cin >> xi >> yi; xi--; yi--;
    adj[xi].push_back(yi); adj[yi].push_back(xi);
  }

  vector<int> order;
  deque<int> q; q.push_back(0);
  set<int> vis; vis.insert(0);
  while(sz(q)) {
    int u = q.front(); q.pop_front();
    order.push_back(u);

    for(int v : adj[u]) {
      if(vis.find(v) == vis.end()) {
        q.push_back(v);
        vis.insert(v);
      }
    }
  }

  reverse(all(order));

  vector<vector<ll>> dp(n, vector<ll>(2, -1));
  for(int u : order) {
    dp[u][0] = 1;
    dp[u][1] = 1;

    for(int v : adj[u]) {
      if(dp[v][0] != -1) {
        dp[u][0] *= (dp[v][0] + dp[v][1]) % MOD;
        dp[u][0] %= MOD;
        dp[u][1] *= dp[v][0];
        dp[u][1] %= MOD;
      }
    }
  }

  cout << (dp[0][0] + dp[0][1]) % MOD;
}
