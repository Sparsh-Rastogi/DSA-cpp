#include <bits/stdc++.h>
using namespace std;
void printEdgeList(vector<tuple<int,int,int>> edgeList){
    for(auto u: edgeList){
        cout << get<0>(u) << " " << get<1>(u) << " " << get<2>(u) << endl;
    }
    return;
}
int find_set(int v,int* parent){
    if(v==parent[v]){
        return v;
    }
    parent[v]=find_set(parent[v],parent);
    return parent[v];
}
void union_set(int a,int b, int*size, int* parent){
    if(find_set(a,parent)==find_set(b,parent)){return;}
    if(size[a]>size[b]){
        parent[find_set(b,parent)] = find_set(a,parent);
        size[a]+=size[b];
    }
    else{
        parent[find_set(a,parent)] = find_set(b,parent);
        size[b]+=size[a];
    }
}
bool isGreater(tuple<int,int,int> a,tuple<int,int,int> b){
    return get<2>(a) < get<2>(b);
}
int main(){
    int n,e;
    cout << "Enter Number of Nodes: ";
    cin >> n;
    int parent[n+1];
    int size[n+1];
    for(int i = 0;i<n+1;i++){
        parent[i]=i;
        size[i]=1;
    }
    cout << "Enter Number of Edges: ";
    cin >> e;
    int e1,e2,w;
    // <from,to,weight>
    vector<tuple<int,int,int>> edgeList;
    cout << "Enter edges: " << endl;
    for(int i =0;i<e;i++){
        cin >> e1 >> e2 >> w;
        edgeList.push_back({e1,e2,w});
    }
    sort(edgeList.begin(),edgeList.end(),isGreater);
    vector<tuple<int,int,int>> MST;
    for(auto e: edgeList){
        // cout << "checking " << find_set(get<0>(e),parent) << " " << find_set(get<1>(e),parent) << endl;
        if(find_set(get<0>(e),parent)==find_set(get<1>(e),parent)){
            continue;
        }
        MST.push_back(e);
        union_set(get<0>(e),get<1>(e),size,parent);
        //cout << "verifying " << find_set(get<0>(e),parent) << " " << find_set(get<1>(e),parent) << endl;
    }
    cout<< "printing MST: " << endl;
    printEdgeList(MST);
    
    
}