#include <iostream>
using namespace std;

// Function prototypes
void getInfo(int &n, int &k);
double computeWays(int n, int k);
double factorial(int num);

/*******************************************************************
* getLotteryInfo                                                   *
* Gets and validates lottery info from the user and places it in   *
* reference parameters referencing variables in the main function. *
********************************************************************/
void getInfo(int &n, int &k) {
    do {
        cout << "How many balls (1-12) are in the pool to pick from? ";
        cin >> n;
        if (cin.fail() || n < 1 || n > 12) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Input error! There must be between 1 and 12 balls." << endl;
        }

    } while (n < 1 || n > 12);

    do {
        cout << "How many balls (1-7) will be drawn? ";
        cin >> k;
        if (cin.fail() || k < 1 || k > n) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Input error!" << endl;
        }
    } while (k < 1 || k > n);
}

/*******************************************************************
* computeWays                                                      *
* Computes and returns the number of different possible sets       *
* of k numbers that can be chosen from a set of n numbers.         *
* The formula for this is     k!(n- k)!                            *
*                             --------                             *
*                                 n!                               *
* Note that the computation is done in a way that does not require *
* multiplying two factorials together. This is done to prevent any *
* intermediate result becoming so large that it causes overflow.   *
********************************************************************/
double computeWays(int n, int k) {
    double m = (factorial(n)) / (factorial(k) * factorial(n - k));
    return 1.0 / m;
}

/*******************************************************************
* factorial                                                        *
* This function computes factorials recursively.                   *
*******************************************************************/
double factorial(int j) {
    if (j <= 1)
        return 1;
    return j * factorial(j - 1);
}

