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
    ll n, k, q;
    cin >> n >> k >> q;

    vector<ll> a;
    a.pb(0);
    rep(k) {
      ll ai;
      cin >> ai;
      a.pb(ai);
    }

    vector<ll> b;
    b.pb(0);
    rep(k) {
      ll bi;
      cin >> bi;
      b.pb(bi);
    }

    rep(q) {
      ll qi;
      cin >> qi;

      int lo = 0;
      int hi = k;
      while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;

        if (a[mid] <= qi) {
          lo = mid;
        } else {
          hi = mid - 1;
        }
      }

      if (qi == a[lo]) {
        cout << b[lo] << " ";
      } else {
        ll ret =
            b[lo] + ((qi - a[lo]) * (b[lo + 1] - b[lo])) / (a[lo + 1] - a[lo]);
        cout << ret << " ";
      }
    }
    cout << "\n";
  }
}
