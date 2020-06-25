class CustomStack {
public:
    int size = -1;
    vector<int> s;
    CustomStack(int maxSize) {
        s.resize(maxSize);
    }
    
    void push(int x) {
        if(size + 1 < s.size())
            s[++size] = x;
    }
    
    int pop() {
        return size < 0 ? -1 : s[size--];
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < min(k, size + 1); i++)
            s[i] += val;
    }
};
