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

#define tst int t; cin >> t; while(t--)

const int dr[4] = {1, 0, -1, 0}, dc[4] = {0, 1, 0, -1};

const int MOD = 1e9+7;
const int INF = 1e9;

void vin(int n, vi& a) {
  rep(n) {
    int ai; cin >> ai;
    a.pb(ai);
  }
}

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0);
  if (sz(name)) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

int main() {
  setIO();

  tst {
    int n, m; cin >> n >> m;
    vector<vi> a;
    F0R(i, n) {
      vi ai;
      F0R(j, m) {
	int aij; cin >> aij;
	ai.pb(aij);
      }
      a.pb(ai);
    }

    int gcd = __gcd(a[0][0], a[n-1][m-1]);

    vector<vector<bool>> dp(n, vector<bool>(m));

    int i = 1;
    int ret = 1;
    while(i * i <= gcd) {
      if(gcd % i == 0 && (i > ret || (gcd / i) > ret)) {
	F0R(j, n) {
	  F0R(k, m) {
	    dp[j][k] = false;
	  }
	}

	dp[0][0] = true;
	F0R(j, n) {
	  F0R(k, m) {
	    if(!dp[j][k] && (a[j][k] % i == 0)) {
	      int nj = j - 1;
	      int nk = k - 1;
	      if(nj >= 0) {
		dp[j][k] = dp[j][k] || dp[nj][k];
	      }

	      if(nk >= 0) {
		dp[j][k] = dp[j][k] || dp[j][nk];
	      }
	    }
	  }
	}

	if(dp[n-1][m-1]) {
	  ret = max(ret, i);
	}

	F0R(j, n) {
	  F0R(k, m) {
	    dp[j][k] = false;
	  }
	}

	dp[0][0] = true;
	F0R(j, n) {
	  F0R(k, m) {
	    if(!dp[j][k] && (a[j][k] % (gcd / i) == 0)) {
	      int nj = j - 1;
	      int nk = k - 1;
	      if(nj >= 0) {
		dp[j][k] = dp[j][k] || dp[nj][k];
	      }

	      if(nk >= 0) {
		dp[j][k] = dp[j][k] || dp[j][nk];
	      }
	    }
	  }
	}

	if(dp[n-1][m-1]) {
	  ret = max(ret, gcd / i);
	}
      }
      i++;
    }

    cout << ret << "\n";
  }
}
