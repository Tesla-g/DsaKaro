class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(auto & ele : letters){
            if(ele>target){
                return ele ; 
            }
        }
        return letters[0];
    }
};