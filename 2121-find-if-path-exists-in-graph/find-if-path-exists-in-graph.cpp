class Solution {
public:

    void bfs(vector<int> &visited,int source, unordered_map<int,vector<int> > &graph){
        queue<int>q;
        q.push(source);
        visited[source]=1;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(auto nbr:graph[front]){
                if(!visited[nbr]){
                    visited[nbr]=1;
                    q.push(nbr);
                }
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> graph(n);
        vector<int> visited(n);
        if(source==destination) return true;
        if(edges.size()==0) return false;
        for(int i=0; i<edges.size(); i++){
            int a=edges[i][0];
            int b=edges[i][1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        bfs(visited,source,graph);

        return visited[destination];

    }
};