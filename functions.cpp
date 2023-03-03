#include "chat.h"
#include <iostream>
#include <vector>
using namespace std;

void Chat::registration() {
	string x, y;
	cout << "Enter username" << endl;
	cin >> x;
	cout << "Enter password" << endl;
	cin >> y;
	cout << "Password entered" << endl;
	pair<string, string> p1 = make_pair(x, y);
	for (auto& p : user_arr) {
		if (p1.first == p.first) {
			cout << "error" << endl;
			return;
		}
	}
	cout << "Registration complete" << endl;
	user_arr.emplace_back(p1);
}

string Chat::login() {
	string x, y;
	cout << "Enter username" << endl;
	cin >> x;
	cout << "Enter password" << endl;
	cin >> y;
	for (auto& p : user_arr) {
		if (x == p.first && y == p.second) {
			return p.first;
		}
	}
	cout << "error" << endl;
	return "err";
}

void Chat::authorized_user(string name) {
	if (name == "err") {
		return;
	}
	cout << "Hello " << name << endl 
		<< "Enter 1 to send a message, 2 to send a message to someone, 3 to show messages or 4 to logout." << endl;;
	bool b = true;
	char x;
	string mes, write_name;
	while (b == true) {
		cin >> x;
		switch (x) {
		case('1'):
			cout << "Write message" << endl;
			cin >> mes;
			cout << name << ": " << mes << endl;
			break;
		case('2'):
			cout << "Write the name of the person to send the message to." << endl;
			cin >> write_name;
			for (auto& p : user_arr) {
				if (write_name == p.first) {
					cout << "correct" << endl << "Write yout message" << endl;
					cin >> mes;
					string send_mes = name + " -> " + write_name + ": " + mes;
					mes_arr.push_back(send_mes);
					cout << "Message sended" << endl;
					break;
				}
			}
			break;
		case('3'):
			for (auto& p : user_arr) {
				if (name == p.first) {
					for (int i = 0; i < mes_arr.size(); i++) {
						cout << mes_arr[i] << endl;
						break;
					}
				}
			}
			break;
		case('4'):
			cout << "logout" << endl;
			b = false;
			break;
		default:
			cout << "error" << endl;
			break;
		}
	}
}