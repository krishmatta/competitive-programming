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

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int curr = 0;
    while(curr < sz(intervals) && intervals[curr][0] < newInterval[0]) {
      curr++;
    }
    intervals.insert(intervals.begin() + curr, newInterval);

    vector<vi> ret;
    each(i, intervals) {
      vi last = sz(ret) ? ret[sz(ret) - 1] : vi{};
      if(sz(ret) && i[0] <= ret[sz(ret) - 1][1]) {
        ret[sz(ret) - 1][1] = max(ret[sz(ret) - 1][1], i[1]);
      } else {
        ret.pb(i);
      }
    }
    return ret;
  }
};
