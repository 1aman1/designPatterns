#include <iostream>
#include <vector>
#include <memory>
#include <string>

class FileSystemComponent
{
public:
    virtual ~FileSystemComponent() = default;
    virtual void showDetails(int indent = 0) const = 0;
};

// ---- Leaf ----
class File : public FileSystemComponent
{
    std::string name;

public:
    explicit File(std::string n) : name(std::move(n)) {}
    void showDetails(int indent = 0) const override
    {
        std::cout << std::string(indent, ' ') << "- File: " << name << '\n';
    }
};

// ---- Composite ----
class Folder : public FileSystemComponent
{
    std::string name;
    std::vector<std::shared_ptr<FileSystemComponent>> children;

public:
    explicit Folder(std::string n) : name(std::move(n)) {}

    void add(const std::shared_ptr<FileSystemComponent> &component)
    {
        children.push_back(component);
    }

    void showDetails(int indent = 0) const override
    {
        std::cout << std::string(indent, ' ') << "+ Folder: " << name << '\n';
        for (const auto &child : children)
            child->showDetails(indent + 2);
    }
};

// ---- Client Code ----
int main()
{
    auto root = std::make_shared<Folder>("root");
    auto docs = std::make_shared<Folder>("Documents");
    auto pics = std::make_shared<Folder>("Pictures");

    auto file1 = std::make_shared<File>("resume.pdf");
    auto file2 = std::make_shared<File>("budget.xlsx");
    auto file3 = std::make_shared<File>("vacation.jpg");

    docs->add(file1);
    docs->add(file2);
    pics->add(file3);

    root->add(docs);
    root->add(pics);

    root->showDetails();
}
