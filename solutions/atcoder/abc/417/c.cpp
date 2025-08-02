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

  int n; cin >> n;
  vector<int> a(n, 0);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll ret = 0;
  map<int, int> curr;
  for(int i = 0; i < n; i++) {
    int diff = (i + 1) - a[i];
    int sum = (i + 1) + a[i];

    if(curr.find(diff) != curr.end()) {
      ret += curr[diff];
    }

    if(curr.find(sum) == curr.end()) {
      curr[sum] = 0;
    }
    curr[sum]++;
  }
  cout << ret;
}
