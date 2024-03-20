#include <iostream>

using namespace std;

struct Product {
    char nazva[50];
    char vurobnuktovary[50];
    double price;
    char group[50];
    char arrivalDate[11];
    char expiryDate[11];
};

void searchByName(Product products[], int nomerprodyctiv, const char* name) {
    cout << "Результати пошуку за назвою \"" << name << "\":" << endl;
    bool found = false;
    for (int i = 0; i < nomerprodyctiv; ++i) {
        if (strstr(products[i].nazva, name) != nullptr) {
            cout << "Номер товару: " << i + 1 << endl;
            cout << "Назва: " << products[i].nazva << endl;
            cout << "Виробник: " << products[i].vurobnuktovary << endl;
            cout << "Ціна: " << products[i].price << endl;
            cout << "Група: " << products[i].group << endl;
            cout << "Дата надходження: " << products[i].arrivalDate << endl;
            cout << "Термін придатності: " << products[i].expiryDate << endl;
            cout << "----------------------------------------" << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Товар не знайдено за вказаною назвою." << endl;
    }
}
void sortByPrice(Product products[], int nomerprodyctiv) {
    for (int i = 0; i < nomerprodyctiv - 1; ++i) {
        for (int j = 0; j < nomerprodyctiv - i - 1; ++j) {
            if (products[j].price > products[j + 1].price) {
                Product temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }
    cout << "Товари відсортовані за ціною." << endl;
}
void sortByGroup(Product products[], int nomerprodyctiv) {
    for (int i = 0; i < nomerprodyctiv - 1; ++i) {
        for (int j = 0; j < nomerprodyctiv - i - 1; ++j) {
            if (strcmp(products[j].group, products[j + 1].group) > 0) {
                Product temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }
    cout << "Товари відсортовані за групою товару." << endl;
}
int main() {
    setlocale(LC_ALL, "rus");
    const int maximumproductiv = 100;
    Product products[maximumproductiv];
    int nomerprodyctiv = 0;

    char choice;
    do {
        cout << "Меню:" << endl;
        cout << "1. Додати новий товар" << endl;
        cout << "2. Показати список товарів" << endl;
        cout << "3. Видалити товар" << endl;
        cout << "4. Замінити товар" << endl;
        cout << "5. Пошук товару" << endl;
        cout << "6. Сортування товару"<< endl;
        cout << "7. Завершити програму" << endl;
        cout << "Виберіть опцію: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case '1': {
            cout << "Додавання нового товару:" << endl;
            cout << "Введіть назву товару: ";
            cin.getline(products[nomerprodyctiv].nazva, sizeof(products[nomerprodyctiv].nazva));
            cout << "Введіть виробника товару: ";
            cin.getline(products[nomerprodyctiv].vurobnuktovary, sizeof(products[nomerprodyctiv].vurobnuktovary));
            cout << "Введіть ціну товару: ";
            cin >> products[nomerprodyctiv].price;
            cin.ignore();
            cout << "Введіть групу товару: ";
            cin.getline(products[nomerprodyctiv].group, sizeof(products[nomerprodyctiv].group));
            cout << "Введіть дату надходження товару: ";
            cin.getline(products[nomerprodyctiv].arrivalDate, sizeof(products[nomerprodyctiv].arrivalDate));
            cout << "Введіть дату закінчення терміну придатності товару: ";
            cin.getline(products[nomerprodyctiv].expiryDate, sizeof(products[nomerprodyctiv].expiryDate));
            nomerprodyctiv++;
            break;
        }
        case '2': {
            cout << "Список товарів на складі:" << endl;
            for (int i = 0; i < nomerprodyctiv; ++i) {
                cout << "Товар " << i + 1 << ":" << endl;
                cout << "Назва: " << products[i].nazva << endl;
                cout << "Виробник: " << products[i].vurobnuktovary << endl;
                cout << "Ціна: " << products[i].price << endl;
                cout << "Група: " << products[i].group << endl;
                cout << "Дата надходження: " << products[i].arrivalDate << endl;
                cout << "Термін придатності: " << products[i].expiryDate << endl;
                cout << "----------------------------------------" << endl;
            }
            break;
        }
        case '3': {
            if (nomerprodyctiv > 0) {
                cout << "Виберіть номер товару для видалення: ";
                int vudalenyatovara;
                cin >> vudalenyatovara;
                if (vudalenyatovara > 0 && vudalenyatovara <= nomerprodyctiv) {
                    for (int i = vudalenyatovara - 1; i < nomerprodyctiv - 1; ++i) {
                        products[i] = products[i + 1];
                    }
                    nomerprodyctiv--;
                    cout << "Товар успішно видалено зі складу." << endl;
                }
                else {
                    cout << "Некоректний номер товару." << endl;
                }
            }
            else {
                cout << "Склад порожній. Немає товарів для видалення." << endl;
            }
            break;
        }
        case '4': {
            if (nomerprodyctiv > 0) {
                cout << "Виберіть номер товару для заміни: ";
                int replaceIndex;
                cin >> replaceIndex;
                if (replaceIndex > 0 && replaceIndex <= nomerprodyctiv) {
                    cout << "Введіть нову назву товару: ";
                    cin.ignore();
                    cin.getline(products[replaceIndex - 1].nazva, sizeof(products[replaceIndex - 1].nazva));
                    cout << "Введіть нового виробника товару: ";
                    cin.getline(products[replaceIndex - 1].vurobnuktovary, sizeof(products[replaceIndex - 1].vurobnuktovary));
                    cout << "Введіть нову ціну товару: ";
                    cin >> products[replaceIndex - 1].price;
                    cin.ignore();
                    cout << "Введіть нову групу товару: ";
                    cin.getline(products[replaceIndex - 1].group, sizeof(products[replaceIndex - 1].group));
                    cout << "Введіть нову дату надходження товару: ";
                    cin.getline(products[replaceIndex - 1].arrivalDate, sizeof(products[replaceIndex - 1].arrivalDate));
                    cout << "Введіть нову дату закінчення терміну придатності товару: ";
                    cin.getline(products[replaceIndex - 1].expiryDate, sizeof(products[replaceIndex - 1].expiryDate));
                    cout << "Товар успішно замінено." << endl;
                }
                else {
                    cout << "Некоректний номер товару." << endl;
                }
            }
            else {
                cout << "Склад порожній. Немає товарів для заміни." << endl;
            }
            break;
        }
        case '5': {
            cout << "Пошук товару:" << endl;
            cout << "1. За назвою" << endl;
            cout << "2. За виробником" << endl;
            cout << "3. За ціною" << endl;
            cout << "4. За групою товару" << endl;
            cout << "5. За датою надходження на склад" << endl;
            cout << "6. За терміном придатності" << endl;
            cout << "Виберіть опцію пошуку: ";
            int poshyktovary;
            cin >> poshyktovary;
            cin.ignore();
            switch (poshyktovary) {
            case 1: {
                char name[50];
                cout << "Введіть назву товару: ";
                cin.getline(name, sizeof(name));
                searchByName(products, nomerprodyctiv, name);
                break;
            }
            }
            break;
        }
        case '6': {
            cout << "Сортування товару:" << endl;
            cout << "1. За ціною" << endl;
            cout << "2. За групою товару" << endl;
            cout << "Виберіть опцію сортування: ";
            int sortingOption;
            cin >> sortingOption;
            cin.ignore();
            switch (sortingOption) {
            case 1: {
                sortByPrice(products, nomerprodyctiv);
                break;
            }
            }
            break;
        }
        case '7': {
            cout << "Програму завершено." << endl;
            break;
        }
        default:
            cout << "Некоректний вибір опції. Будь ласка, спробуйте ще раз." << endl;
            break;
        }
    } while (choice != '6');

    return 0;
}