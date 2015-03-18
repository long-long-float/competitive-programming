#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0;i < (n);i++)
#define all(c) (c).begin(),(c).end()

typedef unsigned int uint;

using namespace std;

vector<int> split(const string &str, char delim){
  istringstream iss(str); string tmp; vector<int> res;
  while(getline(iss, tmp, delim)) {
    int tmp2;
    stringstream ss;
    ss << tmp;
    ss >> tmp2;
    res.push_back(tmp2);
  } 
  return res;
} 

int main() {
  int N, C;
  cin >> N >> C;
  string aa;
  getline(cin, aa); //read end-line
  getline(cin, aa);
  vector<int> a(split(aa, ' '));
  int len = a.size();

  for(int c = 1;c <= C;c++) {
    int ans = 0;
    rep(b, len) {
      bool exist = false;
      for(int e = b;e < len;e++) {
        if(a[e] == c) {
          ans += len - e;
          break;
        }
        //cout << b+1 << " " << e+1 << " " << exist << " " << a[e] << endl;
        ans++;
      }
    }
    cout << ans << endl;
  }

  return 0;
}
