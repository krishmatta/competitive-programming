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
    int n, m; cin >> n >> m;
    vi prev(n, -1);
    rep(m) {
      int a, b; cin >> a >> b; a--; b--;
      if(a < b) {
        prev[b] = max(prev[b], a);
      } else {
        prev[a] = max(prev[a], b);
      }
    }
    ll ret = 0;
    int l = 0;
    FOR(r, 1, n) {
      if(prev[r] >= l) {
        ll tot_len = r - l;
        ll up_len = r - prev[r] - 1;
        ret += (tot_len*(tot_len+1))/2 - (up_len*(up_len+1))/2;
        l = prev[r] + 1;
      }
    }
    ll len = n - l;
    ret += (len*(len+1))/2;
    cout << ret << "\n";
  }
}
