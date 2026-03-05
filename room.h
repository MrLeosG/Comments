#ifndef ROOM_H
#define ROOM_H

class Room {
public:
    Room(const std::string& description);
    std::string getDescription() const;
private:
    std::string roomDescription;
};

#endif // ROOM_H
