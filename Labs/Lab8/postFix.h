/**@Lab 08 Stacks
 * This program uses postfix and prefix to preform stack operations 
 * @Taylor Martin
 * Aaron Agostinelli
 * Stephen Haldi
 * @3/5/20
 */
#ifndef POSTFIX_H
#define POSTFIX_H
#include <iostream>
#include <string>
#include <stack>
using namespace std; 

const string OPERATORS = "+-*/";
const string SEPARATOR = " ";

string getNextToken(string& expression);
double parsePostfix(string expression);
void performCalculation(stack<double>& s, char op);

#endif 