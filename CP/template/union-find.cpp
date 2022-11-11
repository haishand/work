#include<iostream>
#include<vector>

using namespace std;

struct UF {
    vector<int> parent, rank;
    UF(int n):parent(n), rank(n) { 
        for(int i=0; i<n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        if(parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        if(rank[x]<rank[y]) {
            parent[x] = y;
        }else {
            parent[y] = x;
            if(rank[x] == rank[y]) ++rank[x];
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

int main(void) {
    int n = 5;

    UF uf(n);

    uf.unite(0, 1);
    uf.unite(0, 2);
    uf.unite(3, 4);


    for(int i=0; i<n; i++){
        cout<< i << " " << uf.find(i) << endl;
        
    }

}