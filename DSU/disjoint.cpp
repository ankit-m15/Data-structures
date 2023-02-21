#include<bits/stdc++.h>
using namespace std;

class disjointSet{
    vector<int>rank,parent,size;
    public:
        disjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i=0; i<=n; i++){
                parent[i]=i;
            }
        }
        findParent(int node){
            if(node==parent[node]){
                return node;
            }
            return parent[node]=findParent(parent[node]);
        }
        void unionByRank(int u,int v){
            int parentOfU=findParent(u);
            int parentOfV=findParent(v);
            if(parentOfU==parentOfV) return;
            if(rank[parentOfU] < rank[parentOfV]){
                parent[parentOfU]=parentOfV;
                rank[parentOfV]++;
            }
            else{
                parent[parentOfV]=parentOfU;
                rank[parentOfU]++;
            }
        }
        void unionBySize(int u,int v){
            int parentOfU=findParent(u);
            int parentOfV=findParent(v);
            if(parentOfU==parentOfV) return;
            if(size[parentOfU] < size[parentOfV]){
                parent[parentOfU]=parentOfV;
                size[parentOfV]+=size[parentOfU];
            }
            else{
                parent[parentOfV]=parentOfU;
                size[parentOfU]+=size[parentOfV];
            }
        }
        bool check(int first,int second){
            if(findParent(first)==findParent(second)) 
                return true;
            return false;
        }
};

int main(){
    disjointSet ds1(6);
    ds1.unionBySize(1,2);
    ds1.unionBySize(3,4);
    ds1.unionBySize(5,6);
    ds1.unionBySize(3,6);
    // check if node 1 and 6 belong to same component or not;
    cout<<ds1.check(1,6)<<endl; // false
    ds1.unionBySize(4,2);
    // again checking
    cout<<ds1.check(1,6)<<endl; // true

    return 0;
}