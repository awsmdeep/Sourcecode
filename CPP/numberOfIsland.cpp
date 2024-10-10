#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Helper function that performs BFS starting from the given (row, col) cell
void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
    // Mark the starting cell as visited
    vis[row][col] = 1;
    
    // Create a queue for BFS
    queue<pair<int, int>> q;
    // Push the starting cell (row, col) into the queue
    q.push({row, col});
    
    // Get the number of rows and columns in the grid
    int n = grid.size();
    int m = grid[0].size();
    
    // Define the possible movements (up, down, left, right)
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    // BFS loop - process each cell in the queue
    while (!q.empty()) {
        int curRow = q.front().first;
        int curCol = q.front().second;
        q.pop(); // Remove the cell from the queue

        // Traverse the 4 possible neighbors (up, down, left, right)
        for (int i = 0; i < 4; i++) {
            int nRow = curRow + delRow[i]; // New row
            int nCol = curCol + delCol[i]; // New column

            // Check if the new cell is within bounds, is land ('1'), and not visited
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == '1' && !vis[nRow][nCol]) {
                vis[nRow][nCol] = 1; // Mark the new cell as visited
                q.push({nRow, nCol}); // Add the new cell to the queue for further processing
            }
        }
    }
}

// Main function to count the number of islands in the grid
int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();    // Number of rows in the grid
    int m = grid[0].size(); // Number of columns in the grid
    int count = 0;          // Counter to keep track of the number of islands

    // Create a visited array initialized to 0 (not visited)
    vector<vector<int>> vis(n, vector<int>(m, 0));

    // Traverse every cell in the grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // If the current cell is land ('1') and not visited, start a BFS
            if (grid[i][j] == '1' && !vis[i][j]) {
                count++;          // Increment the island count
                bfs(i, j, vis, grid); // Perform BFS to mark all connected land cells
            }
        }
    }
    
    // Return the total number of islands found
    return count;
}

int main() {
    int n, m;
    
    // Get the size of the grid from the user
    cout << "Enter the number of rows (n): ";
    cin >> n;
    cout << "Enter the number of columns (m): ";
    cin >> m;
    
    // Create a grid of size n x m
    vector<vector<char>> grid(n, vector<char>(m));
    
    // Get the grid elements from the user (1 for land, 0 for water)
    cout << "Enter the grid elements (0 for water, 1 for land):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    // Call the function to count the number of islands and print the result
    int numberOfIslands = numIslands(grid);
    cout << "Number of islands: " << numberOfIslands << endl;
    
    return 0;
}
