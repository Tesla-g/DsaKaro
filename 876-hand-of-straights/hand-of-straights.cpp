class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize){
            return false;
        }

        map<int,int>mp;
        for(auto & ele : hand){
            mp[ele]++;
        }
       while(!mp.empty()){
           int curr=mp.begin()->first;
//            getting the first value 
           //check for all the there element is present or nto and decrement their freq
           for(int i=0;i<groupSize;i++){
               if(mp[curr+i]==0){
                   return false;
               }
               mp[curr+i]--;
               if(mp[curr+i]<1){
                   mp.erase(curr+i);
               }
               
           }
           
       }
        return true;
    }
};