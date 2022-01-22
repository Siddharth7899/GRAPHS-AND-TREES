#include <bits/stdc++.h>
#include <vector>
#include <deque>
#define INF 1e9+10
using namespace std;

const int N = 1e5+5;
vector<pair<int,int>> graph[N];
vector<int> level(N,INF);

void BFS(int source){
  deque<int> q;
  q.push_back(source);
  level[source]=0;
  while(!q.empty()){
      int curr_v = q.front();
      q.pop_front();
      for(auto child : graph[curr_v]){
          int child_v = child.first;
          int wt = child.second;
          if(level[curr_v]+wt<level[child_v]){
              level[child_v] = level[curr_v]+wt;
              if(wt==0) q.push_front(child_v);
              else q.push_back(child_v);
          }
      }
   }
}

int main(){
    int n,m;
    cin>>n>>m;
    //Weight of the edged must be either 0 or 1
    for(int i=0 ; i<m ; i++){
        int x,y,wt;cin>>x>>y>>wt;
        graph[x].push_back({y,wt});
        graph[y].push_back({x,wt});
    }
    BFS(1);
    return 0;
}