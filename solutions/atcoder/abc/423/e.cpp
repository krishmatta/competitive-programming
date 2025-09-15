#include <vector>
#include <iostream>

int main() {
  int n, q; std::cin >> n >> q;
  std::vector<long long> a(n, 0LL);
  for(int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::vector<long long> prefix(1, 0);
  for(int i = 0; i < n; i++) {
    prefix.push_back(prefix[i] + a[i]);
  }
  std::vector<long long> prefix_prefix(1, 0);
  std::vector<long long> prefix_inc(1, 0);
  std::vector<long long> prefix_dec(1, 0);
  for(int i = 0; i < n + 1; i++) {
    prefix_prefix.push_back(prefix_prefix[i] + prefix[i]);
    prefix_inc.push_back(prefix_inc[i] + i * prefix[i]);
    prefix_dec.push_back(prefix_dec[i] - (n + 1 - i) * prefix[i]);
  }

  for(int i = 0; i < q; i++) {
    int li, ri; std::cin >> li >> ri;
    long long ret = 0;
    ret += (prefix_inc[ri+1] - prefix_inc[li-1]) - (li - 1) * (prefix_prefix[ri+1] - prefix_prefix[li-1]);
    ret += (prefix_dec[ri+1] - prefix_dec[li-1]) + (n - (ri - 1)) * (prefix_prefix[ri+1] - prefix_prefix[li-1]);
    std::cout << ret << "\n";
  }
}
