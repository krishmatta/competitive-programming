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
    int num_zero = 0;
    int num_ones = 0;
    for(int i = 0; i < n; i++) {
      int si; cin >> si;
      if(si == 0) {
        num_zero++;
      } else if(si == 1) {
        num_ones++;
      } else {
        ret += si;
      }
    }

    ret += 2 * min(num_zero, num_ones);
    ret += num_ones - min(num_zero, num_ones);
    ret += num_zero - min(num_zero, num_ones);
    cout << ret << "\n";
  }
}
