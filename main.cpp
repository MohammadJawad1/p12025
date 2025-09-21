#include <iostream>
#include <string>
#include "FileUtils.hpp"

int main() {
    std::cout << "Test 1: " << FileUtils::findFileExtension("document.txt.txt") << "\n";    // .txt
    std::cout << "Test 2: " << FileUtils::findFileExtension("archive.tar.gz") << "\n";  // .gz
    std::cout << "Test 3: " << FileUtils::findFileExtension("noextension") << "\n";     // ""
    std::cout << "Test 4: " << FileUtils::findFileExtension("") << "\n";                // ""
    std::cout << "Test 5: " << FileUtils::findFileExtension("file.") << "\n";           // ""

    
    std::cout << "Test 1: " << FileUtils::hasWhitespaces("file name.txt") << "\n"; // true
    std::cout << "Test 2: " << FileUtils::hasWhitespaces("filename.txt") << "\n";  // false
    std::cout << "Test 3: " << FileUtils::hasWhitespaces("file\tname") << "\n";    // true (tab)
    std::cout << "Test 4: " << FileUtils::hasWhitespaces("") << "\n";              // false

    return 0;
}