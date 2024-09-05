class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        // find the missing observations to get the right answer and call 
        int sum=0; int m= rolls.size();
        for(auto & ele : rolls)sum+=ele;
        int missingsum=mean*(m+n)-sum;
        // distribut
        int max_range_value= 6*n;  // nboxes can have 6*n value to get 
        int min_value=n; // if each one of the box has a value 1 
        if(missingsum<min_value or missingsum>max_range_value){
            return {};
        }
        int div= missingsum/n;
        int rem= missingsum%n;
     
        vector<int>ans(n, div);
        for(int i=0; i<rem; i++){
            ans[i]++;
        }
        return ans;
    }
};