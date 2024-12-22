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

vector<vi> adj;
str bw;
int ret;
vector<pi> dp;

void solve(int curr) {
  pi wb = mp(0, 0);
  if (bw[curr] == 'W') {
    wb.f += 1;
  } else {
    wb.s += 1;
  }

  each(i, adj[curr]) {
    if (dp[i].f == -1) {
      solve(i);
    }
    wb.f += dp[i].f;
    wb.s += dp[i].s;
  }

  dp[curr] = wb;
  if (wb.f == wb.s) {
    ret += 1;
  }
}

int main() {
  setIO();

  tst {
    int n;
    cin >> n;
    rep(n) {
      adj.pb(vi());
      dp.pb(mp(-1, -1));
    }
    F0R(i, n - 1) {
      int pi;
      cin >> pi;
      pi--;
      adj[pi].pb(i + 1);
    }
    cin >> bw;
    solve(0);
    cout << ret << "\n";
    adj.clear();
    dp.clear();
    ret = 0;
  }
}
