class Solution {
public:
    static const int MOD = 1e9 + 7;

    struct Node {
        long long val;
        int len;
        int sum;
    };

    vector<Node> seg;
    vector<long long> pow10;
    string str;

    Node merge(Node &L, Node &R) {
        return {
            (L.val * pow10[R.len] + R.val) % MOD,
            L.len + R.len,
            L.sum + R.sum
        };
    }

    void build(int idx, int l, int r) {
        if (l == r) {
            int d = str[l] - '0';
            if (d == 0)
                seg[idx] = {0, 0, 0};
            else
                seg[idx] = {d, 1, d};
            return;
        }

        int mid = (l + r) / 2;
        build(2 * idx, l, mid);
        build(2 * idx + 1, mid + 1, r);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return seg[idx];

        int mid = (l + r) / 2;

        if (qr <= mid)
            return query(2 * idx, l, mid, ql, qr);

        if (ql > mid)
            return query(2 * idx + 1, mid + 1, r, ql, qr);

        Node left = query(2 * idx, l, mid, ql, qr);
        Node right = query(2 * idx + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        str = s;
        int n = s.size();

        pow10.assign(n + 1, 1);
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        seg.assign(4 * n, {0, 0, 0});
        build(1, 0, n - 1);

        vector<int> ans;

        for (auto &q : queries) {
            Node cur = query(1, 0, n - 1, q[0], q[1]);
            ans.push_back((cur.val * cur.sum) % MOD);
        }

        return ans;
    }
};