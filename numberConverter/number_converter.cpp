#include <iostream>
#include <string>
#include <algorithm> // for reverse
#include <cmath>     // for pow
using namespace std;

// Convert Decimal to Binary (supports negatives)
string decimalToBinary(int n) {
    if (n == 0) return "0";

    bool isNegative = n < 0;
    if (isNegative) n = -n;

    string binary = "";
    while (n > 0) {
        binary += (n % 2 == 0 ? "0" : "1");
        n /= 2;
    }
    reverse(binary.begin(), binary.end());

    if (isNegative) binary = "-" + binary;
    return binary;
}

// Convert Binary string to Decimal (supports negatives)
int binaryToDecimal(string binary) {
    bool isNegative = false;
    if (binary[0] == '-') {
        isNegative = true;
        binary = binary.substr(1);
    }

    int decimal = 0;
    for (int i = 0; i < binary.size(); i++) {
        char bit = binary[i];
        decimal = decimal * 2 + (bit - '0');
    }

    return isNegative ? -decimal : decimal;
}

// Convert Decimal to Octal
string decimalToOctal(int n) {
    if (n == 0) return "0";
    bool isNegative = n < 0;
    if (isNegative) n = -n;

    string octal = "";
    while (n > 0) {
        octal += char((n % 8) + '0');
        n /= 8;
    }
    reverse(octal.begin(), octal.end());
    if (isNegative) octal = "-" + octal;
    return octal;
}

// Convert Octal to Decimal
int octalToDecimal(string octal) {
    bool isNegative = false;
    if (octal[0] == '-') {
        isNegative = true;
        octal = octal.substr(1);
    }

    int decimal = 0;
    for (int i = 0; i < octal.size(); i++) {
        decimal = decimal * 8 + (octal[i] - '0');
    }
    return isNegative ? -decimal : decimal;
}

// Convert Decimal to Hexadecimal
string decimalToHex(int n) {
    if (n == 0) return "0";
    bool isNegative = n < 0;
    if (isNegative) n = -n;

    string hex = "";
    char hexDigits[] = "0123456789ABCDEF";
    while (n > 0) {
        hex += hexDigits[n % 16];
        n /= 16;
    }
    reverse(hex.begin(), hex.end());
    if (isNegative) hex = "-" + hex;
    return hex;
}

// Convert Hexadecimal to Decimal
int hexToDecimal(string hex) {
    bool isNegative = false;
    if (hex[0] == '-') {
        isNegative = true;
        hex = hex.substr(1);
    }

    int decimal = 0;
    for (int i = 0; i < hex.size(); i++) {
        char c = hex[i];
        int value;
        if (c >= '0' && c <= '9') value = c - '0';
        else if (c >= 'A' && c <= 'F') value = 10 + (c - 'A');
        else if (c >= 'a' && c <= 'f') value = 10 + (c - 'a');
        else value = 0; // ignore invalid

        decimal = decimal * 16 + value;
    }
    return isNegative ? -decimal : decimal;
}

// 1's Complement of binary
string onesComplement(string binary) {
    string result = "";
    for (int i = 0; i < binary.size(); i++) {
        if (binary[i] == '1') result += '0';
        else if (binary[i] == '0') result += '1';
        else result += binary[i]; // ignore '-' sign if any
    }
    return result;
}

// 2's Complement of binary
string twosComplement(string binary) {
    string oneComp = onesComplement(binary);
    string result = oneComp;

    // Add 1 to one's complement (binary addition)
    int carry = 1;
    for (int i = result.size() - 1; i >= 0; i--) {
        if (result[i] == '0') {
            result[i] = '1';
            carry = 0;
            break;
        } else if (result[i] == '1') {
            result[i] = '0';
            carry = 1;
        }
    }
    if (carry == 1) {
        result = "1" + result;
    }
    return result;
}

// ---------- Main Program ----------
int main() {
    int choice;
    do {
        cout << "\n=========================================\n";
        cout << "   Number System Converter\n";
        cout << "=========================================\n";
        cout << "1. Decimal -> Binary\n";
        cout << "2. Binary -> Decimal\n";
        cout << "3. Decimal -> Octal\n";
        cout << "4. Octal -> Decimal\n";
        cout << "5. Decimal -> Hexadecimal\n";
        cout << "6. Hexadecimal -> Decimal\n";
        cout << "7. Binary -> 1's Complement\n";
        cout << "8. Binary -> 2's Complement\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int decimal;
            cout << "Enter Decimal: ";
            cin >> decimal;
            cout << "Binary = " << decimalToBinary(decimal) << endl;
        }
        else if (choice == 2) {
            string binary;
            cout << "Enter Binary: ";
            cin >> binary;
            cout << "Decimal = " << binaryToDecimal(binary) << endl;
        }
        else if (choice == 3) {
            int decimal;
            cout << "Enter Decimal: ";
            cin >> decimal;
            cout << "Octal = " << decimalToOctal(decimal) << endl;
        }
        else if (choice == 4) {
            string octal;
            cout << "Enter Octal: ";
            cin >> octal;
            cout << "Decimal = " << octalToDecimal(octal) << endl;
        }
        else if (choice == 5) {
            int decimal;
            cout << "Enter Decimal: ";
            cin >> decimal;
            cout << "Hexadecimal = " << decimalToHex(decimal) << endl;
        }
        else if (choice == 6) {
            string hex;
            cout << "Enter Hexadecimal: ";
            cin >> hex;
            cout << "Decimal = " << hexToDecimal(hex) << endl;
        }
        else if (choice == 7) {
            string binary;
            cout << "Enter Binary: ";
            cin >> binary;
            cout << "1's Complement = " << onesComplement(binary) << endl;
        }
        else if (choice == 8) {
            string binary;
            cout << "Enter Binary: ";
            cin >> binary;
            cout << "2's Complement = " << twosComplement(binary) << endl;
        }

    } while (choice != 0);

    cout << "Exiting program. Goodbye!\n";
    return 0;
}
