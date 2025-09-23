//Mohammad Jawad
//9/22/25
//File implementation for getters constructors and such

#include "File.hpp"

/**
* Constructs a new File object.
*
* @post
* Sets the File's filename_ to "New_Text_Document.txt"
* Sets all boolean members to true.
* @post
* <the other post conditions / default conditions>
* NEW: `last_modified_timestamp_` is set to the current system time.
*/
File::File() : filename_("New_Text_Document.txt"), readable_(true), writable_(true), last_modified_timestamp_(cr::system_clock::now()){}

/**
* Constructs a new File object.
*
* @param filename A const reference to a string for the initial filename
* @param isReadable A const reference to a boolean for the readable permission
* @param isWritable A const reference to a boolean for the writable permission
*
* @post
* All booleans should have a default value of true (ie. use true if they are omitted).
*
* Sets the File's filename_ such that:
* 1. If the parameter contains spaces or has no characters at all, the default filename is used
* 2. If the parameter has no extension (no `period` characters whatsoever), .txt is appended to the filename & used
* 3. If the parameter has an empty extension (a `period` characters followed by no characters), txt is appended to the filename & used
* 4. Otherwise, the parameter filename is used as is
* Note: A filename like `.env` or `.log` IS allowed (ie. filenames containing only the extension)!
*/
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
                filename_ = filename + "txt";
            }
            else
            {
                filename_ = filename;
            }
        }
    }

}

/**
* Retrieves the current readable permission as a boolean.
* @return The value stored in `readable_`
*/
bool File::isReadable() const
{
    return readable_;
}
/**
* Sets the readable permission of the File object.
*
* @param new_permission A const reference to a boolean for the new readable permission
* @post
* 1. The readble member is set to the value of the parameter
* 2. The last modified attribute is updated to the current system time
*/
void File::setReadable(bool new_permission)
{
    readable_ = new_permission;
    last_modified_timestamp_ = cr::system_clock::now();
}
/**
* Sets the writable permission of the File object.
*
* @param new_permission A const reference to a boolean for the new writable permission
* @post
* 1. The writable member is set to the value of the parameter
* 2. The last modified attribute is updated to the current system time
*/
bool File::isWritable() const
{
    return writable_;
}
/**
* Sets the writable permission of the File object.
*
* @param new_permission A const reference to a boolean for the new writable permission
* @post
* 1. The writable member is set to the value of the parameter
* 2. The last modified attribute is updated to the current system time
*/
void File::setWritable(bool new_permission)
{
    writable_ = new_permission;
    last_modified_timestamp_ = cr::system_clock::now();
}
/**
* Retrieves the current filename as a string.
*/
std::string File::getFilename() const
{
    return filename_;
}
/**
* Attempts to set a new filename for the File object.
* The operation FAILS if:
* 1. The passed filename is empty or contains spaces
* 2. The extension of the old and new filenames are not equal.
* Note: Do not append a default extension to the parameter!
*
* @param filename A const reference to a string for the new filename.
* @return true if the filename was successfully updated, false otherwise.
* @post
* 1. If possible, the filename variable is set to that of the parameter
* 2. If the filename was modified, the last modified attribute is updated to the current system time
*/
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

/**
* Retrieves the last modified timestamp of the File object.
* @return The timestamp stored within `last_modified_timestamp_`
*/
timestamp File::getLastModified() const
{
    return last_modified_timestamp_;
}
