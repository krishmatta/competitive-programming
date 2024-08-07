#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;
using str = string;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto& a: x)

#define YES cout << "YES" << "\n";
#define NO cout << "NO" << "\n";

#define tst int t; cin >> t; while(t--)

const int dr[4] = {1, 0, -1, 0}, dc[4] = {0, 1, 0, -1};

const int MOD = 1e9+7;
const int INF = 1e9;

void vin(int n, vi& a) {
  rep(n) {
    int ai; cin >> ai;
    a.pb(ai);
  }
}

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0);
  if (sz(name)) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

vector<ll> fact(2, 1);

ll gcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll x1, y1;
  ll d = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

ll inverse(ll x) {
  ll none, ret;
  gcd(x, MOD, ret, none);
  return (ret % MOD + MOD) % MOD;
}

ll choose(ll n, ll k) {
  if (k > n) {
    return 0;
  }
  return (fact[n] * inverse((fact[k] * fact[n - k]) % MOD)) % MOD;
}

int main() {
  setIO();

  while(sz(fact) < 2 * 100000 + 1) {
    fact.pb((sz(fact) * fact[sz(fact) - 1]) % MOD);
  }

  tst {
    ll n, k; cin >> n >> k;
    vi freq(2, 0);
    rep(n) {
      int x; cin >> x; freq[x]++;
    }
    ll ret = 0;
    FOR(i, (k / 2) + 1, k + 1) {
      if(i <= freq[1] && k - i <= freq[0]) {
	ll num_one = choose(freq[1], i);
	ll num_two = choose(freq[0], k - i);
	ret += (num_one * num_two) % MOD;
	ret %= MOD;
      }
    }
    cout << ret << "\n";
  }
}
