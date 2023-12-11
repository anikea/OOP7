#include "class_ini.h"
#include <iostream>
#include <locale>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ukr");
    User user1;
    User user2;
    User user3;
    User user4;

    vector<User> usersA;

    usersA.push_back(user1);
    usersA.push_back(user2);
    usersA.push_back(user3);
    usersA.push_back(user4);

    cout << "Vector size - " << usersA.size() << '\n';

    list<User> users_list;

    users_list.push_back(user1);
    users_list.push_back(user2);
    users_list.push_back(user3);
    users_list.push_back(user4);

    cout << "List size - " << users_list.size() << '\n';

    deque<User> deq_users;

    deq_users.push_back(user1);
    deq_users.push_back(user2);
    deq_users.push_back(user3);
    deq_users.push_back(user4);

    cout << "Deque size - " << deq_users.size() << '\n';

    set<int> users_set;

    users_set.insert(1);
    users_set.insert(2);
    users_set.insert(3);
    users_set.insert(4);

    users_set.erase(4);

    cout << "Set size - " << users_set.size() << '\n';

    multiset<int> multi_users;

    multi_users.insert(2);
    multi_users.insert(3);
    multi_users.insert(4);
    multi_users.insert(4);

    multi_users.erase(2);

    cout << "Multiset size - " << multi_users.size() << '\n';

    map<string, User> users_map;

    users_map["one"] = user1;
    users_map["two"] = user2;
    users_map["three"] = user3;
    users_map["four"] = user4;

    cout << "Map size - " << users_map.size() << '\n';

    multimap<string, User> users_maps;

    users_maps.insert(make_pair("one", user1));
    users_maps.insert(make_pair("one", user2));

    cout << "Multimap size - " << users_maps.size() << '\n';

    stack<User> users_stack;

    users_stack.push(user1);
    users_stack.push(user2);
    users_stack.push(user3);
    users_stack.push(user4);

    users_stack.pop();

    cout << "Stack size - " << users_stack.size() << '\n';

    queue<User> users_que;

    users_que.push(user1);
    users_que.push(user2);
    users_que.push(user3);
    users_que.push(user4);

    users_que.pop();

    cout << "Queue size - " << users_que.size() << '\n';

    priority_queue<int> pri_users;


    pri_users.push(1);
    pri_users.push(2);
    pri_users.push(3);
    pri_users.push(4);

    cout << "Priority Queue size - " << pri_users.size() << '\n';

    std::vector<User> users;

    // Додавання об'єктів класу User у вектор
    users.push_back(User("John", "Doe", 25));
    users.push_back(User("Jane", "Smith", 30));
    users.push_back(User("Alice", "Johnson", 28));

    cout << '\n';

    // Вхідні (Input) ітератори - для читання значень
    std::vector<User>::iterator inputIterator = users.begin();
    for (; inputIterator != users.end(); ++inputIterator) {
        inputIterator->showUser();

    }
    cout << '\n';
    // Вихідні (Output) ітератори - для запису значень
    std::back_insert_iterator<std::vector<User>> outputIterator(users);
    *outputIterator = User("Mark", "Taylor", 22);

    // Односпрямовані (Forward) ітератори - для послідовного доступу
    std::vector<User>::iterator forwardIterator = users.begin();
    // Рух в одному напрямку
    for (; forwardIterator != users.end(); ++forwardIterator) {
        forwardIterator->showUser();
    }
    cout << '\n';
    // Двонаправлені (Bidirectional) ітератори - для руху в обидва напрямки
    std::vector<User>::reverse_iterator backwardIterator = users.rbegin();
    // Рух в зворотньому напрямку
    for (; backwardIterator != users.rend(); ++backwardIterator) {
        backwardIterator->showUser();
    }
    cout << '\n';
    // Ітератор довільного доступу (Random Access) - для випадкового доступу до елементів
    std::vector<User>::iterator randomAccessIterator = users.begin();
    randomAccessIterator += 2; // Переміщення на 2 позиції вперед
    randomAccessIterator->showUser(); // Показати користувача на позиції 2


    std::vector<User> algo_users = {
    User("John", "Doe", 25),
    User("Alice", "Smith", 30),
    User("Bob", "Johnson", 28),
    User("Eva", "Williams", 22)
    };

    // Відсортуємо вектор об'єктів за ім'ям
    std::sort(algo_users.begin(), algo_users.end());

    // Для прикладу, знайдемо користувача з ім'ям "Alice"
    std::string targetName = "Alice";
    auto it = std::find_if(algo_users.begin(), algo_users.end(), [targetName](const User& user) {
        return user.getName() == targetName;
        });

    if (it != algo_users.end()) {
        std::cout << "User found: " << it->getName() << std::endl;
    }
    else {
        std::cout << "User not found." << std::endl;
    }

    return 0;
}