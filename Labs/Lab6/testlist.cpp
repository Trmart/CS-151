

// testlist.cpp
// Description: Understanding linked list
// Name(s): Taylor Martin, Dan Blanchette, Aaron Agostinelli
// Date: 2/20/20
//Use the code below to represent your version of the list STL class.
#include <iostream>
#include <string> 
using namespace std;

struct ListNode
{
    string name;
    ListNode* next;

    ListNode(){}  // default constructor

    ListNode(string& name1, ListNode* next1=nullptr)
    {
        name = name1;
        next = next1;
    }

    ListNode(const char* name1, ListNode* next1=nullptr)
    {
        name = name1;
        next = next1;
    }
};

int main()
{
    char ch = '\0';

    // STEP 1: Get a paper and draw the linked list based
    // on the next line of code. Label it as STEP 1.
    ListNode* head = nullptr;

    // STEP 2: Draw the linked list based on the next 3 lines of code
    // Label it as STEP 2.
    head = new ListNode; 
    head->name = "Fruit Salad"; // FS
    head->next = nullptr;

    // STEP 3A: Draw the linked list based on the next 3 lines of code
    // Label it as STEP 3A.
    ListNode* ptr = new ListNode;
    ptr->name = "Pineapple Upside Down Cake"; // PUDC
    ptr->next = nullptr;
    // STEP 3B: Redraw the linked list based on the next line of code
    // Label it as STEP 3B.
    head->next = ptr;

    // STEP 4: Draw the linked list based on the next line of code.
    // Ensure you that can explain that sequence of steps that happened
    // in this single line of code. Also that you can identify which
    // constructor in the ListNode struct was called.
    head = new ListNode("Berry Cobbler", head); // BC

    // STEP 5A: Draw the linked list based on the next 3 lines of code
    // Label it as STEP 5A.
    ptr = new ListNode;
    ptr->name = "Banana Bread"; // BB
    ptr->next = nullptr;
    // STEP 5B: Redraw the linked list based on the next line of code
    // Label it as STEP 5B.
    head->next->next->next = ptr;

    // STEP 6: Add a 5th node with the dessert name "Carrot Cake"
    // and attached the 5th node at the end of the list
//    head = new ListNode("Carrot Cake", head);
    ptr = new ListNode; 
    ptr->name = "Carrot Cake"; 
    ptr->next= nullptr; 
    head->next->next->next->next = ptr;
    // cout << head->next->next->next->next->name; 
    // STEP 7: Add a 6th node with the dessert name "Buko Pandan"
    // and attached this node at the front of the list
    head = new ListNode("Buko Pandan", head);
    // ptr-
    cout << "\nPress enter to continue\n";
    cin.get(ch);
    cout << '\n';

    cout << "My Favorite Desserts!\n";
    cout << "=====================\n";
    cout << "1. " << head->name << '\n';
    cout << "2. " << head->next->name << '\n';
    cout << "3. " << head->next->next->name << '\n';
    cout << "4. " << head->next->next->next->name << '\n';
    cout << "5. " << head->next->next->next->next->name << '\n';
    cout << "6. " << head->next->next->next->next->next->name << '\n';
    // STEP 8: Add two more cout(s) to printout the two nodes
    // you just added.

    cout << "\nPress enter to continue\n";
    cin.get(ch);
    cout << '\n';

    cout << "My Favorite Desserts!\n";
    cout << "=====================\n";

    // STEP 9: Add two more cout(s) at the end to
    // printout the remaining nodes following the pattern
    // of code below.
    ListNode* nodePtr = head;
    // cout << "1. " << nodePtr->name << '\n';
    // nodePtr = nodePtr->next;
    // cout << "2. " << nodePtr->name << '\n';
    // nodePtr = nodePtr->next;
    // cout << "3. " << nodePtr->name << '\n';
    // nodePtr = nodePtr->next;
    // cout << "4. " << nodePtr->name << '\n';
    // nodePtr = nodePtr->next;
    // cout << "5. " << nodePtr->name << '\n';
    // nodePtr = nodePtr->next;
    // cout << "6. " << nodePtr->name << '\n';
    // cout << "\nPress enter to continue\n";
    // cin.get(ch);
    // cout << '\n';

    // STEP 10: Study how the items in the linked list
    // are printed in STEP 9. Write a while loop to simplify
    // the code.
    int count=1;
    
    while(nodePtr!=nullptr)
    {   
        
        cout << count << ".) " << nodePtr->name << '\n'; 
        nodePtr = nodePtr->next; 
        count++;
        // cout << count  <<".) "<< nodePtr->name << '\n'; 
        // nodePtr = nodePtr->next; 
        
    }

    //*********************************************************
    // CODES AFTER THIS LINE WILL NOT BE GRADED AS PART OF THIS
    // LAB. BUT I HIGHLY ENCOURAGE YOU TO FINISH IT SINCE
    // UNDERSTANDING THIS WILL HELP YOU ON WHAT'S AHEAD.
    //*********************************************************

    // STEP 11: Between "Berry Cobbler" and "Banana Bread"
    // insert the dessert "Camote Cue" then print out the
    // list of desserts again using the code you wrote in STEP 5.
    // (OPTIONAL: You could just make a function for the code
    // you wrote in STEP 10 and call it again here).

    // STEP 12: Who eats fruits these days??? Update "Fruit Salad"
    // as "Deep Fried Fruit Salad"

    // STEP 13: Remove "Berry Cobbler" from the linked list and
    // print the dessert list again.

    // STEP 14: Delete everything in the linked list one by one.

    return 0;
}
