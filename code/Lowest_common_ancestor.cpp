#include <bits/stdc++.h>
#include <vector>

using namespace std;
const int N = 1e5+5;
vector<int> graph[N];
int parent[N];
void dfs(int vertex,int par){
    parent[vertex] = par;
    for(auto &child : graph[vertex]){
        if(child == par) continue;
        dfs(child,vertex);
    }
}

vector<int> path(int v){
    vector<int> ans;
    while(v!=0){
        ans.push_back(v);
        v = parent[v];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0 ; i<m ; i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1,0);
    int x,y;
    cin>>x>>y;
    vector<int> path1 = path(x);
    vector<int> path2 = path(y);
    int mn = min(path1.size(),path2.size());
    int lca = -1;
    for(int i=0 ; i<mn ; i++){
        if(path1[i]==path2[i]) lca = path1[i];
        else break;
    }
    cout<<lca<<"\n";
    return 0;
}