class Solution {
public:

    struct Node {
        char lc, rc;
        int llen, rlen;
        int best, len;
        
        Node() {
            lc = rc = '#';
            llen = rlen = best = len = 0;
        }
    };

    vector<Node> tree;

    Node merge(Node a, Node b) {
        if(a.len == 0) return b;
        if(b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;
        res.lc = a.lc;
        res.rc = b.rc;

        // Prefix length
        res.llen = a.llen;

        if(a.llen == a.len && a.rc == b.lc) {
            res.llen = a.len + b.llen;
        }

        // Suffix length
        res.rlen = b.rlen;

        if(b.rlen == b.len && a.rc == b.lc) {
            res.rlen = b.len + a.rlen;
        }

        // Best answer inside either half
        res.best = max(a.best, b.best);

        // Combine suffix of a + prefix of b
        if(a.rc == b.lc) {
            res.best = max(res.best, a.rlen + b.llen);
        }

        return res;
    }

    void build(int node, int l, int r, string &s) {
        if(l == r) {
            tree[node].lc = tree[node].rc = s[l];
            tree[node].llen = tree[node].rlen = 1;
            tree[node].best = 1;
            tree[node].len = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(2 * node, l, mid, s);
        build(2 * node + 1, mid + 1, r, s);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, char ch) {
        if(l == r) {
            tree[node].lc = tree[node].rc = ch;
            tree[node].llen = tree[node].rlen = 1;
            tree[node].best = 1;
            tree[node].len = 1;
            return;
        }

        int mid = (l + r) / 2;

        if(idx <= mid)
            update(2 * node, l, mid, idx, ch);
        else
            update(2 * node + 1, mid + 1, r, idx, ch);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {

        int n = s.size();

        tree.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for(int i = 0; i < queryIndices.size(); i++) {

            int idx = queryIndices[i];
            char ch = queryCharacters[i];

            update(1, 0, n - 1, idx, ch);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};