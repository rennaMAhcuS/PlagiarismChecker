class Solution {
   public:
    string getPath(int v, vector<vector<int>>& path, set<int>& vis, vector<string>& words) {
        int cur = v;
        string pp = "";
        int mask = 1 << v;
        while (path[cur][mask] != -1) {
            pp = addFront(words[cur], pp);
            vis.erase(vis.find(cur));
            int next = path[cur][mask];
            cur = next;
            mask = mask | ((1 << next));
        }
        if (vis.size()) {
            // int left = *(vis.begin());
            pp = addFront(words[*(vis.begin())], pp);
        }
        return pp;
    }

    void fill(vector<vector<int>>& dp) {
        int i = 0;
        while (i < dp.size()) {
            for (int j = 0; j < dp[0].size(); j++)
                dp[i][j] = -1;
            i++;
        }
    }

    int solve(int v, int vis, vector<vector<int>> adj[], vector<vector<int>>& dp, int& n, vector<string>& words, vector<vector<int>>& path) {
        vis |= (1 << v);
        if (vis == pow(2, n) - 1) return 0;
        if (dp[v][vis] != -1) return dp[v][vis];

        int ans = 1e9;
        for (int i = 0; i < adj[v].size(); i++) {
            auto child = adj[v][i];
            if (vis & (1 << child[0])) continue;
            int val = solve(child[0], vis, adj, dp, n, words, path);
            if (val + child[1] < ans) {
                path[v][vis] = child[0];
                ans = val + child[1];
            }
        }
        return dp[v][vis] = ans;
    }

    string addFront(string a, string b) {
        string ans = "";
        int n1 = a.length();
        int n2 = b.length();
        int i = n2 - 1;
        while (i >= 0) {
            int i1 = i;
            int i2 = 0;
            int len = 0;
            while (i1 < n2 && i2 < n1) {
                if (b[i1] == a[i2]) {
                    i2++;
                    i1++;
                } else
                    break;
            }
            if (i2 == n1) return b;
            if (i1 == n2) {
                string cur = b;
                for (int j = i2; j < a.length(); j++)
                    cur += a[j];
                ans = cur;
            }
            i--;
        }
        if (ans.size() == 0)
            ans = b + a;
        return ans;
    }

    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        // cout<<n<<"\n";
        if (n == 1) return words[0];
        vector<vector<int>> adj[n];

        vector<vector<int>> dp(n, vector<int>(2 << n, -1));
        vector<vector<int>> path(n, vector<int>(2 << n, -1));
        int ans = 1e9;

        int i = 0;
        while (i < words.size()) {
            for (int j = 0; j < words.size(); j++) {
                if (i == j) continue;
                string common = addFront(words[j], words[i]);
                int cost = common.size() - words[i].size();
                adj[i].push_back({j, cost});
            }
            i++;
        }

        string pathAns;
        i = 0;
        while (i < words.size()) {
            // fill(dp);
            // fill(path);
            // int start = words[i].size();
            int val = solve(i, 0, adj, dp, n, words, path) + words[i].size();
            if (val < ans) {
                ans = val;
                set<int> vis;
                for (int k = 0; k < n; k++) vis.insert(k);
                pathAns = getPath(i, path, vis, words);
                // reverse(order.begin(),order.end());

                ans = val;
            }
            i++;
        }
        return pathAns;
    }
};