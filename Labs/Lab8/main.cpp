/**@Lab 08 Stacks
 * This program uses postfix and prefix to preform stack operations 
 * @Taylor Martin
 * Aaron Agostinelli
 * Stephen Haldi
 * @3/5/20
 */
#include <iostream>
#include <string>
#include <stack>
#include "postFix.h"
using namespace std;


int main()
{
    string expression;

    do
    {
        cout << "Please Enter a Post Fix Expression(blank to quit): "; 
        getline(cin, expression);
        cout << "\n";
        cout << "The answer is : " << parsePostfix(expression);
        cout << "\n\n";
    } while (expression!="");
    
    return 0;
}

