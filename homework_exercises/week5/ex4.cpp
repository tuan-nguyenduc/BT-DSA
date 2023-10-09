#include <iostream>
#include <map>

using namespace std;

int main() {
    map<int, pair<string, string>> students;

    while (true) {
        string command;
        cin >> command;

        if (command == "Insert") {
            int ID;
            string name, className;
            cin >> ID >> name >> className;
            students[ID] = make_pair(name, className);
        } else if (command == "Delete") {
            int ID;
            cin >> ID;
            students.erase(ID);
        } else if (command == "Infor") {
            int ID;
            cin >> ID;
            if (students.find(ID) != students.end()) {
                cout << students[ID].first << "," << students[ID].second << endl;
            } else {
                cout << "NA, NA" << endl;
            }
        }
        else {
            break;
        }
    }
    return 0;
}