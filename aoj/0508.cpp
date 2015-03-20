#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0;i < (n);i++)
#define all(c) (c).begin(),(c).end()

#define INF INT_MAX

typedef unsigned int uint;

using namespace std;

int table[100][100];

int n;

int solve(int start) {
  stack<tuple<int, set<int>, int>> que; //current_pos, history, distance
  que.push(make_tuple(start, set<int>(), 0));

  int max_dist = -1;
  while(!que.empty()) {
    auto a = que.top(); //que.front();
    que.pop();

    auto cur_pos  = get<0>(a);
    auto &history = get<1>(a);
    auto dist     = get<2>(a);

    int push_num = 0;
    rep(i, 100) {
      if(table[cur_pos][i] == 0 || history.find(i) != history.end()) continue;

      auto new_hist = history;
      new_hist.insert(cur_pos);

      que.push(make_tuple(i, new_hist, dist + 1));
      push_num++;
    }
    if(push_num == 0) max_dist = max(max_dist, dist);
  }

  return max_dist;
}

int main() {
  while(true) {
    cin >> n;
    if(n == 0) break;

    memset(table, 0, 100 * 100 * sizeof(int));

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

      ans = max(solve(i), ans);
    }

    cout << ans + 1 << endl;
  }
  return 0;
}
