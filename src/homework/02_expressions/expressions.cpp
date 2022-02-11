#include "expressions.h"



//example
int add_numbers(int num1, int num2)
{
	return num1 + num2;
}

//write code for multiply_numbers function here
//function returns product of num1 and num2

double get_sales_tax_amount(double meal_amount)
{
	return TAX_RATE * meal_amount;
}

double get_tip_amount(double meal_amount, double tip_rate)
{
	return meal_amount * (tip_rate/100);
}
