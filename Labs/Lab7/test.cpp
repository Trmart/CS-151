// test.cpp
// Description:
/*Taylor Martin
   Dan Blanchette
   Lab 07 
   CS-151L 
   2/27/20*/
#include <iostream>
#include <vector>
#include <string>
#include "list.h"

using namespace std;

int main()
{
    /**STEP 1: Implement the following functions only
     *   a) List()  <- default constructor only
     *   b) addFront()
     *   c) str()
     */


    /**STEP 2: Uncomment the next 5 lines of code. 
     * Compile and run to test.
     */
    List myList;
    myList.addFront("fox");
    myList.addFront("brown");
    myList.addFront("quick");
    cout << myList.str() << "\n";

    /**STEP 3: Implement strReverse() then uncomment the next
     * line of code. Recompile and run to test.
     */
    cout << myList.strReverse() << "\n\n";

    /**STEP 4: Implement addEnd() then uncomment the next 5
     * lines of code. Recompile and run to test.
     */
    myList.addEnd("jumps");
    myList.addEnd("over");
    myList.addEnd("lazy");
    cout << myList.str() << "\n";
    cout << myList.strReverse() << "\n\n";

    /**STEP 5: Uncomment the next 4 lines of code.
     * Recompile and run to test.
     */
    myList.addFront("the");
    myList.addEnd("dog");
    cout << myList.str() << "\n";
    cout << myList.strReverse() << "\n\n";

    /**STEP 6: Implement removeFront() then uncomment the 
     * next 3 lines of code. Recompile and run to test.
     */
    myList.removeFront();
    myList.removeFront();
    cout << myList.str() << "\n\n";

    /**STEP 7: Implement removeEnd() then uncomment the
     * next 2 lines of code. Recompile and run to test.
     */
    myList.removeEnd();
    cout << myList.str() << "\n\n";

    /**STEP 8: Uncomment the next 6 lines of code. Recompile
     * and run to test.
     */
    myList.addFront("maleficent");
    myList.addFront("A");
    myList.addEnd("sabertooth");
    myList.addEnd("tiger");
    cout << myList.str() << '\n';
    cout << myList.strReverse() << "\n";

    /**STEP 9: Implement front() and end(). Uncomment the
     * next 3 lines of code. Recompile and run to test.
     */
    myList.front() = "The";
    myList.end() = "dragon";
    cout << myList.str() << '\n';

    const int SIZE = 5;
    string students[SIZE] = {"Barry", "John", "Mario", "Yazzi", "Lipton"};
    /**STEP 10: Implement List(string[], int) constructor.
     * Uncomment the next 3 lines of code. Recompile and run to test.
     */
    List myList1(students, SIZE);
    cout << "\nInitialize list with an array: \n";
    cout << myList1.str() << '\n';

    vector<string> fruits = {"guyabano", "caimito", "atis", "lanzones",                  
                             "santol", "durian", "langka", "papaya", 
                             "rambutan", "siniguelas"};
    /**STEP 11: Implement List(vector<string>) constructor.
     * Uncomment the next 3 lines of code. Recompile and run to test.
     */
    List myList2(fruits);
    cout << "\nInitialize list with a vector: \n";
    cout << myList2.str() << '\n';

    /**STEP 12: Implement List(List&) constructor.
     * Uncomment the next 3 lines of code. Recompile and run to test.
     */
    List myList3(myList2);
    cout << "\nInitialize list with another list: \n";
    cout << myList3.str() << '\n';

    /**STEP 13: Implement size() and getNth().
     */

    /**STEP 14: Using size() and getNth(), write the code
     * to print out the list. It should display as
     *   Filipino Fruits
     *   1. guyabano
     *   2. caimito
     *   3. atis
     *   4. lanzones
     *   5. santol
     *   6. durian
     *   7. langka
     *   8. papaya
     *   9. rambutan
     *   10. siniguelas
     */
    cout << "\nFilipino Fruits\n";
    for (int i = 0; i < myList3.size(); i++)
    {
        cout << i+1 << ". " << myList3.getNth(i) << "\n"; 
    }
    

    /**STEP 15: Implement toVector(). Uncomment the next
     * 6 lines of code. Recompile and run to test.
     */
    // vector<string> myVector = myList3.toVector();
    // cout << "\nFilipino Fruits\n";
    // for (int i = 0; i < myVector.size(); ++i)
    // {
    //     cout << i + 1 << ". " << myVector[i] << '\n';
    // }

    return 0;
}