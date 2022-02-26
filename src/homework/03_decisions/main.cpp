#include<iostream>
#include<string>
using std::cout; using std::cin;
//write include statements
#include "decisions.h"

int main() 
{
	int selection;
	int grade;
	cout<<"\t"<<"-MAIN MENU-"<<"\n";
	cout<<"Please type select from these three options"<<"\n";
	cout<<"Grade using IF statements: Type 1 "<<"\n";
	cout<<"Grade using Switch statements: Type 2"<<"\n";
	cout<<"Exit program: Type 3"<<"\n";
	cin>>selection;
	switch(selection)
	{
	case 1:
		cout<<"please input the grade"<<"\n";
		cin>>grade;
		cout<<get_letter_grade_using_if(grade);
		break;
	case 2: 
		cout<<"please input the grade"<<"\n";
		cin>>grade;
		cout<<get_letter_grade_using_switch(grade);
		break;
	case 3:
		cout<<"Exiting program...";
		break;
	default:
		cout<<"Not a valid input.";	
	}


	return 0;
}