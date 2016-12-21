// Copyright 2016 <Anna Simakova>
#include "Animals.h"
//#include "TypeOfAnimal.h"
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

vector<vector<Animals>> DoMatr(vector<Animals> arr) {
    vector<vector<Animals>> matrix(arr.size());
    for (unsigned int i = 0; i < arr.size(); i++)
        matrix[i].resize(arr.size());
    for (unsigned int i = 0; i < arr.size(); i++) {
        for (unsigned int j = i; j < arr.size(); j++) {
            if (i == j){
                matrix[i][j] = arr[j];
                matrix[i][j].SetDistance(INT32_MAX);
            }
            else {
                double dist = sqrt(((arr[i].GetX()) - (arr[j].GetX()))*((arr[i].GetX()) - (arr[j].GetX())) + ((arr[i].GetY()) - 
                    (arr[j].GetY()))*((arr[i].GetY()) - (arr[j].GetY()))) * 100 / (arr[j].GetP());
                matrix[i][j] = arr[j];
                matrix[i][j].SetDistance(dist);
                matrix[j][i] = matrix[i][j];
            }
        }
    }

    return matrix;
}


double GetMinRow(vector<vector<Animals>> matr, int num) {
    double min = INT32_MAX;
    for (unsigned int i = 0; i < matr[num].size() - 1; i++)
        if (min > matr[num][i].GetDistance())
            min = matr[num][i].GetDistance();
    return min;
}


double GetMinCol(vector<vector<Animals>> matr, int num) {
    double min = INT32_MAX;
    for (unsigned int i = 0; i < matr[num].size() - 1; i++)
        if (min > matr[i][num].GetDistance())
            min = matr[i][num].GetDistance();
    return min;
}
vector<vector<Animals>> GetRowMatr(vector<vector<Animals>> arr, int size) {
    vector<vector<Animals>> matrixforRow(size);
    for (unsigned int i = 0; i < size; i++)
        matrixforRow[i].resize(size);
    for (unsigned int i = 0; i < size; i++)
        for (unsigned j = 0; j < size; j++)
            matrixforRow[i][j].SetExist(0);
    for (unsigned int i = 0; i < size; i++) {
        double min = GetMinRow(arr, i);
        for (unsigned int j = 0; j < size; j++) {
            if (min == arr[i][j].GetDistance())
                matrixforRow[i][j] = arr[i][j];
        }
    }
    return matrixforRow;
}

vector<vector<Animals>> GetColMatr(vector<vector<Animals>> arr, int size) {
    vector<vector<Animals>> matrixforCol(size);
    for (unsigned int i = 0; i < size; i++)
        matrixforCol[i].resize(size);
    for (unsigned int i = 0; i < size; i++) {
        double min = GetMinCol(arr, i);
        for (unsigned int j = 0; j < size; j++) {
            if (min == arr[j][i].GetDistance())
                matrixforCol[j][i] = arr[j][i];
        }
    }
    return matrixforCol;
}

vector<vector<Animals>> GetLessMatr(vector<vector<Animals>> matrix, vector<vector<Animals>> matrixforRow, vector<vector<Animals>> matrixforCol, vector<Animals> ms, int size) {
    int type;
    for (unsigned int i = 0; i < size; i++) {
        for (unsigned int j = 0; j < matrix[i].size(); j++){
            if ((matrixforCol[i][j] == matrixforRow[i][j]) && (matrixforCol[i][j].GetExist() != false) && (i != j)) {
                type = matrix[i][j].GetType();
                for (unsigned int m = 0; m < size; m++) {
                    if (ms[m].GetType() == type){
                        for (unsigned int t = 0; t < ms.size(); t++) {
                            if ((m == j) && (m != 5))
                                break;
                            // m++;
                            matrix[m][t].SetExist(false);
                        }
                    }
                    for (unsigned int t = 0; t < ms.size(); t++) {
                        matrix[t][m].SetExist(false);
                    }
                }
            }

        }
    }
    return matrix;
}

vector<vector<Animals>> GetLessMatrRow(vector<vector<Animals>> matrix, vector<vector<Animals>> matrixforRow, vector<vector<Animals>> matrixforCol, vector<Animals> ms, int size) {
    int type;
    for (unsigned int i = 0; i < size; i++) {
        for (unsigned int j = 0; j < matrix[i].size(); j++){
            if ((matrixforCol[i][j] == matrixforRow[i][j]) && (matrixforCol[i][j].GetExist() != false) && (i != j)) {
                type = matrix[i][j].GetType();
                for (unsigned int m = 0; m < size; m++) {
                    if (ms[m].GetType() == type){
                        for (unsigned int t = 0; t < ms.size(); t++) {
                            if ((m == j) && (m != 5))
                                break;
                            // m++;
                            matrixforRow[m][t].SetExist(false);
                        }
                        for (unsigned int t = 0; t < ms.size(); t++) {
                            matrixforRow[t][m].SetExist(false);
                        }
                    }
                }

            }
        }
    }
    return matrixforRow;
}

vector<vector<Animals>> GetLessMatrCol(vector<vector<Animals>> matrix, vector<vector<Animals>> matrixforRow, vector<vector<Animals>> matrixforCol, vector<Animals> ms, int size) {
    int type;
    for (unsigned int i = 0; i < size; i++) {
        for (unsigned int j = 0; j < matrix[i].size(); j++){
            if ((matrixforCol[i][j] == matrixforRow[i][j]) && (matrixforCol[i][j].GetExist() != false) && (i != j)) {
                type = matrix[i][j].GetType();
                for (unsigned int m = 0; m < size; m++) {
                    if (ms[m].GetType() == type){
                        for (unsigned int t = 0; t < ms.size(); t++)
                            matrixforCol[m][t].SetExist(false);
                        for (unsigned int t = 0; t < ms.size(); t++)
                            matrixforCol[t][m].SetExist(false);
                    }
                }

            }
        }
    }
    return matrixforCol;
}

int CountType(vector<Animals> mas) {
    vector < int > rt(1);
    unsigned int i, type;
    for (i = 0; i < mas.size(); i++){
        type = mas[i].GetType();
        for (unsigned int j = 0; j < rt.size(); j++)
            if (rt[j] == type)
                break;
            else if (j == rt.size()-1)
                rt.push_back(type);


    }
    return (rt.size()-1);
}

Animals GetforResult(vector<vector<Animals>> matrix, vector<vector<Animals>> matrixforRow, vector<vector<Animals>> matrixforCol, vector<Animals> ms, int size) {
    int type;
    for (unsigned int i = 0; i < size; i++) {
        for (unsigned int j = 0; j < matrix[i].size(); j++)
            if ((matrixforCol[i][j] == matrixforRow[i][j]) && (matrixforCol[i][j].GetExist() != 0)) {
                type = matrix[i][j].GetType();
                return matrix[i][j];
                
            }

        }
}

int Geti(vector<vector<Animals>> matrix, vector<vector<Animals>> matrixforRow, vector<vector<Animals>> matrixforCol, vector<Animals> ms, int size) {
    int type;
    for (unsigned int i = 0; i < size; i++) {
        for (unsigned int j = 0; j < matrix[i].size(); j++)
            if ((matrixforCol[i][j] == matrixforRow[i][j]) && (matrixforCol[i][j].GetExist() != 0)) {
                type = matrix[i][j].GetType();
                return i;

            }

    }
}

int Getj(vector<vector<Animals>> matrix, vector<vector<Animals>> matrixforRow, vector<vector<Animals>> matrixforCol, vector<Animals> ms, int size) {
    int type;
    for (unsigned int i = 0; i < size; i++) {
        for (unsigned int j = 0; j < matrix[i].size(); j++)
            if ((matrixforCol[i][j] == matrixforRow[i][j]) && (matrixforCol[i][j].GetExist() != 0)) {
                type = matrix[i][j].GetType();
                return j;

            }

    }
}


int main() {

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

    if ((k % 4) != 0)
        throw WrongEntr();

    int* arr = new int[k];
    for (int i = 0; i < k; i++)
        arr[i] = array[i];// копирование 
    int l = 0;
    vector<Animals> mas(k/4);
    Animals animals = Animals();
    for (int i = 0; i < k; i ++) {
        Animals animal = Animals(arr[i], arr[i + 1], arr[i + 2], arr[i + 3]);
        mas[l] = animal;
        l++;
        i += 3;
    }

    int amount = CountType(mas);

    vector<vector<Animals>> matrix = DoMatr(mas);
    vector<vector<Animals>> matrixforRow = GetRowMatr(matrix, mas.size());
    vector<vector<Animals>> matrixforCol = GetColMatr(matrix, mas.size());

    vector<string> result(amount);
    vector<vector<Animals>> matrixforRowCopy = matrixforRow;
    vector<vector<Animals>> matrixforColCopy = matrixforCol;
    vector<vector<Animals>> matrixCopy = matrix;
    double res = 0.0;

    for (int i = 0; i < amount; i++) {
        Animals animal = Animals(GetforResult(matrixCopy, matrixforRowCopy, matrixforColCopy, mas, mas.size()));
        int from, to;
        from = Geti(matrixCopy, matrixforRowCopy, matrixforColCopy, mas, mas.size());
        to = Getj(matrixCopy, matrixforRowCopy, matrixforColCopy, mas, mas.size());
        stringstream take;
        string get;
        take << "from " << from << " to " << to << " " << animal << " " ;
        get = take.str();
        result[i] = get;
        res += animal.GetDistance();
        matrix = GetLessMatr(matrixCopy, matrixforRowCopy, matrixforColCopy, mas, mas.size());
        matrixforRow = GetLessMatrRow(matrixCopy, matrixforRowCopy, matrixforColCopy, mas, mas.size());
        matrixforCol = GetLessMatrCol(matrixCopy, matrixforRowCopy, matrixforColCopy, mas, mas.size());
        matrixCopy = matrix;
        matrixforRowCopy = matrixforRow;
        matrixforColCopy = matrixforCol;
    }

    ofstream fout(path_out);
    fout << res << "\n";
    for (unsigned int i = 0; i < amount; i++)
        fout << result[i] << " ";
    fout.close();
    system("pause");
    return 0;
}