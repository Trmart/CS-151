/*Taylor Martin
   Dan Blanchette
   Lab 07 
   CS-151L 
   2/27/20*/
#include "list.h" 
    
List::List()
{   
    m_head = nullptr; 
    m_tail = nullptr;  
    m_size = 0; 
}
List::List(const string arr[], int size)
{
    m_head = nullptr; 
    m_tail = nullptr;  
    m_size = 0; 
    for (int i = 0; i < size; i++)
    {   
        addEnd(arr[i]); 
    }
    
}
List::List(const vector<string>& vec)
{
    m_head = nullptr; 
    m_tail = nullptr;  
    m_size = 0; 
    for (int i = 0; i < vec.size(); i++)
    {   
        addEnd(vec[i]); 
    }
}
List::List(const List& srcList)
{
    m_head = nullptr; 
    m_tail = nullptr;  
    m_size = 0; 
    ListNode* nodePtr = srcList.m_head;
    while (nodePtr)
    {
        addEnd(nodePtr->value); 
        nodePtr = nodePtr->next; 
    }
    
}
List::~List()
{

}


// Adds an element to the beginning of the list
void List::addFront(string data)
{
    if (m_head == nullptr)
    {
        m_head = m_tail = new ListNode(data,nullptr,nullptr);
    }
    else // not empty
    {
       m_head = new ListNode(data, m_head, nullptr);
       m_head->next->prev = m_head;
    }
    ++m_size;
}

// Adds an element to the end of the list
void List::addEnd(string data)
{
    if (m_head == nullptr)
    {
        m_head = m_tail = new ListNode(data,nullptr,nullptr);
    }
    else // not empty
    {
       m_tail = new ListNode(data, nullptr, m_tail);
       m_tail->prev->next = m_tail; 
    }
    ++m_size;
}

// Removes the first element of the list
void List::removeFront()
{   
   
    if(m_head != nullptr)
    {
        ListNode* nodePtr = m_head; 
        m_head = m_head->next; 
        m_head->prev = nullptr; 
        delete nodePtr; 
    }
    --m_size; 
    
}

// Removes the last element of the list
void List::removeEnd()
{
    if(m_tail != nullptr)
    {
        ListNode* nodePtr = m_tail; 
        m_tail = m_tail->prev; 
        m_tail->next = nullptr; 
        delete nodePtr; 
    }
    --m_size; 
}

// Returns the number of elements
int List::size() const
{
    return m_size; 
}

// Returns true if list is empty, otherwise false
// bool empty() const
// {

// }

// Returns string of the values in the list separated by spaces
string List:: str() const
{
    ostringstream ostr; 
    ListNode* nodePtr = m_head; 
    while(nodePtr != nullptr)
    {
        ostr << nodePtr->value << " "; 
        nodePtr=nodePtr->next; 
    }
    return ostr.str(); 
}

// Returns string of the values in the list in reverse 
// separated by spaces
string List::strReverse() const
{
    ostringstream ostr; 
    ListNode* nodePtr = m_tail; 
    while(nodePtr != nullptr)
    {
        ostr << nodePtr->value << " "; 
        nodePtr=nodePtr->prev; 
    }
    return ostr.str(); 
}

// Returns a reference to the value of the first element in the list
string& List::front()
{
    return m_head->value; 
}

// Returns a reference to the value of the last element in the list
string& List::end()
{
    return m_tail->value; 
}

// Returns a reference to the value of nth index in the list
string& List::getNth(int index) const
{   
    ListNode* nodePtr = m_head; 
    for (int i = 0; i < index; i++)
    {
        nodePtr=nodePtr->next; 
    }
    return nodePtr->value; 
}


// Returns the vector version of the list
vector<string> List::toVector() const
{

}