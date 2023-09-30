#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Một Node trong cây
class Node {
    // Chứa thông tin của Node đó
    int data;
    // Con trỏ đến Node cha
    Node* fatherNode;

    // Con trỏ đến các Node con
    // Đây là một danh sách liên kết (con trỏ đến con đầu tiên)
    // Thứ tự ưu tiên từ nhỏ đến lớn (con nhỏ được duyệt trước)
    Node* firstChild;
    Node* nextChild;
public:
    Node() {
        // ...
        fatherNode = NULL;
        firstChild = NULL;
        nextChild = NULL;
    }

    Node(int _data) {
        // ...
        data = _data;
        fatherNode = NULL;
        firstChild = NULL;
        nextChild = NULL;
    }
    // Các hàm khởi tạo khác nếu cần thiết
    friend class Tree;
};

// Lớp Cây
class Tree {
    // Chứa một Node gốc
    Node* root;
public:
    Tree() {
        root = NULL;
    }

    // Các hàm khởi tạo khác nếu cần thiết

    // Hàm thêm một Node vào cây
    // Hàm trả về false nếu Node cha không tồn tại trên cây
    // hoặc Node father đã có con là data
    bool insert(int father, int data) {
        if (!root) {
            if (father == 0) {
                root = new Node(data);
                return true;
            } else {
                return false;
            }
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->data == father) {
                if (current->firstChild == NULL) {
                    current->firstChild = new Node(data);
                    current->firstChild->fatherNode = current;
                    return true;
                } else {
                    Node* child = current->firstChild;
                    while (child->nextChild != NULL) {
                        child = child->nextChild;
                    }
                    child->nextChild = new Node(data);
                    child->nextChild->fatherNode = current;
                    return true;
                }
            }
            if (current->firstChild) {
                q.push(current->firstChild);
                Node* sibling = current->firstChild->nextChild;
                while (sibling != NULL) {
                    q.push(sibling);
                    sibling= sibling->nextChild;
                }
            }
        }
        return false;
    }

    // Hàm xoá một Node trên cây
    // Nếu không phải Node lá xoá Node đó và toàn bộ các Node con của nó
    // Hàm trả về số lượng Node đã xoá
    // Nếu Node data không tồn tại trả về 0 (zero)
    // int remove(int data) {
    //     if(!root) {
    //         return 0;
    //     }

    //     if (!root->firstChild) {
    //         if (root->data == data) {
    //             root = NULL;
    //             return 1;
    //         } else {
    //             return 0;
    //         }
    //     }

    //     int deletedNodes = 0;
    //     Node* current = root;

    //     queue<Node*> q;
    //     q.push(root);

    //     while (!q.empty()) {
    //         Node* current = q.front();
    //         q.pop();

    //         if (current->data == data) {
    //             deletedNodes = removeSubtree(current);
    //             break;
    //         }

    //         if (current->firstChild) {
    //             Node* child = current->firstChild;
    //             q.push(child);
    //             Node* sibling = child->nextChild;
    //             while(sibling) {
    //                 q.push(sibling);
    //                 sibling = sibling->nextChild;
    //             }
    //         }
    //     }

    //     return deletedNodes;

    // }

    // int removeSubtree(Node* node) {
    //     if (node == NULL) {
    //         return 0;
    //     }
    //     Node* parentNode = node->fatherNode;

    //     int deletedNotes = 0;

    //     //Xoa not la
    //     if (!node->firstChild) {
    //         if (parentNode->firstChild->data == node->data) {
    //             parentNode->firstChild = node->nextChild;
    //             delete node;
    //             return 1;
    //         } else {
    //             Node* prev = parentNode->firstChild;
    //             Node* current = parentNode->firstChild->nextChild;
    //             while (current->data != node->data) {
    //                 prev = prev->nextChild;
    //                 current = current->nextChild;
    //             }
    //             prev->nextChild = prev->nextChild->nextChild;
    //             delete current;
    //             return 1;
    //         }
    //     }

    //     Node* temp = node;

    //     while (temp->firstChild) {
    //         Node* child = temp->firstChild;
    //         deletedNotes++;
    //         Node* sibling = child->nextChild;
    //         while(sibling) {
    //             deletedNotes++;
    //             sibling = sibling->nextChild;
    //         }
    //         temp = temp->firstChild;
    //     }



    //     return deletedNotes;
    // }

    int remove(int data) {
    if (!root) {
        return 0;
    }

    if (root->data == data) {
        int deletedNodes = countNodes(root);
        deleteSubtree(root);
        root = nullptr;
        return deletedNodes;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        Node* parentNode = nullptr;

        // Search for the node to remove and its parent
        if (current->firstChild) {
            if (current->firstChild->data == data) {
                parentNode = current;
                current = current->firstChild;
            } else {
                Node* sibling = current->firstChild->nextChild;
                while (sibling) {
                    if (sibling->data == data) {
                        parentNode = current;
                        current = sibling;
                        break;
                    }
                    sibling = sibling->nextChild;
                }
            }
        }

        if (parentNode) {
            // Node with the given data was found, remove it
            int deletedNodes = countNodes(current);
            deleteSubtree(current);
            
            // Remove the deleted node from the parent's child list
            if (parentNode->firstChild == current) {
                parentNode->firstChild = current->nextChild;
            } else {
                Node* prev = parentNode->firstChild;
                while (prev->nextChild != current) {
                    prev = prev->nextChild;
                }
                prev->nextChild = current->nextChild;
            }

            return deletedNodes;
        }

        if (current->firstChild) {
            Node* child = current->firstChild;
            while (child) {
                q.push(child);
                child = child->nextChild;
            }
        }
    }

    return 0;
}

int countNodes(Node* node) {
    if (!node) {
        return 0;
    }

    int count = 1;

    Node* child = node->firstChild;
    while (child) {
        count += countNodes(child);
        child = child->nextChild;
    }

    return count;
}

void deleteSubtree(Node* node) {
    if (!node) {
        return;
    }

    // Recursively delete all children of the current node
    Node* child = node->firstChild;
    while (child) {
        Node* nextChild = child->nextChild;
        deleteSubtree(child);
        child = nextChild;
    }

    // Delete the current node
    delete node;
}


    // Hàm in ra các Node theo thứ tự preorder
    void preorder() {
        if (root) {
            preorderNode(root);
        }
        
    }

    void preorderNode(Node* node) {
        if (node) {
            cout << node->data << " ";
            Node* current = node->firstChild;
            while (current)
            {
                preorderNode(current);
                current = current->nextChild;
            }
        }
    }

    // Hàm in ra các Node theo thứ tự postorder
    void postorder() {
        if (root) {
            postorderNode(root);
        }
    }

    void postorderNode(Node* node) {
        if (node) {
            Node* current = node->firstChild;
            while(current) {
                postorderNode(current);
                current = current->nextChild;
            }

            cout << node->data << " ";
        }
    }

    // Hàm kiểm tra cây nhị phân
    bool isBinaryTree() {
        if (!root) {
            return true;
        }

        return isBinaryTreeNode(root);

    }

    bool isBinaryTreeNode(Node* node) {
        if (!node) {
            return true;
        }

        int childCount = 0;
        Node* current = node->firstChild;
        while (current) {
            childCount++;
            if (childCount > 2) {
                return false;
            }
            current = current->nextChild;
        }

        return isBinaryTreeNode(node->firstChild);
    }

    // Hàm kiểm tra cây tìm kiếm nhị phân
    bool isBinarySearchTree() {
            Node* prev = nullptr; // Initialize prev to nullptr
            return isBST(root, prev);
    }
    bool isBST(Node* node, Node*& prev) {
    if (!node) {
        return true; // An empty tree is a BST
    }

    // Recursively check the left subtree
    if (!isBST(node->firstChild, prev)) {
        return false;
    }

    // Check if the current node's value is greater than the previous node's value (if prev is not nullptr)
    if (prev && node->data <= prev->data) {
        return false;
    }

    // Update prev to the current node
    prev = node;

    // Recursively check the right subtree
    return isBST(node->nextChild, prev);
}

    // Hàm kiểm tra cây max-heap
    bool isMaxHeapTree() {
        if (!root) {
        return true; // An empty tree is a max-heap
    }

    return isMaxHeap(root);
    }

    bool isMaxHeap(Node* node) {
    if (!node) {
        return true; // An empty subtree is a max-heap
    }

    Node* current = node->firstChild;

    while (current) {
        // Check if the current node's value is less than its child's value
        if (current->data > node->data) {
            return false; // Violation of max-heap property
        }

        // Recursively check the child's subtree
        if (!isMaxHeap(current)) {
            return false;
        }

        current = current->nextChild;
    }

    return true; // Max-heap property holds for this subtree
}


    // Hàm in ra các Node theo thứ tự inorder nếu là cây nhị phân
    void inorder() {
        if (root) {
            inorderNode(root);
        }
    }

    void inorderNode(Node* node) {
        if (node) {
            inorderNode(node->firstChild);

            cout << node->data << " ";

            inorderNode(node->firstChild->nextChild);
        }
    }

    // Hàm trả về độ cao của cây
    int height() {
        return calculateHeight(root);
    }

    int calculateHeight(Node* node) {
        if (!node) {
            return 0;
        }

        int maxHeight = 0;

        Node* current = node->firstChild;
        while(current) {
            int childHeight = calculateHeight(current);
            if (childHeight > maxHeight) {
                maxHeight = childHeight;
            }
            current = current->nextChild;
        }

        return maxHeight + 1;
    }

    // Hàm trả về độ sâu của một Node
    int depth(int data) {
        return findDepth(root, data, 1);
    }

    int findDepth(Node* node, int data, int currentDepth) {
        if (!node) {
            return -1;
        }

        if (node->data == data) {
            return currentDepth;
        }

        Node* current = node->firstChild;

        while(current) {
            int childDepth = findDepth(current, data, currentDepth + 1);
            if (childDepth != -1) {
                return childDepth;
            }
            current = current->nextChild;
        }

        return -1;
    }

    // Hàm đếm số lượng lá
    int numOfLeaves() {
        return countLeaves(root);
    }

    int countLeaves(Node* node) {
        if (!node) {
            return 0;
        }

        if (!node->firstChild) {
            return 1;
        }

        int leafCount = 0;

        Node* current = node->firstChild;
        while(current) {
            leafCount += countLeaves(current);
            current = current->nextChild;
        }

        return leafCount;
    }

    // Hàm trả về Node có giá trị lớn nhất
    int findMax() {
        if (!root) {
            return -1;
        }
        int maxVal = root->data;

        findMaxNode(root, maxVal);

        return maxVal;
    }

    void findMaxNode(Node* node, int& maxVal) {
        if (!node) {
            return;
        }

        if (node->data > maxVal) {
            maxVal = node->data;
        }

        Node* current = node->firstChild;

        while(current) {
            findMaxNode(current, maxVal);
            current = current->nextChild;
        }
    }

    // Hàm trả về Node có nhiều con nhất
    int findMaxChild() {
        if (!root) {
            return -1;
        }

        int maxChildCount = 0;

        Node* maxChildNode =  nullptr;

        findMaxChildNode(root, maxChildCount, maxChildNode);

        return (maxChildNode ? maxChildNode->data : -1);
    }

    void findMaxChildNode(Node* node, int& maxChildCount, Node*& maxChildNode) {
        if (!node) {
            return;
        }

        int childCount = 0;

        Node* current = node->firstChild;

        while (current) {
            childCount++;
            current = current->nextChild;
        }

        if (childCount > maxChildCount) {
            maxChildCount = childCount;
            maxChildNode = node;
        }

        current = node->firstChild;

        while (current) {
            findMaxChildNode(current, maxChildCount, maxChildNode);
            current = current->nextChild;
        }
    }
};

int main(int argc, char const *argv[]) {
    // Tạo ra một cây ngẫu nhiên có tối thiểu 30 Node
    Tree tree;
    tree.insert(0, 1);
    tree.insert(1, 2);
    tree.insert(1, 3);
    tree.insert(2, 4);
    tree.insert(2, 5);
    tree.insert(3, 6);
    tree.insert(3, 7);
    tree.insert(3, 8);
    //tree.insert(3, 8);
    // Test thử các hàm của lớp cây
    cout << "Preorder traversal: ";
    tree.preorder();
    cout << endl;
    cout << "Postorder traversal: ";
    tree.postorder();
    cout << endl;
    // cout << "Inorder traversal: ";
    // tree.inorder();
    // cout << endl;
    cout << "Is binary? " << tree.isBinaryTree() << endl;
    cout << "Is binary search tree? " << tree.isBinaryTree() << endl;
    cout << "Is max heap tree? " << tree.isBinaryTree() << endl;
    cout << "Tree height " << tree.height() << endl;
    cout << "Node 2 height " << tree.depth(2) << endl;
    cout << "Number of leaves: " << tree.numOfLeaves() << endl;
    cout << "Find max: " << tree.findMax() << endl;
    cout << "Find max children node: " << tree.findMaxChild() << endl;
    cout << "Nodes deleted: " << tree.remove(3) << endl;
    cout << "Preorder traversal after remove 3: ";
    tree.preorder();
    cout << endl;
    // Tạo ra một cây thoả mãn tính chất là Binary Search Tree và test lại
    
    // Tạo ra một cây thoả mãn tính chất là Max Heap Tree và test lại
    return 0;
}