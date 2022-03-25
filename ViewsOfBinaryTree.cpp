// Displaying of Various Views of Binary Tree ( Top, Right, Bottom, Left )
#include <iostream>
#include <queue>
using namespace std;
class Node                    // Node class created for each Tree Node creation
{
    public:
    int data;         // Data member
    Node* left;      // Left Node pointer
    Node* right;     // Right Node pointer
    Node* root;      // Root Node pointer
    public:
    Node (int val)    // Parametrized Constructor
    {
        data = val;
        left = NULL;
        right = NULL;
        root = NULL;
    }
};
class BinaryTree     //  Class created for Binary Tree Implementation ( Non-Linear Data Structure )
{
    public:
    Node* InsertNodeInTree(Node* root, int val)   // Inserting Node recursively.. O(log n) time
    {
        if(root == NULL)               // If No root node is there, create one
            return new Node(val);
        if(val <= root -> data)   // If data is lesser than or equal to parent store in left subtree
            root -> left = InsertNodeInTree(root -> left, val);
        else         // If data is greater than the parent stor it in right subtree
            root -> right = InsertNodeInTree(root -> right, val);
        return root;
    }
    void ShowTree(Node* root)   // Displaying tree with Node.. O(log n) time
    {
        Node* temp = root;
        if(temp == NULL)    // If Tree is empty nothing to show
            return;                            // Control moves out of the function
        ShowTree(temp -> left);     // Recursive Call
        cout << "Node: " << endl;
        if(temp -> left != NULL)    // If left subtree is not empty
            cout << "\t" << temp -> data << " ---> " << temp -> left -> data << "\t Left ( Occupied )" << endl;
        else      // If left subtree is empty
            cout << "\t" << temp -> data << "\t\t Left ( Empty )" << endl;
        if(temp -> right != NULL)   // If right subtree is not empty
            cout << "\t" << temp -> data << " ---> " << temp -> right -> data << "\t Right ( Occupied ) " << endl;
        else     // If right subtree is empty
            cout << "\t" << temp -> data << "\t\t Right ( Empty )" << endl;
        ShowTree(temp -> right);     // Recursive Call
    }
    void RightViewOfTree(Node* root)    // Printing Rightmost Nodes of the Binary Tree ( Right View )
    {
        if(root == NULL)    // If current becomes empty, then backtrack
            return;
        queue<Node*> Queue;   // Queue created of Node data type ( user defined )
        Queue.push(root);          // Enqueuing root element to the Queue
        while(!Queue.empty())    // If Queue is not Empty
        {
            int size = Queue.size();       // Evaluating size of every Level of the Tree
            for(int j = 0; j < size; j++)       
            {
                Node* curr = Queue.front();    // Storing front Node
                Queue.pop();                       // Dequeuing the First Node
                if(j == size-1)                       // Print the Node data at the end element of the
                    cout << curr -> data << ", ";     // queue ( the rightmost node )
                if(curr -> left)
                    Queue.push(curr -> left);     // Enqueuing Left Node if present
                if(curr -> right)
                    Queue.push(curr -> right);    // Enqueuing Right Node if present
            }
        }
    }
    void LeftViewOfTree(Node* root)   //  Printing the Leftmost Nodes of the Binary Tree ( Left View )
    {
        if(root == NULL)   // If Current Node is empty, backtrack
            return;
        queue<Node*> Queue;    // Queue creation of Node data type ( user defined )
        Queue.push(root);          // Enqueuing Root Node
        while(!Queue.empty())   // If Queue is not empty
        {
            int size = Queue.size();         // Getting size of each level of the Tree 
            for(int j = 0; j < size; j++)  
            {
                Node* curr = Queue.front();    // Storing front Node value
                Queue.pop();                   // Dequeuing First Node
                if(j == 0)                         // Printing the first Node of each Level of the
                    cout << curr -> data << ", ";  // tree, the first Queue element ( the leftmost Node )
                if(curr -> left)
                    Queue.push(curr -> left);   // If Left Node exist, Enqueue it
                if(curr -> right)
                    Queue.push(curr -> right);  // If Right Node exist, Enqueue it
            }
        }
    }
    void BottomViewOfTree(Node* root)  // Printing every Leaf Node of the Tree ( Bottom View )
    {
        if(root == NULL)    // If the Current Node is empty, then we backtrack
            return;
        queue<Node*> Queue;    // Queue creation of Node data type ( user defined )
        Queue.push(root);          // Enqueuing Root node to the Queue
        while(!Queue.empty())    // If Queue is not empty
        {
            int size = Queue.size();         // Getting size of every level of the Tree iteratively
            for(int j = 0; j < size ; j++)
            {
                Node* curr = Queue.front();    // Getting the front element of the Queue
                Queue.pop();                   // Dequeuing the first element
                if(curr -> left == NULL && curr -> right == NULL)
                    cout << curr -> data << ", ";    // Printing the Node having no child Nodes below it
                if(curr -> left)
                    Queue.push(curr -> left);   // If Left Node present, Enqueue it
                if(curr -> right)
                    Queue.push(curr -> right);   // If Right Node present, Enqueue it
            }
        }
    }
    void TopViewOfTree(Node* root)    // Printing the Leftmost Subtree and Rightmost Subtree from the
    {                                 // Root node ( Top view )
        if(root == NULL)
           return;             // If Current Node is empty, then we backtrack
        Node* temp = root;        // Temporary Root Node pointer created
        while(temp != NULL)    // If Current Node is not empty
        {
            cout << temp -> data << ", ";    // Printing and Traversing through the Left most side
            temp = temp -> left;             // of the Subtree from the Root Node
        }
        temp = root -> right;             // Temporary pointer adjusted
        while(temp != NULL)         // If Current Node is not empty
        {
            cout << temp -> data << ", ";    // Printing and Traversing through the Right most side
            temp = temp -> right;            // of the Subtree from the Root Node
        }
    }
};
int main()
{
    Node* root = NULL;      // Root node initialization
    BinaryTree binarytree;      // Object creation of Binary Tree
    int s, x;
    cout << "Enter root Node value : ";
    cin >> x;
    root = binarytree.InsertNodeInTree(root, x);    // Root Node created
    cout << "Enter the number of Nodes to Insert in the Binary Search Tree : ";
    cin >> s;
    for(int i = 1; i <= s; i++)   // Loop begins
    {
        cout << "Enter the New Node value : ";
        cin >> x;
        binarytree.InsertNodeInTree(root, x);   // Calling Insert Tree function
    }
    binarytree.ShowTree(root);
    cout << "The Right View of the Binary Tree is :  ";  // Printing Right View of the Binary Tree
    binarytree.RightViewOfTree(root);
    cout << endl;
    cout << "The Left View of the Binary Tree is :   ";  // Printing Left View of the Binary Tree
    binarytree.LeftViewOfTree(root);
    cout << endl;
    cout << "The Bottom View of the Binary Tree is : ";  // Printing Bottom View of the Binary Tree
    binarytree.BottomViewOfTree(root);
    cout << endl;
    cout << "The Top View of the Binary Tree is :    ";  // Printing Top View of the Binary Tree
    binarytree.TopViewOfTree(root);
    cout << endl;
    return 0;          // End of Program
}