#include <iostream>
#include <windows.h>
#include <time.h>
#include <iomanip>

using namespace std;

struct E
{
    E* next;
    E* prev;
    int info;
};

void CreateDoubleList(E*& first, E*& last, int N, int Low, int High, int i);
void Print(E* first);
int Count(E* first, int k);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand((unsigned)time(NULL));
    E* first = NULL, 
        * last = NULL;

    int N, Low, High;
    cout << "Кількість елементів у списку: "; cin >> N;
    cout << "Найменше значення елементу списку: "; cin >> Low;
    cout << "Найбільше значення елементу списку: "; cin >> High;

    CreateDoubleList(first, last, N, Low, High, 0);

    cout << "Список: ";  Print(first);
    cout << endl << endl;

    cout << "Кількість від'ємних елементів: " << Count(first, 0) << endl;

    return 0;
}

void CreateDoubleList(E*& first, E*& last, int N, int Low, int High, int i)
{
    if (i <= N)
    {
        int infoElem = Low + rand() % (Low - High + 1); // 1
        E* tmp = new E; // 2
        tmp->info = infoElem; // 3
        tmp->next = NULL; // 4
        if (last != NULL)
            last->next = tmp; // 5
        tmp->prev = last; // 6
        last = tmp; // 7
        if (first == NULL)
            first = tmp; // 8
        CreateDoubleList(first, last, N, Low, High, i + 1);
    }
}

void Print(E* first)
{
    if (first != NULL)
    {
        cout << first->info << "  "; // 1
        Print(first->next); // 2
    }
}

int Count(E* first, int k)
{
    if (first != NULL)
    {
        if (first->info < 0) // 1
            k++;
        return Count(first->next, k); // 2
    }
    else
        return k;
}