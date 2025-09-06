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

    int x = 1;
    for(int i = n - 2; i > -1; i--) {
      if(a[i+1] % a[i]) {
        if(a[i+1] % (a[i] / x)) {
          x *= (a[i] / x) / (gcd(a[i] / x, a[i+1]));
        }
        a[i] /= x;
      }
    }

    cout << x << "\n";
  }
}
