#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0;i < (n);i++)
#define all(c) (c).begin(),(c).end()

typedef unsigned int uint;
typedef long long ll;

using namespace std;

ll combination_of_2(int n) {
  if(n < 2) return 0;

  ll c = 1;
  rep(i, 2){ c *= n - i; }
  return c / 2;
}

int main() {
  int N;
  cin >> N;

  bool increase = false;
  int seq_length = 1;

  ll ans = N;

  int pa;
  cin >> pa;
  rep(i, N - 1) {
    int a;
    cin >> a;

    increase = a > pa;
    if(increase) {
      seq_length++;
    } else {
      ans += combination_of_2(seq_length);
      seq_length = 1;
    }

    pa = a;
  }


  if(increase) {
    ans += combination_of_2(seq_length);
  }

  cout << ans << endl;

  return 0;
}
