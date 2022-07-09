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

void solve() {
  int n, x; cin >> n >> x;
  vi a; vin(n, a);
  sort(all(a));

  ll sum = 0;
  F0R(i, sz(a)) {
    sum += a[i];
  }

  ll ret = 0;
  ll day = 0;
  int curr = sz(a) - 1;
  while(curr >= 0) {
    ll cost = sum + (day * (curr + 1)); // 5
    while(cost > x && curr >= 0) {
      sum -= a[curr];
      curr--;
      cost = sum + (day * (curr + 1));
    }

    if(curr >= 0) {
      cost = sum + (day * (curr + 1));
    }

    ll add = ((x - cost) / (curr + 1)) + 1;
    ret += add * (curr + 1);
    day += add;
  }
  cout << ret << "\n";
}

int main() {
  setIO();

  tst {
    solve();
  }
}
