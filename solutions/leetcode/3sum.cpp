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
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(all(nums));

    vector<vi> ret;
    F0R(i, sz(nums)) {
      if (!i || (i && nums[i] != nums[i - 1])) {
        int l = i + 1;
        int r = sz(nums) - 1;
        while (l < r) {
          int sum = nums[i] + nums[l] + nums[r];
          if (sum < 0) {
            l++;
          } else if (sum > 0) {
            r--;
          } else {
            ret.pb(vi{nums[i], nums[l], nums[r]});
            while (l < r && nums[l + 1] == nums[l]) {
              l++;
            }
            while (l < r && nums[r - 1] == nums[r]) {
              r--;
            }
            l++;
            r--;
          }
        }
      }
    }
    return ret;
  }
};
