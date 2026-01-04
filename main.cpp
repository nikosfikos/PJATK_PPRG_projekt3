#include <iostream>
#include <string>
using namespace std;

string nameOfDays[7] = {
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
Meal* addMeal(Meal* head ,Meal* meal) {
    Meal* current = head;
    if (head == nullptr) {
        // add meal to empty list
        head = meal;
        return head;
    }

    while (current->next != nullptr) {
        Meal* next= current->next;
        current = next;
    }
    current->next = meal;
    return head;
}

// II
int dailyCalorieSum(Day* day) {

        int sum = 0;
        Meal* current = (*day).head;

        while (current != nullptr ) {
            sum += (*current).calorieValue;
            Meal* next= (*current).next;
            current = next;
        }
        return sum;

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

bool isHealthy(Meal meal) {
    if (meal.calorieCategory == "good") {
        return true;
    }
    return false;
}

void raport(Meal* head, bool(*mealCalorieCheck)(Meal) ) {
        for (Meal* current = head; current != nullptr; current = current->next) {
            if (mealCalorieCheck(*current)) {
                cout << current->mealName << endl;
            }
        }
}

int main() {
    int numOfDays;
    int counter = 0;
    Meal* tmpMeal4 = new Meal{"Pizza", "bad", 1200, nullptr};
    Meal* tmpMeal3 = new Meal{"Jablko", "good", 50, nullptr};
    Meal* tmpMeal2 = new Meal{"Burger", "bad", 850, nullptr};
    Meal* tmpMeal1 = new Meal{"Owsianka", "good", 300, nullptr};

    cout<<"Podaj liczbe dni do analizy"<<endl;
    cin>>numOfDays;
    Day* array = new Day[numOfDays];

    // naming days loop
    while (counter <= numOfDays-1) {
        (*(array+counter)).head = nullptr;
        if (counter > 6){
            (*(array+counter)).dayName = *(nameOfDays+(counter%7));

        } else {
            (*(array+counter)).dayName = *(nameOfDays+counter);

        }
        counter++;
    }



    (*array).head = addMeal( (*array).head, tmpMeal1);
    (*array).head = addMeal( (*array).head, tmpMeal2);
    (*array).head = addMeal( (*array).head, tmpMeal3);
    (*(array+1)).head = addMeal( (*(array+1)).head, tmpMeal4);

    // display raport
    cout<< "--- RAPORT KALORYCZNY ---" <<endl;
    for (int i = 0; i < numOfDays; i++) {
        cout<< "Day: " << (*(array+i)).dayName << endl;
        cout<< "Suma kalorii: " << dailyCalorieSum(array+i) <<endl;
        cout<< "Znalezione posiłki wysokokaloryczne (>500kcal): "<<endl;
        raport((*(array+i)).head, categoryConditional);
        // different callback
        cout<< "Food in good category: " <<endl;
        raport((*(array+i)).head, isHealthy);
        cout << endl;
    }

    cout<< "--- CZYSZCZENIE PAMIĘCI ---" <<endl;
    for (int i=0; i <numOfDays; i++) {
        cout<<"Czyszczenie dnia: "<< (*(array+i)).dayName << endl;
        deleteMeal((*(array+i)).head);
    }
    delete[] array;
    return 0;
}