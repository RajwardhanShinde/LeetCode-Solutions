class Solution {
public:
    int parent[26];
    int find(int x) {
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    bool equationsPossible(vector<string>& equations) {
        for(int i = 0; i < 26; ++i) 
            parent[i] = i;
        for(string eq: equations) {
            if(eq[1] == '=') {
                int x = find(eq[0] - 'a');
                int y = find(eq[3] - 'a');
                parent[x] = y;
            }
        }
        for(string eq: equations) {
            if(eq[1] == '!') {
                int x = find(eq[0] - 'a');
                int y = find(eq[3] - 'a');
                if(x == y) return false;
            }
        }
        return true;
    }
};
