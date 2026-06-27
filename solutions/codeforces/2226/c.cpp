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

    sort(all(a));

    int lo = 0;
    int hi = n;
    while(lo < hi) {
      int mid = lo + (hi - lo + 1) / 2;
      vector<int> used(n, false);
      vector<int> done(mid, false);

      for(int i = 0; i < n; i++) {
        if(a[i] < mid && !done[a[i]]) {
          done[a[i]] = true;
          used[i] = true;
        }
      }

      bool good = true;
      int curr = 0;
      for(int i = 0; i < mid; i++) {
        if(!done[i]) {
          while(curr < n && (a[curr] < 2 * i + 1 || used[curr])) {
            curr++;
          }

          if(curr < n) {
            done[i] = true;
            used[curr] = true;
            curr++;
          } else {
            good = false;
          }
        }
      }

      if(good) {
        lo = mid;
      } else {
        hi = mid - 1;
      }
    }

    cout << lo << "\n";
  }
}
