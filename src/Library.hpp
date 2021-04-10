#pragma once

namespace tacl
{
    // from Christopher's submission to Project 1
    // prints ids in the passed vector reference. O(n), where n is the number of elements in the vector
    template<typename T>
    void print(std::vector<T>& data)
    {
        for (auto iter = data.begin(); iter != data.end(); iter++)
            std::cout << *iter << std::endl;
    }

    // from Christopher's submission to Project 1
    // prints the success of a function that returns a bool
    void printSuccess(bool success)
    {
        if (success)
            std::cout << "successful" << std::endl;
        else
            std::cout << "unsuccessful" << std::endl;
    }

    // from Christopher's submission to Project 1
    // gets the remainder of a line following the command's first word. substr and getline are O(s), where s is the length of the string, so this runs in
    // that time as well.
    std::string getLineRemoveSpace()
    {
        std::string line;
        std::getline(std::cin, line);
        return line.substr(1, line.size() - 1);
    }
}