#include <iostream>
#include <conio.h>
#include <regex>
#include <string>
using namespace std;

int main()
{
    string in;
    cout << "Enter any arithmetic operation, for example 1 + 1: ";
    getline(cin, in);

    regex p("(\\d+)\\s*([-+])\\s*(\\d+)");
    smatch m;
    // check if the input string 'in' matches the regular expression pattern 'p'
    // and store the match results in 'm'
    if (regex_search(in, m, p)) {
        // convert the first captured group (representing the first number) to an integer
        int n1 = stoi(m[1]);
        // convert the third captured group (representing the second number) to an integer
        int n2 = stoi(m[3]);
        // get the second captured group (representing the operator) as a string,
        // then extract the first character of this string to get the operator
        char oper = m[2].str()[0];

        if (oper=='+'){
            cout<<n1<<" + " <<n2<<" = "<<(n1 + n2)<<endl;
        }
        else {
            if(oper=='-') {
                cout<<n1<<" - "<< n2<<" = "<<(n1 - n2)<<endl;
            }
        }
    }
    else {
        cout << "Invalid input" << endl;
    }
    return 0;
}
