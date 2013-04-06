/*
 * File: NumericConversions.cpp
 * ---------------------------
 * Name: Eric Beach
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Numeric Conversions problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include <string>
#include <math.h>
#include "console.h"
using namespace std;

/* Function prototypes */

string intToString(int n);
int stringToInt(string str);

/* Main program */

bool assertEquals(string expected, string received) {
    if (expected == received) {
        return true;
    } else {
        cout << "TEST FAILURE -- Expected: " << expected << ", RECEIVED: " <<
        received << endl;
        return false;
    }
}

bool assertEquals(int expected, int received) {
    if (expected == received) {
        return true;
    } else {
        cout << "TEST FAILURE -- Expected: " << expected << ", RECEIVED: " <<
        received << endl;
        return false;
    }
}

string digitToString(int n) {
    return string() + char(n % 10 + '0');
}

int digitToInt(string num) {
    char temp = *(num.substr(0, 1).c_str());
    int digit = temp - 48;
    return digit;
}

void runUnitTests() {
    assertEquals("0", digitToString(0));
    assertEquals("1", digitToString(1));
    assertEquals("7", digitToString(7));
    assertEquals("23", intToString(23));
    assertEquals("-23", intToString(-23));
    assertEquals("-27", intToString(-27));
    assertEquals("0", intToString(0));
    assertEquals("-1", intToString(-1));
    assertEquals("7", intToString(7));
    assertEquals("72349", intToString(72349));
    assertEquals("-72349", intToString(-72349));
    assertEquals(0, digitToInt("0"));
    assertEquals(2, digitToInt("2"));
    assertEquals(8, digitToInt("8"));
    assertEquals(9, digitToInt("9"));
    assertEquals(-9, stringToInt("-9"));
    assertEquals(99, stringToInt("99"));
    assertEquals(999, stringToInt("999"));
}

int main() {
    runUnitTests();
    return 0;
}

int stringToInt(string num) {
    if (num.length() == 1) {
        // base case
        return digitToInt(num);
    } else if (num.substr(0, 1) == "-") {
        // recursive case
        return -1 * stringToInt(num.substr(1));
    } else {
        // recursive case
        int power = num.size() - 1;
        int leftDigitContribution = digitToInt(num.substr(0, 1)) * pow(10, power);
        string remaining = num.substr(1);
        return  leftDigitContribution + stringToInt(remaining);
    }
}

string intToString(int n) {
    if (n == 0) {
        return string("0");
    } else if (n < 0) {
        return "-" + intToString(n*-1);
    } else if (n < 10) {
        return digitToString(n % 10);
    } else {
        return intToString(n / 10) + digitToString(n % 10);
    }
}