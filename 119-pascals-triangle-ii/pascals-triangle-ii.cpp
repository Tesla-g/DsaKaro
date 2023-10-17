class Solution
{
    public:
        vector<int> getRow(int rowIndex)
        {
           	//create a pascals trialgle of 2
            vector<vector < int>> row(34);
            for (int i = 0; i < 34; i++)
            {

                row[i] = vector<int> (i + 1, 1);
                for (int j = 1; j < i; j++) {
                    
                    row[i][j]=row[i-1][j]+row[i-1][j-1];
                    
                    
                }
                
            }
               return row[rowIndex];
        }
      
};