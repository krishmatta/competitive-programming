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
    int n;
    cin >> n;
    int numP = 0, numN = 0, numZ = 0;
    vi a;
    rep(n) {
      int ai;
      cin >> ai;
      if (ai > 0) {
        a.pb(ai);
        numP++;
      } else if (!ai) {
        if (numZ < 2) {
          a.pb(ai);
        }
        numZ++;
      } else {
        a.pb(ai);
        numN++;
      }
    }

    bool ret = true;
    if (numP <= 2 && numN <= 2) {
      F0R(i, sz(a)) {
        FOR(j, i + 1, sz(a)) {
          FOR(k, j + 1, sz(a)) {
            bool curr = false;
            F0R(l, sz(a)) {
              if (a[i] + a[j] + a[k] == a[l]) {
                curr = true;
              }
            }
            if (!curr) {
              ret = false;
            }
          }
        }
      }
    } else {
      ret = false;
    }

    if (ret) {
      YES
    } else {
      NO
    }
    t--;
  }
}
