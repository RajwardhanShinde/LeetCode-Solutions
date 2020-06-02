class Solution {
public:
    int find(vector<int> &parent, int x) {
        return parent[x] == x ? parent[x] : parent[x] = find(parent, parent[x]);
    }
    
    void unite(vector<int>& children, vector<int>& parent, int x, int y) {
        if(find(parent, x) == find(parent, y)) return;
        
        if(children[find(parent, x)] > children[find(parent, y)]) {
            children[find(parent, x)] += children[find(parent, y)];
            parent[find(parent, y)] = find(parent, x);
        } else {
            children[find(parent, y)] += children[find(parent, x)];
            parent[find(parent, x)] = find(parent, y);
        }
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        vector<int> parent(n);
        vector<int> children(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            children[i] = 1;
        }
        for(int i = 0; i < n; i++) 
            for(int j = i + 1; j < n; j++)
                if(M[i][j]) unite(children, parent, i, j);
        
        int count = 0;
        for(int i = 0; i < n; i++) 
            if(find(parent, i) == i)
                ++count;
        return count;
    }
};
