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

vector<set<int>> adj;
vi group;

bool dfs(int curr_idx, int curr, int parent) {
  bool ret = false;
  each(x, adj[curr_idx]) {
    if (x != parent && group[x] != -1) {
      ret = true;
    }
    if (group[x] == -1) {
      group[x] = curr;
      ret = ret || dfs(x, curr, curr_idx);
    }
  }
  return ret;
}

int main() {
  setIO();

  tst {
    adj.clear();
    group.clear();

    int n;
    cin >> n;
    rep(n) {
      set<int> curr;
      adj.pb(curr);
    }

    F0R(i, n) {
      int curr;
      cin >> curr;
      curr--;
      adj[i].insert(curr);
      adj[curr].insert(i);
    }

    rep(n) group.pb(-1);
    int curr = 0;
    int cycles = 0;
    F0R(i, n) {
      if (group[i] == -1) {
        group[i] = curr;
        if (dfs(i, curr, -1)) cycles++;
        curr++;
      }
    }

    if (cycles == curr) {
      cout << cycles << " " << curr << "\n";
    } else {
      cout << cycles + 1 << " " << curr << "\n";
    }
  }
}
