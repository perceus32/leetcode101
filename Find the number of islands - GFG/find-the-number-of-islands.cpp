//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void bfs(int n, int m, int r, int c, vector<vector<char>> &grid, vector<vector<int>> &vis){
        
        vis[r][c] = 1;
        queue<pair<int, int>> q;
        vector<pair<int, int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0,-1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        
        q.push({r, c});
        
        while(!q.empty()){
            pair<int, int> node = q.front();
            q.pop();
            //ls.push_back(node);
            r = node.first;
            c = node.second;
            
            for(int i=0; i<8; i++){
                int k = r + dir[i].first;
                int l = c + dir[i].second;
                
                if(k>=0 && l>=0 && k<n && l<m && grid[k][l]=='1' && !vis[k][l]){
                    vis[k][l] = 1;
                    q.push({k, l});
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
       // vector<vector<pair<int, int>>> ls;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int count = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    //vector<pair<int, int>> list;
                    //ls.push_back(list);
                    
                    bfs(n, m, i, j, grid, vis);
                    count++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends