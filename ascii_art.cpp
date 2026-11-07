#include <iostream>

int main();

int main() {
    int n{};
    std::cout << "Enter a non-negative integer: ";
    std::cin >> n;

    // Algorithm:
    // Let n be an arbitrary non-negative integer.
    // Say n = 3, then the output will be
    //
    //  row/column          1234567     
    //
    //      1               *******         number of spaces: 0
    //      2                *****          number of spaces: 1
    //      3                 ***           number of spaces: 2
    //      4                  *            number of spaces: 3
    //      5                 ***           number of spaces: 2
    //      6                *****          number of spaces: 1
    //      7               *******         number of spaces: 0
    //  
    // The total number of rows and the total number of columns
    // in the first row is (2n + 1).
    //
    // For each row from 1 to (2n + 1),
    // 1. For each column from 1 to ((2n + 1) - (number of spaces)),
    //    a. If the column number is less than or equal to thes
    //       number of spaces, print a space. Otherwise, print an
    //       asterisk.
    // 2. If the row number is less than or equal to n (upper part), 
    //    increment the number of spaces by 1. Otherwise (lower part),
    //    decrement it by 1.
    // 3. Move to the next line.
    int space{};
    for (int row{1}; row <= (2*n + 1); ++row) {
        for (int column{1}; column <= ((2*n + 1) - space); ++column) {
            if (column <= space) {
                std::cout << " ";
            } else {
                std::cout << "*";
            }
        }

        if (row <= n) {
            ++space;
        } else {
            --space;
        }

        std::cout << std::endl;
    }

    return 0;
}