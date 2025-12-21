// uzyc VALGRID czy jakos tak do weryfikacji wyciekow pamieci
#include <iostream>
#include <string>
enum nameOfDays {
    MONDAY,
    TUESDAY ,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};
using namespace std;
/*
template <typename T>
struct Node {
    T value;
    Node* next;
};
*/
struct Meal {
    string mealName;
    string calorieCategory;
    int calorieValue;
    Meal* next;
};
struct Day {
    string dayName;
    Day* head;
};


int main() {
    int numOfDays;
    cout<<"Podaj liczbe dni do analizy"<<endl;
    cin>>numOfDays;
    return 0;
}