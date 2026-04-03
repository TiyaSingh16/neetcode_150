class Solution {
public:
    bool iscycledfs(int src, vector<bool>& vis, vector<bool>& recpath, vector<vector<int>>& edges){
    vis[src] = true;
    recpath[src] = true;

    for(int i = 0; i < edges.size(); i++){
        int v = edges[i][0];
        int u = edges[i][1];

        if(src == u){
            if(!vis[v]){
                if(iscycledfs(v, vis, recpath, edges))
                    return true;
            }
            else if(recpath[v]){
                return true;
            }
        }
    }

    recpath[src] = false;   // ⭐ MUST ADD THIS
    return false;
}
    void topoorder(int src,vector<bool> &vis, stack<int> &s, vector<vector<int>> &edges){
        vis[src]=true;
        for(int i=0;i<edges.size();i++){
            int v=edges[i][0];
            int u=edges[i][1];
            if(src==u){
                if(!vis[v]){
                    topoorder(v,vis,s,edges);
                }
            }
        }
        s.push(src);
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<bool> vis(n,false);
        vector<bool> recpath(n,false);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(iscycledfs(i,vis,recpath,prerequisites)){
                    return ans;
                }
            }
        }
        stack<int> s;
        vis.assign(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                topoorder(i,vis,s,prerequisites);
            }
        }
        while(s.size()>0){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
