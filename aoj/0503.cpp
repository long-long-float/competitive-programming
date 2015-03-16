#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0;i < (n);i++)
#define all(c) (c).begin(),(c).end()
#define min(a, b) ((a) <= (b) ? (a) : (b))
#define max(a, b) ((a) >= (b) ? (a) : (b))

typedef unsigned int uint;

using namespace std;

typedef vector<uint> tray_set;

int n, m;

int top_cop(uint tray) {
  for(int i = 15;i >= 0;i--) {
    if(tray >> i & 1u) return i;
  }
  return -1;
}

void move_cop(uint *from, uint *to) {
  uint x = 1u << top_cop(*from);
  *from = x ^ *from;
  *to   = x | *to;
}

int count_cop(uint tray) {
  int count = 0;
  for(; tray != 0 ; tray &= tray - 1) count++;
  return count;
}

bool finished(tray_set &trays) {
  return count_cop(trays[0]) == n || count_cop(trays[2]) == n;
}

int solve(tray_set trays, tray_set prev) {
  tray_set temp(3);

  rep(count, m) {
    if(finished(trays)) return count + 1;

    bool moved = false;

    rep(i, 3) {
      if(trays[i] == 0) continue;

      rep(j, 3) {
        if(abs(i - j) >= 2 || i == j) continue;

        if(trays[j] == 0 || top_cop(trays[i]) > top_cop(trays[j])) {
          temp = trays;

          move_cop(&temp[i], &temp[j]);
          if(temp != prev) {
            prev = trays;
            trays = temp;

            moved = true;
            break;
          }
        }
      }
      if(moved) break;
    }
    if(!moved) return -1;
  }

  return -1;
}

int main() {
  while(true) {
    cin >> n >> m;
    if(n == 0 && m == 0) break;

    tray_set trays(3, 0);
    rep(i, 3) {
      int a;
      cin >> a;
      rep(j, a) {
        int b;
        cin >> b;
        trays[i] |= 1u << b;
      }
    }

    if(finished(trays)) {
      cout << 0 << endl;
      continue;
    }

    vector<tray_set> sets;
    rep(i, 3) {
      if(trays[i] == 0) continue;

      rep(j, 3) {
        if(abs(i - j) >= 2 || i == j) continue;

        if(trays[j] == 0 || top_cop(trays[i]) > top_cop(trays[j])) {
          tray_set new_trays = trays;
          move_cop(&new_trays[i], &new_trays[j]);
          sets.push_back(new_trays);
        }
      }
    }

    int ans1 = solve(sets[0], trays), ans2 = -1;
    if(sets.size() > 1) ans2 = solve(sets[1], trays);

    if(ans1 == -1 && ans2 == -1) cout << -1 << endl;
    else if(ans1 != -1 && ans2 != -1) cout << min(ans1, ans2) << endl;
    else cout << max(ans1, ans2) << endl;
  }
}
