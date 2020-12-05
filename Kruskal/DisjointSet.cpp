/* Your code here! */
#include "DisjointSet.h"

void DisjointSets::addelements(int num){
    int i = 0;
    for(i = 0; i < num; i++){
        sets.push_back(-1);
    }
    return;
}

int DisjointSets::find(int elem){
    int parent = sets[elem];
    if(parent < 0){
        return elem;
    }
    parent = find(parent);
    sets[elem] = parent;
    return parent;
}

void DisjointSets::setunion(int a, int b){
    int root1 = find(a);
    int root2 = find(b);
    if(root1 == root2){
        return;
    }
    if((sets[root1] == sets[root2]) || (sets[root2] > sets[root1])){
        sets[root1] += sets[root2];
        sets[root2] = root1;
        return;
    }
    else{
        sets[root2] += sets[root1];
        sets[root1] = root2;
        return;
    }
    return;
}

int DisjointSets::size(int elem){
    int neg_size = sets[find(elem)];
    return -1*neg_size;
}

void DisjointSets::clear(){
    sets.clear();
}