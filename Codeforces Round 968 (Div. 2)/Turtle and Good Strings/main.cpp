#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int T;

int main() {
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  cin >> T;

  for (int i = 0; i < T; i++) {
    int N; cin >> N;
    string s; cin >> s;
    if (s[0] == s[N-1]) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }

  return 0;
}