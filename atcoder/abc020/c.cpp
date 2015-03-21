#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0;i < (n);i++)
#define all(c) (c).begin(),(c).end()

typedef unsigned int uint;

using namespace std;

char field[11][11];
bool visited[10][10];
tuple<int, int> s;
int H, W, T;

int solve(int x, int y, int dot, int sharp) {
  if(dot + sharp > T) return -1;

  if(field[y][x] == 'G') {
    if(sharp == 0) return -1;
    return (T - dot) / sharp;
  }

  int res = -1;
  int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};
  rep(i, 4) {
    int tx = x + dx[i], ty = y + dy[i];
    if(tx < 0 || W <= tx || ty < 0 || H <= ty) continue;
    if(visited[tx][ty]) continue;

    visited[tx][ty] = true;
    int isSharp = field[ty][tx] == '#' ? 1 : 0;
    res = max(res, solve(tx, ty, dot + (1 - isSharp), sharp + isSharp));
    visited[tx][ty] = false;
  }
  return res;
}

int main() {
  cin >> H >> W >> T;

  rep(h, H) {
    rep(w, W) {
      cin >> field[h][w];
      if(field[h][w] == 'S') {
        get<0>(s) = h; get<1>(s) = w;
      }
    }
  }

  cout << solve(get<0>(s), get<1>(s), 0, 0) << endl;

  return 0;
}
