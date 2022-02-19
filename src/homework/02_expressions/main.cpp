//write include statements
#include "expressions.h"
#include<iostream>


//write namespace using statement for cout
using std::cout; using std::cin; 

/*
Call multiply_numbers with 10 and 10 parameter values and display function result
*/
int main()
{
	double meal_amount, tip_rate, tip_amount, tax_amount, total;
	cout<<"Type Meal Amount: ";
	cin>>meal_amount;
	tax_amount = get_sales_tax_amount(meal_amount);
	cout<<"Type tip rate (in percentage): ";
	cin>>tip_rate;
	tip_amount = get_tip_amount(meal_amount, tip_rate);

	total = tip_amount + tax_amount + meal_amount;

	cout<<"\n"<<"Meal Amount: \t"<<meal_amount<<"\n"<<
		  "Sales tax: \t"<<tax_amount<<"\n"<<
		  "Tip Amount: \t"<<tip_amount<<"\n"<<
		  "Total: 	       "<<total<<"\n"; 



	return 0;
}
