class Person {
  public: 
    string name; 
    int height; 
    Person (string na, int he){
        this->name=na; this->height=he; 
    }
    
};
class Solution {
public:
  
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<Person>value; 
        for(int i=0 ; i<names.size(); i++){
            value.push_back(Person(names[i], heights[i]));
        }
        sort(value.begin(), value.end(),[](const Person &a, const Person &b){
              return a.height<b.height; 
        });
        reverse(value.begin(), value.end());
        vector<string> ans; 
        for(auto &ele : value){
            ans.push_back(ele.name);
        }
        return ans; 
        
    }
};