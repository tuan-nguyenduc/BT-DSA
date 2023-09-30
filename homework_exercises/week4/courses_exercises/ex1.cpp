#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node {
    int value;
    vector<Node*> children;
    Node() {

    }

    Node(int _value) {
        value = _value;
    }
};

Node* buildTree(int n, const vector<pair<int, int>> edges) {
    unordered_map<int, Node*> nodes;
    Node* root = new Node();
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;

        if(nodes[u] == nullptr) {
            nodes[u] = new Node(edge.first);
        }
        
        nodes[v] = new Node(edge.second); 

        nodes[u]->children.push_back(nodes[v]);
    }

    root = nodes[edges[0].first];

    return root;
}

bool isBinaryTree(Node* root) {
    if (root == nullptr) {
        return false;
    }

    if (root->children.size() > 2) {
        return false;
    }

    for (Node* child : root->children) {
        return isBinaryTree(child);
    }

    return true;
}

void preorderTraversal(Node* root) {
    if (root) {
        cout << root->value << " ";
        for (Node* child : root->children) {
            preorderTraversal(child);
        }
    }
}

void postorderTraversal(Node* root) {
    if (root) {
        for (Node* child : root->children) {
            postorderTraversal(child);
        }
        cout << root->value << " ";
    }
}

void inorderTraversal(Node* root) {
if (root) {
        if (root->children.size() > 2) {
            cout << "NOT BINARY TREE" << endl;
            return;
        }
        if (root->children.size() > 0) {
            inorderTraversal(root->children[0]);
        }
        cout << root->value << " ";
        if (root->children.size() > 1) {
            inorderTraversal(root->children[1]);
        }
    }
}

int calculateHeight(Node* root) {
    if (!root) {
        return 0;
    }

    int maxHeight = -1;

    for (Node* child : root->children) {
        int childHeight = calculateHeight(child);
        maxHeight = max(maxHeight, childHeight);
    }

    return maxHeight + 1;

}




int main() {
    Node* root = new Node();
    int number_of_nodes, number_of_edges;
    cin >> number_of_nodes >> number_of_edges;
    vector<pair<int, int>> edges(number_of_edges);
    for (int i = 0; i < number_of_edges; i++) {
        cin >> edges[i].first >> edges[i].second;
    }
    
    root = buildTree(number_of_edges, edges);
    cout << "Tree Height: " << calculateHeight(root) << endl;
    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;
    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;
    cout << "Inorder Traversal: "; 
    inorderTraversal(root);
    cout << endl;
}