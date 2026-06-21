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
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> b(n, 0);
    for(int i = 0; i < n; i++) {
      cin >> b[i];
    }

    int ret = 0;
    bool good = true;
    for(int i = 0; i < n; i++) {
      int j = i;
      while(j < n && a[j] > b[i]) {
        j++;
      }

      if(j >= n) {
        cout << -1 << "\n";
        good = false;
        break;
      }

      while(j > i) {
        ret++;
        swap(a[j], a[j-1]);
        j--;
      }
    }

    if(good) {
      cout << ret << "\n";
    }
  }
}
