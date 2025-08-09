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
  string s; cin >> s;
  string t = "tea";
  bool good = false;
  if(sz(s) >= 3) {
    bool curr_good = true;
    for(int i = 0; i < sz(t); i++) {
      if(s[i+sz(s)-3] != t[i])
        curr_good = false;
    }
    good = curr_good;
  }

  if(good) {
    cout << "Yes";
  } else {
    cout << "No";
  }
}
