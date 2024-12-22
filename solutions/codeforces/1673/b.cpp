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
    str s;
    cin >> s;
    map<char, vi> m;
    F0R(i, sz(s)) {
      if (m.find(s[i]) == m.end()) {
        m[s[i]] = vi(sz(s), -1);
      }
      m[s[i]][i] = i;
    }

    vector<pi> cycle;

    each(i, m) {
      FOR(j, 1, sz(i.s)) {
        i.s[j] = max(i.s[j], i.s[j - 1]);
        if (i.s[j] != i.s[j - 1] && i.s[j - 1] != -1) {
          cycle.pb(mp(i.s[j - 1], i.s[j]));
        }
      }
    }

    bool ret = true;
    each(i, cycle) {
      each(j, m) {
        if (j.f != s[i.f]) {
          if (j.s[i.s] < i.f) {
            ret = false;
          }
        }
      }
    }

    if (ret) {
      YES
    } else {
      NO
    }
  }
}
