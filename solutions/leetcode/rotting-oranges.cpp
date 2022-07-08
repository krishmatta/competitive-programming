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

class Solution {
public:
  int orangesRotting(vector<vector<int>>& grid) {
    deque<pair<int, pi>> q;
    F0R(i, sz(grid)) {
      F0R(j, sz(grid[0])) {
        if(grid[i][j] == 2) {
          q.pb(mp(0, mp(i, j)));
        }
      }
    }

    int ret = 0;
    while(sz(q)) {
      pair<int, pi> curr = q.front();
      q.pop_front();

      F0R(i, 4) {
        int nr = curr.s.f + dr[i];
        int nc = curr.s.s + dc[i];

        if(nr >= 0 && nr < sz(grid) && nc >= 0 && nc < sz(grid[0]) && grid[nr][nc] == 1) {
          grid[nr][nc] = 0;
          ret = max(ret, curr.f + 1);
          q.pb(mp(curr.f + 1, mp(nr, nc)));
        }
      }
    }

    F0R(i, sz(grid)) {
      F0R(j, sz(grid[0])) {
        if(grid[i][j] == 1) {
          ret = -1;
        }
      }
    }
    return ret;
  }
};
