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
    int n, a, b; cin >> n >> a >> b;
    if((b - a) % 2 == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
