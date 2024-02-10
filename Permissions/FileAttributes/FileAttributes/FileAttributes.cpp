#include <iostream>
#include <windows.h>

void printFileAttributes(const std::wstring& filePath) {
    WIN32_FILE_ATTRIBUTE_DATA fileAttributes;
    if (GetFileAttributesEx(filePath.c_str(), GetFileExInfoStandard, &fileAttributes)) {
        std::wcout << L"File Attributes for: " << filePath << std::endl;

        // Size
        LARGE_INTEGER fileSize;
        fileSize.LowPart = fileAttributes.nFileSizeLow;
        fileSize.HighPart = fileAttributes.nFileSizeHigh;
        std::wcout << L"Size: " << fileSize.QuadPart << L" bytes" << std::endl;

        // Attributes
        std::wcout << L"Attributes: ";
        if (fileAttributes.dwFileAttributes & FILE_ATTRIBUTE_READONLY)
            std::wcout << L"Read-only ";
        if (fileAttributes.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN)
            std::wcout << L"Hidden ";
        if (fileAttributes.dwFileAttributes & FILE_ATTRIBUTE_SYSTEM)
            std::wcout << L"System ";
        if (fileAttributes.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            std::wcout << L"Directory ";
        if (fileAttributes.dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE)
            std::wcout << L"Archive ";
        if (fileAttributes.dwFileAttributes & FILE_ATTRIBUTE_COMPRESSED)
            std::wcout << L"Compressed ";
        if (fileAttributes.dwFileAttributes & FILE_ATTRIBUTE_DEVICE)
            std::wcout << L"Device ";
        if (fileAttributes.dwFileAttributes & FILE_ATTRIBUTE_NORMAL)
            std::wcout << L"Normal ";
        if (fileAttributes.dwFileAttributes & FILE_ATTRIBUTE_TEMPORARY)
            std::wcout << L"Temp ";
        if (fileAttributes.dwFileAttributes & FILE_ATTRIBUTE_SPARSE_FILE)
            std::wcout << L"Sparse ";
        if (fileAttributes.dwFileAttributes & FILE_ATTRIBUTE_REPARSE_POINT)
            std::wcout << L"Reparse ";
        if (fileAttributes.dwFileAttributes & FILE_ATTRIBUTE_COMPRESSED)
            std::wcout << L"Compressed ";
        if (fileAttributes.dwFileAttributes & FILE_ATTRIBUTE_OFFLINE)
            std::wcout << L"Offline ";

        if (fileAttributes.dwFileAttributes & FILE_ATTRIBUTE_NOT_CONTENT_INDEXED)
            std::wcout << L"Not content indexed ";

        if (fileAttributes.dwFileAttributes & FILE_ATTRIBUTE_ENCRYPTED)
            std::wcout << L"Encrypted ";

        if (fileAttributes.dwFileAttributes & FILE_ATTRIBUTE_INTEGRITY_STREAM)
            std::wcout << L"Integrity stream ";
        if (fileAttributes.dwFileAttributes & FILE_ATTRIBUTE_VIRTUAL)
            std::wcout << L"Virtual ";

        if (fileAttributes.dwFileAttributes & FILE_ATTRIBUTE_NO_SCRUB_DATA)
            std::wcout << L"No scrub data ";
        if (fileAttributes.dwFileAttributes & FILE_ATTRIBUTE_EA)
            std::wcout << L"EA ";
        if (fileAttributes.dwFileAttributes & FILE_ATTRIBUTE_PINNED)
            std::wcout << L"Pinned ";
        if (fileAttributes.dwFileAttributes & FILE_ATTRIBUTE_UNPINNED)
            std::wcout << L"UnPinned ";

        if (fileAttributes.dwFileAttributes & FILE_ATTRIBUTE_RECALL_ON_OPEN)
            std::wcout << L"Recall on open ";

        if (fileAttributes.dwFileAttributes & FILE_ATTRIBUTE_RECALL_ON_DATA_ACCESS)
            std::wcout << L"Recall on data access ";

        std::wcout << std::endl;
    }
    else {
        std::wcerr << L"Error getting file attributes for: " << filePath << std::endl;
    }
}

int main() {
    // Example usage
    std::wstring filePath = L"F:\\my_test_file";
    printFileAttributes(filePath);

    return 0;
}
