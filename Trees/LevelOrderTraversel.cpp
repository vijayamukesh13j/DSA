#include <iostream>
#include <queue>
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
 
 void levelOrderTraversel(Node* root){
    queue<Node*> q;

    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout << temp -> data << " ";
        if(temp->left){
            q.push(temp -> left);
        }
        if(temp -> right){
            q.push(temp -> right);
        }
    }
 }

int main(){
    Node* root = NULL;
    root = buildTree();
    levelOrderTraversel(root);

}