class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
       unordered_map<char, int>mp;
        for(auto & ch : magazine){
            mp[ch]++;
        }
        // got all 
        for(auto & ch : ransomNote){
            if(mp.find(ch)==mp.end()){
                return false;
            }else{
                // if the element is present then decrease it's count
                mp[ch]--;
                if(mp[ch]==0){
                    mp.erase(ch);
                }
            }
        }
        // if all the elmene is present 
        return true; 
        
    }
};