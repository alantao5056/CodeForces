#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int N;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  cin >> N;

  vector<int> next(N);
  vector<vector<int>> prev(N);
  for (int i = 0; i < N; i++) {
    int x; cin >> x; x--;

    next[i] = x;
    prev[x].push_back(i);
  }

  vector<int> visited(N);
  vector<string> res;

  for (int i = 0; i < N; i++) {
    if (visited[i] != 0) continue;

    int slow = i;
    int fast = i;
    bool cycle = false;
    while (true) {
      visited[slow] = i+1;
      visited[fast] = i+1;
      slow = next[slow];
      fast = next[next[fast]];

      if (slow == fast) {
        cycle = true;
        break;
      }
      if ((visited[slow] != 0 && visited[slow] != i+1) || (visited[fast] != 0 && visited[fast] != i+1)) {
        break;
      }
    }

    if (cycle) {
      visited[slow] = -1;
      slow = next[slow];
      while (slow != fast) {
        visited[slow] = -1;
        res.push_back("1 " + to_string(slow+1) + " " + to_string(fast+1));
        slow = next[slow];
      }
    }
  }
  
  for (int i = 0; i < N; i++) {
    if (visited[i] != -1) continue;

    queue<pii> q;

    for (int p : prev[i]) {
      if (visited[p] == -1) continue;
      q.push({p, i});
    } 

    while (!q.empty()) {
      pii cur = q.front(); q.pop();

      res.push_back("2 " + to_string(cur.second+1) + " " + to_string(cur.first+1));
     
      for (int p : prev[cur.first]) {
        if (visited[p] == -1) continue;
        q.push({p, cur.first});
      } 
    }
  }

  cout << res.size() << endl;
  for (string s : res) {
    cout << s << endl;
  }

  return 0;
}