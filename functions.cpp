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
	for (int i = 0; i < name_arr.size(); i++) {
		if (x == name_arr[i] && y == pass_arr[i]) {
			cout << "error" << endl;
			return;
		}
	}
	cout << "Registration complete" << endl;
	name_arr.emplace_back(x);
	pass_arr.emplace_back(y);
}

string Chat::login() {
	string x, y;
	cout << "Enter username" << endl;
	cin >> x;
	cout << "Enter password" << endl;
	cin >> y;
	for (int i = 0; i < name_arr.size(); i++) {
		if (x == name_arr[i] && y == pass_arr[i]) {
			return name_arr[i];
		}
	}
	cout << "error" << endl;
	return "error";
}

void Chat::authorized_user(string name) {
	if (name == "error") {
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
			for (int i = 0; i < name_arr.size(); i++) {
				if (write_name == name_arr[i]) {
					cout << "correct" << endl << "Write yout message" << endl;
					cin >> mes;
					string send_mes = name + " -> " + write_name + ": " + mes;
					mes_arr.push_back(send_mes);
					cout << "Message sended" << endl;
					break;
				}
				else {
					cout << "error" << endl;
					break;
				}
			}
			break;
		case('3'):
			for (int i = 0; i < name_arr.size(); i++) {
				if (name == name_arr[i]) {
					cout << mes_arr[i] << endl;
					break;
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