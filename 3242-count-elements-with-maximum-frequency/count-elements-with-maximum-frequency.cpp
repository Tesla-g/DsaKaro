class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int>freq(110,0);
        for(auto ele : nums){
            freq[ele]++;
        }
//         got the frequency of each and every ele
        int max =*max_element(freq.begin(),freq.end());
//         find out the elemnt whos freq is same with the 
        int cnt=0;
        for(auto ele : freq){
            if(max==ele){
                cnt++;
            }
        }
        return cnt*max;
    }
};