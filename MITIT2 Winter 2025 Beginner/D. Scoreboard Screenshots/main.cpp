#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

struct Score {
  int i;
  vector<int> s;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  //freopen("1.in", "r", stdin);
  //freopen("1.out", "w", stdout);

  int N, K; cin >> N >> K;

  vector<Score> scores(N);
  for (int i = 0; i < N; i++) {
    scores[i].i = i;
    for (int j = 0; j < K; j++) {
      int s; cin >> s;
      scores[i].s.push_back(s);
    }
  }

  sort(scores.begin(), scores.end(), [](const Score& a, const Score& b) {
    for (int i = 0; i < a.s.size(); i++) {
      if (a.s[i] > b.s[i]) {
        return false;
      } else if (a.s[i] < b.s[i]) {
        return true;
      }
    }
    return false;
  });

  bool works = true;
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < K; j++) {
      if (scores[i].s[j] < scores[i-1].s[j]) {
        works = false;
        break;
      }
    }
    if (!works) break;
  }

  if (works) {
    cout << "YES" << endl;
    for (int i = 0; i < N; i++) {
      cout << (scores[i].i+1) << " ";
    }
    cout << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}