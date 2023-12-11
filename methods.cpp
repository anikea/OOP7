#include "class_ini.h"
#include <iostream>
#include <fstream>

// Library

void Library::setLibrary(string lib_name, string lib_addres, bool _isOpen) {
	LibraryName = lib_name;
	LibraryAdress = lib_addres;
	isOpen = _isOpen;
}

void Library::showLibrary() {
	cout << "����� - " << LibraryName << '\n';
	cout << "������ - " << LibraryAdress << '\n';
	if (isOpen)
		cout << "�� ������� - ���" << '\n';
	else
		cout << "�� ������� - ͳ" << '\n';
}

void Library::closeLibrary() {
	isOpen = false;
}

void Library::openLibrary() {
	isOpen = true;
}

void Library::isLibraryOpen() {
	if (isOpen)
		cout << "³�������" << '\n';
	else
		cout << "��������" << '\n';
}

// User

void User::setUser(string _name, string _surname, int _age, bool _isBlocked) {
	name = _name;
	surname = _surname;
	age = _age;
	isBlocked = _isBlocked;
}

void User::showUser() {
	cout << "I�'� - " << name << '\n';
	cout << "��i����� - " << surname << '\n';
	cout << "�i� - " << age << '\n';

	if (!isBlocked)
		cout << "�� � ������� ������" << '\n';
	else
		cout << "� ������� ������" << '\n';
}

void User::checkUser() {
	if (!isBlocked)
		cout << "�� � ������� ������" << '\n';
	else
		cout << "� ������� ������" << '\n';
}

void User::showAge() {
	cout << "³� - " << age << '\n';
}

void User::clearUser() {
	name = "";
	surname = "";
	age = -1;
	isBlocked = false;
}


// Admin


void Admin::ban() {
	setIsBlocked(true);
}

void Admin::unBan() {
	setIsBlocked(false);
}

void Admin::setLogin(string _login) {
	login = _login;
}

void Admin::showAdmin() {
	cout << "���� - " << '\n';
	if (isWork)
		cout << "�� �������� ����" << '\n';
	else
		cout << "�� �� �������� ����" << '\n';
}

void Admin::setWork(bool status) {
	isWork = status;
}

void Admin::deleteAdmin() {
	login = "";
	isWork = false;
}


// Book

void Book::setBook(string _title, string _author, bool _isAvailable) {
	title = _title;
	author = _author;
	isAvailable = _isAvailable;
}

void Book::showBook() {
	cout << "����� - " << title << '\n';
	cout << "����� - " << author << '\n';

	if (isAvailable)
		cout << "� � ��������" << '\n';
	else
		cout << "���� � ��������" << '\n';
}

void Book::setAvailable(bool status) {
	isAvailable = status;
}

void Book::checkAvailable() {
	if (isAvailable)
		cout << "� � ��������" << '\n';
	else
		cout << "���� � ��������" << '\n';
}

void Book::clearBook() {
	title = "";
	author = "";
	isAvailable = false;
}