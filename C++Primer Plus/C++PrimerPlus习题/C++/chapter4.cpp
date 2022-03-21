#include <iostream>
#include <string>
#include <cstring>
#include <array>
using namespace std;
void question4_1()
{
    cout << "What is your first name?";
    string firstName;
    getline(cin, firstName);
    cout << "What is your last name?";
    string lastName;
    getline(cin, lastName);
    char grade;
    cout << "What letter grade do you deserve?";
    cin.get(grade);
    grade += 1;
    int age;
    cout << "What is your age?";
    cin >> age;
    cout << "Name: " + firstName + ", " + lastName << endl;
    cout << "Grade: " << grade << endl;
    cout << "Age: " << age << endl;
    return;
}
void question4_2()
{
    const int ArSize = 20;
    string name;
    string dessert;
    cout << "Enter your name: \n";
    getline(cin, name);
    cout << "Enter your favorite dessert: \n";
    getline(cin, dessert);
    cout << "I have some delicious " << dessert << " for you, " << name << ".\n";
    return;
}
void question4_3()
{
    cout << "Enter your first name: ";
    char firstName[20];
    cin.getline(firstName, sizeof(firstName));
    char lastName[40];
    cout << "Enter your last nane: ";
    cin.getline(lastName, sizeof(lastName));
    int len = strlen(lastName);
    lastName[len] = ',';
    lastName[len + 1] = ' ';
    lastName[len + 2] = '\0';
    strcat_s(lastName, sizeof(lastName), firstName);
    cout << lastName << endl;
}
void question4_4()
{
    cout << "Enter your first name: ";
    string firstName;
    getline(cin, firstName);
    string lastName;
    cout << "Enter your last nane: ";
    getline(cin, lastName);

    cout << lastName + ", " + firstName << endl;
}
void question4_5()
{
    struct Candybar {
        string brand;
        double weight;
        int colories;
    };
    Candybar snack{ "Mocha Munch", 2.3, 350 };
    cout << "Brand: " + snack.brand << endl;
    cout << "weight: " << snack.weight << endl;
    cout << "colories: " << snack.colories << endl;
    return;
}
void question4_6()
{
    struct Candybar {
        string brand;
        double weight;
        int colories;
    };
    Candybar snacks[3]{ { "Mocha Munch", 2.3, 350 }, { "Mocha Munch", 2.3, 350 }, { "Mocha Munch", 2.3, 350 } };
    cout << snacks[2].brand << endl;
}
void question4_9()
{
    struct Candybar {
        string brand;
        double weight;
        int colories;
    };
    Candybar* snacks_p = new Candybar[3]{ { "Mocha Munch", 2.3, 350 }, { "Mocha Munch", 2.3, 350 }, { "Mocha Munch", 2.3, 350 } };

    cout << snacks_p->brand << endl;
}
void question4_10()
{
    array<double, 3> res;
    for (int i = 0; i < 3; i++) {
        cin >> res.at(i);
    }
    cout << res.size() << endl;
    for (int i = 0; i < 3; i++) {
        cout << res[i] << endl;
    }
}