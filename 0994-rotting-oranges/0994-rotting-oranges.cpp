class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        int time = 0;
        int fresh = 0, count = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({{i, j}, time});
                    vis[i][j]=1;
                }

                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        while(!q.empty()){
            pair<pair<int, int>, int> node = q.front();
            q.pop();
            int row = node.first.first;
            int col = node.first.second;
            int t = node.second;
            time = max(time, t);

            for(int i=0; i<4; i++){
                int r = row + dir[i].first;
                int c = col + dir[i].second;

                if(r>=0 && c>=0 && r<n && c<m && grid[r][c]==1 && !vis[r][c]){
                    count++;
                    vis[r][c] = 1;
                    q.push({{r, c}, t+1});
                }
            }
        }
        if(count!=fresh){return -1;}
        return time;
    }
};