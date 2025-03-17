#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const ll INF = 1LL << 60 + 1LL;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

int n = 0;
ll ret = INF;
vector<vector<pair<int, ll>>> adj(11);
vector<bool> vis(11, false);

void dfs(int i, ll x) {
  if(i == n) {
    ret = min(ret, x);
  }

  for(pair<int, ll> nxt : adj[i]) {
    if(!vis[nxt.first]) {
      vis[nxt.first] = true;
      dfs(nxt.first, x ^ nxt.second);
      vis[nxt.first] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int m; cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int ui, vi; cin >> ui >> vi;
    ll wi; cin >> wi;
    adj[ui].push_back(make_pair(vi, wi));
    adj[vi].push_back(make_pair(ui, wi));
  }

  vis[1] = true;
  dfs(1, 0);
  vis[1] = false;
  cout << ret;
}
