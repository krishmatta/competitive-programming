#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;
using str = string;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto& a : x)

#define YES cout << "YES" << "\n";
#define NO cout << "NO" << "\n";

#define tst \
  int t;    \
  cin >> t; \
  while (t--)

const int dr[4] = {1, 0, -1, 0}, dc[4] = {0, 1, 0, -1};

const int MOD = 1e9 + 7;
const int INF = 1e9;

void vin(int n, vi& a) {
  rep(n) {
    int ai;
    cin >> ai;
    a.pb(ai);
  }
}

void setIO(string name = "") {
  cin.tie(0)->sync_with_stdio(0);
  if (sz(name)) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

int main() {
  setIO();

  tst {
    int n, k, c;
    cin >> n >> k >> c;
    vector<vi> adj;
    rep(n) {
      vi curr;
      adj.pb(curr);
    }

    rep(n - 1) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      adj[u].pb(v);
      adj[v].pb(u);
    }

    vi root_dist(n, -1);
    root_dist[0] = 0;
    queue<int> q;
    q.push(0);
    while (sz(q)) {
      int curr = q.front();
      q.pop();
      each(child, adj[curr]) {
        if (root_dist[child] == -1) {
          root_dist[child] = root_dist[curr] + 1;
          q.push(child);
        }
      }
    }

    int mx = 0;
    FOR(i, 1, n) {
      if (root_dist[i] > root_dist[mx]) {
        mx = i;
      }
    }

    vi mx_dist(n, -1);
    mx_dist[mx] = 0;
    q.push(mx);
    while (sz(q)) {
      int curr = q.front();
      q.pop();
      each(child, adj[curr]) {
        if (mx_dist[child] == -1) {
          mx_dist[child] = mx_dist[curr] + 1;
          q.push(child);
        }
      }
    }

    ll ret = 0;
    F0R(i, n) {
      ll curr = ((ll)k * (ll)mx_dist[i]) - ((ll)c * (ll)root_dist[i]);
      ret = max(ret, curr);
    }
    cout << ret << "\n";
  }
}
