class DSU {
public:
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) parent[b] = a;
    }
};

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();

        // Step 0: basic diagonal validation
        for (int i = 0; i < n; i++) {
            if (lcp[i][i] != n - i) return "";
        }

        DSU dsu(n);

        // Step 1: union where lcp > 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (lcp[i][j] > 0) {
                    dsu.unite(i, j);
                }
            }
        }

        // Step 2: assign characters
        vector<char> res(n);
        unordered_map<int, char> mp;
        char curr = 'a';

        for (int i = 0; i < n; i++) {
            int p = dsu.find(i);

            if (mp.find(p) == mp.end()) {
                if (curr > 'z') return ""; // only 26 letters allowed
                mp[p] = curr++;
            }
            res[i] = mp[p];
        }

        // Step 3: validate LCP
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (res[i] == res[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = 0;
                }

                if (dp[i][j] != lcp[i][j]) {
                    return "";
                }
            }
        }

        return string(res.begin(), res.end());
    }
};