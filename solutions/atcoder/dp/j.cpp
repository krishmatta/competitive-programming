#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

long double dp[301][301][301];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<int> a(n, 0);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= n - i; j++) {
      for(int k = 0; k <= n - i - j; k++) {
        dp[k][j][i] = 1.0;
        if(k > 0) {
          dp[k][j][i] += ((long double) k / n) * dp[k-1][j][i];
        }
        if(j > 0) {
          dp[k][j][i] += ((long double) j / n) * dp[k+1][j-1][i];
        }
        if(i > 0) {
          dp[k][j][i] += ((long double) i / n) * dp[k][j+1][i-1];
        }

        int l = n - i - j - k;
        if(l < n) {
          dp[k][j][i] /= (1.0 - ((long double) l / n));
        }

        if(l == n) {
          dp[k][j][i] = 0.0;
        }
      }
    }
  }

  vector<int> count(4, 0);
  for(int ai : a) {
    count[ai]++;
  }

  cout << fixed << setprecision(15) << dp[count[1]][count[2]][count[3]] << "\n";
}
