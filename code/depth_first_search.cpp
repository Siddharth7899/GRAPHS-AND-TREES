#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int N = 1e5+5;
vector<int> graph[N];
bool vis[N];

void dfs(int vertex){
   /*take action on vertex  after entering the vertex*/
   //if(vis[vertex]) return;
   vis[vertex] = true;
   for(auto &child : graph[vertex]){
       /*take action on child after entering the child*/
       if(vis[child]) continue;
       dfs(child);
       /*take action on child after exiting the child*/
   }
   /*take action on vertex after exiting the vertex*/
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0 ; i<m ; i++){
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(1);
    return 0;
}