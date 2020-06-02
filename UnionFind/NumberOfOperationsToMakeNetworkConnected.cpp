class Solution {
public:
    int find(vector<int>& parent, int x) {
        return parent[x] < 0 ? x : parent[x] = find(parent, parent[x]);
    } 
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        vector<int> parent(n, -1);
        for(auto &c: connections) {
            int i = find(parent, c[0]);
            int j = find(parent, c[1]);
            if(i != j) {
                parent[j] = i;
                --n;
            }
        }
        return n-1;
    }
};
