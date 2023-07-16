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

map<ll, ll> dp;
vector<ll> layer;

ll sm(ll curr) {
  return (curr * (curr + 1)) / 2;
}

ll solve(ll curr) {
  if(dp.find(curr) == dp.end()) {
    ll curr_layer = layer[curr];
    ll ret = curr * curr;
    if(curr < sm(curr_layer)) {
      ret += solve(curr - curr_layer + 1);
    }
    if(curr > sm(curr_layer - 1) + 1) {
      ret += solve(curr - curr_layer);
    }
    if(curr > sm(curr_layer - 1) + 1 && curr < sm(curr_layer)) {
      ret -= solve(curr - (curr_layer * 2 - 2));
    }
    dp[curr] = ret;
  }
  return dp[curr];
}

int main() {
  setIO();

  dp[1] = 1;
  ll curr = 0;
  F0R(i, 1e6+1) {
    if(sm(curr) < i) {
      curr++;
    }
    layer.pb(curr);
  }

  tst {
    ll curr; cin >> curr;
    cout << solve(curr) << "\n";
  }
}
