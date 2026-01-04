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

// I
void addMeal(Meal* &head ,Meal* meal) {
    Meal* current = head;
    if (head == nullptr) {
        // add meal to empty list
        head = meal;
        return;
    }

    while (current->next != nullptr) {
        Meal* next= current->next;
        current = next;
    }
    current->next = meal;

}

// II
void dailyCalorieSum(Day* array, int numOfDays ) {

    for (int i = 0; i < numOfDays; i++) {
        int sum = 0;
        Meal* current = (*(array+i)).head;

        cout << (*(array+i)).dayName << endl;

        while (current != nullptr ) {
            sum += (*current).calorieValue;
            Meal* next= (*current).next;
            current = next;
        }
        cout << "Calorie sum: " << sum << endl;

    }

}

void displayMeals(Meal* head) {
    for (Meal* current = head; current != nullptr; current = current->next) {
        cout << current->mealName << " "
        << current->calorieCategory << " "
        << current->calorieValue << endl;
    }
}
 // III
void deleteMeal(Meal* head) {
    if (head == nullptr) {
        return;
    }
    deleteMeal(head->next);
    cout<< "Removed from memory: "<< head->mealName << endl;
    delete head;
}

// IV
bool categoryConditional(Meal meal) {
    if (meal.calorieValue > 500) {
        return true;
    }
    return false;

}

void raport(Day* array, int numOfDays, bool(*mealCalorieCheck)(Meal) ) {

    for (int i = 0; i < numOfDays; i++) {
        cout<<"found high calorie value meals (>500kcal):"<<endl;
        for (Meal* current = array[i].head; current != nullptr; current = current->next) {
            if (mealCalorieCheck(*current)) {
                cout << current->mealName << endl;
            }
        }
    }

}

int main() {
    int numOfDays;
    int counter = 0;

    cout<<"Podaj liczbe dni do analizy"<<endl;
    cin>>numOfDays;

    Day* array = new Day[numOfDays];

    // naming days loop
    while (counter <= numOfDays-1) {
        array[counter].head = nullptr;
        if (counter > 6){
            array[counter].dayName = nameOfDays[counter%7];

        } else {
            array[counter].dayName = nameOfDays[counter];

        }
        counter++;
    }


    Meal* tmpMeal2 = new Meal{"tost", "dobra", 100, nullptr};
    Meal *tmpMeal1 = new Meal{"jajka", "zla", 501, nullptr};
    array[0].head = tmpMeal1;

    addMeal(array[0].head, tmpMeal2);
    // displayMeals(array[0].head);

    dailyCalorieSum(array, numOfDays);

    raport(array, numOfDays, categoryConditional);

    deleteMeal(array[0].head);
    delete[] array;
    return 0;
}