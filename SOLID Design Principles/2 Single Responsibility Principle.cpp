/*
basically a class should concentrate on a specific task, and not doing all things all by itself.

*/

#include <iostream>
#include <vector>
#include <fstream>

class Journal
{
public:
    std::string title;

    std::vector<std::string> list;

    Journal(const std::string &S) : title(S) {}

    bool add_Journal(const std::string S)
    {
        static int count = 1;
        list.push_back(S + std::to_string(count));
        return true;
    }
};

// persistance
// a separate concern is in separate class
class PersistanceManager
{
public:
    void save(const Journal &j, const std::string filename)
    {
        std::fstream ofs(filename);

        for (const auto &each : j.list)
            ofs << each << std::endl;
    }
};

int main()
{

    Journal J1("my New Journal");
    J1.add_Journal("First page");
    J1.add_Journal("Second page");

    PersistanceManager pm;

    pm.save(J1, "file1.txt");

    
    return 0;
}
