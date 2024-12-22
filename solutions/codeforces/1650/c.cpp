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
    int n, m;
    cin >> n >> m;
    vector<pair<int, pi>> pts;
    F0R(i, m) {
      int x, w;
      cin >> x >> w;
      pts.pb(mp(w, mp(x, i)));
    }
    sort(all(pts));
    vector<pi> tmp;
    int sum = 0;
    F0R(i, 2 * n) {
      sum += pts[i].f;
      tmp.pb(pts[i].s);
    }
    sort(all(tmp));
    int l = 0;
    int r = sz(tmp) - 1;
    cout << sum << "\n";
    while (l < r) {
      cout << tmp[l].s + 1 << " " << tmp[r].s + 1 << "\n";
      l++;
      r--;
    }
    cout << "\n";
  }
}
