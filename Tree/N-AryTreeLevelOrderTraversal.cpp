class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL)
            return vector<vector<int>>();
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>> ans;
        vector<int> v;
        while(!q.empty()) {
            Node *node = q.front();
            q.pop();
            if(node) {
                v.push_back(node->val);
                for(int i = 0; i < node->children.size(); i++) 
                    q.push(node->children[i]);
            }
            else {
                ans.push_back(v);
                v.clear();
                if(q.empty()) break;
                q.push(NULL);
                
            }
        }
        return ans;
    }
};
