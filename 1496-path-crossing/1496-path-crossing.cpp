class Solution {
public:
    
void changedir(int &x,int& y,char &ch){
  if(ch=='N'){
    x-=1;

  }else if(ch=='S'){
    x+=1;
  }
  else if (ch=='E'){
    y+=1;
  }
  else if(ch=='W'){
    y-=1;
  }

}


bool c(string path){
  int n=path.size();
  set<pair<int,int>> s;
  int x=0; int y=0;
  s.insert({x,y});


  for(int i=0;i<n;i++){
    changedir(x,y,path[i]);
    if(s.find({x,y})!=s.end()){
      return true;
    }
    s.insert({x,y});


  }

  return false;
}


    bool isPathCrossing(string path) {
        return c(path);
    }
};