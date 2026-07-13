class Solution {
public:
    bool checkBfs(int start,vector<vector<int>>&graph,vector<int>&color){
        queue<int>q;
        q.push(start);
        color[start]=0;
        while(!q.empty()){
            int f=q.front();
            q.pop();
            for(auto nbr:graph[f]){
                if(color[nbr]==-1){
                    color[nbr]=1-color[f];
                    q.push(nbr);
                }else if(color[nbr]==color[f]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>color(V,-1);
        for(int i=0; i<V; i++){
            if(color[i]==-1){
                if(!checkBfs(i,graph,color)){
                    return false;
                }
            }
        }
        return true;
        
    }
};