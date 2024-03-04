class Solution {
public:
 int  p ( vector<int>&token,int power){

  int n=token.size();
  int i,j;
  int maxscore=0;
int score=0;
  i=0; j=n-1;
  sort(token.begin(),token.end());
  while(i<=j){
    if(power>=token[i]){
      power-=token[i];
      score+=1;
      maxscore=max(score,maxscore);
        i++;
    }
    else if(score>=1){
      power+=token[j];
      score-=1;
      maxscore=max(score,maxscore);
        j--;
    }
      else{
          return maxscore ;
      }
    
  }
  return maxscore;

}

    int bagOfTokensScore(vector<int>& tokens, int power) {
        return p(tokens,power);
    }
};