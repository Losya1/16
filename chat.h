#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Chat {
private:
	vector <string> name_arr;
	vector <string> pass_arr;
	vector <string> mes_arr;
public:
	void registration();
	string login();
	void authorized_user(string name);
};