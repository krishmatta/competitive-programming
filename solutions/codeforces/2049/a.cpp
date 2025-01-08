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

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int ret = 0;
    bool zero = true;
    for(int i = 0; i < n; i++) {
      int ai; cin >> ai;
      if(ai == 0) {
	if(!zero) {
	  ret++;
	}
	zero = true;
      } else {
	zero = false;
      }
    }
    if(!zero) {
      ret++;
    }

    cout << min(2, ret) << "\n";
  }
}
