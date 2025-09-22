//Mohammad Jawad
//9/22/25
//File implementation for getters constructors and such

#include "File.hpp"

File::File() : filename_("New_Text_Document.txt"), readable_(true), writable_(true), last_modified_timestamp_(cr::system_clock::now()){}

File::File(const std::string& filename, bool isReadable, bool isWritable) : readable_(isReadable), writable_(isWritable), last_modified_timestamp_(cr::system_clock::now()) 
{
    std::string defaultName = "New_Text_Document.txt";

    if (filename.empty()  || FileUtils::hasWhitespaces(filename))
    {
        filename_ = defaultName;
    }
    else
    {
        size_t pos = filename.find_last_of('.');
        {
            if (pos == std::string::npos)
            {
                filename_ = filename + ".txt";
            }
            else if (pos == filename.length() - 1)
            {
                filename_ = filename + ".txt";
            }
            else
            {
                filename_ = filename;
            }
        }
    }

}


bool File::isReadable() const
{
    return readable_;
}

void File::setReadable(bool new_permission)
{
    readable_ = new_permission;
    last_modified_timestamp_ = cr::system_clock::now();
}
bool File::isWritable() const
{
    return writable_;
}

void File::setWritable(bool new_permission)
{
    writable_ = new_permission;
    last_modified_timestamp_ = cr::system_clock::now();
}
std::string File::getFilename() const
{
    return filename_;
}

bool File::setFilename(const std::string& newFilename)
{
    if (newFilename.empty()  || FileUtils::hasWhitespaces(newFilename))
    {
        return false;
    }

    std::string oldExt = FileUtils::findFileExtension(filename_);
    std::string newExt = FileUtils::findFileExtension(newFilename);

    if (oldExt != newExt)
        return false; // extensions do not match

    // All checks passed → update filename
    filename_ = newFilename;
    last_modified_timestamp_ = cr::system_clock::now();
    return true;
}

timestamp File::getLastModified() const
{
    return last_modified_timestamp_;
}
