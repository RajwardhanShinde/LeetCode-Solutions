class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        next_permutation(begin(s), end(s));
        auto res = stoll(s);
        return (res > INT_MAX || res <= n) ? -1 : res;
    }
};
