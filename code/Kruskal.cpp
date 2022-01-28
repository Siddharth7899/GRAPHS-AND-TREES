#include <bits/stdc++.h>
#include <vector>

using namespace std;

const int N = 1e5+5;
int parent[N];
int size[N];
vector<pair<int,pair<int,int>>> Edges;
vector<pair<pair<int,int>,int>> Tree;

void make(int vertex){
    parent[vertex] = vertex;
    size[vertex]=1;
}

int find(int v){
    if(v==parent[v]) return v;
    return parent[v] = find(parent[v]);
}

void Union(int a,int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        if(size[a] < size[b]) swap(a,b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1 ; i<=n ; i++) make(i);

    for(int i=1 ; i<=m ; i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        Edges.push_back({wt,{u,v}});
    }

    sort(Edges.begin(),Edges.end());
   
    int min_w_spanning_tree=0;
    
    for(auto &edge : Edges){
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.first;
        if(find(u)==find(v)) continue;
        Union(u,v);
        Tree.push_back({{u,v},wt});
        min_w_spanning_tree += wt;
    }
    return 0;
}