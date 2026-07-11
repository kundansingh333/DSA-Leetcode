class Solution {
public:
    void bfs(int start,vector<vector<int>>&adj,vector<bool>&visited,pair<int,int>&count){
        queue<int>q;
        q.push(start);
        visited[start]=true;
        // int nodes=0;
        // int edg=0;

        while(!q.empty()){
            count.first++;
            int f=q.front();
            q.pop();
            for(auto nbr:adj[f]){
                count.second++;
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(n);

        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int valid=0;
        vector<bool>visited(n,false);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                pair<int,int>count={0,0};
                bfs(i,adj,visited,count);
                int c_node=count.first;
                int c_edge=count.second/2;
                if(c_edge==c_node*(c_node-1)/2){
                    valid++;
                }
            }
        }
        return valid;
    }
};