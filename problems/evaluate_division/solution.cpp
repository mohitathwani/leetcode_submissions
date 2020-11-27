class Solution {
public:
    struct Node {
        string name;
        double value;
    };
    
    struct BFSNode {
        double prevProd;
        Node node;
    };
    
    map<string, vector<Node>> graph;
    
    void buildGraph(vector<vector<string>>& equations, vector<double>& values) {
        int i = 0;
        for (const auto& equation : equations) {
            string first = equation[0];
            string second = equation[1];
            Node node = {second, values[i]};
            Node rNode = {first, 1/values[i]};
            
            if (graph.count(first) == 0) {
                graph[first] = {node};
            } else {
                graph[first].push_back(node);
            }
            
            if (graph.count(second) == 0) {
                graph[second] = {rNode};
            } else {
                graph[second].push_back(rNode);
            }
            i++;
        }
    }
    
    
    //19/22 passing
    bool dfs(string first, string second, set<string>visited, double& product) {
        if (graph.count(first) == 0 || graph.count(second) == 0) {
            product = -1;
            return false;
        }
        if (first == second) {
            return true;
        }
        
        visited.insert(first);
        
        for(const auto& node : graph[first]) {
            if (visited.count(node.name) == 1) {
                continue;
            }
            
            product *= node.value;
            bool result = dfs(node.name, second, visited, product);
            if (result) {
                return result;
            }
            product /= node.value;
            visited.erase(node.name);
        }
        return false;
    }
    
    double bfs(string first, string second) {
        queue<BFSNode> q;
        set<string> visited;
        
        vector<Node> neighbors = graph[first];
        for (const auto& node : neighbors) {
            BFSNode b = {1, node};
            q.push(b);
            visited.insert(node.name);
        }
        
        while (!q.empty()) {
            BFSNode first = q.front();
            q.pop();
            if (first.node.name == second) {
                return first.prevProd * first.node.value;
            }
            
            for (const auto& neighbor: graph[first.node.name]) {
                if (visited.count(neighbor.name) == 0) {
                    BFSNode b = {first.prevProd * first.node.value, neighbor};
                    q.push(b);
                    visited.insert(neighbor.name);
                }
            }
        }
        return -1;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        buildGraph(equations, values);
        vector<double> result;
        for (const auto& query : queries) {
            string first = query[0];
            string second = query[1];
            double product = 1;
            //set<string> visited;
            //dfs(first, second, visited, product);
            
            product = bfs(first, second);
            result.push_back(product);
        }
        return result;
    }
};