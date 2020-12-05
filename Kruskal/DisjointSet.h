#pragma once
#include <vector>
#include <iostream>

class DisjointSets{
    private:
    std::vector<int> sets;

    public:
    void addelements(int num);
    int find(int elem);
    void setunion(int a, int b);
    int size(int elem);
    void clear();
};