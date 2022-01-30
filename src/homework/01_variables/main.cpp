//write include statements
#include "variables.h"
#include<iostream>


//write namespace using statement for cout
using std::cout; using std::cin;

int main()
{
	int num;
	int result;
	int num1 = 4;
	
	cout<<"Please type in an integer:"<<'\n';
	cin >> num;

	result = multiply_numbers(num);
	cout<<"The first result is: " << result << '\n';
		
	result = multiply_numbers(num1);
	cout<<"The second result is: "<<result<< '\n';

	return 0;
}
