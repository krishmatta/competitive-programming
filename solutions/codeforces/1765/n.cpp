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
    str xs;
    cin >> xs;
    int k;
    cin >> k;

    vi x;
    F0R(i, sz(xs)) x.pb(xs[i] - '0');
    vector<vi> right;
    vector<vi> right_zero;
    rep(10) {
      vi curr, curr_zero;
      rep(sz(x)) curr.pb(sz(x));
      rep(sz(x)) curr_zero.pb(sz(x));
      right.pb(curr);
      right_zero.pb(curr_zero);
    }

    FOR(i, 1, sz(x)) {
      int curr = x[i];
      F0R(j, 10) {
        if (j > curr) right[j][i - 1] = i;
      }

      if (curr) {
        F0R(j, 10) {
          if (j == 0 || j > curr) right_zero[j][i - 1] = i;
        }
      }
    }

    F0R(i, 10) {
      int curr = sz(x);
      int curr_zero = sz(x);
      R0F(j, sz(x)) {
        curr = min(curr, right[i][j]);
        curr_zero = min(curr_zero, right_zero[i][j]);
        right[i][j] = curr;
        right_zero[i][j] = curr_zero;
      }
    }

    vi ret;
    bool ignore_zero = true;
    for (int i = 0; i < sz(x); i++) {
      if (ignore_zero) {
        if (right_zero[x[i]][i] - i <= k) {
          k--;
        } else {
          ret.pb(x[i]);
          ignore_zero = false;
        }
      } else {
        if (right[x[i]][i] - i <= k) {
          k--;
        } else {
          ret.pb(x[i]);
        }
      }
    }

    each(digit, ret) cout << digit;
    cout << "\n";
  }
}
