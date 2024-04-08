class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>qt;
        stack<int>st;
        int n=students.size();
        for(int i=0;i<n;i++){
            qt.push(students[i]);
            st.push(sandwiches[n-i-1]);
        }
        int unableToEatSandwich=0;
        while(true){
            
            if(qt.front()==st.top()){
                unableToEatSandwich=0;
//                 the student can eat the sandwich
                qt.pop();
                st.pop();
                
            }else{
//                 unable to eat the sandwich 
                int qtFront=qt.front();
                qt.pop();
                qt.emplace(qtFront);
                unableToEatSandwich++;
            }
            
            if(unableToEatSandwich==qt.size()){ // if all of them in the queu is unable to eat and the size of 
                // queue is also reducing and if this is the case them returnthe 
                break;
            }
        }
        
        return unableToEatSandwich;
    }
};