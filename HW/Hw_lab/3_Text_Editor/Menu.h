#pragma once
// Copyright 2022 Who?

class Menu0{
 public:
    char Title[80];  // Menu title
    char** Items;  // Menu items
    int ItemsCount;  // Number of menu items

    explicit Menu0(const char* menuFileName);
    ~Menu0(void);
    void showMenu0();
    int selectItem();
};