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

  if(n == 1) {
    cout << a[0];
  } else {
    sort(all(a));

    set<int> ret;

    bool good = true;
    int inner = a[0] + a[n-1];
    int l = 1;
    int r = n - 2;
    while(l < r) {
      good = good && ((a[l] + a[r]) == inner);
      r--;
      l++;
    }

    if(l == r) {
      good = false;
    }

    if(good) {
      ret.insert(inner);
    }

    int mx = a[n-1];
    l = 0;
    r = n - 1;
    while(r >= 0 && a[r] == mx) {
      r--;
    }

    if(r == -1) {
      ret.insert(mx);
    } else {
      good = true;
      while(l < r) {
        good = good && ((a[l] + a[r]) == mx);
        r--;
        l++;
      }
    }

    if(l == r) {
      good = false;
    }

    if(good) {
      ret.insert(mx);
    }

    for(int i : ret) {
      cout << i << " ";
    }
  }
}
