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

  int n;
  cin >> n;
  if (1 < n && n < 4) {
    cout << "NO SOLUTION";
  } else {
    for (int i = 2; i <= n; i += 2) {
      cout << i << " ";
    }
    for (int i = 1; i <= n; i += 2) {
      cout << i << " ";
    }
  }
}
