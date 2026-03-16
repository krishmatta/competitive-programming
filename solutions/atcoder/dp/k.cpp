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
  
  int n, k; cin >> n >> k;
  vector<int> a(n, 0);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  
  vector<bool> dp(k+1, false);
  for(int i = 1; i <= k; i++) {
    for(int ai : a) {
      if(ai <= i && !dp[i-ai]) {
        dp[i] = true;
      }
    }
  }
  
  if(dp[k]) {
    cout << "First";
  } else {
    cout << "Second";
  }
}
