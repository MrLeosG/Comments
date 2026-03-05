#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory {
public:
    void addItem(const std::string& item);
    void removeItem(const std::string& item);
private:
    std::vector<std::string> items;
};

#endif // INVENTORY_H
