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
    int n, s; cin >> n >> s;
    int sum = 0;
    vector<int> count(3, 0);
    for(int i = 0; i < n; i++) {
      int ai; cin >> ai;
      sum += ai;
      count[ai]++;
    }

    int diff = s - sum;
    bool bad = true;
    if(diff < 0 || diff == 1) {
      bad = false;
    }

    if(bad) {
      cout << -1 << "\n";
    } else {
      vector<int> nums = {0, 2, 1};
      for(auto i : nums) {
        for(int j = 0; j < count[i]; j++) {
          cout << i << " ";
        }
      }
      cout << "\n";
    }
  }
}
