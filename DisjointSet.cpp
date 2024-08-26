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
        int ult_u=ult_parent(u);
        int ult_v=ult_parent(v);

        if(ult_u == ult_v) return;
        
        if(size[ult_u] > size[ult_v]){
            parent[v]=u;
            size[u]+=size[v];
        }else{
            parent[u]=v;
            size[v]+=size[u];
        }
    }
};