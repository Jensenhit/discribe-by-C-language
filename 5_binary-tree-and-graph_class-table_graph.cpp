/*
binary tree and graph
class table by graph
plan 1: DFS
plan 2: BFS
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct GraphNode{
    int label;
    vector<GraphNode *> neighbors;
    GraphNode(int x) : label(x){};
};

// DFS
bool DFS_graph(GraphNode *node, vector<int> &visit){
    visit[node->label] = 0;
    for (int i = 0; i < node->neighbors.size(); i++){
        if (visit[node->neighbors[i]->label] == -1){
            if (DFS_graph(node->neighbors[i], visit) == 0){
                return false;
            }
        }
        else if (visit[node->neighbors[i]->label] == 0){
            return false;
        }
    }
    visit[node->label] = 1;
    return true;
}

class Solution1{
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites){
        vector<GraphNode *> graph;
        vector<int> visit;
        for (int i = 0; i < numCourses; i++){
            graph.push_back(new GraphNode(i));
            visit.push_back(-1);
        }
        for (int i = 0; i < prerequisites.size(); i++){
            GraphNode *begin = graph[prerequisites[i].second];
            GraphNode *end = graph[prerequisites[i].first];
            begin->neighbors.push_back(end);
        }
        for (int i = 0; i < graph.size(); i++){
            if (visit[i] == -1 && !DFS_graph(graph[i], visit)){
                return false;
            }
        }
        for (int i = 0; i < numCourses; i++){
            delete graph[i];
        }
        return true;
    }
};

// BFS
class Solution2{
public:
    bool canFinish(int numCourse, vector<pair<int, int>>& prerequisites){
        vector<GraphNode *> graph;
        vector<int> degree;
        for (int i = 0; i < numCourse; i++){
            degree.push_back(0);
            graph.push_back(new GraphNode(i));
        }
        for (int i = 0; i < prerequisites.size(); i++){
            GraphNode *begin = graph[prerequisites[i].second];
            GraphNode *end = graph[prerequisites[i].first];
            begin->neighbors.push_back(end);
            degree[prerequisites[i].first]++;
        }
        queue<GraphNode *> Q;
        for (int i = 0; i < numCourse; i++){
            if (degree[i] == 0){
                Q.push(graph[i]);
            }
        }
        while (!Q.empty()){
            GraphNode *node = Q.front();
            Q.pop();
            for (int i = 0; i < node->neighbors.size(); i++){
                degree[node->neighbors[i]->label]--;
                if (degree[node->neighbors[i]->label] == 0){
                    Q.push(node->neighbors[i]);
                }
            }
        }
        for (int i = 0; i < graph.size(); i++){
            delete graph[i];
        }
        return true;
    }
};


int main(){
    vector<pair<int, int>> prerequisites;
    prerequisites.push_back(make_pair(1, 0));
    prerequisites.push_back(make_pair(2, 0));
    prerequisites.push_back(make_pair(3, 1));
    prerequisites.push_back(make_pair(3, 2));
    Solution2 solve;
    cout<<solve.canFinish(4, prerequisites)<<endl;
    return 0;
}
