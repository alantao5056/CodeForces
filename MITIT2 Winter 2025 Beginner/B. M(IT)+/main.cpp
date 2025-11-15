#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  int T; cin >> T;

  while (T--) {
    int N; cin >> N;
    string s; cin >> s;
    
    if (s[0] != 'M') {
      cout << "NO" << endl;
      continue;
    }

    bool works = true;
    bool t = false; // looking for t
    for (int i = 0; i < N; i++) {
      if (s[i] == 'M') {
        if (t || (i>0&&s[i-1] == 'M')) {
          works = false; break;
        }
      } else if (s[i] == 'I') {
        if (t) {
          works = false; break;
        }
        t = true;
      } else if (s[i] == 'T') {
        if (!t) {
          works = false; break;
        }
        t = false;
      } else {
        works = false; break;
      }
    }

    if (t || s[N-1] == 'M') works = false;

    if (works) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}