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

const int dr[4] = {1, 0, -1, 0}, dc[4] = {0, 1, 0, -1};

const int MOD = 1e9 + 7;
const int INF = 1e9;

void setIO(string name = "") {
  cin.tie(0)->sync_with_stdio(0);
  if (sz(name)) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

vector<vi> ret;
vector<vi> adj;

void solve(int curr, vi& path) {
  path.pb(curr);
  if (!sz(adj[curr])) {
    ret.pb(path);
  } else {
    solve(adj[curr][0], path);
    FOR(i, 1, sz(adj[curr])) {
      vi init;
      solve(adj[curr][i], init);
    }
  }
}

int main() {
  setIO();

  int t;
  cin >> t;
  while (t) {
    int root = 0;
    int n;
    cin >> n;
    F0R(i, n + 1) { adj.pb(vi()); }
    FOR(i, 1, n + 1) {
      int pi;
      cin >> pi;
      if (pi == i) {
        root = i;
      } else {
        adj[pi].pb(i);
      }
    }

    vi start;
    solve(root, start);

    cout << sz(ret) << "\n";
    each(i, ret) {
      cout << sz(i) << "\n";
      each(j, i) { cout << j << " "; }
      cout << "\n";
    }
    cout << "\n";

    ret.clear();
    adj.clear();
    t--;
  }
}
