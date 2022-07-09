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
    map<int, int> freq;
    vi a;
    F0R(i, n) {
      int ai; cin >> ai;
      if(freq.find(ai) == freq.end()) {
        freq[ai] = 0;
      }
      freq[ai]++;
      if(freq[ai] == k) {
        a.pb(ai);
      }
    }
    sort(all(a));

    pi ret = mp(0, 0);
    pi curr = mp(0, 0);
    int prev = -1;
    F0R(i, sz(a)) {
      if(a[i] == prev + 1) {
        curr.s = a[i];
      } else {
        curr = mp(a[i], a[i]);
      }

      if(curr.s - curr.f >= ret.s - ret.f) {
        ret = mp(curr.f, curr.s);
      }
      prev = a[i];
    }
    if(ret.f == 0 && ret.s == 0) {
      cout << -1;
    } else {
      cout << ret.f << " " << ret.s;
    }
    cout << "\n";
    t--;
  }
}
