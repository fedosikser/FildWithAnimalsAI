#pragma once

#include <iostream>
using namespace std;

class Matrix {
    public:
    int height;
    int width;
    int scaler;
    char** matrix;

    void SetScaler(int scaler=1) {
        this->scaler = scaler;
    }

    char** createEmptyMatrix() {
        char** matrix = new char*[height];
        for (int i = 0; i < height; i++) {
            matrix[i] = new char[width];
            for (int j = 0; j < width; j++) {
                matrix[i][j] = ' ';
            }
        }
        return matrix;
    }

    void FillMartixBorder() {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (i == 0 || i == height-1 || j == 0 || j == width-1) {
                    matrix[i][j] = '*';
                }
            }
        }
    }

    void printMatrix() {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cout << matrix[i][j];
            }
            cout << endl;
        }
    }

    void SetSize(int height, int width) {
        this->height = height;
        this->width = width;
    }
    Matrix(int height, int width) {
        this->height = height;
        this->width = width;
        this->matrix=createEmptyMatrix();
        FillMartixBorder();
    }
    ~Matrix() {
        for (int i = 0; i < height; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
};
