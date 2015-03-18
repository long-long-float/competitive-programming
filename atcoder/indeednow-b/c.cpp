#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0;i < (n);i++)
#define all(c) (c).begin(),(c).end()

typedef unsigned int uint;

using namespace std;

const int MAX_N = 100000;

int main() {
  int N;
  cin >> N;

  vector<list<int>> nodes(N);

  rep(i, N - 1) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    nodes[a].push_back(b);
    nodes[b].push_back(a);
  }

  vector<int> ans;
  ans.push_back(0);

  set<int> targets, history;
  queue<int> que;
  que.push(0);
  while(!que.empty()) {
    int cur = que.front();
    que.pop();

    if(history.find(cur) != history.end()) continue;
    history.insert(cur);
    //cout << cur + 1 << endl;

    for(int dist : nodes[cur]) {
      if(history.find(dist) != history.end()) continue;
      targets.insert(dist);
    }

    /*cout << cur+1 << " targets: ";
    for(int e : targets) {
      cout << e+1 << ' ';
    }*/

    if(!targets.empty()) {
      int min_dist = INT_MAX;
      for(int t : targets) {
        min_dist = min(min_dist, t);
      }

      //cout << " pushed: " << min_dist+1 << endl;

      targets.erase(min_dist);
      ans.push_back(min_dist);
      que.push(min_dist);
    }
  }

  rep(i, ans.size()) {
    cout << ans[i] + 1;
    if(i != ans.size() - 1) cout << ' ';
  }
  cout << endl;

  return 0;
}
