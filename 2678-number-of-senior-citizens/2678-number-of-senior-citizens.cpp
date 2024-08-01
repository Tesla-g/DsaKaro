class Solution {
public:
    
    
    
    /*
    You are given a 0-indexed array of strings details. Each element of details provides information about a given passenger compressed into a string of length 15. The system is such that:

The first ten characters consist of the phone number of passengers.
The next character denotes the gender of the person.
The following two characters are used to indicate the age of the person.
The last two characters determine the seat allotted to that person.
Return the number of passengers who are strictly more than 60 years old.

*/
int countSeniors(vector<string>& details) {
        int cnt=0;    
    for(auto & ele : details){
        
         string age=ele.substr(11, 2);
         int finalage=stoi(age);
            if(finalage>60){
                cnt++;
            }
           
        }
       return cnt; 
      
    }
};