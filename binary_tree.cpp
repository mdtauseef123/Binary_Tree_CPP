#include<bits/stdc++.h>


using namespace std;


class Node{
public:
    Node *left;
    int data;
    Node *right;
    Node* create_node(int);
};


Node* Node::create_node(int num){
    Node *new_node;
    new_node=new Node();
    new_node->data=num;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}


class BinaryTree{
public:
    Node *root;
    BinaryTree();
    void create_binary_tree(void);
    void preorder_traversal(Node*);
    void inorder_traversal(Node*);
    void postorder_traversal(Node*);
};


BinaryTree::BinaryTree(){
    root=NULL;
}


void BinaryTree::create_binary_tree(){
    Node *temp;
    Node nobj;
    int num;
    queue<Node*> node;
    cout<<"Enter the value of root:- ";
    cin>>num;
    root=nobj.create_node(num);
    node.push(root);
    while(!node.empty()){
        temp=node.front();
        node.pop();
        cout<<"Enter the left child of "<<temp->data<<":- ";
        cin>>num;
        if(num!=-1){
            Node *left_child;
            left_child=nobj.create_node(num);
            temp->left=left_child;
            node.push(left_child);
        }
        cout<<"Enter the right child of "<<temp->data<<":- ";
        cin>>num;
        if(num!=-1){
            Node *right_child;
            right_child=nobj.create_node(num);
            temp->right=right_child;
            node.push(right_child);
        }
    }
}


void BinaryTree::preorder_traversal(Node *temp){
    if(temp!=NULL){
        cout<<temp->data<<" ";
        preorder_traversal(temp->left);
        preorder_traversal(temp->right);
    }
}


void BinaryTree::postorder_traversal(Node *temp){
    if(temp!=NULL){
        postorder_traversal(temp->left);
        postorder_traversal(temp->right);
        cout<<temp->data<<" ";
    }
}


void BinaryTree::inorder_traversal(Node *temp){
    if(temp!=NULL){
        inorder_traversal(temp->left);
        cout<<temp->data<<" ";
        inorder_traversal(temp->right);
    }
}


int main(){
    BinaryTree obj;
    obj.create_binary_tree();
    cout<<"Preorder Traversal:- "<<endl;
    obj.preorder_traversal(obj.root);
    cout<<endl;
    cout<<"Inorder Traversal:- "<<endl;
    obj.inorder_traversal(obj.root);
    cout<<endl;
    cout<<"Postorder Traversal:- "<<endl;
    obj.postorder_traversal(obj.root);
    cout<<endl;
    return 0;
}
