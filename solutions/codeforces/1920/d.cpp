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

int main() {
  setIO();

  tst {
    vi a;
    vector<ll> szs(1, 0);
    vector<pi> ops; ops.pb(mp(-1, -1));

    int n, q; cin >> n >> q;
    rep(n) {
      ll b, x; cin >> b >> x;
      if(b == 1) {
	a.pb(x);
	szs.pb(szs[sz(szs) - 1] + 1);
	ops.pb(mp(1, sz(a)));
      } else {
	if((x + 1) > 2e18 / szs[sz(szs) - 1]) {
	  szs.pb((ll) 2e18);
	} else {
	    szs.pb(szs[sz(szs) - 1] * (x + 1));
	}
	ops.pb(mp(2, sz(a)));
      }
    }

    rep(q) {
      ll ki; cin >> ki;
      while(true) {
	int lo = 0;
	int hi = sz(szs);
	while(lo < hi) {
	  int mid = lo + (hi - lo) / 2;
	  if(ki <= szs[mid]) {
	    hi = mid;
	  } else {
	    lo = mid + 1;
	  }
	}

	int b = ops[lo].f;
	if(b == 1) {
	  ll idx = ops[lo].s - 1;
	  cout << a[idx] << " ";
	  break;
	} else {
	  ki = ((ki - 1) % szs[lo - 1]) + 1;
	}
      }
    }
    cout << "\n";
  }
}
