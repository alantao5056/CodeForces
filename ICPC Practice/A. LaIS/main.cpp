#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 2e9;

// Represents the DP state
struct State {
    int len;
    int val; // This is the "Constraint" (min of the last pair)

    // Comparison operator to determine if 'this' state is worse than 'other'.
    // We want larger length. If lengths are equal, we want smaller constraint.
    bool operator<(const State& other) const {
        if (len != other.len) return len < other.len;
        return val > other.val; 
    }
};

int N;
vector<int> A;
vector<State> dp;

// Coordinate compression
vector<int> coords;

// Fenwick Tree (BIT)
vector<int> bit;
int bit_n;

void bit_update(int idx, int val) {
    for (; idx <= bit_n; idx += idx & -idx)
        bit[idx] = max(bit[idx], val);
}

int bit_query(int idx) {
    int res = 0;
    for (; idx > 0; idx -= idx & -idx)
        res = max(res, bit[idx]);
    return res;
}

void bit_clear(int idx) {
    for (; idx <= bit_n; idx += idx & -idx)
        bit[idx] = 0;
}

int get_coord(int v) {
    return lower_bound(coords.begin(), coords.end(), v) - coords.begin() + 1;
}

void solve_cdq(int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    
    // 1. Recursively solve the left half
    solve_cdq(l, mid);

    // Create temporary lists of indices for the current range
    vector<int> left_ids, right_ids;
    left_ids.reserve(mid - l + 1);
    right_ids.reserve(r - mid);
    for (int i = l; i <= mid; ++i) left_ids.push_back(i);
    for (int i = mid + 1; i <= r; ++i) right_ids.push_back(i);

    // --- Case 1: A[j] <= A[i] ---
    // Transition: New len = dp[j].len + 1, New Const = A[j]
    // Sort both sides by A ascending
    sort(left_ids.begin(), left_ids.end(), [](int a, int b){
        return A[a] < A[b];
    });
    sort(right_ids.begin(), right_ids.end(), [](int a, int b){
        return A[a] < A[b];
    });

    State best_c1 = {0, INF};
    int ptr = 0;
    for (int i : right_ids) {
        // Collect candidates from left where A[j] <= A[i]
        while(ptr < left_ids.size() && A[left_ids[ptr]] <= A[i]) {
            int j = left_ids[ptr];
            // We want to maximize len. 
            // Note: iterating A ascending means newer j's have worse (larger) constraints A[j].
            // So we only update if we find a strictly better length.
            if (dp[j].len > best_c1.len) {
                best_c1 = {dp[j].len, A[j]};
            }
            ptr++;
        }
        
        if (best_c1.len > 0) {
            State cand = {best_c1.len + 1, best_c1.val};
            if (dp[i] < cand) dp[i] = cand;
        }
    }

    // --- Case 2: A[j] > A[i] ---
    // Transition: New len = dp[j].len + 1, New Const = A[i]
    // Condition: dp[j].val <= A[i]
    // Sort both sides by A descending to filter A[j] > A[i]
    sort(left_ids.begin(), left_ids.end(), [](int a, int b){
        return A[a] > A[b];
    });
    sort(right_ids.begin(), right_ids.end(), [](int a, int b){
        return A[a] > A[b];
    });

    ptr = 0;
    for (int i : right_ids) {
        // Collect candidates from left where A[j] > A[i]
        while(ptr < left_ids.size() && A[left_ids[ptr]] > A[i]) {
            int j = left_ids[ptr];
            // Add valid j to BIT based on its constraint dp[j].val
            bit_update(get_coord(dp[j].val), dp[j].len);
            ptr++;
        }
        
        // Check condition dp[j].val <= A[i] via BIT query
        int max_len = bit_query(get_coord(A[i]));
        if (max_len > 0) {
            State cand = {max_len + 1, A[i]};
            if (dp[i] < cand) dp[i] = cand;
        }
    }

    // Clean up BIT for next use (manual clear is faster than memset for sparse updates)
    for(int k=0; k<ptr; ++k) {
        bit_clear(get_coord(dp[left_ids[k]].val));
    }

    // 3. Recursively solve the right half
    solve_cdq(mid + 1, r);
}

void run_test_case() {
    if (!(cin >> N)) return;
    
    A.assign(N, 0);
    coords.clear();
    
    for(int i=0; i<N; ++i) {
        cin >> A[i];
        coords.push_back(A[i]);
    }
    // Add 0 for the base constraint of length-1 sequences
    coords.push_back(0);
    
    // Coordinate Compression
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());

    // Initialization
    // Base case: sequence of length 1 has "previous constraint" 0 (or -inf)
    dp.assign(N, {1, 0});
    
    bit_n = coords.size() + 5;
    bit.assign(bit_n + 1, 0);

    if (N > 0) solve_cdq(0, N - 1);

    int ans = 0;
    for(const auto& s : dp) ans = max(ans, s.len);
    
    // If N=0, ans=0. If N>0, min ans is 1.
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while(t--) {
            run_test_case();
        }
    }
    return 0;
}