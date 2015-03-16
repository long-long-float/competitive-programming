#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0;i < (n);i++)
#define min(a, b) ((a) <= (b) ? (a) : (b))
#define max(a, b) ((a) >= (b) ? (a) : (b))

using namespace std;

typedef list<int> tray;
typedef vector<tray> tray_set;

int n, m;

void print_tray(tray_set &trays) {
  for(tray& t : trays) {
    for(int& e : t) {
      cout << e;
    }
    cout << endl;
  }
  cout << "---------------" << endl;
}

int solve(tray_set trays, tray_set prev) {
  rep(count, m) {
    if(trays[0].size() == n || trays[2].size() == n) return count + 1;

    rep(i, 3) {
      if(trays[i].empty()) continue;

      rep(j, 3) {
        if(abs(i - j) >= 2 || i == j) continue;

        if(trays[j].empty() || trays[i].back() > trays[j].back()) {
          tray_set temp = trays;
          temp[j].push_back(temp[i].back());
          temp[i].pop_back();
          if(temp != prev) {
            prev = trays;
            trays = temp;
            goto outer;
          }
        }
      }
    }
outer:
    ;
    //print_tray(trays);
  }

  return -1;
}

int main() {
  while(true) {
    cin >> n >> m;
    if(n == 0 && m == 0) break;

    tray_set trays(3);
    rep(i, 3) {
      int a;
      cin >> a;
      rep(j, a) {
        int b;
        cin >> b;
        trays[i].push_back(b);
      }
    }

    if(trays[0].size() == n || trays[2].size() == n) {
      cout << 0 << endl;
      continue;
    }

    vector<tray_set> sets;
    rep(i, 3) {
      if(trays[i].empty()) continue;

      rep(j, 3) {
        if(abs(i - j) >= 2 || i == j) continue;

        if(trays[j].empty() || trays[i].back() > trays[j].back()) {
          tray_set new_trays = trays;
          new_trays[j].push_back(new_trays[i].back());
          new_trays[i].pop_back();
          sets.push_back(new_trays);
        }
      }
    }

    int ans1 = solve(sets[0], trays), ans2 = -1;
    if(sets.size() > 1) ans2 = solve(sets[1], trays);

    //cout << ans1 << ' ' << ans2 << endl;

    if(ans1 == -1 && ans2 == -1) cout << -1 << endl;
    else if(ans1 != -1 && ans2 != -1) cout << min(ans1, ans2) << endl;
    else cout << max(ans1, ans2) << endl;
  }
}
