#include <stdlib.h>
#include <stdio.h>

struct Matrix {
	int row;
	int column;
	int *data;
};

typedef struct Matrix Matrix;

struct Matrix2 {
	int row;
	int column;
	int **data; // row number of pointers, each points to column length integer array, separated in memory
};

Matrix create_matrix(int row, int col) {
	Matrix m;
	m.row = row;
	m.column = col;
	m.data = (int*)malloc(row * col * sizeof(int));

	for (int i = 0; i < row * col; ++i) {
		m.data[i] = 0;
	}

	return m;
}

int* access_item(Matrix* m, int row, int col) {
	// check if row and col are not too high or small
	
	int index = row * m->column + col;
	return &m->data[index];
}

int get_item(const Matrix* const m, int row, int col) {
	// check if row and col are not too high or small
	
	int index = row * m->column + col;
	return m->data[index];
}

void print_matrix(const Matrix* const m) {
	printf("\n\n");
	for (int i = 0; i < m->row; ++i) {
		for (int j = 0; j < m->column; ++j) {
			printf("%d ", m->data[i * m->column + j]);
		}
		printf("\n");
	}
}

Matrix matrix_multiply(const Matrix* const lhs, const Matrix* rhs, int* error) {
	Matrix result = create_matrix(lhs->row, rhs->column);
	
	if (lhs->column != rhs->row) {
		*error = 1;
		return result; // it's filled with zeros
	} else {
		*error = 0;
	}
	
	for (int i = 0; i < lhs->row; ++i) {
		for (int j = 0; j < rhs->column; ++j) {
			for (int k = 0; k < lhs->column; ++k) {
				*access_item(&result, i, j) += get_item(lhs, i, k) * get_item(rhs, k, j);
			}
		}
	}

	return result;
}

int main() {
	Matrix m = create_matrix(4, 5);
	Matrix m2 = create_matrix(5, 3);

	print_matrix(&m);

	int *topLeft = access_item(&m, 0, 0);
	
	*topLeft = 5;
	print_matrix(&m);

	*topLeft = 3;
	print_matrix(&m);

	*access_item(&m2, 0, 1) = 4;

	int error;
	Matrix result = matrix_multiply(&m, &m2, &error);

	print_matrix(&result);

	free(m.data);
	free(m2.data);
	free(result.data);

	return 0;
}
