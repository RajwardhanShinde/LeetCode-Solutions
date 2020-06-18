class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0, high = letters.size() - 1;
        if(letters[low] > target || letters[high] <= target)
            return letters[low];
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(letters[mid] == target) {
                if(letters[mid + 1] > target)
                    return letters[mid + 1];
                else
                    low = mid + 1;
            } 
            else if(letters[mid] < target)
                low = mid + 1;
            else 
                high = mid - 1;
        }
        return letters[low];
    }
};
