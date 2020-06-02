class Solution {
public:
    vector<int> parent;
    int find(int x) {
        return parent[x] == x ? x : find(parent[x]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        int n = edges.size();
        parent.resize(n+1, 0);
        for(int i = 0; i <= n; i++)
            parent[i] = i;
        
        vector<int> res(2, 0);
        for(int i = 0; i < n; i++) {
            int x = find(edges[i][0]);
            int y = find(edges[i][1]);
            if(x != y) {
                parent[y] = x;
            }
            else {
                res[0] = edges[i][0];
                res[1] = edges[i][1];
            }
        }
        return res;
    }
};
