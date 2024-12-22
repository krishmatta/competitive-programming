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
  long long true_sum = (n * (n + 1)) / 2;
  long long sum = 0;
  for (int i = 0; i < n - 1; i++) {
    long long x;
    cin >> x;
    sum += x;
  }
  cout << true_sum - sum;
}
