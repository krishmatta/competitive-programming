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

int inv(int i) {
  return i <= 1 ? i : MOD - (long long)(MOD/i) * inv(MOD % i) % MOD;
}

int main() {
  setIO();

  tst {
    int n, m; cin >> n >> m;
    vi a;
    map<int, int> freq;
    F0R(i, n) {
      int ai; cin >> ai;
      if(freq.find(ai) == freq.end()) {
        a.pb(ai);
	freq[ai] = 0;
      }
      freq[ai]++;
    }
    sort(all(a));
    
    int curr = 0;
    ll init = 1;
    while(curr < min(m, sz(a))) {
      init *= freq[a[curr]];
      init %= MOD;
      curr++;
    }

    ll ret = 0;
    if(sz(a) >= m && a[m - 1] - a[0] < m) {
      ret += init;
      ret %= MOD;
    }

    while(curr < sz(a)) {
      init *= inv(freq[a[curr - m]]);
      init %= MOD;
      init *= freq[a[curr]];
      init %= MOD;
      if(a[curr] - a[curr - m + 1] < m) {
        ret += init;
	ret %= MOD;
      }
      curr++;
    }

    cout << ret << "\n";
  }
}
