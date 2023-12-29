class Solution {
private:
    void dfs(int node, vector<vector<int>>& isConnected, int vis[]) {
        vis[node] = 1;
        for (int i = 0; i < isConnected[0].size(); i++) {
            if (isConnected[node][i] == 1 && !vis[i]) {
                    dfs(i, isConnected, vis);
            }
        }
    }

    // void bfs(int start_node, vector<int> &bls, vector<vector<int>> &isConnected, int vis[]) {
    //     //cout<<3<<endl;
    //     queue<int> q;
    //     q.push(start_node);
    //     while (!q.empty()) {
    //       //  cout<<4<<endl;
    //         int node = q.front();
    //         q.pop();
    //         bls.push_back(node);

    //         for (int i = 0; i < isConnected[0].size(); i++) {
    //         //    cout<<5<<endl;
    //             if (isConnected[node][i]==1) {
    //                 if (!vis[i]) {
    //                     vis[i] = 1;
    //                     q.push(i);
    //                 }
    //             }
    //         }
    //     }
    // }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //APPROACH 1 : DFS
        int n = isConnected[0].size(), count = 0;
        int vis[200] = {0};
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                count++;
                int start = i;
                dfs(start, isConnected, vis);
            }
        }
        return count;

        //APPROACH 2: BFS
        /*
        int n = isConnected[0].size(), count = 0;
        int vis[200] = {0};
        vector<int> bls;
        for (int i = 0; i < n; i++) {
           // cout<<1<<endl;
            if (!vis[i]) {
             //   cout<<2<<endl;
                count++;
                int start = i;
                vis[start] = 1;

                bfs(start, bls, isConnected, vis);
            }
        }
        return count;
        */
    }
};