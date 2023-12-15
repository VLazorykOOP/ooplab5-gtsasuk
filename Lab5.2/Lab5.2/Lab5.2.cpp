#include <iostream>
#include <queue>

using namespace std;

// Клас, що представляє вузол бінарного дерева
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Клас бінарного дерева
class BinaryTree {
public:
    Node* root;
    BinaryTree() : root(nullptr) {}
    // Метод для вставки вузла в бінарне дерево
    void insertNode(int value) {
        root = insert(root, value);
    }
    // Метод для обходу дерева в ширину
    void BypassWidth() {
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
            return;
        }
        cout << "Bypass width:" << endl;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";
            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }
        cout << endl;
    }

private:
    // Допоміжний метод для вставки вузла в бінарне дерево
    Node* insert(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);
        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        return node;
    }
};

int main() {
    BinaryTree tree;
    tree.insertNode(50);
    tree.insertNode(30);
    tree.insertNode(70);
    tree.insertNode(20);
    tree.insertNode(40);
    tree.insertNode(60);
    tree.insertNode(80);
    tree.BypassWidth();
    return 0;
}