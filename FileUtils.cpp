//Mohammad Jawad
//9/22/25
//File utils implementation
#include "FileUtils.hpp"

std::string FileUtils::timestampToString(timestamp time_point)
{
    std::time_t tt = cr::system_clock::to_time_t(time_point);
    std::tm streamable_time = *std::localtime(&tt);

    std::stringstream ss;
    ss << std::put_time(&streamable_time, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

// YOUR CODE BELOW HERE --------
/**
* Extracts the file extension from a given filename.
*
* We define the file extension as the string containing:
* 1. The last period within the filename
* 2. All characters after that period
*
* @pre Assume the given filename has no spaces
* @param filename A const reference to a string representing the filename from which to find the extension.
* @return A string containing the extracted file extension or an empty string if:
* 1. No extension is found
* 2. The filename is empty.
*/
std::string FileUtils::findFileExtension(const std::string& filename)
{
    if(filename.empty())
    {
        return "";
    }

    size_t pos= filename.find_last_of('.');

    if (pos == std::string::npos)
    {
        return "";
    }

    return filename.substr(pos);
}

bool FileUtils::hasWhitespaces(const std::string& filename)
{
    for(unsigned char ch : filename)
    {
        if (std::isspace(ch))
        {
            return true;
        }
    }
    return false;
}