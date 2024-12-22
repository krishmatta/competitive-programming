#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long n;
  cin >> n;
  while (n > 1) {
    cout << n << " ";
    if (n % 2) {
      n = 3 * n + 1;
    } else {
      n /= 2;
    }
  }
  cout << 1;
}
