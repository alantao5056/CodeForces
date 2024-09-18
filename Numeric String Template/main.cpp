#include <bits/stdc++.h>

using namespace std;

int main() {
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  int T; cin >> T;

  for (int i = 0; i < T; i++) {
    int N; cin >> N;
    vector<int> arr(N);
    for (int j = 0; j < N; j++) {
      cin >> arr[j];
    }

    int M; cin >> M;

    for (int j = 0; j < M; j++) {
      string s; cin >> s;
      if (s.size() != arr.size()) {
        cout << "NO" << endl;
        continue;
      }

      map<char, int> ci;
      set<int> nums;

      bool flag = false;
      for (int k = 0; k < N; k++) {
        if (ci.find(s[k]) != ci.end()) {
          if (ci[s[k]] != arr[k]) {
            cout << "NO" << endl;
            flag = true;
            break;
          }
        } else {
          if (nums.find(arr[k]) != nums.end()) {
            cout << "NO" << endl;
            flag = true;
            break;
          }
          ci[s[k]] = arr[k];
          nums.insert(arr[k]);
        }
      }

      if (!flag) {
        cout << "YES" << endl;
      }
    }
  }

  return 0;
}