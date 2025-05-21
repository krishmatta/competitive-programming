#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

vector<vector<int>> dp(2, vector<int>(2001, INF));
vector<vector<pair<int, pair<bool, bool>>>> out(2, vector<pair<int, pair<bool, bool>>>(2001, make_pair(1, make_pair(false, false))));

void print(int i, int j) {
  pair<int, pair<bool, bool>> curr = out[i][j];

  if(curr.first == j) {
    cout << j;
    return;
  }

  if(curr.second.second) {
    if(curr.second.first) {
      cout << curr.first << "*";
      print(1, j / curr.first);
    } else {
      if(dp[1][curr.first] < dp[0][curr.first] + 2) {
        print(1, curr.first);
        cout << "*";
        print(1, j / curr.first);
      } else {
        cout << "(";
        print(0, curr.first);
        cout << ")*";
        print(1, j / curr.first);
      }
    }
  } else {
    if(curr.second.first) {
      if(i) {
        cout << "(";
      }
      cout << curr.first << "+";
      print(0, j - curr.first);
      if(i) {
        cout << ")";
      }
    } else {
      if(i) {
        cout << "(";
      }
      if(dp[1][curr.first] < dp[0][curr.first] + 2) {
        print(0, curr.first);
        cout << "+";
        print(0, j - curr.first);
      } else {
        cout << "(";
        print(0, curr.first);
        cout << ")+";
        print(0, j - curr.first);
      }
      if(i) {
        cout << ")";
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;

  for(int i = 0; i < 2; i++) {
    dp[i][1] = 1;
  }

  for(int i = 2; i <= n; i++) {
    // Use something with all 1s
    int base = 1;
    int len = 1;
    while(base <= i) {
      int add = len + 1 + dp[0][i - base];
      for(int j = 0; j < 2; j++) {
        if(2 * j + add < dp[j][i]) {
          dp[j][i] = 2 * j + add;
          out[j][i] = make_pair(base, make_pair(true, false));
        }
      }

      if(i % base == 0 && base > 1) {
        int mult = len + 1 + dp[1][i / base];
        for(int j = 0; j < 2; j++) {
          if(mult < dp[j][i]) {
            dp[j][i] = mult;
            out[j][i] = make_pair(base, make_pair(true, true));
          }
        }
      }

      if(base == i) {
        for(int j = 0; j < 2; j++) {
          if(len < dp[j][i]) {
            dp[j][i] = len;
            out[j][i] = make_pair(base, make_pair(true, false));
          }
        }
      }

      base = base * 10 + 1;
      len++;
    }

    // Don't use something with all 1s (need parentheses)
    for(int j = 1; j < i; j++) {
      // Add, wrapping left around parentheses
      int add = 2 + dp[0][j] + 1 + dp[0][i - j];
      for(int k = 0; k < 2; k++) {
        if(2 * k + add < dp[k][i]) {
          dp[k][i] = 2 * k + add;
          out[k][i] = make_pair(j, make_pair(false, false));
        }
      }

      // Add, not wrapping left
      add = dp[1][j] + 1 + dp[0][i - j];
      for(int k = 0; k < 2; k++) {
        if(2 * k + add < dp[k][i]) {
          dp[k][i] = 2 * k + add;
          out[k][i] = make_pair(j, make_pair(false, false));
        }
      }

      // Multiply
      int mult = 2 + dp[0][j] + 1 + dp[1][i / j];
      if(i % j == 0 && j > 1) {
        for(int k = 0; k < 2; k++) {
          if(mult < dp[k][i]) {
            dp[k][i] = min(dp[k][i], mult);
            out[k][i] = make_pair(j, make_pair(false, true));
          }
        }
      }

      mult = dp[1][j] + 1 + dp[1][i / j];
      if(i % j == 0 && j > 1) {
        for(int k = 0; k < 2; k++) {
          if(mult < dp[k][i]) {
            dp[k][i] = min(dp[k][i], mult);
            out[k][i] = make_pair(j, make_pair(false, true));
          }
        }
      }

    }
  }

  print(0, n);
}
