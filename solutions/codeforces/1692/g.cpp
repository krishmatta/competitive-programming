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
    vi a; rep(n) { int x; cin >> x; a.pb(x); }
    vi pfix(n, 0);
    FOR(i, 1, n) {
      if(2 * a[i] > a[i - 1]) {
        pfix[i]++;
      }
    }
    FOR(i, 0, n) {
      pfix[i] += pfix[i - 1];
    }

    int l = 0; int r = k;
    int ret = 0;
    while(r < n) {
      if(pfix[r] - pfix[l] == k) {
        ret += 1;
      }
      l++; r++;
    }
    cout << ret << "\n";
    t--;
  }
}
