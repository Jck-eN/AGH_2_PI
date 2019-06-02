#include <iostream>
#include <climits>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

const int INF = INT_MAX;

typedef struct Node {
    Node *parent;
    vector <pair<Node *, int>> neighbours;
    int val, dist;
} Node;

typedef struct Qnode { 
    Node* vertex;
    Qnode* next; 
}QNode;

QNode* newNode(Node* node) 
{ 
    QNode* temp = (QNode*)malloc(sizeof(QNode)); 
    temp->vertex = node; 
    temp->next = NULL; 
  
    return temp; 
} 
  
// Return the value at head 
Node* peek(QNode** head) 
{ 
    return (*head)->vertex; 
} 
  
// Removes the element with the 
// highest priority form the list 
void pop(QNode** head) 
{ 
    QNode* temp = *head; 
    (*head) = (*head)->next; 
    free(temp); 
} 
  
// Function to push according to priority 
void push(QNode** head, Node* p) 
{ 
    QNode* start = (*head); 
  
    // Create new QNode 
    QNode* temp = newNode(p); 
  
    // Special Case: The head of list has lesser 
    // priority than new node. So insert new 
    // node before head node and change head node. 
    if ((*head)->vertex->dist > p->dist) { 
  
        // Insert New QNode before head 
        temp->next = *head; 
        (*head) = temp; 
    } 
    else { 
  
        // Traverse the list and find a 
        // position to insert new node 
        while (start->next != NULL && 
               start->next->vertex->dist < p->dist) { 
            start = start->next; 
        } 
  
        // Either at the ends of the list 
        // or at required position 
        temp->next = start->next; 
        start->next = temp; 
    } 
} 
  
// Function to check is list is empty 
int isEmpty(QNode** head) 
{ 
    return (*head) == NULL; 
} 
//---------------------------------------------------


Node *newNode(int val) {
    Node *n = new Node;
    n->val = val;
    n->dist = INF;
    n->parent = NULL;
}

void addEdge(Node *u, Node *v, int w) {
    pair <Node *, int> u_edge(v, w);
    pair <Node *, int> v_edge(u, w);
    u->neighbours.push_back(u_edge);
    v->neighbours.push_back(v_edge);
}

auto cmp = [](Node *x, Node *y) { return x->dist > y->dist; };

bool relax(Node *u, Node *v, int weight) {
    // put your code here
}

void dijkstra(Node **nodes, int n, Node *start) {
    priority_queue <Node *, vector<Node *>, decltype(cmp)> queue(cmp);

    // put your code here
}

int main() {
    int N, k, start, end;
    cin >> N >> k;
    Node *nodes[N];
    for (int i = 0; i < N; i++) nodes[i] = newNode(i);

    for (int i = 0; i < k; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(nodes[u], nodes[v], w);
    }

    cin >> start >> end;
    dijkstra(nodes, N, nodes[start]);
    cout << nodes[end]->dist << endl;

    for (int i=0; i<N; i++) delete nodes[i];
}