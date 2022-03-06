#include "dna.h"

int factorial(int num)
{
    int sum = (num + 1) - num;
    while(num > 0)
    {
        sum = sum * num;
        num--;
    }
    return sum;
}

int gcd(int num1, int num2)
{
    while(num1 != num2)
    {
        if(num1 < num2)
        {
            int temp;
            temp = num1;
            num1 = num2;
            num2 = temp;
        }
        else if(num1 > num2)
        {
            num1 = num1 - num2;
        }
    }
    return num1;

}
