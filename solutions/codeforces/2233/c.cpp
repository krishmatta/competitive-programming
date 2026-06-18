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
    int n, k; cin >> n >> k;
    string s; cin >> s;

    vector<int> ret(n, 0);
    for(int i = 0; i < k; i++) {
      int mn_open = INF;
      for(int i = 0; i < n; i++) {
        if(!ret[i] && s[i] == '(') {
          mn_open = i;
          break;
        }
      }

      vector<int> stack;
      for(int j = 0; j < n; j++) {
        if(ret[j]) {
          continue;
        }

        if(s[j] == '(') {
          stack.push_back(j);
        } else {
          if(sz(stack)) {
            stack.pop_back();
          }
        }
      }

      if(sz(stack) && stack[0] == mn_open) {
        for(int j = n - 1; j > -1; j--) {
          if(!ret[j] && s[j] == ')') {
            ret[j] = 1;
            break;
          }
        }
      } else {
        for(int j = 0; j < n; j++) {
          if(!ret[j] && s[j] == '(') {
            ret[j] = 1;
            break;
          }
        }
      }
    }

    for(int i = 0; i < n; i++) {
      cout << ret[i];
    }
    cout << "\n";
  }
}
