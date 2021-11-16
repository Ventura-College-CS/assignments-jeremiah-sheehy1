
#include <iostream>
#include "stack.h"
#include "PostFix.h"
using namespace std;

class PostfixExp
{
private:
	string expression;

    int isOperator(char op)
	{
		switch (op)
		{
		case '+':
		case '-':
		case '*':
		case '/':
			return 1;
		default:
			return 0;
		}
	}
	int evaluate(int op1, int op2, char opr)
	{
		int result;
		switch (opr)
		{
		case '*':
			result = op1 * op2;
			break;
		case '/':
			result = op1 / op2;
			break;
		case '+':
			result = op1 + op2;
			break;
		case '-':
			result = op1 - op2;
			break;
		default:
			cout << "Undefined operator error\n";
			exit(0);
		}
		return result;
	}

public:
	PostfixExp() {} 
	PostfixExp(string s)
	{
		expression = s; 	
	}
	void setExpression(string s)
	{
		expression  = s;
	}
	void printExpression() const
	{
		for (int i = 0; i < expression.size(); i++)
			cout << expression[i] << "\t";
		cout << endl;
	}
	int Evaluation()
	{
		int input, opr1, opr2, result;
		const int offset = 48;
		Stack<int> stack;
		
		for (int i = 0; i < expression.size(); i++)
		{
			input = expression[i];
			if (isdigit(input))
				stack.push(int(input) - offset);
			else if (isOperator(input))
			{
				opr1 = stack.pop();
				opr2 = stack.pop();
				result = evaluate(opr1, opr2, input);
				stack.push(result);
			}
		}
	}
};