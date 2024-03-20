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
    cout << "���������� ������ �� ������ \"" << name << "\":" << endl;
    bool found = false;
    for (int i = 0; i < nomerprodyctiv; ++i) {
        if (strstr(products[i].nazva, name) != nullptr) {
            cout << "����� ������: " << i + 1 << endl;
            cout << "�����: " << products[i].nazva << endl;
            cout << "��������: " << products[i].vurobnuktovary << endl;
            cout << "ֳ��: " << products[i].price << endl;
            cout << "�����: " << products[i].group << endl;
            cout << "���� �����������: " << products[i].arrivalDate << endl;
            cout << "����� ����������: " << products[i].expiryDate << endl;
            cout << "----------------------------------------" << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "����� �� �������� �� �������� ������." << endl;
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
    cout << "������ ���������� �� �����." << endl;
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
    cout << "������ ���������� �� ������ ������." << endl;
}
int main() {
    setlocale(LC_ALL, "rus");
    const int maximumproductiv = 100;
    Product products[maximumproductiv];
    int nomerprodyctiv = 0;

    char choice;
    do {
        cout << "����:" << endl;
        cout << "1. ������ ����� �����" << endl;
        cout << "2. �������� ������ ������" << endl;
        cout << "3. �������� �����" << endl;
        cout << "4. ������� �����" << endl;
        cout << "5. ����� ������" << endl;
        cout << "6. ���������� ������"<< endl;
        cout << "7. ��������� ��������" << endl;
        cout << "������� �����: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case '1': {
            cout << "��������� ������ ������:" << endl;
            cout << "������ ����� ������: ";
            cin.getline(products[nomerprodyctiv].nazva, sizeof(products[nomerprodyctiv].nazva));
            cout << "������ ��������� ������: ";
            cin.getline(products[nomerprodyctiv].vurobnuktovary, sizeof(products[nomerprodyctiv].vurobnuktovary));
            cout << "������ ���� ������: ";
            cin >> products[nomerprodyctiv].price;
            cin.ignore();
            cout << "������ ����� ������: ";
            cin.getline(products[nomerprodyctiv].group, sizeof(products[nomerprodyctiv].group));
            cout << "������ ���� ����������� ������: ";
            cin.getline(products[nomerprodyctiv].arrivalDate, sizeof(products[nomerprodyctiv].arrivalDate));
            cout << "������ ���� ��������� ������ ���������� ������: ";
            cin.getline(products[nomerprodyctiv].expiryDate, sizeof(products[nomerprodyctiv].expiryDate));
            nomerprodyctiv++;
            break;
        }
        case '2': {
            cout << "������ ������ �� �����:" << endl;
            for (int i = 0; i < nomerprodyctiv; ++i) {
                cout << "����� " << i + 1 << ":" << endl;
                cout << "�����: " << products[i].nazva << endl;
                cout << "��������: " << products[i].vurobnuktovary << endl;
                cout << "ֳ��: " << products[i].price << endl;
                cout << "�����: " << products[i].group << endl;
                cout << "���� �����������: " << products[i].arrivalDate << endl;
                cout << "����� ����������: " << products[i].expiryDate << endl;
                cout << "----------------------------------------" << endl;
            }
            break;
        }
        case '3': {
            if (nomerprodyctiv > 0) {
                cout << "������� ����� ������ ��� ���������: ";
                int vudalenyatovara;
                cin >> vudalenyatovara;
                if (vudalenyatovara > 0 && vudalenyatovara <= nomerprodyctiv) {
                    for (int i = vudalenyatovara - 1; i < nomerprodyctiv - 1; ++i) {
                        products[i] = products[i + 1];
                    }
                    nomerprodyctiv--;
                    cout << "����� ������ �������� � ������." << endl;
                }
                else {
                    cout << "����������� ����� ������." << endl;
                }
            }
            else {
                cout << "����� �������. ���� ������ ��� ���������." << endl;
            }
            break;
        }
        case '4': {
            if (nomerprodyctiv > 0) {
                cout << "������� ����� ������ ��� �����: ";
                int replaceIndex;
                cin >> replaceIndex;
                if (replaceIndex > 0 && replaceIndex <= nomerprodyctiv) {
                    cout << "������ ���� ����� ������: ";
                    cin.ignore();
                    cin.getline(products[replaceIndex - 1].nazva, sizeof(products[replaceIndex - 1].nazva));
                    cout << "������ ������ ��������� ������: ";
                    cin.getline(products[replaceIndex - 1].vurobnuktovary, sizeof(products[replaceIndex - 1].vurobnuktovary));
                    cout << "������ ���� ���� ������: ";
                    cin >> products[replaceIndex - 1].price;
                    cin.ignore();
                    cout << "������ ���� ����� ������: ";
                    cin.getline(products[replaceIndex - 1].group, sizeof(products[replaceIndex - 1].group));
                    cout << "������ ���� ���� ����������� ������: ";
                    cin.getline(products[replaceIndex - 1].arrivalDate, sizeof(products[replaceIndex - 1].arrivalDate));
                    cout << "������ ���� ���� ��������� ������ ���������� ������: ";
                    cin.getline(products[replaceIndex - 1].expiryDate, sizeof(products[replaceIndex - 1].expiryDate));
                    cout << "����� ������ �������." << endl;
                }
                else {
                    cout << "����������� ����� ������." << endl;
                }
            }
            else {
                cout << "����� �������. ���� ������ ��� �����." << endl;
            }
            break;
        }
        case '5': {
            cout << "����� ������:" << endl;
            cout << "1. �� ������" << endl;
            cout << "2. �� ����������" << endl;
            cout << "3. �� �����" << endl;
            cout << "4. �� ������ ������" << endl;
            cout << "5. �� ����� ����������� �� �����" << endl;
            cout << "6. �� ������� ����������" << endl;
            cout << "������� ����� ������: ";
            int poshyktovary;
            cin >> poshyktovary;
            cin.ignore();
            switch (poshyktovary) {
            case 1: {
                char name[50];
                cout << "������ ����� ������: ";
                cin.getline(name, sizeof(name));
                searchByName(products, nomerprodyctiv, name);
                break;
            }
            }
            break;
        }
        case '6': {
            cout << "���������� ������:" << endl;
            cout << "1. �� �����" << endl;
            cout << "2. �� ������ ������" << endl;
            cout << "������� ����� ����������: ";
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
            cout << "�������� ���������." << endl;
            break;
        }
        default:
            cout << "����������� ���� �����. ���� �����, ��������� �� ���." << endl;
            break;
        }
    } while (choice != '6');

    return 0;
}