#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

vector<map<int, int>> dp;
vector<vector<int>> adj;

int solve(int u, int p) {
  if(dp[u].find(p) == dp[u].end()) {
    if(sz(adj[u]) < 4) {
        return 1;
    }

    vector<int> children;
    for(int v : adj[u]) {
        if(v != p) {
        children.push_back(solve(v, u));
        }
    }

    sort(all(children));
    reverse(all(children));

    dp[u][p] = 1 + children[0] + children[1] + children[2];
  }
  return dp[u][p];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for(int i = 0; i <= n; i++) {
    map<int, int> curr_m;
    vector<int> curr_v;

    dp.push_back(curr_m);
    adj.push_back(curr_v);
  }

  for(int i = 0; i < n - 1; i++) {
    int ai, bi; cin >> ai >> bi;
    adj[ai].push_back(bi);
    adj[bi].push_back(ai);
  }

  int ret = -1;
  for(int u = 1; u <= n; u++) {
    if(sz(adj[u]) >= 4) {
      vector<int> children;
      for(int v : adj[u]) {
        children.push_back(solve(v, u));
      }
      sort(all(children)); reverse(all(children));

      ret = max(ret, 1 + children[0] + children[1] + children[2] + children[3]);
    }
  }
  cout << ret;
}
