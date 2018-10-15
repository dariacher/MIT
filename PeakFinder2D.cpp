//
// Created by user on 02.10.2018.
//
#include <iostream>

using namespace std;

int FindGlobalMax(int **matrix, int column, int count_rows) {
    int index = 0;
    int max = 0;
    for (int i = 0; i < count_rows; i++) {
        if (max < matrix[i][column]) {
            max = matrix[i][column];
            index = i;
        }
    }
    return index;
}

int FindPeak(int **matrix, int n, int m, int left = 0, int right = -1) {

    if (m < 0)
        return 0;


    if (right == -1) {
        right = m - 1;
    }

    int mid = (left + right) / 2;
    int globalMax = FindGlobalMax(matrix, mid, n);

    if (
            (globalMax > 1 && matrix[globalMax][mid] >= matrix[globalMax - 1][mid]) &&
            (globalMax + 1 < n && matrix[globalMax][mid] >= matrix[globalMax + 1][mid]) &&
            (mid - 1 > 0 && matrix[globalMax][mid] >= matrix[globalMax][mid - 1]) &&
            (mid + 1 < m && matrix[globalMax][mid] >= matrix[globalMax][mid + 1])
            ) {
        return matrix[globalMax][mid];
    }

    else if (mid > 0 && matrix[globalMax][mid - 1] > matrix[globalMax][mid]) {
        right = mid;
        return FindPeak(matrix, n, mid + 1, left, right);
    }

    else if (mid + 1 < m && matrix[globalMax][mid + 1] > matrix[globalMax][mid]) {
        left = mid;
        return FindPeak(matrix, n, m , left, right);
    }
    return matrix[globalMax][mid];
}

int main()
{
    cout << "Hello";
    int matrix[4][4]= {
            {0,2,0,0},
            {0,3,0,0},
            {0,5,0,0},
            {0,4,7,0}
    };
    int peak = FindPeak(matrix, 4, 4);
    cout << "Peak is: " << peak;
    return 0;
}
