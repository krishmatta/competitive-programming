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
    ll n, c, d; cin >> n >> c >> d;
    vector<ll> a;
    F0R(i, n) {
      ll ai; cin >> ai; a.pb(ai);
    }

    sort(all(a)); reverse(all(a));

    ll sum = 0;
    F0R(i, min(d, n)) {
      sum += a[i];
    }
    if(sum >= c) {
      cout << "Infinity";
    } else if(a[0] * d < c) {
      cout << "Impossible";
    } else {
      ll lo = 0;
      ll hi = d;
      while(lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;

	sum = 0;
	F0R(i, min(n, mid + 1)) sum += a[i];
	sum *= (d / (mid + 1));
	F0R(i, min(n, d % (mid + 1))) sum += a[i];
	if(sum >= c) {
          lo = mid;
	} else {
          hi = mid - 1;
	}
      }
      cout << lo;
    }
    cout << "\n";
  }
}
