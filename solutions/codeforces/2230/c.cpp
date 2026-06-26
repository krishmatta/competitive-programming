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
    vector<ll> c(n, 0);
    for(int i = 0; i < n; i++) {
      cin >> c[i];
    }

    if(n == 1) {
      if(c[0] >= 3) {
        cout << c[0] << "\n";
      } else {
        cout << "0\n";
      }
    } else {
      sort(all(c));

      ll ret = c[n-1] + c[n-2];
      ll slots = 0;
      if(c[n-1] >= 4) {
        slots += (c[n-1] - 2) / 2;
      }

      if(c[n-2] >= 4) {
        slots += (c[n-2] - 2) / 2;
      }

      int i = n - 3;
      while(i > -1) {
        if(c[i] >= 2) {
          ret += c[i];
          if(c[i] >= 4) {
            slots += (c[i] - 2) / 2;
          }
        } else {
          if(slots) {
            ret += c[i];
            slots--;
          }
        }
        i--;
      }

      if(ret >= 3) {
        cout << ret << "\n";
      } else {
        cout << "0\n";
      }
    }
  }
}
