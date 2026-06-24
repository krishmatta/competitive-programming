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
    vector<ll> a(n, 0);

    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }

    int i = 0;
    while(i < n - 1) {
      if(a[i] > a[i+1]) {
        swap(a[i], a[i+1]);
        a[i+1] += a[i];
      }

      i++;
    }

    cout << a[n-1] << "\n";
  }
}
