#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int N, C;

class SegmentTree {
private:
    vector<pii> tree;
    int n;

    pii add(pii a, pii b) {
      if (a.first > b.first) {
        return a;
      }
      if (b.first > a.first) {
        return b;
      }

      return {a.first, (a.second + b.second) % MOD};
    }

    // Helper function to build the segment tree
    void buildTree(const vector<pii>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }

        int mid = (start + end) / 2;
        buildTree(arr, 2 * node, start, mid);
        buildTree(arr, 2 * node + 1, mid + 1, end);
        tree[node] = add(tree[2 * node], tree[2 * node + 1]); // Change this for different queries (e.g., min or max)
    }

public:
    // Constructor to initialize the segment tree
    SegmentTree(const vector<pii>& arr) {
        n = arr.size();
        tree.resize(4 * n); // The segment tree can have at most 4 * n nodes
        buildTree(arr, 1, 0, n - 1);
    }

    // Update the value at index 'index' to 'newValue'
    void update(int index, pii newValue, int node, int start, int end) {
        if (start == end) {
            tree[node] = add(tree[node], newValue);
            return;
        }

        int mid = (start + end) / 2;
        if (index <= mid) {
            update(index, newValue, 2 * node, start, mid);
        } else {
            update(index, newValue, 2 * node + 1, mid + 1, end);
        }
        tree[node] = add(tree[2 * node], tree[2 * node + 1]); // Change this for different queries (e.g., min or max)
    }

    // Update the value at index 'index' to 'newValue'
    void update(int index, pii newValue) {
        update(index, newValue, 1, 0, n - 1);
    }

    // Query the range [left, right]
    pii query(int left, int right, int node, int start, int end) {
        if (right < start || left > end) {
            return {-1, 0}; // Change this for different queries (e.g., INT_MAX for min query)
        }

        if (left <= start && right >= end) {
            return tree[node];
        }

        int mid = (start + end) / 2;
        pii leftSum = query(left, right, 2 * node, start, mid);
        pii rightSum = query(left, right, 2 * node + 1, mid + 1, end);

        return add(leftSum, rightSum); // Change this for different queries (e.g., min or max)
    }

    // Query the range [left, right]
    pii query(int left, int right) {
        return query(left, right, 1, 0, n - 1);
    }
};

int main() {
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  cin >> N >> C;

  vector<int> arr = {-1};
  vector<int> sArr = {-1};
  set<int> s;
  for (int i = 0; i < N; i++) {
    int cur; cin >> cur;
    arr.push_back(cur);
    if (s.find(cur) == s.end()) {
      sArr.push_back(cur);
      s.insert(cur);
    }
  }

  sort(sArr.begin(), sArr.end());

  int M = sArr.size()-1;
  map<int, int> conv;
  for (int i = 1; i <= M; i++) {
    conv[sArr[i]] = i;
  }

  vector<pii> init(M+1, {-1, 0});
  SegmentTree st(init);

  int curM = 1;
  int curC = 1;
  for (int i = 1; i <= N; i++) {
    pii q = st.query(0, conv[arr[i]]-1);

    if (q.first > 0) {
      st.update(conv[arr[i]], {q.first + 1, q.second});
      if (q.first + 1 > curM) {
        curM = q.first + 1;
        curC = q.second;
      } else if (q.first + 1 == curM) {
        curC += q.second;
        curC %= MOD;
      }
    } else {
      st.update(conv[arr[i]], {1, 1});
    }
  }

  cout << curM << endl;
  if (C) {
    cout << curC << endl;
  }

  return 0;
}
