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

ll binpow(ll b, ll e) {
  ll ret = 1;
  while (e > 0) {
    if (e & 1) ret = ret * b % MOD;
    b = b * b % MOD;
    e >>= 1;
  }
  return ret;
}

int main() {
  setIO();

  tst {
    int n, k;
    cin >> n >> k;
    vi a;
    vin(n, a);
    vector<vector<ll>> dp;
    F0R(i, 64) {
      vector<ll> curr(n + 1, 0);
      dp.pb(curr);
    }

    F0R(i, n) {
      dp[a[i]][i + 1]++;
      dp[a[i]][i + 1] %= MOD;
      F0R(j, 64) {
        dp[j][i + 1] += dp[j][i];
        dp[j][i + 1] %= MOD;
        dp[a[i] & j][i + 1] += dp[j][i];
        dp[a[i] & j][i + 1] %= MOD;
      }
    }

    ll ret = 0;
    F0R(i, 64) {
      int curr = i;
      int count = 0;
      while (curr) {
        if (curr & 1) {
          count++;
        }
        curr >>= 1;
      }

      if (count == k) {
        ret += dp[i][n];
        ret %= MOD;
      }
    }
    cout << ret << "\n";
  }
}
