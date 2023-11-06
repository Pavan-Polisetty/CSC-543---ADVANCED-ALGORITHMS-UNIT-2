#include <iostream>
#include <vector>

class SparseMatrix {
private:
    int n_R;  // Number of rows
    int n_C;  // Number of columns
    std::vector<std::vector<int>> matrix;  // A 2D vector to store the sparse matrix

public:
    SparseMatrix(int rows, int cols) : n_R(rows), n_C(cols) {
        // Initialize the 2D vector with all elements set to 0
        matrix = std::vector<std::vector<int>>(n_R, std::vector<int>(n_C, 0));
    }

    // Insert a non-zero element into the sparse matrix
    void insert(int r, int c, int v) {
        if (r >= 0 && r < n_R && c >= 0 && c < n_C) {
            matrix[r][c] = v;
        }
    }

    // Print the sparse matrix
    void print() {
        for (int i = 0; i < n_R; i++) {
            for (int j = 0; j < n_C; j++) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int n_R;  // Number of rows
    int n_C;  // Number of columns
    std::cout << "Enter the number of rows: ";
    std::cin >> n_R;
    std::cout << "Enter the number of columns: ";
    std::cin >> n_C;

    SparseMatrix sparseMatrix(n_R, n_C);

    std::cout << "Enter non-zero elements (row, column, value) - Enter -1 to stop:" << std::endl;
    int r;  // Row
    int c;  // Column
    int v;  // Value
    while (true) {
        std::cin >> r;
        if (r == -1) break;
        std::cin >> c >> v;
        sparseMatrix.insert(r, c, v);
    }

    std::cout << "Sparse Matrix:" << std::endl;
    sparseMatrix.print();

    return 0;
}
