#include<iostream>
using namespace std;
// Structure for each node of the binary tree
struct node
{
    int data;
    node* left;
    node* right;
};
// Function to create a new node
node* create_node(int val)
{
   node* newnode = new node;  // allocate memory for new node
   newnode->data = val;       // assign value to node
   newnode->left = 0;         // initially no left child
   newnode->right = 0;        // initially no right child
   return newnode;
}
// Inorder Traversal: Left → Root → Right
void inorder(node* root)
{
    if(root == 0)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
// Preorder Traversal: Root → Left → Right
void preorder(node* root)
{
    if(root == 0)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
// Postorder Traversal: Left → Right → Root
void postorder(node* root)
{
    if(root == 0)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right); 
    cout << root->data << " ";  
}
int main()
{
    // Making a simple tree manually
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    int val;
    cout << "Enter value for root node: ";
    cin >> val;
    node* root = create_node(val);

    cout << "Enter value for root->left: ";
    cin >> val;
    root->left = create_node(val);

    cout << "Enter value for root->right: ";
    cin >> val;
    root->right = create_node(val);

    cout << "Enter value for root->left->left: ";
    cin >> val;
    root->left->left = create_node(val);

    cout << "Enter value for root->left->right: ";
    cin >> val;
    root->left->right = create_node(val);
    
    // Traversal outputs
    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    return 0;

}
