#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int data){
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(){
    int data;
    cout << "Enter the data" << endl;
    cin >> data;

    if (data == -1){
        return NULL;
    }

    //Steps A, B and C

    // A: Creating the node
    Node* root = new Node(data);

    // B : left of the Node
    cout << "enter the data for the left part of " << data << " node" << endl;
    root -> left = buildTree();

    // C : right of the Node
    cout << "enter the data for the right part of " << data << " node" << endl;
    root -> right = buildTree();

    return root;

}
int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftheight = height(root -> left);
    int rightheight = height(root -> right);
    int ans = 1 + max(leftheight,rightheight);
    return ans;

}

int main(){
    Node* root = NULL;
    root = buildTree();
    int h = height(root);
    cout << "height : "<< h <<endl;

}