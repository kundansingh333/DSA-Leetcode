class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:roads){
            int u=it[0];
            int v=it[1];
            adj[u].push_back({v,it[2]});
            adj[v].push_back({u,it[2]});
        }
        // bfs
        vector<bool>visited(n+1,false);
        queue<int>q;
        q.push(1);
        visited[1]=true;
        int min_score=INT_MAX;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto &neighbour:adj[curr]){
                int next_city=neighbour.first;
                int dist=neighbour.second;
                min_score=min(min_score,dist);
                if(!visited[next_city]){
                    visited[next_city]=true;
                    q.push(next_city);
                }
            }

        }
        return min_score;


    }
    
};