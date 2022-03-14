// Taylor Martin 
// Dan Blanchette
// Aaron Agostinelli 
// 3/12/20
// CS-151 Lab 09 
// Binary Search Trees
#include <iostream> 
#include <string> 


#ifndef BST_H 
#define BST_H

using namespace std; 

struct TreeNode
{
    string data; 
    TreeNode* left; 
    TreeNode* right; 
    TreeNode()
    {

    } 
    TreeNode(string data1, TreeNode *left1 =nullptr, TreeNode *right1 = nullptr)
    {
        data  = data1;
        left  = left1;
        right = right1;
    }

}; 

class BST
{
public:
    BST()  // constructor
    {
        m_root=nullptr;
    } 
    ~BST()
    {} // destructor
    void addNode(string data);    //adds an item to the BST 
    void printInOrder();    //prints BST contents inorder
    void printPreOrder();    
    void printPostOrder();
    int size();    //use recursive
    string minValue();    //return the minimum data value in BST
    string maxValue(); 
    traverseInOrder();    //traverse the BST inorder and place the inorder strings back into the original array of peoples' names
    bool isEmpty(); 
    void clear(); 
private:
    TreeNode* m_root;
    int sizeHelper(TreeNode *ptr);
    void destroyTree();    //helper function called from the destructor
    void addNodeHelper(TreeNode*&ptr,string data);
    void printInOrderHelper(TreeNode*ptr); 
    void printPreOrderHelper(TreeNode*ptr); 
    void printPostOrderHelper(TreeNode*ptr);
    string minValueHelper(TreeNode * ptr);    //return the minimum data value in BST
    string maxValueHelper(TreeNode*ptr); 
    void destroyTree(TreeNode*ptr); 
    void storeInOrder(TreeNode*&ptr); 
};
#endif
