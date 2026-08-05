class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        for (auto &it : edges) {
            adj[it[0]].push_back(it[1]);
        }

        vector<bool> vis(n, false);

        queue<int> q;
        q.push(k);
        vis[k] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }

        // Check for any direct edge from non-suspicious to suspicious
        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];

            if (!vis[u] && vis[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                ans.push_back(i);
        }

        return ans;
    }
};