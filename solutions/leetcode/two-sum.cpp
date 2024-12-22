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

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vi ret;
    map<int, int> prev;
    F0R(i, sz(nums)) {
      if (prev.find(target - nums[i]) == prev.end()) {
        prev[nums[i]] = i;
      } else {
        ret.pb(i);
        ret.pb(prev[target - nums[i]]);
      }
    }
    return ret;
  }
};
