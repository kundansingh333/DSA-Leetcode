class Solution {
public:

    void dfs(int k, vector<vector<int>>&adj,vector<bool>&visited){
        visited[k]=true;
        for(auto nbr:adj[k]){
            if(!visited[nbr]){
                dfs(nbr,adj,visited);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        int s=invocations.size();
        for(int i=0; i<s; i++){
            int u=invocations[i][0];
            int v=invocations[i][1];
            adj[u].push_back(v);
        }
        vector<bool>visited(n,false);
        dfs(k,adj,visited);
        bool edgeFromOutside=false;
        for(auto& edge:invocations){
            int u=edge[0];
            int v=edge[1];
            if(!visited[u] && visited[v]){
                edgeFromOutside=true;
                break;
            }
        }
        vector<int>ans;
        if(edgeFromOutside){
            for(int i=0; i<n; i++){
                ans.push_back(i);
            }
        }else{
            for(int i=0; i<n; i++){
                if(!visited[i]){
                    ans.push_back(i);
                }
            }
        }

        return ans;
    }   
};