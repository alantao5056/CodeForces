#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int T;

int main() {
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  cin >> T;

  string temp = "aeiou";

  for (int i = 0; i < T; i++) {
    int N; cin >> N;

    if (N <= 5) {
      cout << temp.substr(0, N) << endl;
      continue;
    }

    string s = "";
    int cur = N;
    for (int j = 0; j < 5; j++) {
      int rep = cur / (5-j);
      cur -= cur / (5-j);

      for (int k = 0; k < rep; k++) {
        s += temp[j];
      }
    }

    cout << s << endl;
  }

  return 0;
}