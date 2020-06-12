class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int notgrumpy = 0;
        for(int i = 0; i < customers.size(); i++)
            if(grumpy[i] == 0)
                notgrumpy += customers[i];
        
        int winStart = 0, winSum = 0, satisfied = 0;
        for(int winEnd = 0; winEnd < customers.size(); winEnd++) {
            if(grumpy[winEnd])
                winSum += customers[winEnd];
            if(winEnd >= X - 1) {
                satisfied = max(satisfied, winSum);
                if(grumpy[winStart])
                    winSum -= customers[winStart];
                winStart++;
            }
        }
        return notgrumpy + satisfied;
    }
};
