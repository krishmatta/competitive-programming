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

  vi sieve(10e6 + 1, 0);
  FOR(i, 2, 10e6 + 1) {
    if (sieve[i] == 0) {
      for (int j = i; j < 10e6 + 1; j += i) {
        sieve[j] = i;
      }
    }
  }

  tst {
    int x;
    cin >> x;
    ll ret = 1;
    while (x > 1) {
      int curr_divisor = sieve[x];
      int curr_count = 0;
      while (x % curr_divisor == 0) {
        x /= curr_divisor;
        curr_count += 1;
      }
      ret *= (curr_count + 1);
    }
    cout << ret << "\n";
  }
}
