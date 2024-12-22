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

void gen(vector<pi>& rng, str s) {
  F0R(i, sz(s)) {
    if (sz(rng) && s[rng[sz(rng) - 1].f] == s[i]) {
      rng[sz(rng) - 1].s = i;
    } else {
      rng.pb(mp(i, i));
    }
  }
}

int main() {
  setIO();

  str s, t;
  cin >> s >> t;
  vector<pi> srng;
  vector<pi> trng;
  gen(srng, s);
  gen(trng, t);

  bool ret = sz(srng) == sz(trng);
  F0R(i, min(sz(srng), sz(trng))) {
    if (s[srng[i].f] != t[trng[i].f]) {
      ret = false;
    } else {
      if (trng[i].s - trng[i].f < srng[i].s - srng[i].f) {
        ret = false;
      }

      if (trng[i].s - trng[i].f && !(srng[i].s - srng[i].f)) {
        ret = false;
      }
    }
  }

  if (ret) {
    cout << "Yes" << "\n";
  } else {
    cout << "No" << "\n";
  }
}
