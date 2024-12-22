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
const int INF = 1e9 + 1;

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
    int n;
    cin >> n;

    vector<ll> c;
    F0R(i, n) {
      ll ci;
      cin >> ci;
      c.pb(ci);
    }

    ll k;
    cin >> k;

    vector<ll> cs(n, INF);
    R0F(i, n - 1) {
      cs[i] = cs[i + 1];
      cs[i] = min(cs[i], c[i + 1]);
    }

    vector<ll> ret(n, 0);
    int curr = 0;

    while (true) {
      if (curr == n - 1) {
        if (k < c[curr]) {
          break;
        }

        ret[curr] += k / c[curr];
        k -= (k / c[curr]) * c[curr];
      } else {
        if (k < c[curr] && k < cs[curr]) {
          break;
        }

        if (cs[curr] <= c[curr]) {
          curr++;
          continue;
        }

        ll diff = cs[curr] - c[curr];
        ll rem = k % c[curr];

        ll spend = k / c[curr];

        ret[curr] += spend;
        k -= spend * c[curr];

        ll refund = min(spend, rem / diff);
        ret[curr] -= refund;
        k += c[curr] * refund;
        curr++;
      }
    }

    R0F(i, n - 1) { ret[i] += ret[i + 1]; }

    each(x, ret) { cout << x << " "; }
    cout << "\n";
  }
}
