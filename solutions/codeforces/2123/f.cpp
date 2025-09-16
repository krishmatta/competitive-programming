#include <vector>
#include <iostream>

const int MAXN = 100000 + 2;

int main() {
  std::vector<bool> is_prime(MAXN, true);
  is_prime[0] = is_prime[1] = false;
  for(long long i = 2; i < is_prime.size(); i++) {
    if(is_prime[(size_t) i]) {
      for(long long j = i * i; j < MAXN; j += i) {
        is_prime[(size_t) j] = false;
      }
    }
  }

  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    std::vector<int> ret(n, 0); ret[0] = 1;
    std::vector<bool> vis(n, false);
    for(int i = n; i > 1; i--) {
      if(is_prime[i]) {
        std::vector<int> chain;
        for(int j = i; j <= n; j += i) {
          if(!vis[j-1]) {
            vis[j-1] = true;
            chain.push_back(j);
          }
        }

        for(int j = 0; j < chain.size(); j++) {
          int k = (j + 1) % chain.size();
          ret[chain[j]-1] = chain[k];
        }
      }
    }

    for(int i : ret) {
      std::cout << i << " ";
    }
    std::cout << "\n";
  }
}
