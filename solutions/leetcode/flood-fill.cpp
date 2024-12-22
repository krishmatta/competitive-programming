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
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                int newColor) {
    deque<pi> q;
    q.pb(mp(sr, sc));

    vector<vector<bool>> vis(sz(image), vector<bool>(sz(image[0]), false));
    vis[sr][sc] = true;

    while (sz(q)) {
      pi curr = q.front();
      F0R(i, 4) {
        int nr = curr.f + dr[i];
        int nc = curr.s + dc[i];

        if (nr >= 0 && nr < sz(image) && nc >= 0 && nc < sz(image[0]) &&
            image[nr][nc] == image[curr.f][curr.s] && !vis[nr][nc]) {
          q.pb(mp(nr, nc));
          vis[nr][nc] = true;
        }
      }
      image[curr.f][curr.s] = newColor;
      q.pop_front();
    }
    return image;
  }
};
