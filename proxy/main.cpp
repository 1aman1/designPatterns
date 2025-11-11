#include <iostream>
#include <memory>
#include <string>

class Database
{
public:
    virtual void query(const std::string &q) = 0;
    virtual ~Database() = default;
};

class RealDatabase : public Database
{
public:
    void query(const std::string &q) override
    {
        std::cout << "[RealDatabase] Executing query: " << q << "\n";
    }
};

class DatabaseProxy : public Database
{
    std::unique_ptr<Database> realDb;
    bool hasAccess;

public:
    DatabaseProxy(bool access) : hasAccess(access) {}

    void query(const std::string &q) override
    {
        if (!hasAccess)
        {
            std::cout << "[Proxy] Access denied! Cannot execute query.\n";
            return;
        }

        if (!realDb)
        {
            std::cout << "[Proxy] Creating RealDatabase instance lazily...\n";
            realDb = std::make_unique<RealDatabase>();
        }

        std::cout << "[Proxy] Forwarding request to RealDatabase.\n";
        realDb->query(q);
    }
};

int main()
{
    std::cout << "--- Trying with NO access ---\n";
    DatabaseProxy proxyNoAccess(false);
    proxyNoAccess.query("SELECT * FROM users");

    std::cout << "\n--- Trying WITH access ---\n";
    DatabaseProxy proxyWithAccess(true);
    proxyWithAccess.query("SELECT * FROM products");

    // Notice: RealDatabase is created only when first needed
    // proxyWithAccess.query("UPDATE products SET price=99 WHERE id=1");

    return 0;
}
