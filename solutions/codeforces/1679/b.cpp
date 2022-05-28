#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;
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

  ll n, q; cin >> n >> q;
  vector<ll> arr(n, 0);
  vector<ll> last(n, 0);
  ll ret = 0;
  F0R(i, n) {
    ll x; cin >> x;
    arr[i] = x;
    ret += arr[i];
  }

  ll curr_step = 0;
  ll curr_num = 0;
  rep(q) {
    ll t; cin >> t;
    if(t == 1) {
      ll i, x; cin >> i >> x; i--;
      if(last[i] == curr_step) {
        ret -= arr[i];
      } else {
        ret -= curr_num;
      }
      arr[i] = x;
      ret += arr[i];
      last[i] = curr_step;
    } else {
      ll x; cin >> x;
      curr_step += 1;
      curr_num = x;
      ret = x * n;
    }
    cout << ret << "\n";
  }
}
