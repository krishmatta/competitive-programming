#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int INF = 1e9;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

int n;
vector<int> a;

vector<vector<int> > children;

bool check(int i, long long val) {
  if(val > 2e9) {
    return false;
  }

  if(sz(children[i]) == 0) {
    return (long long) a[i] >= val;
  }

  bool ret = true;
  for(int j = 0; j < sz(children[i]); j++) {
    ret = ret && check(children[i][j], val + max(0LL, val - (long long) a[i]));
  }
  return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
      a.clear(); children.clear();
      cin >> n;
      for(int i = 0; i < n; i++) {
	int ai; cin >> ai;
	a.push_back(ai);

	children.push_back(vector<int>());
      }

      for(int i = 1; i < n; i++) {
	int pi; cin >> pi; pi--;
	children[pi].push_back(i);
      }

      int lo = 0;
      int hi = 2e9;
      while(lo < hi) {
	int mid = lo + (hi - lo + 1) / 2;
	bool ret = true;
	for(int i = 0; i < sz(children[0]); i++) {
	  ret = ret && check(children[0][i], max(0, mid - a[0]));
	}

	if(ret) {
	  lo = mid;
	} else {
	  hi = mid - 1;
	}
      }
      cout << lo << "\n";
    }
}
