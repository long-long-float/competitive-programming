#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0;i < (n);i++)
#define all(c) (c).begin(),(c).end()

typedef unsigned int uint;

using namespace std;

int main() {
  string str;
  cin >> str;
  cout << (str[str.size() - 1] == 'T' ? "YES" : "NO") << endl;
  return 0;
}
