class Solution {
public:

    struct Node {
        int prod;
        int cnt[5];

        Node() {
            prod = 1;
            for (int i = 0; i < 5; i++)
                cnt[i] = 0;
        }
    };

    int n, k;
    vector<Node> tree;

    Node merge(Node a, Node b) {

        Node res;

        // Product of complete segment
        res.prod = (a.prod * b.prod) % k;

        // Prefixes completely inside left
        for (int r = 0; r < k; r++) {
            res.cnt[r] += a.cnt[r];
        }

        // Prefixes = whole left + prefix of right
        for (int r = 0; r < k; r++) {

            int newRem = (a.prod * r) % k;

            res.cnt[newRem] += b.cnt[r];
        }

        return res;
    }

    void build(vector<int>& nums, int node, int l, int r) {

        if (l == r) {

            int val = nums[l] % k;

            tree[node].prod = val;

            tree[node].cnt[val] = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(nums, 2 * node + 1, l, mid);
        build(nums, 2 * node + 2, mid + 1, r);

        tree[node] = merge(
            tree[2 * node + 1],
            tree[2 * node + 2]
        );
    }

    void update(int node, int l, int r, int idx, int val) {

        if (l == r) {

            val %= k;

            tree[node] = Node();

            tree[node].prod = val;
            tree[node].cnt[val] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid) {
            update(2 * node + 1, l, mid, idx, val);
        }
        else {
            update(2 * node + 2, mid + 1, r, idx, val);
        }

        tree[node] = merge(
            tree[2 * node + 1],
            tree[2 * node + 2]
        );
    }

    Node query(int node, int l, int r, int ql, int qr) {

        // Completely inside
        if (ql <= l && r <= qr) {
            return tree[node];
        }

        int mid = (l + r) / 2;

        // Entirely in right
        if (ql > mid) {
            return query(
                2 * node + 2,
                mid + 1,
                r,
                ql,
                qr
            );
        }

        // Entirely in left
        if (qr <= mid) {
            return query(
                2 * node + 1,
                l,
                mid,
                ql,
                qr
            );
        }

        // Split
        Node left = query(
            2 * node + 1,
            l,
            mid,
            ql,
            qr
        );

        Node right = query(
            2 * node + 2,
            mid + 1,
            r,
            ql,
            qr
        );

        return merge(left, right);
    }

    vector<int> resultArray(
        vector<int>& nums,
        int K,
        vector<vector<int>>& queries
    ) {

        n = nums.size();
        k = K;

        tree.resize(4 * n);

        build(nums, 0, 0, n - 1);

        vector<int> ans;

        for (auto &q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Permanent update
            update(0, 0, n - 1, index, value);

            // Query [start ... n-1]
            Node res = query(
                0,
                0,
                n - 1,
                start,
                n - 1
            );

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};