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
    str s; cin >> s;
    int p; cin >> p;
    vector<pi> si;
    int sum = 0;
    F0R(i, sz(s)) {
      si.pb(mp(s[i] - 'a' + 1, i));
      sum += s[i] - 'a' + 1;
    }
    sort(all(si));

    set<int> rm;
    int curr = sz(si) - 1;
    while(curr >= 0 && sum > p) {
      sum -= si[curr].f;
      rm.insert(si[curr].s);
      curr--;
    }

    str ret = "";
    F0R(i, sz(s)) {
      if(rm.find(i) == rm.end()) {
        ret += s[i];
      }
    }
    cout << ret << "\n";
  }
}
