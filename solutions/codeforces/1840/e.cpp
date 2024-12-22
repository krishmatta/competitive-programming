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
  setIO();

  tst {
    str s1, s2;
    cin >> s1 >> s2;

    int t, q;
    cin >> t >> q;

    int num_off = 0;
    F0R(i, sz(s1)) {
      if (s1[i] != s2[i]) {
        num_off++;
      }
    }

    queue<pi> q1;
    F0R(i, q) {
      if (sz(q1) && q1.front().f == i) {
        int idx = q1.front().s;
        q1.pop();
        if (s1[idx] != s2[idx]) {
          num_off++;
        }
      }

      int type;
      cin >> type;
      if (type == 1) {
        int idx;
        cin >> idx;
        idx--;
        if (s1[idx] != s2[idx]) {
          num_off--;
        }
        q1.push(mp(i + t, idx));
      }
      if (type == 2) {
        int ot, idxo, to, idxt;
        cin >> ot >> idxo >> to >> idxt;
        idxo--;
        idxt--;
        int prev_diff = 0;
        if (s1[idxo] != s2[idxo]) {
          prev_diff++;
        }
        if (s1[idxt] != s2[idxt]) {
          prev_diff++;
        }
        num_off -= prev_diff;

        if (ot == 1 && to == 1) {
          char tmp = s1[idxo];
          s1[idxo] = s1[idxt];
          s1[idxt] = tmp;
        }
        if (ot == 1 && to == 2) {
          char tmp = s1[idxo];
          s1[idxo] = s2[idxt];
          s2[idxt] = tmp;
        }
        if (ot == 2 && to == 1) {
          char tmp = s2[idxo];
          s2[idxo] = s1[idxt];
          s1[idxt] = tmp;
        }
        if (ot == 2 && to == 2) {
          char tmp = s2[idxo];
          s2[idxo] = s2[idxt];
          s2[idxt] = tmp;
        }

        int curr_diff = 0;
        if (s1[idxo] != s2[idxo]) {
          curr_diff++;
        }
        if (s1[idxt] != s2[idxt]) {
          curr_diff++;
        }
        num_off += curr_diff;
      }
      if (type == 3) {
        if (num_off == 0) {
          cout << "YES\n";
        } else {
          cout << "NO\n";
        }
      }
    }
  }
}
