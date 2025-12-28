#include <chrono>
#include <iostream>
#include <string>
using namespace std;

constexpr string nameOfDays[7] = {
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday"
};



struct Meal {
    string mealName;
    string calorieCategory;
    int calorieValue;
    Meal* next;
};

struct Day {
    string dayName;
    Meal *head;
};

void addMeal(Meal* head ,Meal* meal) {
    Meal* current = head->next;
    head->next = current;
    Meal* tmp = current;
    while (current->next != nullptr) {
        current = current->next;
        tmp = current->next;
    }
    current = tmp;
    current->next = meal;

}

void displayMeals(Meal* head) {
    for (Meal* current = head; current != nullptr; current = current->next) {
        cout << current->mealName << " "
        << current->calorieCategory << " "
        << current->calorieValue << endl;
    }
}

void deleteMeal(Meal* head) {
    if (head->next == nullptr) {
        return;
    }
    deleteMeal(head->next);
    delete head;
}

int main() {
    int numOfDays;
    int counter = 0;

    cout<<"Podaj liczbe dni do analizy"<<endl;
    cin>>numOfDays;

    Day* array = new Day[numOfDays];


    while (counter <= numOfDays-1) {
        if (counter > 6){
            array[counter].dayName = nameOfDays[counter%7];

        } else {
            array[counter].dayName = nameOfDays[counter];

        }
        counter++;
    }

    for (int i = 0; i < numOfDays; i++) {
        cout << array[i].dayName << endl;
    }

    Meal* tmpMeal2 = new Meal{"bulka", "dobra", 100, nullptr};
    Meal *tmpMeal1 = new Meal{"piwko", "zla", 500, tmpMeal2};
    addMeal(array[0].head, tmpMeal1);

    for (int i = 0; i < numOfDays; i++) {
        cout << array[i].dayName << endl;
    }

    deleteMeal(array[0].head);
    delete[] array;
    return 0;
}