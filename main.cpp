#include <iostream>
#include <string>
#include "FileUtils.hpp"
#include "File.hpp"

int main() {
    std::cout << "Test 1: " << FileUtils::findFileExtension("document.txt.txt") << "\n";   
    std::cout << "Test 2: " << FileUtils::findFileExtension("archive.tar.gz") << "\n";  
    std::cout << "Test 3: " << FileUtils::findFileExtension("noextension") << "\n";     
    std::cout << "Test 4: " << FileUtils::findFileExtension("") << "\n";               
    std::cout << "Test 5: " << FileUtils::findFileExtension("file.") << "\n";         

    
    std::cout << "Test 1: " << FileUtils::hasWhitespaces("file name.txt") << "\n"; 
    std::cout << "Test 2: " << FileUtils::hasWhitespaces("filename.txt") << "\n";  
    std::cout << "Test 3: " << FileUtils::hasWhitespaces("file\tname") << "\n";    
    std::cout << "Test 4: " << FileUtils::hasWhitespaces("") << "\n";    

    File f1;  // default
    std::cout << "Filename: " << f1.getFilename()  << ", Last Modified: " << FileUtils::timestampToString(f1.getLastModified()) << "\n";

    f1.setReadable(false);
    f1.setWritable(false);

    f1.setFilename("example.txt"); 
    std::cout << "Filename: " << f1.getFilename() << ", Last Modified: " << FileUtils::timestampToString(f1.getLastModified()) << "\n";

    return 0;

    return 0;
}