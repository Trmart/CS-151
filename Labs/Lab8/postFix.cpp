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



/**This function pulls out the substring up to the first space
 * and return the token, removing it from the expression.
 *
 * @param expression a postfix expression as string with 
 *        operands and operator separated by a single space
 * @return next token from the expression (operand or operator)
 */
string getNextToken(string& expression)
{
    // pull out the substring up to the first space
    // and return the token, removing it from the expression

    string token;
    int sepLoc = expression.find(SEPARATOR);
    if (sepLoc != static_cast<int>(string::npos))
    {
        token = expression.substr(0, sepLoc);
        expression = expression.substr(sepLoc + 1, expression.size() - sepLoc);
        return token;
    }
    else
    {
        token = expression;
        expression = "";
        return token;
    }
}
/*This function pushes numbers and operators to the stack, when it finds an operator it calls our calculation
 * function and preforms the calculation 
 *
 * @param expression a postfix expression as string with 
 *        operands and operator separated by a single space
 * @return the result at the top of the stack 
 */
double parsePostfix(string expression)
{
    stack<double> ourStack;
    while(expression != "")    // loop while expression is not empty string
    {
        //get the next token and removes it from expression
        string token = getNextToken (expression);
        //if token is not an operator
        
        if (string::npos == OPERATORS.find(token))
        {
            //push to stack when you get a number
            ourStack.push(stod(token));
        }
        //else it is an operator
        else
        {
            //calculate when you get an operator
            performCalculation(ourStack, token[0]); 
        }
    }
    return ourStack.top(); 
}
/*This function performs calculations based on the stack and operands sent in 
 * and return the result to the parsePostfix. 
 *
 * @param stck of doubles s and our operator character 
 *        
 * @return the top of the stack and pushes result to the top of the  stack returned
 */
void performCalculation(stack<double>& s, char op)
{
    // get two operands from the stack
    double operand1 = s.top(); 
    s.pop(); 
    double operand2 = s.top(); 
    s.pop(); 

    double result; 

    // compute the operation
    if(op =='+')
    {
        result = operand1 + operand2; 
    }
    else if(op == '-')
    {
        result = operand2 - operand1;
    }

    else if(op == '*')
    {
        result= operand1 * operand2;
    }
    else if(op == '/')
    {
        result = operand2 / operand1;
    }

    // return result of computation
    s.push(result); 
}