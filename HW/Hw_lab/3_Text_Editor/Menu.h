#pragma once
// Copyright 2022 Who?

class Menu0{
 public:
    char Title[80];  // Заголовок меню
    char** Items;  // Позиции меню
    int ItemsCount;  // К-во позиций меню

    explicit Menu0(const char* menuFileName);
    ~Menu0(void);
    void showMenu0();
    int selectItem();
};