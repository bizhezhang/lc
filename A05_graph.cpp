#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;

class Edge;

class Node {
public:
    int val;
    int in;
    int out;
    vector<Node*> nexts;
    vector<Edge*> edges;
    Node(int v): val(v), in(0), out(0) {}
};

class Edge {
public:
    int weight;
    Node* from;
    Node* to;
    Edge(int w, Node* f, Node* t): weight(w), from(f), to(t) {}
};

class Graph {
public:
    unordered_map<int, Node*> nodes;
    unordered_set<Edge*> edges;
    
    void addNode(int val) {
        if (nodes.find(val) == nodes.end()) {
            nodes[val] = new Node(val);
        }
    }

    void addEdge(int from, int to, int weight) {
        if (nodes.find(from) == nodes.end() || nodes.find(to) == nodes.end()) return;
        Node* f = nodes[from];
        Node* t = nodes[to];
        Edge* e = new Edge(weight, f, t);
        f->nexts.push_back(t);
        f->edges.push_back(e);
        f->out++;
        t->in++;
        edges.insert(e);
    }

    ~Graph() {
        for (auto& node : nodes) {
            delete node.second;
        }
        for (auto& edge : edges) {
            delete edge;
        }
    }
};

void bfsGraphWithQueue(Node* node){
    if(!node) return;
    unordered_set<Node*> visited;
    queue<Node*> q;
    q.push(node);
    visited.insert(node);
    while(!q.empty()){
        Node* cur = q.front();q.pop();
        cout<<cur->val<<" ";
        sort(cur->edges.begin(), cur->edges.end(), [=](const Edge *x, const Edge *y){
            return x->weight < y->weight;
        });
        for(auto edge: cur->edges){
            if(visited.find(edge->to) == visited.end()){
                q.push(edge->to);
                visited.insert(edge->to);
            }
        }
    }
    cout<<endl;
}

void dfsGraphWithStack(Node* node){
    if(!node) return;
    unordered_set<Node*> visited;
    stack<Node*> st;
    st.push(node);
    visited.insert(node);
    cout<<node->val<<" ";
    while(!st.empty()){
        Node* cur = st.top(); st.pop();
        sort(cur->edges.begin(), cur->edges.end(), [=](const Edge *x, const Edge *y){
            return x->weight < y->weight;
        });
        for(auto edge: cur->edges){
            if(visited.find(edge->to) == visited.end()){
                st.push(cur);
                st.push(edge->to);
                visited.insert(edge->to);
                cout<<edge->to->val<<" ";
                break;
            }
        }
    }
    cout<<endl;
}


int main() {
    vector<vector<int> > weight_from_to = {
        {1, 0, 1},
        {3, 0, 2},
        {2, 0, 4},
        {3, 1, 2},
        {6, 1, 3},
        {8, 1, 4},
        {5, 2, 1},
        {7, 3, 2},
        {9, 3, 4},
    };

    Graph g;
    for (auto x : weight_from_to) {
        g.addNode(x[1]);
        g.addNode(x[2]);
        g.addEdge(x[1], x[2], x[0]);
    }

    bfsGraphWithQueue(g.nodes[0]);
    dfsGraphWithStack(g.nodes[0]);
    for (auto& node : g.nodes) {
        for (auto& edge : node.second->edges) {
            cout << "[" << edge->from->val << "---" << edge->weight << "--->" << edge->to->val << "]" << endl;
        }
    }
    return 0;
}


// 二叉树的非递归
// kruskal, prim, dijkstra
// 前缀树
// 并查集
// 拓扑排序
// KMP
// manacher
// 线段树