#include <iostream>
#include <string>
using namespace std;

int findFirstSubstringLocation(const string& mainStr, const string& subStr) {
    const char* mainPtr = mainStr.c_str();
    const char* subPtr = subStr.c_str();

    while (*mainPtr) {
        const char* tempMainPtr = mainPtr;
        const char* tempSubPtr = subPtr;

        while (*tempMainPtr && *tempSubPtr && *tempMainPtr == *tempSubPtr) {
            ++tempMainPtr;
            ++tempSubPtr;
        }

        if (*tempSubPtr == '\0') {
            return static_cast<int>(mainPtr - mainStr.c_str());
        }

        ++mainPtr;
    }

    return -1;
}
int main() {
    string mainString, subString;

    cout << "Enter the main string: ";
    cin >> mainString;

    cout << "Enter the substring to find: ";
    cin >> subString;

    int location = findFirstSubstringLocation(mainString, subString);

    if (location != -1) {
        cout << "Substring found at position: " << location << "\n";
    } else {
        cout << "Substring not found in the main string.\n";
    }

    return 0;
}
