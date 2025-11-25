#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

pii solve(string s) {
  int x = 0; int y = 0;
  for (int i = 0; i < s.size(); i++) {
    int ox, oy;
    char d = s[i];
    if (d == 'U') {
      ox = x;
      oy = y+1;
    } else if (d == 'D') {
      ox = x;
      oy = y-1;
    } else if (d == 'L') {
      ox = x-1;
      oy = y;
    } else {
      ox = x+1;
      oy = y;
    }

    if (ox == 0 && oy == 0) {
      x = ox; y = oy;
      continue;
    }

    int cx = 0;
    int cy = 0;
    for (int j = 0; j < s.size(); j++) {
      char dd = s[j];
      if (dd == 'U' && !(cx == ox && cy+1 == oy)) {
        cy++;
      } else if (dd == 'D' && !(cx == ox && cy-1 == oy)) {
        cy--;
      } else if (dd == 'L' && !(cx-1 == ox && cy == oy)) {
        cx--;
      } else if (dd == 'R' && !(cx+1 == ox && cy == oy)) {
        cx++;
      } 
    }

    if (cx == 0 && cy == 0) {
      return {ox, oy};
    }

    x = ox; y = oy;
  }

  return {0, 0};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  int T; cin >> T;

  while (T--) {
    string s; cin >> s;
    
    pii res = solve(s);
    cout << res.first << " " << res.second << endl;
  }

  return 0;
}