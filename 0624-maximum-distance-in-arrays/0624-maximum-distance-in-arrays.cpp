class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minval=arrays[0][0]; // min element encountered so far 
        int maxval=arrays[0].back(); // max element encounted so far 
        int d= 0;
        /// this will be  paired with the other elements of the arrays 
        for(int i=1; i<arrays.size(); ++i){
            d=max(d, abs(minval-arrays[i].back()));
            d=max(d, abs(maxval-arrays[i][0]));
            
            // update the min val and the max val so far 
            minval=min(minval, arrays[i][0]);
            maxval=max(maxval, arrays[i].back());
            
        }
       
        return d;
    }
};
