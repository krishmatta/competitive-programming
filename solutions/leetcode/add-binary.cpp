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
  string addBinary(string a, string b) {
    int prev = 0;
    int currA = sz(a) - 1;
    int currB = sz(b) - 1;
    str ret;
    while(currA > -1 || currB > -1 || prev) {
      int currSum = prev;
      if(currA > -1) {
        currSum += a[currA] - '0';
        currA--;
      }
      if(currB > -1) {
        currSum += b[currB] - '0';
        currB--;
      }

      ret += char(currSum % 2 + '0');
      prev = currSum / 2;
    }
    reverse(all(ret));
    return ret;
  }
};
