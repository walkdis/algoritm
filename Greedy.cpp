// Copyright 2016 <Anna Simakova>
#include "Animals.h"
#include <cstdlib>
#include <exception>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <stdint.h>
#include "WrongEntr.h"

using namespace std;

int CountType(vector<Animals> mas) {
    vector < int > rt(1);
    unsigned int i, type;
    for (i = 0; i < mas.size(); i++){
        type = mas[i].GetType();
        for (unsigned int j = 0; j < rt.size(); j++)
            if (rt[j] == type)
                break;
            else if (j == rt.size() - 1)
                rt.push_back(type);


    }
    return (rt.size() - 1);
}

Animals GetMin(vector<Animals> matr) {
    Animals min = Animals();
    min.SetDistance(INT32_MAX);
    for (unsigned int i = 0; i < matr.size(); i++)
        if (min.GetDistance() > matr[i].GetDistance())
            min = matr[i];
    return min;
}

vector<Animals> DeleteType(vector<Animals> masiv, int type) {
    for (unsigned int i = 0; i < masiv.size(); i++) 
        if (masiv[i].GetType == type) {
            masiv.erase(masiv.begin() + i -1);
            i--;
        }
    return masiv;
}

vector<Animals> CountDistance(vector<Animals> masiv, Animals animal) {
    double distance = 0;
    for (unsigned int i = 0; i < masiv.size(); i++) {
        distance = sqrt(((masiv[i].GetX()) - animal.GetX())*((masiv[i].GetX()) - animal.GetX()) + ((masiv[i].GetY()) -
            animal.GetY())*((masiv[i].GetY()) - animal.GetY())) * 100 / animal.GetP();
        masiv[i].SetDistance(distance);
    }
    return masiv;
}

void main() {
    cout << "enter path to file in \n";
    string path_in, path_out, file_str, str;
    cin >> path_in;
    cout << "enter path to file out \n";
    cin >> path_out;

    std::ifstream xfile(path_in, std::ios::binary);
    //узнаем размер файла, и выделяем память в строке
    xfile.seekg(0, std::ios_base::end);
    file_str.resize(xfile.tellg());
    xfile.seekg(0, std::ios_base::beg);
    //копируем данные
    xfile.read((char*)file_str.data(), file_str.size());


    int length = file_str.length();
    int* array = new int[length];
    int k = 0;

    for (int i = 0; i <= length; i++) {
        if ((file_str[i] == ' ') || (i == length)) {
            array[k] = atoi(str.c_str());
            k++;
            str = "";
        }
        else
            str += file_str[i];
    }

    int* arr = new int[k];
    for (int i = 0; i < k; i++)
        arr[i] = array[i];// копирование 
    int l = 0;
    vector<Animals> mas(k / 4);
    Animals animals = Animals();
    for (int i = 0; i < k; i++) {
        Animals animal = Animals(arr[i], arr[i + 1], arr[i + 2], arr[i + 3]);
        mas[l] = animal;
        l++;
        i += 3;
    }
    int amount = CountType(mas);
    vector<string> result(amount);
    double res;
    mas = CountDistance(mas, animals);
    for (int i = 0; i < amount; i++) {
        animals = GetMin(mas);
        stringstream take;
        string get;
        take << animals << " ";
        res += animals.GetDistance();
        get = take.str();
        result[i] = get;
        mas = DeleteType(mas, animals.GetType());
        mas = CountDistance(mas, animals);
    }

    ofstream fout(path_out);
    fout << res << "\n";
    for (unsigned int i = 0; i < amount; i++)
        fout << result[i] << " ";
    fout.close();


}