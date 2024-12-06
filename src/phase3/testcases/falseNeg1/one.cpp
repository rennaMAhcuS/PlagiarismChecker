class Solution {
   public:
    string addFront(string a, string b) {
        int n1 = a.length();
        int n2 = b.length();
        string ans = "";
        for (int i = b.length() - 1; i >= 0; i--) {
            int len = 0;

            int i1 = i;
            int i2 = 0;
            while (i1 < b.length() && i2 < a.length()) {
                if (b[i1] == a[i2]) {
                    i1++;
                    i2++;
                } else
                    break;
            }
            if (i2 == a.length()) return b;
            if (i1 == b.length()) {
                string cur = b;
                for (int j = i2; j < a.length(); j++)
                    cur += a[j];
                ans = cur;
            }
        }
        if (ans.size() == 0)
            ans = b + a;
        return ans;
    }

    int solve(int v, int vis, vector<vector<int>> adj[], vector<vector<int>>& dp, int& n, vector<string>& words, vector<vector<int>>& path) {
        vis |= (1 << v);
        if (vis == pow(2, n) - 1) return 0;
        if (dp[v][vis] != -1) return dp[v][vis];

        int ans = 1e9;
        for (auto child : adj[v]) {
            if (vis & (1 << child[0])) continue;
            int val = solve(child[0], vis, adj, dp, n, words, path) + child[1];
            if (val < ans) {
                ans = val;
                path[v][vis] = child[0];
            }
        }
        return dp[v][vis] = ans;
    }

    void fill(vector<vector<int>>& dp) {
        for (int i = 0; i < dp.size(); i++)
            for (int j = 0; j < dp[0].size(); j++)
                dp[i][j] = -1;
    }

    string getPath(int v, vector<vector<int>>& path, set<int>& vis, vector<string>& words) {
        string pp = "";
        int cur = v;
        int mask = 1 << v;
        while (path[cur][mask] != -1) {
            pp = addFront(words[cur], pp);
            vis.erase(vis.find(cur));
            int next = path[cur][mask];
            mask = mask | ((1 << next));
            cur = next;
        }
        if (vis.size()) {
            int left = *(vis.begin());
            pp = addFront(words[left], pp);
        }
        return pp;
    }

    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        // cout<<n<<"\n";
        if (n == 1) return words[0];
        vector<vector<int>> adj[n];

        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if (i == j) continue;
                string common = addFront(words[j], words[i]);
                int cost = common.size() - words[i].size();
                adj[i].push_back({j, cost});
            }
        }
        vector<vector<int>> dp(n, vector<int>(2 << n, -1));
        vector<vector<int>> path(n, vector<int>(2 << n, -1));
        int ans = 1e9;
        string pathAns;
        for (int i = 0; i < words.size(); i++) {
            // fill(dp);
            // fill(path);
            int start = words[i].size();
            int val = solve(i, 0, adj, dp, n, words, path) + start;
            if (val < ans) {
                ans = val;
                set<int> vis;
                for (int k = 0; k < n; k++) vis.insert(k);
                pathAns = getPath(i, path, vis, words);
                // reverse(order.begin(),order.end());

                ans = val;
            }
        }
        return pathAns;
    }
};