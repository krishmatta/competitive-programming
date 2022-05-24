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
  int maxDepth(TreeNode* root) {
    deque<TreeNode*> s;
    if(root) {
      s.pb(root);
    }

    int ret = 0;
    map<TreeNode*, int> m;
    while(sz(s)) {
      TreeNode* curr = s.back();
      if((!curr->left || m.find(curr->left) != m.end()) && (!curr->right || m.find(curr->right) != m.end())) {
        int l = curr->left ? m[curr->left] : 0;
        int r = curr->right ? m[curr->right] : 0;

        m[curr] = max(l, r) + 1;
        ret = max(ret, m[curr]);
        s.pop_back();
      } else {
        if(curr->left && m.find(curr->left) == m.end()) {
          s.pb(curr->left);
        }

        if(curr->right && m.find(curr->right) == m.end()) {
          s.pb(curr->right);
        }
      }
    }
    return ret;
  }
};
