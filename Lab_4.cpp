/* 
 * File:   Lab_4.cpp
 * Author: Alyssa Gibson
 *
 * Created on February 6, 2019, 4:39 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {
    
    double ans;
    string ret = ""; // This is the return string
                     // that is built during the for loop
                     // and returned when the calculations
                     // are finished.
    
    string input1 = argv[1]; // Sets the first argument
                             // (that isn't ./Lab_4)
                             // to a string that can be 
                             // tested in varying cases.
    
    if (argc < 4) {
        // Fail Case 1- Less than 4 command line arguments
        //              (including program name and operator)
        if (!(input1 == "-h")) {
            cout << "Error: You need at least two numbers"
                    " and an operator" << endl;
        }
        // Exception: "-h"
        else {  
            cout << "Usage: Lab_4 <operation> <operands>" << endl;
        }
    }
    
    // From here, the input has passed the first fail case.
    // Next cases: finding out if there are multiple
    // or no operators.
    else {
        for (int i = 2; i < argc; i++) {
            // Fail Case 2- Only one operation allowed per run.
            string input = argv[i];
            if (input == "+" ||
                input == "*" ||
                input == "^") {
                cout << "Error: Only one operation can be"
                        " performed at a time." << endl;
                return 0; // Return early so that other cases
                          // aren't tested.
            }
        }
        // From here, we know that the input has
        // at most one operator.
        // But, it could still have none, so that
        // is dealt with in a separate else case.
        if (input1 == "+") {
            // Addition
            ans = 0;
            for (int i = 2; i < argc; i++) {
                ret += argv[i];
                if ((i + 1) != argc) {
                   ret += " + ";
                }
                double num = stod(argv[i]);
                ans += num;
            }
            
            cout << ret << " = " << ans << endl;
        }
        else if (input1 == "*") {
            // Multiply
            ans = 1;
            for (int i = 2; i < argc; i++) {
                ret += argv[i];
                if ((i + 1) != argc) {
                   ret += " * ";
                }
                double num = stod(argv[i]);
                ans = ans*num;
            }
            cout << ret << " = " << ans << endl;
        }
        else if (input1 == "^") {
            // Exponential
            ans = stod(argv[2]);
            for (int i = 3; i < argc; i++) {
                ret += argv[i];
                if ((i + 1) != argc) {
                    ret += "^";
                }
                double num = stod(argv[i]);
                ans = pow(ans, num);
            }
            cout << ret << " = " << ans << endl;
        }
        // Fail Case 3- No operators present.
        else {
            cout << "Error: You need to enter an operator"
                    " +, *, or ^." << endl;
        }
    }
    
    return 0;
}