#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    public:
    vector<int>parent,size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    
    // path compression
    int ult_parent(int node){
            if(node==parent[node]){
                return node;
            }
            return parent[node]=ult_parent(parent[node]);
    }
   
   // size by union
    void Union(int u,int v){
        int ulp_u = ult_parent(u);
        int ulp_v = ult_parent(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
