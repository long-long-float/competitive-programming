#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int get_index(int p, int N, int shift) {
  int index = (p + shift) % N;
  return index;
}

int main() {
  int N, Q;
  cin >> N >> Q;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    A[i] = i + 1;
  }

  int shift = 0;
  for (int i = 0; i < Q; i++) {
    int q;
    cin >> q;
    if (q == 1) {
      int p, x;
      cin >> p >> x;
      p--;

      int index = get_index(p, N, shift);
      A[index] = x;
    } else if (q == 2) {
      int p;
      cin >> p;
      p--;

      int index = get_index(p, N, shift);
      cout << A[index] << endl;
      //   num_outputs++;

    } else if (q == 3) {
      int k;
      cin >> k;

      shift += k;
      shift = shift % N;
    }
  }

  return 0;
}
