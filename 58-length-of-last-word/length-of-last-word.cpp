class Solution {
public:
// string trimSpaces(string  s){
//     int n=s.size();
//     string word="";
//     string ans="";
//     bool flag=false;
//     for(int i=0;i<n;i++){
//         if(s[i]!=' '){
//             word+=s[i];
//             flag=false;
//         }
//         else{
//             if(flag){
//                 continue;
//             }
//             ans+=word+',';
//             word="";
//             flag=true;
//         }
//     }
// //     Intensive that you can solve the 
//     ans+=word;
//     return ans;
// }
    int lengthOfLastWord(string s) {
        bool flag=false;
        int n=s.size();
        int ans=0;
        for(int i=n-1;i>=0;--i){
            if(s[i]==' '&& flag){
                break;
            }
            if(s[i]!=' '){
                flag=true;
                ans++;
            }
        }
        return ans;
    }
};