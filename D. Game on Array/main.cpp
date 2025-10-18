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

  int T;
  cin >> T;

  while (T--) {
    int N; cin >> N;

    ll S = 0;
    vector<int> arr(N);
    map<int, int> freq;
    for (int i = 0; i < N; i++) {
      cin >> arr[i];
      freq[arr[i]]++;
      S += arr[i];
    }

    vector<int> odds;
    ll s = 0;
    for (auto& [key, val] : freq) {
      if (key%2 == 1) {
        odds.push_back(val);
        s+=val;
      }
    }

    sort(odds.begin(), odds.end(), greater<>());

    ll ss = 0;
    for (int i = 0; i < odds.size(); i+=2) {
      ss += odds[i];
    }

    ll a = (S-s)/2+ss;
    cout << a << " " << S-a << endl;
  }

  return 0;
}