#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0;i < (n);i++)
#define all(c) (c).begin(),(c).end()

typedef unsigned int uint;
typedef unsigned long long ull;

using namespace std;

const int MAX = 1000000007;
map<tuple<int, int>, int> memo;

int gcd(int m, int n) {
  if(m < n) swap(m, n);

  auto key = make_tuple(m, n);
  if(memo.find(key) != memo.end()) {
    return memo[key];
  }
  int ret = (n == 0 ? m : gcd(n, m % n));
  memo[key] = ret;
  return ret;
}

int lcm(int m, int n) {
  return m * n / gcd(m, n);
}

int main() {
  long long N, K;
  cin >> N >> K;

  long long ans = 0;
  rep(i, N + 1) {
    ans += lcm(i, K);
  }
  cout << ans % MAX << endl;

  return 0;
}
