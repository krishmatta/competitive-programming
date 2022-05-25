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

void swap(vector<vi> &a, int idx1, int idx2) {
  F0R(i, sz(a)) {
    a[i][idx1] = a[i][idx1] ^ a[i][idx2];
    a[i][idx2] = a[i][idx2] ^ a[i][idx1];
    a[i][idx1] = a[i][idx1] ^ a[i][idx2];
  }
}

int main() {
  setIO();

  int t; cin >> t;
  while(t) {
    int n, m; cin >> n >> m;
    vector<vi> grid;
    rep(n) {
      grid.pb(vi());
      rep(m) {
        int x; cin >> x;
        grid[sz(grid) - 1].pb(x);
      }
    }

    vi idx_swap;
    each(curr, grid) {
      vi sort_curr = curr;
      sort(all(sort_curr));

      F0R(i, sz(curr)) {
        if(curr[i] != sort_curr[i]) {
          idx_swap.pb(i);
        }
      }
      
      if(sz(idx_swap)) {
        break;
      }
    }

    if(!sz(idx_swap)) {
      cout << 1 << " " << 1;
    } else if(sz(idx_swap) > 2) {
      cout << -1;
    } else {
      swap(grid, idx_swap[0], idx_swap[1]);
      bool done = false;
      F0R(i, n) {
        FOR(j, 1, m) {
          if(grid[i][j] < grid[i][j - 1]) {
            done = true;
            cout << -1;
            break;
          }
        }

        if(done) {
          break;
        }
      }

      if(!done) {
        cout << idx_swap[0] + 1 << " " << idx_swap[1] + 1;
      }
    }
    cout << "\n";
    t--;
  }
}

