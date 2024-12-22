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
    int n;
    cin >> n;
    vi a;
    vin(n, a);
    map<int, ll> freq;
    each(x, a) {
      if (freq.find(x) == freq.end()) {
        freq[x] = 0;
      }
      freq[x]++;
    }

    ll ret = 0;
    each(x, freq) {
      if (x.s >= 3) {
        ret += x.s * (x.s - 1) * (x.s - 2);
      }

      vector<ll> divisors;
      for (int i = 2; i * i <= x.f; i++) {
        if (x.f % i == 0) {
          divisors.pb((ll)i);
          if (i * i < x.f) divisors.pb((ll)x.f / (ll)i);
        }
      }

      each(y, divisors) {
        if (x.f % (y * y) == 0) {
          int a = x.f / y;
          int b = a / y;
          if (freq.find(a) != freq.end() && freq.find(b) != freq.end()) {
            ret += freq[a] * freq[b] * x.s;
          }
        }
      }
    }
    cout << ret << "\n";
  }
}
