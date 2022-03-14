// Taylor Martin 
// Dan Blanchette
// Aaron Agostinelli 
// 3/12/20
// CS-151 Lab 09 
// Binary Search Trees
#include "bst.h"

void BST::addNode(string data)
{
    addNodeHelper(m_root, data);  
}

 void BST::addNodeHelper(TreeNode*&ptr,string data)
 {
    if(ptr==nullptr)
    {
        ptr = new TreeNode(data); 
        return; 
    }
    if(ptr->data==data)
    {
        return; 
    }
    else if(ptr->data < data)
    {
        addNodeHelper(ptr->right,data); 
    }
    else if(ptr->data > data)
    {
        addNodeHelper(ptr->left,data); 
    }
 }

void BST::printInOrder()
{
    printInOrderHelper(m_root); 
    cout << "\n"; 
}

void BST::printInOrderHelper(TreeNode*ptr)
{ 
    if(ptr!=nullptr)
    {
        printInOrderHelper(ptr->left); 
        cout << ptr->data << " "; 
        printInOrderHelper(ptr->right);
    }
}

void BST::printPreOrder()
{
    printPreOrderHelper(m_root); 
    cout << "\n"; 
}
void BST::printPostOrder()
{
    printPostOrderHelper(m_root); 
    cout << "\n"; 
}
void BST::printPreOrderHelper(TreeNode*ptr)
{
    if(ptr!=nullptr)
    {
        cout << ptr->data << " "; 
        printPreOrderHelper(ptr->left); 
        printPreOrderHelper(ptr->right);
    }
}
void BST::printPostOrderHelper(TreeNode*ptr)
{
    
    printPostOrderHelper(ptr->left); 
    printPostOrderHelper(ptr->right);
    cout << ptr->data << " "; 
}
bool BST::isEmpty()
{
    return (m_root == nullptr);
}
int BST::size()
{
    return sizeHelper(m_root); 
}
int BST::sizeHelper(TreeNode *ptr)
{
    if (ptr == nullptr)
    {
        return 0;
    }
    return sizeHelper(ptr->left) + 1 + sizeHelper(ptr->right);
}
string BST::minValue()
{
    if(isEmpty())
    {
        return "";
    }
    return minValueHelper(m_root->left);
}
string BST::minValueHelper(TreeNode * ptr)   //return the minimum data value in BST
{
    if(ptr->left == nullptr)
    {
        return ptr->data;
    }
    else
    return minValueHelper(ptr->left);
}   

string BST::maxValue()
{
    if(isEmpty())
    {
        return "";
    }
    return maxValueHelper(m_root->right);
}
string BST::maxValueHelper(TreeNode * ptr)   //return the minimum data value in BST
{
    if(ptr->right == nullptr)
    {
        return ptr->data;
    }
    else
    return maxValueHelper(ptr->right);
} 
void BST::destroyTree(TreeNode*ptr)
{
    if(ptr!=nullptr)
    {
        destroyTree(ptr->left); 
        destroyTree(ptr->right);
        delete ptr; 
        ptr=nullptr; 
    }
}
void BST::clear()
{
    destroyTree(m_root); 
}
void BST::storeInOrder(TreeNode*&ptr)
{
    if(ptr!=nullptr)
    {
        storeInOrder(ptr->left); 
        storeInOrder(ptr->right); 
    }
}