#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0;i < (n);i++)
#define all(c) (c).begin(),(c).end()

#define INF INT_MAX

typedef unsigned int uint;

using namespace std;

vector<list<int>> graph;
set<int> nodes;
bool visited[100];

int solve(int start, int dist) {
  int res = -1;
  for(int to : graph[start]) {
    if(visited[to]) continue;

    visited[to] = true;
    res = max(res, solve(to, dist + 1));
    visited[to] = false;
  }
  if(res == -1) return dist;
  return res;
}

int main() {
  while(true) {
    int n;
    cin >> n;
    if(n == 0) break;

    graph.clear(); nodes.clear();
    graph.resize(100);
    memset(visited, 0, 100 * sizeof(bool));

    rep(i, n) {
      int a, b;
      cin >> a >> b;
      a--; b--;
      graph[a].push_back(b);
      graph[b].push_back(a);
      nodes.insert(a); nodes.insert(b);
    }

    int ans = 0;

    for(int node : nodes) {
      visited[node] = true;
      ans = max(solve(node, 0), ans);
      visited[node] = false;
    }

    cout << ans + 1 << endl;
  }
  return 0;
}
