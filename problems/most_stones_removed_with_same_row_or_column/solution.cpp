class Solution {
    map<int, int> parent;
public:
    
    void makeSet(int i) {
        parent[i] = i;
    }
    
    int findParent(int i) {
        if (parent[i] != i) {
            parent[i] = findParent(parent[i]); //Path Compression
        }
        
        return parent[i];
    }
    
    void unionize(int i, int j) {
        int p1 = findParent(i);
        int p2 = findParent(j);
        
        if (p1 != p2) {
            parent[p2] = p1;
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        
        //Make initial Set
        for (const auto& stone: stones) {
            makeSet(stone[0]);
            makeSet(~stone[1]);
        }
        
        //Unionize
        for (const auto& stone: stones) {
            unionize(stone[0], ~stone[1]);
        }
        
        //Get count of all disjoint sets
        set<int> parents;
        for (const auto& stone: stones) {
            parents.insert(findParent(stone[0])); //Path compression again as parents might've changed because we are not using ranks here.
        }
        
        return stones.size() - parents.size();
    }
};