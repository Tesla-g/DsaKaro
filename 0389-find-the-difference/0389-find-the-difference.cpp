class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>mp;
        for(auto & ele : s){
            mp[ele]++;
        }
        for(auto & ele : t){
            if(mp.find(ele)!=mp.end()){
                mp[ele]--;
                if(mp[ele]==0){
                    mp.erase(ele);
                }
            }else{
                return ele;
            }
        }
        return ' ';
    }
};