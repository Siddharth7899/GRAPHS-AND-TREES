#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+10;
int parent[N];
int size[N];

void make(int vertex){
   parent[vertex]=vertex;
   size[vertex]=1;
}

int find(int v){
   if(v==parent[v]) return v;
   //path compression optimization
   return parent[v] = find(parent[v]);
}

void Union(int a,int b){
   a = find(a);
   b = find(b);
   if(a!=b){
       //optimization by union of size
       if(size[a]<size[b]) swap(a,b);
        parent[b]=a;
       size[a]+=size[b];
   }
}

int main(){
    int n;//number of vertex
    int k;
    cin>>n>>k;
    for(int i=1 ; i<=n ; i++){
      make(i);
    }
    while(k--){
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }
    /*
    //if in any que we have to ask to find the number of connected component
    //No. of connected component is basically total number of root present in the dsu
    int connected_c = 0;
    for(int i=1 ; i<=n ; i++){
        if(find(i)==i) connected_c++;
    }
    cout<<connected_c<<"\n";
    */
    return 0;
}