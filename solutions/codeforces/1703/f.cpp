#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;
using str = string;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto& a : x)

#define YES cout << "YES" << "\n";
#define NO cout << "NO" << "\n";

#define tst \
  int t;    \
  cin >> t; \
  while (t--)

const int dr[4] = {1, 0, -1, 0}, dc[4] = {0, 1, 0, -1};

const int MOD = 1e9 + 7;
const int INF = 1e9;

void vin(int n, vi& a) {
  rep(n) {
    int ai;
    cin >> ai;
    a.pb(ai);
  }
}

void setIO(string name = "") {
  cin.tie(0)->sync_with_stdio(0);
  if (sz(name)) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

struct segtree {
  int n;
  vector<int> t;

  segtree(int pn) {
    n = pn;
    t.assign(2 * n, 0);
    for (int i = n - 1; i > 0; i--) t[i] = t[i << 1] + t[i << 1 | 1];
  }

  void set(int i, int v) {
    for (t[i += n] = v; i > 1; i >>= 1) t[i >> 1] = t[i] + t[i ^ 1];
  }

  int get(int l, int r) {
    int ret = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ret += t[l++];
      if (r & 1) ret += t[--r];
    }
    return ret;
  }
};

int main() {
  setIO();

  tst {
    int n;
    cin >> n;
    vector<pi> nums;
    F0R(i, n) {
      int x;
      cin >> x;
      if (x < i + 1) {
        nums.pb(mp(x, i + 1));
      }
    }
    sort(all(nums));

    ll ret = 0;
    segtree st(n + 1);
    ll run = 0;
    F0R(i, sz(nums)) {
      if (!i && nums[i].f != nums[i - 1].f) {
        run = 0;
      }
      int curr = st.get(0, nums[i].f);
      ret += st.get(0, nums[i].f);
      st.set(nums[i].s, 1);
      if (!i && nums[i].f == nums[i - 1].f) {
        run += 1;
      }
    }
    cout << ret << "\n";
  }
}
