#include <iostream>

using namespace std;

typedef int Info;
struct Elem
{
    Elem* link;
    Info  info;
};

void Input(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->link = NULL;
    if (last != NULL)
        last->link = tmp;
    last = tmp;
    if (first == NULL)
        first = tmp;
}

void PrintList(Elem* current)
{
    if (current == NULL)
    {
        cout << endl;
        return;
    }

    cout << current->info << " ";
    PrintList(current->link);
}

void Delete(Elem* first, Elem* last)
{
    if (first == NULL)
    {
        return;
    }

    cout << first->info << " ";
    Elem* tmp = first;
    first = first->link;
    delete tmp;

    Delete(first, last);
}

void DeleteBefore(Elem*& first, Elem*& last, Info value)
{
    if (first == NULL || first->info == value)
    {
        return;
    }

    Elem* tmp = first;
    first = first->link;
    delete tmp;

    DeleteBefore(first, last, value);
}

void AddElements(Elem*& first, Elem*& last, int current, int n)
{
    if (current > n)
    {
        return;
    }

    Input(first, last, current);
    AddElements(first, last, current + 1, n);
}

int main()
{
    Elem* first = NULL, * last = NULL;
    int n = 20;

    AddElements(first, last, 1, n);
    PrintList(first);

    int value;
    cout << "Input value" << endl;
    cin >> value;
    cout << "Result:" << endl;
    DeleteBefore(first, last, value);

    Delete(first, last);

    return 0;
}



