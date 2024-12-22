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

int main() {
  tst {
    int n;
    cin >> n;
    int mimic_type = 0;
    vi a;
    vin(n, a);
    rep(2) {
      vi prev(10, 0);
      F0R(i, n) { prev[a[i]]++; }

      cout << "- 0\n";

      vi b;
      vin(n, b);

      vi nxt(10, 0);
      F0R(i, n) { nxt[b[i]]++; }

      a = b;

      F0R(i, 10) {
        if (nxt[i] > prev[i]) {
          mimic_type = i;
          break;
        }
      }

      if (mimic_type) {
        break;
      }
    }

    vi del;
    F0R(i, n) {
      if (a[i] != mimic_type) {
        del.pb(i + 1);
      }
    }

    cout << "- " << sz(del);
    each(x, del) { cout << " " << x; }
    cout << "\n";

    n -= sz(del);

    bool done = false;
    a.clear();
    vin(n, a);
    F0R(i, n) {
      if (a[i] != mimic_type) {
        cout << "! " << i + 1 << "\n";
        done = true;
        break;
      }
    }

    if (!done) {
      cout << "- 0\n";

      a.clear();
      vin(n, a);
      F0R(i, n) {
        if (a[i] != mimic_type) {
          cout << "! " << i + 1 << "\n";
          break;
        }
      }
    }
  }
}
