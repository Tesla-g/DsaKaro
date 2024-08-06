class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int>freq;
        for(auto & ch: word){
            freq[ch]++;
        }
        vector<pair<char,int>>charmap(freq.begin(),freq.end());
     
        sort(charmap.begin(), charmap.end(),[&](auto & a, auto & b){
           return b.second<a.second; 
        });

        // jab tak all the characters are not mapped with something else ;
        int mappingindex=2;
        unordered_map<int, vector<char>>keymapp;
        for(auto & ch : charmap){
            keymapp[mappingindex].push_back(ch.first);
             mappingindex++;
             if(mappingindex==10){
                mappingindex=2;
            }
            
        }
        // got an index and the 
        int ans=0;
        for(auto & ele : keymapp){
            int i=1;
            for(auto & ch : ele.second ){
                ans+=freq[ch]*i;
                i++;
                // fo rthis ch the number of times is this k
            }
        }
        return ans;
    }
};