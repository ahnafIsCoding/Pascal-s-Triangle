// pascalstriangle.cpp

#include <iostream>

using namespace std;

void pascalsTriangle(unsigned int x) {

    cout << endl;

    // default cases
    if (x <= 1) { // printing only 1 row if the input is <= 1
        cout << "1" << endl;
        return;
    }

    else if (x == 2) { // printing the first 2 rows if the input is exactly 2
        cout << " 1 \n1 1\n";
        return;
    }

    // main part of the function
    else {

        for (int k = 1; k <= 2; k++) { // printing the first 2 rows with formatting

            cout << " ";
            for (int j = 0; j < x - k; j++) { // parent int = x, nested int = k
                cout << " ";
            }
            for (int j = 0; j < k; j++) {
                cout << "1 ";
            }
            cout << endl;
        }

        unsigned long int s[x]; // having a super array that will keep record of the current row and help build the next row
        s[0] = s[1] = 1; // assigning 1 to the first 2 indexes -- this will help generate the 3rd row, since an element of a new row is made of off the sum of its previous row's elements
        
        for (int i = 2; i < x; i++) { // i = 2 because the first 2 rows have already been printed

            unsigned long int n[i+1]; // array n will generate the next row
            n[0] = n[i] = s[i] = 1; // assigning 1 to the first and last index of n and the 'i'th (current row number) index of s

            for (int j = 1; j < i; j++) {
                n[j] = s[j-1] + s[j]; // assigning the sum of the previous row's elements from the s array to the current element of the n array
            }

            // printing the current row with formatting
            for (int j = 0; j < x - i; j++) { // parent int = x, nested int = i
                cout << " ";
            }

            for (int k = 0; k <= i; k++) {
                cout << n[k] << " "; // printing the current row that is stored in n
                s[k] = n[k]; // updating the super array with the elements of the current row so it can generate the next row
            }
            cout << endl;
        }
    }
}

void again(); // prototype

int main() {

    cout << "\nWelcome to Pascal's Triangle generator!!!\n\n";

    int r;

    do {

        cout << "Enter the number of rows you want to print: ";
        cin >> r;

        if (r <= 0) cout << "\nPlease enter a valid input!\n\n";

    } while (r <= 0); // input validation

    pascalsTriangle(r); // calling the function with the user input as the argument

    again(); // prompt to restart

    return 0;
}

void again() {

    int c;

    do {

        cout << "\nDo you wish to print it again? (1 for yes, 0 for no): ";
        cin >> c;

        if (c != 1 && c != 0) cout << "\nPlease enter a valid choice!\n";

    } while (c != 1 && c != 0); // input validation

    if (c == 1) main();

    else cout << "\nThank you for trying this program. Hope to see you soon! :)\n\n";
}


/*

Identified bug(s)/design issue(s):

- The triangle breaks out of shape once the value of an element reaches multiple digits, and the whole thing starts to look wacky on the terminal!
> Possible solution(s): Needs rigorous teawking of the terminal display with the help of available C++ libraries that can manipulate the cout function such as adjusting the width of the line and other useful functions.

*/