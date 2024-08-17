class NeighborSum {
public:
    vector<vector<int>> grid;
    int n; 

    // Constructor
    NeighborSum(vector<vector<int>>& grid) {
        this->grid = grid; // Correct assignment
        n = grid.size();
    }
    bool isValidDir(int& newRow, int& newCol){
        if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < n){
            return true;
        }
        return false;
    }
    pair<int,int>getPosition(int &value){
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == value) {
                  return {i, j};
                }
            }
        }
        return {-1,-1};
        
    }
    int adjacentSum(int value) {
     

      auto [row, col]=getPosition(value);
        int sum = 0;

        // Directions for adjacent cells
        vector<pair<int, int>> directions = {
            {0, -1},  // left
            {0, 1},   // right
            {1, 0},   // down
            {-1, 0}   // up
        };

        // Sum the values of adjacent cells
        for (auto [dr, dc] : directions) {
            int newRow = row + dr;
            int newCol = col + dc;
            if (isValidDir(newRow, newCol)) {
                sum += grid[newRow][newCol];
            }
        }
        return sum;
    }
    
    int diagonalSum(int value) {
        auto [row, col]=getPosition(value);
        int sum = 0;

        // Directions for diagonal cells
        vector<pair<int, int>> directions = {
            {-1, -1}, // top-left
            {1, 1},   // bottom-right
            {1, -1},  // bottom-left
            {-1, 1}   // top-right
        };

        // Sum the values of diagonal cells
        for (auto [dr, dc] : directions) {
            int newRow = row + dr;
            int newCol = col + dc;
            if (isValidDir(newRow, newCol)) {
                sum += grid[newRow][newCol];
            }
        }
        return sum;
    }
};


/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */