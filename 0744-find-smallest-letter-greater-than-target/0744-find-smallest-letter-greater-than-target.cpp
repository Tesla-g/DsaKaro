class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0;
        int high = letters.size() - 1;

        // Handle the case where target is greater than or equal to the last letter
        if (target >= letters[high]) {
            return letters[0];
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (letters[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // 'low' will be pointing to the smallest element greater than 'target'
        return letters[low];
    }
};
