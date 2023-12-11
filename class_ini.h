#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


class Library {
public:

	virtual void sayHelloLibrary() const {
		cout << "Hello Library from yourself" << '\n';
	}

	string LibraryName = "OpenBook";
	string LibraryAdress = "Bibliotechna 17";
	bool isOpen = false;


	void setLibrary(string lib_name, string lib_addres, bool _isOpen = false);
	void showLibrary();
	void closeLibrary();
	void openLibrary();
	void isLibraryOpen();

	virtual void showStaff() {
		cout << "I am from Library" << '\n';
	}

	// add Virtual
	//  ~Library() {
	//	cout << "Library Destructor" << '\n';
	//}
};

class User : public Library {
public:

	void sayHelloLibrary() const override {
		cout << "Hello Library from User" << '\n';
	}

	User() {}

	User(const User& other) {
		this->name = other.name;
		this->surname = other.surname;
		this->age = other.age;
		this->isBlocked = other.isBlocked;
	}

	User(string _name, string _surname, int _age, bool _isBlocked = false)
		: Library(), name(_name), surname(_surname), age(_age), isBlocked(_isBlocked) {}


	void setUser(string _name, string _surname, int _age, bool _isBlocked = false);
	void showUser();
	void checkUser();
	void showAge();
	void clearUser();

	void write(const std::string& filename) const {
		std::ofstream file(filename);
		if (file.is_open()) {
			file << "Name: " << name << '\n';
			file << "Surname: " << surname << '\n';
			file << "Age: " << age << '\n';
			file << "Blocked: " << (isBlocked ? "true" : "false") << '\n';

			file.close();
		}
		else {
			std::cerr << "Unable to create file: " << filename << std::endl;
		}
	}

	void read(const std::string& filename) {
		std::ifstream file(filename);
		if (file.is_open()) {
			std::string line;

			// Читаємо Name
			std::getline(file, line);
			name = line.substr(line.find(":") + 2);

			// Читаємо Surname
			std::getline(file, line);
			surname = line.substr(line.find(":") + 2);

			// Читаємо Age
			std::getline(file, line);
			istringstream iss(line.substr(line.find(":") + 2));
			iss >> age;

			// Читаємо Blocked
			std::getline(file, line);
			isBlocked = (line.substr(line.find(":") + 2) == "true") ? true : false;

			file.close();

			cout << "Readed: " << '\n';

			cout << "Name - " << name << '\n';
			cout << "Surname - " << surname << '\n';
			cout << "Age - " << age << '\n';
			cout << "Blocked - " << (isBlocked ? "true" : "false") << '\n';
		}
		else {
			std::cerr << "Unable to open file: " << filename << std::endl;
		}
	}

	static void manageUsers(vector<User>& users, int count) {
		if (!users.empty()) {
			if (count <= 0) {
				count = users.size();
			}

			cout << "List of Users:" << endl;
			for (int i = 0; i < count; i++) {
				users[i].showUser();
			}
		}
		else {
			cout << "No users found." << endl;
		}
	}

	//~User() {
	//	cout << "Destructor USER" << '\n';
	//}

	User operator+(const User& other) const {
		User result(*this); // Створюємо копію поточного об'єкта
		result.name += other.name; // Об'єднуємо імена
		result.surname += other.surname; // Об'єднуємо прізвища
		result.age += other.age; // Сумуємо вік

		// Додайте інші поля, якщо потрібно

		return result; // Повертаємо об'єднаний об'єкт User
	}

	User operator-(const User& other) const {
		User result(*this); // Створюємо копію поточного об'єкта

		// Перевіряємо, чи співпадають ім'я та прізвище
		if (result.name == other.name && result.surname == other.surname) {
			result.name = ""; // Очищаємо ім'я
			result.surname = ""; // Очищаємо прізвище
			result.age = -1; // Змінюємо вік на недійсний (-1) або іншим чином обробляємо цю ситуацію

			// Додайте інші поля, якщо потрібно

			// Тут ви можете додати інші дії з виключенням користувача
		}

		return result; // Повертаємо об'єкт User після виключення
	}

	// Перевантаження оператора присвоєння "="
	User& operator=(const User& other) {
		if (this != &other) { // Перевіряємо, чи це не той самий об'єкт
			this->name = other.name;
			this->surname = other.surname;
			this->age = other.age;
			this->isBlocked = other.isBlocked;
			// Присвоєння інших полів, якщо потрібно
		}
		return *this; // Повертаємо об'єкт, на який вказує this
	}

	// Перевантаження оператора множення "*"
	User operator*(int multiplier) const {
		User result(*this); // Створюємо копію поточного об'єкта
		// Множимо числові поля на multiplier
		result.age *= multiplier;
		// Множення інших числових полів, якщо потрібно
		return result; // Повертаємо об'єкт зі зміненими значеннями
	}

	// Перевантаження оператора плюс-рівно "+="
	User& operator+=(const User& other) {
		// Додаємо числові поля обох об'єктів
		this->age += other.age;
		// Додавання інших числових полів, якщо потрібно
		return *this; // Повертаємо об'єкт, на який вказує this
	}

	// Перевантаження оператора мінус-рівно "-="
	User& operator-=(const User& other) {
		// Віднімаємо числові поля обох об'єктів
		this->age -= other.age;
		// Віднімання інших числових полів, якщо потрібно
		return *this; // Повертаємо об'єкт, на який вказує this
	}

	// Перевантаження оператора множення-рівно "*="
	User& operator*=(int multiplier) {
		// Множимо числові поля на multiplier
		this->age *= multiplier;
		// Множення інших числових полів, якщо потрібно
		return *this; // Повертаємо об'єкт, на який вказує this
	}

	// Перевантаження оператора доступу до елементів "[]"
	int& operator[](int index) {
		// Припускаємо, що вік зберігається в першому полі
		if (index == 0) {
			return this->age;
		}
		else {
			// Якщо індекс не відповідає жодному з полів, повертаємо вік
			return this->age;
		}
	}

	void showStaff() override {
		cout << "I am from User" << '\n';
	}

	bool operator<(const User& other) const {
		return name < other.name;
	}

	// Метод для отримання імені
	std::string getName() const {
		return name;
	}

private:
	string name = "";
	string surname = "";
	int age = -1;
	bool isBlocked = false;

protected:
	void setIsBlocked(bool blocked) {
		isBlocked = blocked;
	}
};

inline void Service(User user, string filename) {
	try {
		user.write(filename);
		user.read(filename);
	}
	catch (...) {
		cerr << "Got some problem" << '\n';
	}
}

class Admin : virtual protected User {
public:

	void sayHelloLibrary() const override {
		cout << "Hello Library from Admin" << '\n';
	}

	Admin() {}
	Admin(const Admin& other) {
		this->login = other.login;
	}

	Admin(string _login) {
		login = _login;
	}

	void ban();
	void setLogin(string _login);
	void unBan();
	void showAdmin();
	void setWork(bool status);
	void deleteAdmin();

	void showStaff() override {
		cout << "I am from Admin" << '\n';
	}

private:
	string login = "";
	bool isWork = false;
};

class Book : public Library {
public:

	void sayHelloLibrary() const override {
		cout << "Hello Library from Book" << '\n';
	}

	Book() {}
	Book(const Book& other) {
		this->title = other.title;
		this->author = other.author;
		this->isAvailable = other.isAvailable;
	}

	Book(string _title, string _author, bool _isAvailable = false) {
		title = _title;
		author = _author;
		isAvailable = _isAvailable;
	}

	void setBook(string _title, string _author, bool _isAvailable = false);
	void showBook();
	void setAvailable(bool status);
	void checkAvailable();
	void clearBook();

	void showStaff() override {
		cout << "I am from Book" << '\n';
	}

	//~Book() {
	//	cout << "Destructor BOOK" << '\n';
	//}

private:
	string title = "";
	string author = "";
	bool isAvailable = false;
};


template<typename T, typename U, typename V, typename W, typename X>
// Template Class
class TC {
private:
	T data1;
	U data2;
	V data3;
	W data4;
	X data5;

public:
	TC(T d1, U d2, V d3, W d4, X d5)
		: data1(d1), data2(d2), data3(d3), data4(d4), data5(d5) {}

	void displayData() {
		std::cout << "Data 1: " << data1 << std::endl;
		std::cout << "Data 2: " << data2 << std::endl;
		std::cout << "Data 3: " << data3 << std::endl;
		std::cout << "Data 4: " << data4 << std::endl;
		std::cout << "Data 5: " << data5 << std::endl;
	}

	void setData(T d1, U d2, V d3, W d4, X d5) {
		data1 = d1;
		data2 = d2;
		data3 = d3;
		data4 = d4;
		data5 = d5;
	}

	T getData1() const { return data1; }
	U getData2() const { return data2; }
	V getData3() const { return data3; }
	W getData4() const { return data4; }
	X getData5() const { return data5; }
};