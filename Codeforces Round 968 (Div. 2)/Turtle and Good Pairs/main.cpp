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

    vector<int> freq(26);

    for (int j = 0; j < N; j++) {
      freq[s[j]-'a']++;
    }

    string news;

    while (true) {
      bool done = true;
      for (int j = 0; j < 26; j++) {
        if (freq[j] > 0) {
          done = false;
          freq[j]--;
          news += char(j + 97);
        }
      }

      if (done) break;
    }

    cout << news << endl;
  }

  return 0;
}