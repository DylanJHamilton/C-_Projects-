#include <iostream>
#include <cmath>

//Very Basic Calculator
int main()
{

//Variable Declarations
int num1, num2;
char operation;
int result; 

//Communication between program and user. 
std::cout << "Enter your first number: ";
std::cin >> num1; //Assigns value for Num1

std::cout << "Enter your second number: ";
std::cin >> num2;  //Assigns value for Num2

std::cout << "Enter the operation: ";
std::cin >> operation;

//Checks the condition based on user input
if(operation == '+'){
    result = num1 + num2;
}
 else if(operation == '-'){
    result = num1 - num2;
 }
 else if(operation == '*'){
    result = num1 * num2;
 }
 else if(operation == '/'){
    result = num1 / num2;
 } 
  else{
    std::cout << "Invalid Operation: Try again."; 
    }

//Returns the result.
std::cout << "The result: " << result << std::endl;

return 0;

}