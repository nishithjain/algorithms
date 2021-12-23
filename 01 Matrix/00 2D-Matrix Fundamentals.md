# 2D Matrix Fundamentals

## Allocating Memory

>### 1. Allocating memory using 'new'

        int rows, cols; 
        cin >> rows >> cols;
        int** myArray = new int*[rows];
        for (auto i = 0; i < rows; i++)
        {
            myArray[i] = new int[cols];
        }


>### 2. Using 'vector'

>>#### Solution 1:

            #include <vector>
            using namespace std;
            int rows, cols; cin >> rows >> cols;
            vector<vector<int>> myArray(rows, vector<int>(cols));


>>#### Solution 2:

            #include <vector>
            using namespace std;
            int rows, cols; cin >> rows >> cols;
            using matrix = vector<vector<int>>;
            matrix myArray(rows, vector<int>(cols));

## Deleting memory which was allocated using 'new'

        for (auto i = 0; i < rows; i++)
        {
            delete [] myArray[i];
        }
        delete[] myArray;

## Filling 2D Matrix

        #include <iostream>
        #include <vector>
        using namespace std;
        void fill2DMatrix(vector<vector<int>>& matrix)
        {
            int ele, rows = matrix.size(), cols = matrix[0].size();
            
            for (auto i = 0; i < rows; i++)
            {
                for (auto j = 0; j < cols; j++)
                {
                    cin >> ele;
                    matrix[i][j] = ele;
                }
            }
        }


## Displaying 2D Matrix

        #include <iostream>
        #include <iomanip>
        #include <vector>
        using namespace std;

        void display2DMatrix(vector<vector<int>>& matrix)
        {
            for (auto i : matrix)
            {
                for (auto j : i)
                {
                    cout << setw(2) << j << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
