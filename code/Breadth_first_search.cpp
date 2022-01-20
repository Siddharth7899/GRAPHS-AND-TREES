#include <bits/stdc++.h>
#include <vector>
#include <queue>

using namespace std;
const int N = 1e5+5;
vector<int> graph[N];
bool vis[N];
int level[N];

void bfs(int root){
   queue<int> q;
   q.push(root);
   vis[root] = true;
   while(!q.empty()){
       int curr_vertex = q.front();
       q.pop();
       for(auto &child : graph[curr_vertex]){
          if(!vis[child]){
              q.push(child);
              vis[child]=true;
              level[child] = level[curr_vertex]+1;
          }
       }
   }
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
    bfs(1);
    return 0;
}