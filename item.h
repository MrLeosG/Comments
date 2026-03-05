#ifndef ITEM_H
#define ITEM_H

class Item {
public:
    Item(const std::string& name);
    std::string getName() const;
private:
    std::string itemName;
};

#endif // ITEM_H
