class Solution {
    private: 
    void dfs(int node,vector<int> adjls[],int vis[])
    {
        vis[node]=1;
        for(auto it:adjls[node])
        {
            if(!vis[it])
            {
                vis[it]=1;
                dfs(it,adjls,vis);
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int>adjls[V];
        
        //to change adjacency matrix to adjacency list
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1)
                {
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }
        
        int vis[V]={0};
        int cnt=0;
        for(int i=0;i<V;i++)
        {
            if(!vis[i]){
                cnt++;
                dfs(i,adjls,vis);
            }
        }
        return cnt;
    }
};