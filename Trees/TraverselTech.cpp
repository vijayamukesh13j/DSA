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

void inOrderTraversal(Node* root){
    //base case
    if(root == NULL){
        return;
    }

    inOrderTraversal(root -> left);
    cout << root -> data << " ";
    inOrderTraversal(root -> right);
}
void preOrderTraversel(Node* root){
    //base case
    if(root == NULL){
        return;
    }
    cout << root -> data << " ";
    preOrderTraversel(root -> left);
    preOrderTraversel(root -> right);
}

void postOrderTraversel(Node* root){
    //base case
    if (root == NULL){
        return;
    }
    postOrderTraversel(root -> left);
    postOrderTraversel(root -> right);
    cout << root -> data << " ";
}

int main(){
    Node* root = NULL;
    root = buildTree();

    cout << "inOrderTraversal : ";
    inOrderTraversal(root);
    cout << endl;

    cout << "preOrderTraversel : ";
    preOrderTraversel(root);
    cout << endl;

    cout << "postOrderTraversel : ";
    postOrderTraversel(root);
    cout << endl;

}