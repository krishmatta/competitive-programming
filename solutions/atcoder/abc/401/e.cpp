#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

int parent[200001];
int sizee[200001];

int num = 0;

void make_set(int v) {
  parent[v] = v;
  sizee[v] = 1;
  num++;
}

int find_set(int v) {
  if(v == parent[v]) return v;
  return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);

  if(a != b) {
    if(sizee[a] < sizee[b]) swap(a, b);
    parent[b] = a;
    sizee[a] += sizee[b];
    num--;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  for(int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  set<int> frontier;
  for(int u = 1; u <= n; u++) {
    frontier.erase(u);
    make_set(u);
    for(int v : adj[u]) {
      if(v > u) {
        frontier.insert(v);
      } else {
        union_sets(u, v);
      }
    }

    if(num == 1) {
      cout << sz(frontier) << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
}
