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
    int n; cin >> n;

    int curr_g = 0;
    int curr_w = 0;
    map<str, int> g_map;
    map<str, int> w_map;
    vector<pi> gw;

    rep(n) {
      str gi, wi; cin >> gi >> wi;
      if(g_map.find(gi) == g_map.end()) {
	g_map[gi] = curr_g;
	curr_g++;
      }

      if(w_map.find(wi) == w_map.end()) {
	w_map[wi] = curr_w;
	curr_w++;
      }

      gw.pb(mp(g_map[gi], w_map[wi]));
    }

    vector<vector<bool>> dp(n, vector<bool>(1 << n, false));
    F0R(i, n) {
      dp[i][1 << i] = true;
    }

    int ret = 1;

    F0R(i, 1 << n) {
      F0R(j, n) {
	if(i & (1 << j)) {
	  F0R(k, n) {
	    if(j != k && i & (1 << k) && (gw[j].f == gw[k].f || gw[j].s == gw[k].s) && dp[k][i ^ (1 << j)]) {
	      dp[j][i] = true;
	      break;
	    }
	  }
	}
      }
    }

    F0R(i, 1 << n) {
      F0R(j, n) {
	if(dp[j][i]) {
	  int curr = 0;
	  F0R(k, n) {
	    if(i & (1 << k)) {
	      curr++;
	    }
	  }
	  ret = max(ret, curr);
	}
      }
    }

    cout << n - ret << "\n";
  }
}
