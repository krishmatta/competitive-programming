#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<int> c(1, 0);
  for(int i = 1; i < n; i++) {
    int ci; cin >> ci;
    c.push_back(ci);
  }
  vector<int> a(1, 0);
  for(int i = 1; i < n; i++) {
    int ai; cin >> ai;
    a.push_back(ai);
  }

  int ret = 0;
  for(int i = n - 1; i > 0; i--) {
    if(a[i]) {
      bool found = false;
      int mn_idx = i;
      int mn_reach = i - c[i];
      for(int j = i - c[i]; j < i; j++) {
	if(a[j]) {
	  found = true;
	  a[j] += a[i];
	  a[i] = 0;
	  break;
	}
	if(j - c[j] < mn_reach) {
	  mn_idx = j;
	  mn_reach = j - c[j];
	}
      }

      if(!found) {
	a[mn_idx] += a[i];
	a[i] = 0;
      }
      ret++;
    }
  }

  cout << ret;
}
