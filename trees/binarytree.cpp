#include<iostream>
using namespace std;

// Structure for Binary tree params
struct btree_node{
    btree_node *left;
    btree_node *right;
    int data;
};
// Binary tree Class
class bt{
    btree_node *root;
    public:
    bt(){
        root = NULL;
    }
    int isempty() {
        return(root == NULL);
    }
    void insert(int item);
    void displayBinaryTree();
    void printBinaryTree(btree_node *);
};
// Inserts item into tree
void bt::insert(int item){
    btree_node *p = new btree_node;
    btree_node *parent;
    p->data = item;
    p->left = NULL;
    p->right = NULL;
    parent = NULL;
    if(isempty())
        root = p;
    else{
        btree_node *ptr;
        ptr = root;
        while(ptr != NULL){
            parent = ptr;
            if(item > ptr->data)
                ptr = ptr->right;
            else
                ptr = ptr->left;
        }
        if(item < parent->data)
            parent->left = p;
        else
            parent->right = p;
    }
}



void bt::displayBinaryTree(){
    printBinaryTree(root);
}
void bt::printBinaryTree(btree_node *ptr){
    if(ptr != NULL){
        printBinaryTree(ptr->left);
        cout << "  " << ptr->data << "     ";
        printBinaryTree(ptr->right);
    }
}

int main(){
    bt b;
    b.insert(5);
    b.insert(15);
    b.insert(45);
    b.insert(135);
    cout << "Binary tree created: " << endl;
    b.displayBinaryTree();
}
