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

  vi sieve(10e5 + 1, 0);
  FOR(i, 2, 10e5 + 1) {
    if (!sieve[i]) {
      for (int j = i; j < 10e5 + 1; j += i) {
        if (!sieve[j]) {
          sieve[j] = i;
        }
      }
    }
  }

  int n, k;
  cin >> n >> k;
  ll ret = 0;
  map<vector<pi>, int> freq;
  rep(n) {
    int ai;
    cin >> ai;
    vector<pi> pf;
    while (ai > 1) {
      int curr = sieve[ai];
      int count = 0;
      while (!(ai % curr)) {
        ai /= curr;
        count++;
      }
      count %= k;
      if (count) {
        pf.pb(mp(curr, count));
      }
    }

    vector<pi> comp;
    each(p, pf) { comp.pb(mp(p.f, k - p.s)); }

    if (freq.find(comp) != freq.end()) {
      ret += freq[comp];
    }

    if (freq.find(pf) == freq.end()) {
      freq[pf] = 0;
    }
    freq[pf]++;
  }
  cout << ret;
}
