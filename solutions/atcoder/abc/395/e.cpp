#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

vector<vector<pair<int, ll>>> adj;

ll dijkstra(int s, int t) {
  int n = adj.size();
  vector<ll> d(n, INF);

  d[s] = 0LL;
  set<pair<ll, int>> q;
  q.insert({0, s});
  while(!q.empty()) {
    int v = q.begin()->second;
    q.erase(q.begin());

    for(auto edge : adj[v]) {
      int to = edge.first;
      ll len = edge.second;

      if(d[v] + len < d[to]) {
	q.erase({d[to], to});
	d[to] = d[v] + len;
	q.insert({d[to], to});
      }
    }
  }
  return d[t];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, x; cin >> n >> m >> x;

  for(int i = 0; i < 2 * n + 1; i++) {
    vector<pair<int, ll>> curr;
    adj.push_back(curr);
  }
  for(int i = 1; i < n + 1; i++) {
    adj[i].push_back(make_pair(i + n, x));
    adj[i + n].push_back(make_pair(i, x));
  }
  for(int i = 0; i < m; i++) {
    int ui, vi; cin >> ui >> vi;
    adj[ui].push_back(make_pair(vi, 1));
    adj[vi + n].push_back(make_pair(ui + n, 1));
  }

  cout << min(dijkstra(1, n), dijkstra(1, 2*n));
}
