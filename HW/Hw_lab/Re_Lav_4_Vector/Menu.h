#pragma once

class Menu0
{
public:
	char Title[80];	// ��������� ����
	char** Items;		// ������� ����
	int ItemsCount;		// �-�� ������� ����

	Menu0(const char* menuFileName);
	~Menu0(void);
	void showMenu0();
	int selectItem();
	// 

};