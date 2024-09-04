#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> st;
        for (const auto& obs : obstacles) {
            string key = to_string(obs[0]) + "&" + to_string(obs[1]);
            st.insert(key);
        }
        int currX=0;
        int currY=0;
        pair<int,int> dir={0,1}; //facing the north dir;
        int maxD=0;
        for(int i = 0; i< commands.size() ; ++i){
            if(commands[i]==-2){
                dir={-dir.second, dir.first}; // take left 
            }else if(commands[i]==-1){
                dir={dir.second,-dir.first}; // tek right 
            }else{
                
                for(int step=0; step<commands[i]; ++step ){
                    int newX= currX+dir.first;
                    int newY=currY+dir.second;
                    string key=to_string(newX)+"&"+to_string(newY);
                    if(st.find(key)!=st.end()){
                        break; // if obstackle is found 
                    }
                    currX=newX;
                    currY=newY;
                }
           
            }
            maxD=max(maxD, currX*currX +currY*currY);
            
            
        }

    

        return maxD;
    }
};
