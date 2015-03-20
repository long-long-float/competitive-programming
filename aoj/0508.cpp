#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0;i < (n);i++)
#define all(c) (c).begin(),(c).end()

#define INF INT_MAX

typedef unsigned int uint;

using namespace std;

int table[100][100];
bool visited[100];

int solve(int start, int dist) {
  int res = -1;
  rep(i, 100) {
    if(visited[i] || table[start][i] == 0) continue;

    visited[i] = true;
    res = max(res, solve(i, dist + 1));
    visited[i] = false;
  }
  if(res == -1) return dist;
  return res;
}

int main() {
  while(true) {
    int n;
    cin >> n;
    if(n == 0) break;

    memset(table, 0, 100 * 100 * sizeof(int));
    memset(visited, 0, 100 * sizeof(bool));

    rep(i, n) {
      int a, b;
      cin >> a >> b;
      a--; b--;
      table[a][b] = table[b][a] = 1;
    }

    int ans = 0;

    rep(i, 100) {
      bool indep = true;
      rep(j, 100) {
        if(table[i][j] != 0) {
          indep = false;
          break;
        }
      }
      if(indep) continue;

      visited[i] = true;
      ans = max(solve(i, 0), ans);
      visited[i] = false;
    }

    cout << ans + 1 << endl;
  }
  return 0;
}
