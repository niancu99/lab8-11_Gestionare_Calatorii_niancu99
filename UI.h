#pragma once
#include "Service.h"

class UI {
private:
	Service serv;
public:
	UI();
	UI(Service& serv);
	~UI();
	void menu();
	void UIAddBus();
	void UIAddAvion();
	void SearchByDate();
	void chooseFormatFile();
	void run();
};