# 45pkt - Zadanie na ocene 3
Termin: 10 stycznia 2026 16:00
Instrukcje

## Zadanie Programistyczne: Dietetyczny Detektyw – Etap II (łącznie 45 pkt)

Temat: Dynamiczne struktury danych, zarządzanie pamięcią, arytmetyka wskaźników i rekurencja.
Wprowadzenie

W związku z ograniczeniami poprzedniej wersji systemu, polegającymi na sztywnym limitowaniu liczby wpisów w dzienniku, podjęto decyzję o refaktoryzacji warstwy danych. Nowa implementacja modułu analitycznego ma opierać się na strukturach dynamicznych, pozwalających na elastyczne zarządzanie pamięcią operacyjną w zależności od liczby wprowadzonych przez użytkownika danych.
Celem zadania jest weryfikacja umiejętności manualnego zarządzania pamięcią (sterta), operowania na listach jednokierunkowych oraz rozumienia mechanizmów wskaźnikowych bez użycia abstrakcji wysokiego poziomu (jak kontenery STL).

### Wymagania Wstępne i Ograniczenia

Program nie może zawierać wycieków pamięci. Każda zaalokowana dynamicznie struktura musi zostać poprawnie zwolniona przed zakończeniem programu.
Rozwiązanie musi ściśle przestrzegać narzuconych w dalszej części instrukcji ograniczeń składniowych (tzw. restrykcje implementacyjne).
Specyfikacja Struktur Danych

Należy zaprojektować system oparty na dwóch typach struktur:  

**Struktura Posiłku:** Przechowuje nazwę posiłku, kategorie kalotyczną, wartość kaloryczną oraz wskaźnik na kolejny element tego samego typu (tworząc listę jednokierunkową).  

**Struktura Dnia:** Przechowuje nazwę dnia oraz wskaźnik na pierwszy element listy posiłków (głowę listy).
W funkcji głównej program ma pobrać od użytkownika liczbę dni do analizy, a następnie utworzyć dynamiczną tablicę struktur Dnia o zadanym rozmiarze.
## Część I: Dynamiczna Alokacja Danych

Należy zaimplementować funkcję umożliwiającą dodanie nowego posiłku do wybranego dnia.
Funkcja powinna przyjmować wskaźnik na strukturę Dnia oraz dane nowego posiłku.
Nowy element musi zostać dodany na koniec listy wiązanej przypisanej do danego dnia.
Przykład logiczny działania:
Stan obecny: Poniedziałek: [Jajka] -> [Tost] -> NULL
Akcja: Dodaj "Kawa"
Stan po operacji: Poniedziałek: [Jajka] -> [Tost] -> [Kawa] -> NULL
## Część II: Analiza z Wykorzystaniem Arytmetyki Wskaźników

Należy zaimplementować funkcję obliczającą sumę kalorii dla wskazanego dnia.
Restrykcja implementacyjna (Kluczowa):
W ciele tej funkcji zabrania się używania operatora dostępu do składowych przez wskaźnik (->) oraz operatora indeksowania tablic ([]).
Dostęp do pól struktur oraz nawigacja po liście musi odbywać się wyłącznie poprzez jawne wyłuskanie (*) i operacje na adresach. Celem jest weryfikacja zrozumienia, czym w istocie jest wskaźnik na strukturę w pamięci.
## Część III: Rekurencyjne Zwalanianie Zasobów

Należy zaimplementować funkcję czyszczącą pamięć przydzieloną na listę posiłków.
Wymagania:
Funkcja musi być rekurencyjna.
Usuwanie elementów musi odbywać się w porządku odwrotnym do ich występowania na liście (od ostatniego do pierwszego).
Przed usunięciem każdego elementu program ma wypisać komunikat na konsolę potwierdzający operację.
Przykład oczekiwanego wyjścia dla listy: [Jajka] -> [Tost] -> [Kawa]
Plaintext


Usuwanie: Kawa
Usuwanie: Tost
Usuwanie: Jajka

## Część IV: Funkcje Wyższego Rzędu (Callback)

Należy zaimplementować funkcję raportującą, która przyjmuje:
Wskaźnik na listę posiłków.
Wskaźnik na funkcję warunkową (zwracającą bool, a przyjmującą struct Dania struct Danie).
Funkcja raportująca ma wypisać nazwy tylko tych posiłków, które spełniają warunek zdefiniowany w przekazanej funkcji (np. kalorie > 500) oraz 2 przykład użycia: funkcja która wypisze tylko nazwy posiłków z podanej kategorii

## Część V: Idiomatyczny c++

Należy przepisać cały program używając:
std::vector<>
std::memory (make_unique, move, etc)
const gdzie będzie to możliwe
referencji (&) zamiast wskaźników (*) gdzie to możliwe
templateów (template <typename T>) przy funkcjach tam gdzie kod może byc taki sam dla więcej niż 1 typu (np. wprowadzanie danych)
Zwracamy będą 2 wersje tego samego programu.
Scenariusz Testowy (Oczekiwane działanie programu)

Program po uruchomieniu powinien realizować poniższy scenariusz (dane wejściowe mogą być wpisane na sztywno w main lub podawane przez użytkownika):
Utworzenie tablicy dla 2 dni.
Dodanie do Dnia 1 (Poniedziałek) posiłków:
"Owsianka" (300 kcal)
"Burger" (850 kcal)
"Jabłko" (50 kcal)
Dodanie do Dnia 2 (Wtorek) posiłków:
"Pizza" (1200 kcal)
Wyświetlenie sumy kalorii (test arytmetyki wskaźników).
Wyszukanie "Grzechów" (posiłków > 500 kcal).
Usunięcie danych (test rekurencji).
Przykładowy zrzut ekranu konsoli (Output):

Plaintext


--- RAPORT KALORYCZNY ---
Dzień: Poniedziałek
Suma kalorii: 1200
Znalezione posiłki wysokokaloryczne (>500kcal):
- Burger

Dzień: Wtorek
Suma kalorii: 1200
Znalezione posiłki wysokokaloryczne (>500kcal):
- Pizza

--- CZYSZCZENIE PAMIĘCI ---
Czyszczenie dnia: Poniedziałek...
> Usunięto z pamięci: Jabłko
> Usunięto z pamięci: Burger
> Usunięto z pamięci: Owsianka
Czyszczenie dnia: Wtorek...
> Usunięto z pamięci: Pizza

Koniec programu.