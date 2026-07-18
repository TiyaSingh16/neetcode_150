class DSU{
public:
    vector<int> parent;
    vector<int> size;
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    int findp(int x){
        if(x==parent[x]) return x;
        else return parent[x]=findp(parent[x]);
    }
    bool unionsize(int x,int y){
        int ulp_x=findp(x);
        int ulp_y=findp(y);
        if(ulp_x==ulp_y) return false;
        else if(size[ulp_x]>size[ulp_y]){
            parent[ulp_y]=ulp_x;
            size[ulp_x]+=size[ulp_y];
        }else{
            parent[ulp_x]=ulp_y;
            size[ulp_y]+=size[ulp_x];
        }
        return true;
    }
};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        DSU dsu(n);
        for(auto e:edges){
            if(!dsu.unionsize(e[0], e[1])) return false;
            
        }
        return true;
    }
};
