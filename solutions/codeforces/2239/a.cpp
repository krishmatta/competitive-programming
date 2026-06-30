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
    int xr = 0;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      xr ^= a[i];
    }

    int ret = 0;
    for(int i = 0; i < n; i++) {
      if(((xr ^ a[i]) < a[i]) && n > 1) {
        ret++;
      }
    }

    if(n > 1 && xr == 0) {
      ret++;
    }

    cout << ret << "\n";
  }
}
