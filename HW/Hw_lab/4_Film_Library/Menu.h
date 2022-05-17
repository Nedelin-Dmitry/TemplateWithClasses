#pragma once

class Menu0 {
public:
    char Title[80];  // Menu title
    char** Items;  // Menu items
    int ItemsCount;  // Number of menu items

    Menu0(const char* menuFileName);
    ~Menu0(void);
    void showMenu0();
    int selectItem();
    // 

};