//Kyle Neubarth
//recitation #
//Monica Tak
#include <iostream>

using namespace std;

int addNumber(int a, int b)
{
    int x;
    x = a + b;
    return x;
}
void swapTwoNumbers(int a, int b) {
    int temp;
    cout << "Before swapping." << endl;
    cout << "a = " << a << ", b = " << b << endl;

    temp = a;
    a = b;
    b = temp;

    cout << "\nAfter swapping." << endl;
    cout << "a = " << a << ", b = " << b << endl;
}

int loopsOfNumbers(int n) {
    for (int i=n;i>=0;i--) {
        cout << i * i << endl;
    }
    return -1;
}

int main(){
    //~~~~~~~~~~~ Loops and Numbers ~~~~~~~~~~~~~~~~~~~~~
    cout << "Enter a number: " << endl;
    int number;
    cin >> number;
    cout << endl;
    loopsOfNumbers(number);

    //~~~~~~~~~~~~ Swapping Numbers ~~~~~~~~~~~~~~~~~~~~~
    swapTwoNumbers(16,79);

    //~~~~~~~~~~~~ Adding Numbers ~~~~~~~~~~~~~~~~~~~~~~~
    cout<< "Let’s perform some addition." << endl;
    cout << "Please enter the First number:" <<endl;
    int firstnum;
    cin >> firstnum;
    cout << "Please enter the Second number:" << endl;
    int secondnum;
    cin >> secondnum;
    int res;
    res = addNumber(firstnum,secondnum);
    cout  << "The Sum of Two numbers is " << res << endl;
    return 0;
}