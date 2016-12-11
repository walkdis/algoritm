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
            if ((matrixforCol[i][j] == matrixforRow[i][j]) && (matrixforCol[i][j].GetExist() != 0)) {
                type = matrix[i][j].GetType();
                for (unsigned int m = size - 1; m != 0; m--) {
                    if (ms[m].GetType() == type)
                        for (unsigned int t = 0; t < ms.size(); t++) {
                            if (m == j)
                                m--;
                            matrix[m][t].SetExist(0);
                        }
                    for (unsigned int t = 0; t < ms.size(); t++) {
                        matrix[t][m].SetExist(0);
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
            if ((matrixforCol[i][j] == matrixforRow[i][j]) && (matrixforCol[i][j].GetExist() != 0)) {
                type = matrix[i][j].GetType();
                for (unsigned int m = size - 1; m != 0; m--) {
                    if (ms[m].GetType() == type)
                        for (unsigned int t = 0; t < ms.size(); t++) {
                            if (m == j)
                                m--;
                            matrixforRow[m][t].SetExist(0);
                        }
                    for (unsigned int t = 0; t < ms.size(); t++) {
                        matrixforRow[t][m].SetExist(0);
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
            if ((matrixforCol[i][j] == matrixforRow[i][j]) && (matrixforCol[i][j].GetExist() != 0)) {
                type = matrix[i][j].GetType();
                for (unsigned int m = size - 1; m != 0; m--) {
                    if (ms[m].GetType() == type)
                        for (unsigned int t = 0; t < ms.size(); t++) 
                            matrixforCol[m][t].SetExist(0);                       
                    for (unsigned int t = 0; t < ms.size(); t++) 
                        matrixforCol[t][m].SetExist(0);                    
                }
            }

        }
    }
    return matrix;
}

int CountType(vector<Animals> mas) {
    vector < int > rt;
    unsigned int i, type;
    for (i = 0; i < mas.size(); i++){
        type = mas[i].GetType();
        for (unsigned int j = 0; j < rt.size() + 1; j++)
            if (rt[j] == type)
                break;
            else if (rt[j] != type)
                j++;
            else if (j == rt.size())
                rt.push_back(type);
    }
    return rt.size();
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


int main() {

    cout << "enter path to file \n";
    string s, file_str, str; // считать сюда документ
    cin >> s;
    std::ifstream xfile(s, std::ios::binary);
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

    
        /*(mas.size());
    for (unsigned int i = 0; i < mas.size(); i++)
        matrixforRow[i].resize(mas.size());
    for (unsigned int i = 0; i < mas.size(); i++)
        for (unsigned j = 0; j < mas.size(); j++)
            matrixforRow[i][j].SetExist(0);
            */
  
    vector<vector<Animals>> matrix = DoMatr(mas);
    vector<vector<Animals>> matrixforRow = GetRowMatr(matrix, mas.size());
    vector<vector<Animals>> matrixforCol = GetColMatr(matrix, mas.size());
    /*
    for (unsigned int i = 0; i < mas.size(); i++) {
        double min = GetMinRow(matrix, i);
        for (unsigned int j = 0; j < mas.size(); j++) {
            if (min == matrix[i][j].GetDistance())
                matrixforRow[i][j] = matrix[i][j];
        }
    }
    for (unsigned int i = 0; i < mas.size(); i++) {
        double min = GetMinCol(matrix, i);
        for (unsigned int j = 0; j < mas.size(); j++) {
            if (min == matrix[j][i].GetDistance())
                matrixforCol[j][i] = matrix[j][i];
        }
    }
    */
    vector<Animals> result(mas.size());
    vector<vector<Animals>> matrixforRowCopy = matrixforRow;
    vector<vector<Animals>> matrixforColCopy = matrixforCol;
    vector<vector<Animals>> matrixCopy = matrix;

    /*
    for (unsigned int i = 0; i < ms.size(); i++) {
        for (unsigned int j = 0; j < matrixCopy[i].size(); j++){
            if ((matrixforColCopy[i][j] == matrixforRowCopy[i][j]) && (matrixforColCopy[i][j].GetExist() != 0)) {
                type = matrixCopy[i][j].GetType();
                result[i] = matrixCopy[i][j];
                for (unsigned int m = ms.size() - 1; m != 0; m--) {
                    if (ms[m].GetType() == type)
                        for (unsigned int t = 0; t < ms.size(); t++) {
                            if (m == j)
                            m--;
                            matrixCopy[m][t].SetExist(0);
                            matrixforRowCopy[m][t].SetExist(0);
                            matrixforColCopy[m][t].SetExist(0);
                        }
                    for (unsigned int t = 0; t < ms.size(); t++) {
                        matrixCopy[t][m].SetExist(0);
                        matrixforRowCopy[t][m].SetExist(0);
                        matrixforColCopy[t][m].SetExist(0);
                    }
                }
            }
                    
        }
    }
    */

    for (unsigned int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    system("pause");
    return 0;
}