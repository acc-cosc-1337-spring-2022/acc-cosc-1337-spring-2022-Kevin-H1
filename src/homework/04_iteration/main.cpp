//write include statements
#include "dna.h"


int main() 
{
	int select = 0;
	int confirmation;
	int end_flag = 0;
	do
	{

		//Menu start up
		cout<<"\nMain Menu\n";
		cout<<"Please select an option\n";
		cout<<"Type 1 - for factorial\n"
			<<"Type 2 - for Greatest Common Divisor\n"
			<<"Type 3 - to Exit.\n";
		//User selections menu item
		cin>>select;
		//Check if user wants to exit
		if(select == 3)
		{
			cout<<"Are you sure you want to exit?\n"
            <<"Type 0 to continue or 1 to exit\n";
			cin>>confirmation;
			//Input validation
			while(confirmation < 0 or confirmation > 1)
			{
				cout<<"not a valid input, type 0 to continue or 1 to exit: \n";
				cin>>confirmation;
				if(confirmation == 1)
				{
					cout<<"Program is exiting...\n";
					end_flag = 1;
				}
				else if(!confirmation)
				{
					cout<<"Program will continue...\n";
				}
			}
		}
		else
		{
			menu_selection(select);
		}
	}
	while(end_flag != 1);
	return 0;
}


//Runs factorial or GCD depending on user selection
void menu_selection(int selection)
{
    switch (selection)
    {
    case 1:
		//Factorial Option Selected
        int input_data;
        cout<<"Please input the integer you wish to calculate its factorial\n";
        cin>>input_data;
        cout<<"The factorial of "<<input_data<<" is "<<factorial(input_data)<<"\n";
        break;
    case 2:
		//GCD Option Selected
        int num1;
        int num2;
        cout<<"Please enter two integers you wish to find their GCD\n";
        cout<<"First input: ";
        cin>>num1;
        cout<<"Second input: ";
        cin>>num2;
        cout<<"The GCD of "<<num1<<" and "<<num2<< " is "<<gcd(num1, num2)<<"\n";
        break;
    default:
		//Any other input
		cout<<"Not a valid input. Try again...\n";
        break;
    }
}


