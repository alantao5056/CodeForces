#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  int N, M, x1, x2, y1, y2;
  cin >> N >> M >> x1 >> y1 >> x2 >> y2;

  int dx = abs(x1 - x2);
  int dy = abs(y1 - y2);

  if (dx > dy) {
    dx--;
  } else {
    dy--;
  }

  if (dy == dx && dy == 3) {
    cout << "Second" << endl;
    return 0;
  }

  if (max(dx, dy) <= 3) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
  }

  return 0;
}