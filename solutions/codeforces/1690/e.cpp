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

const int dr[4] = {1, 0, -1, 0}, dc[4] = {0, 1, 0, -1};

const int MOD = 1e9+7;
const int INF = 1e9;

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0);
  if (sz(name)) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

int main() {
  setIO();

  int t; cin >> t;
  while(t) {
    int n, k; cin >> n >> k;
    vector<pair<ll, ll>> a; rep(n) { int x; cin >> x; a.pb(mp(x % k, x)); }
    sort(all(a));
    int lb = k - a[n - 1].f;
    ll ret = 0;
    int r = n - 1;
    F0R(i, r) {
      if(a[i].f < lb) {
        ret += (a[i].s + a[i + 1].s) / k;
        i += 1;
      } else {
        ret += (a[i].s + a[r].s) / k;
        r--;
        lb = k - a[r].f;
      }
    }
    cout << ret << "\n";
    t--;
  }
}
