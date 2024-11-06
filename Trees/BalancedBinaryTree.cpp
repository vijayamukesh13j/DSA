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
int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int lefheight = height(root -> left);
    int rightheight = height(root -> right);
    int ans = 1 + max(lefheight,rightheight);

    return ans;
}

bool isBalance(Node* root){
    if(root == NULL){
        return true;
    }

    int leftheight = height(root -> left);
    int rightheight = height(root -> right);
    int diff = abs(leftheight - rightheight);

    bool ans1 = (diff <= 1);


    bool leftAns = isBalance(root -> left);
    bool rightAns = isBalance(root -> right);

    if(ans1 && leftAns && rightAns){
        return true;
    }
    else{
        return false;
    }
}

// void LevelOrderTraversal(Node* root) {
//     if (root == NULL) return;

//     queue<Node*> q;
//     q.push(root);

//     while (!q.empty()) {
//         Node* temp = q.front();
//         q.pop();

//         cout << temp->data << " ";

//         if (temp->left) {
//             q.push(temp->left);
//         }
//         if (temp->right) {
//             q.push(temp->right);
//         }
//     }
// }

int main() {
    //vector<int> v = {3, 9, -1, -1, 20, 15, -1, -1, 7, -1, -1};
    //vector<int> v = {3, 9, 20, -1, -1, 15, 7};
    vector<int> v = {1, 2, -1, 3, -1, 4, -1, 5};
    Node* root = CreateTreeFromLevelOrder(v);
    // LevelOrderTraversal(root);
    if(isBalance(root)){
        cout<<"ture" << endl;
    }
    else{
        cout<<"false"<<endl;
    }

    return 0;
}
