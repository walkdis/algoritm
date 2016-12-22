#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()

{
    string s1, s2, greedy, mine;
    cout << "введите адрес фаил вывода жадного алгоритма";
    cin >> greedy;
    cout << "введите адрес фаил вывода другого алгоритма";
    cin >> mine;
    ifstream file1(greedy); 
    ifstream file2(mine);
    double gred, my;

    getline(file1, s1);
    getline(file2, s2);
    gred = atof(s1.c_str());
    my = atof(s2.c_str());
    if (gred > my)
      cout << "Жадный алгоритм менее эфективен";
    else     if (gred = my)
        cout << "Жадный алгоритм так же эфективен";
    else     if (gred < my)
        cout << "Жадный алгоритм более эфективен";
    file1.close();
    file1.close();
    system("pause");
    return 0;
}