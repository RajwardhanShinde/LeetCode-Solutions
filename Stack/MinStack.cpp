class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> v;
    int t;
    MinStack() {
        t = -1;
    }
    
    void push(int x) {
        v.push_back(x);
        t++;
    }
    
    void pop() {
        v.pop_back();
        t--;
    }
    
    int top() {
        return v[t];
    }
    
    int getMin() {
        return *min_element(v.begin(), v.end());
    }
};

