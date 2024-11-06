#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* CreateTreeFromLevelOrder(const vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) {
        return NULL;
    }

    // Create root node
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        Node* temp = q.front();
        q.pop();

        // Insert left child
        if (i < arr.size() && arr[i] != -1) {
            temp->left = new Node(arr[i]);
            q.push(temp->left);
        }
        i++;

        // Insert right child
        if (i < arr.size() && arr[i] != -1) {
            temp->right = new Node(arr[i]);
            q.push(temp->right);
        }
        i++;
    }
    return root;
}

void LevelOrderTraversal(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left) {
            q.push(temp->left);
        }
        if (temp->right) {
            q.push(temp->right);
        }
    }
}

int main() {
    vector<int> v = {3, 9, -1, -1, 20, 15, -1, -1, 7, -1, -1};
    Node* root = CreateTreeFromLevelOrder(v);
    LevelOrderTraversal(root);

    return 0;
}
