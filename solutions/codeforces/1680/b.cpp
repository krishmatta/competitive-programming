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

const int dr[4] = {1, 0, -1, 0}, dc[4] = {0, 1, 0, -1};

const int MOD = 1e9 + 7;
const int INF = 1e9;

void setIO(string name = "") {
  cin.tie(0)->sync_with_stdio(0);
  if (sz(name)) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

int main() {
  setIO();

  int t;
  cin >> t;
  while (t) {
    int n, m;
    cin >> n >> m;

    int minR = INF;
    int minC = INF;
    vector<pi> coords;
    F0R(i, n) {
      str curr;
      cin >> curr;
      F0R(j, m) {
        if (curr[j] == 'R') {
          coords.pb(mp(i, j));
          minR = min(minR, i);
          minC = min(minC, j);
        }
      }
    }

    bool ret = false;
    each(i, coords) {
      if (i.f == minR && i.s == minC) {
        ret = true;
      }
    }

    if (ret) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << "\n";
    t--;
  }
}
