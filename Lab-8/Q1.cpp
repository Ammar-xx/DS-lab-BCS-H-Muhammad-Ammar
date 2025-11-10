#include <iostream>
#include <string>
using namespace std;

struct Person {
    string name;
    Person* mother;
    Person* father;
    Person(string n) : name(n), mother(NULL), father(NULL) {}
};

void printLeafNodes(Person* root) {
    if (!root) return;
    if (!root->mother && !root->father) {
        cout << root->name << " ";
        return;
    }
    printLeafNodes(root->mother);
    printLeafNodes(root->father);
}

int height(Person* root) {
    if (!root) return 0;
    int leftH = height(root->mother);
    int rightH = height(root->father);
    return (leftH > rightH ? leftH : rightH) + 1;
}

void printLevels(Person* root, int level = 1) {
    if (!root) return;
    cout << root->name << " → Level " << level << endl;
    printLevels(root->mother, level + 1);
    printLevels(root->father, level + 1);
}

int main() {
    Person* alex = new Person("Alex");
    alex->mother = new Person("Mary");
    alex->father = new Person("John");
    alex->mother->mother = new Person("Linda");
    alex->mother->father = new Person("Robert");
    alex->father->mother = new Person("Emma");
    alex->father->father = new Person("William");

    cout << "Root (Youngest Person): " << alex->name << endl;
    cout << "Leaf Nodes (Ancestors with no known parents): ";
    printLeafNodes(alex);
    cout << endl;
    cout << "Height of the Family Tree: " << height(alex) << endl;
    cout << "\nFamily Members with Levels:\n";
    printLevels(alex);
}
