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

  int n, m; cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  vector<int> in(n, 0);
  for(int i = 0; i < m; i++) {
    int xi, yi; cin >> xi >> yi;
    xi--; yi--;
    adj[xi].push_back(yi);
    in[yi]++;
  }

  // toposort
  vector<int> sort;
  deque<int> q;
  for(int u = 0; u < n; u++) {
    if(in[u] == 0) {
      sort.push_back(u);
      q.push_back(u);
    }
  }

  while(sz(q)) {
    int u = q.front(); q.pop_front();
    for(int v : adj[u]) {
      in[v]--;
      if(in[v] == 0) {
        sort.push_back(v);
        q.push_back(v);
      }
    }
  }

  vector<int> inv_sort(n, 0);
  for(int i = 0; i < n; i++) {
    inv_sort[sort[i]] = i;
  }

  vector<int> dp(n, 0);
  int ret = 0;
  for(int u = n - 1; u > -1; u--) {
    dp[u] = 1;
    for(int v : adj[sort[u]]) {
      dp[u] = max(dp[u], 1 + dp[inv_sort[v]]);
    }
    ret = max(ret, dp[u]);
  }
  cout << ret - 1;
}
