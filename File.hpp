//Mohammad Jawad
//9/22/25
//File header

#pragma once
#include "FileUtils.hpp"

class File
{
private:

    std::string filename_;
    bool readable_;
    bool writable_;

    timestamp last_modified_timestamp_;

public:
/**
* Constructs a new File object.
*
* @post
* Sets the File's filename_ to "New_Text_Document.txt"
* Sets all boolean members to true.
* @post
* <the other post conditions / default conditions>
* NEW: `last_modified_timestamp_` is set to the current system time
*/
    File();
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
    File(const std::string& filename, bool isReadable, bool isWritable);

/**
* Retrieves the current readable permission as a boolean.
* @return The value stored in `readable_`
*/
    bool isReadable() const;

/**
* Sets the readable permission of the File object.
*
* @param new_permission A const reference to a boolean for the new readable permission
* @post
* 1. The readble member is set to the value of the parameter
* 2. The last modified attribute is updated to the current system time
*/
    void setReadable(bool new_permission);


/**
* Retrieves the current writable permission as a boolean.
* @return The value stored in `writable_`
*/
    bool isWritable() const;

/**
* Sets the writable permission of the File object.
*
* @param new_permission A const reference to a boolean for the new writable permission
* @post
* 1. The writable member is set to the value of the parameter
* 2. The last modified attribute is updated to the current system time
*/
    void setWritable(bool new_permission);

/**
* Retrieves the current filename as a string.
*/
    std::string getFilename() const;
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
    bool setFilename(const std::string& newFilename);

    /**
* Retrieves the last modified timestamp of the File object.
* @return The timestamp stored within `last_modified_timestamp_`
*/
    timestamp getLastModified() const;
};
