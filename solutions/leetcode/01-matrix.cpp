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

class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    vector<vi> ret;
    rep(sz(mat)) { ret.pb(vi(sz(mat[0]), INF)); }

    deque<pair<int, pi>> q;
    F0R(i, sz(mat)) {
      F0R(j, sz(mat[0])) {
        if (!mat[i][j]) {
          q.pb(mp(0, mp(i, j)));
          ret[i][j] = 0;
        }
      }
    }

    while (sz(q)) {
      pair<int, pi> curr = q.front();
      F0R(i, 4) {
        int nr = curr.s.f + dr[i];
        int nc = curr.s.s + dc[i];
        if (nr >= 0 && nc >= 0 && nr < sz(mat) && nc < sz(mat[0]) &&
            ret[nr][nc] == INF) {
          ret[nr][nc] = curr.f + 1;
          q.pb(mp(curr.f + 1, mp(nr, nc)));
        }
      }
      q.pop_front();
    }
    return ret;
  }
};
