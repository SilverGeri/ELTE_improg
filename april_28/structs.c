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

void print_matrix(const Matrix* const m) {
	printf("\n\n");
	for (int i = 0; i < m->row; ++i) {
		for (int j = 0; j < m->column; ++j) {
			printf("%d ", m->data[i * m->column + j]);
		}
		printf("\n");
	}
}

int main() {
	Matrix m = create_matrix(4, 5);

	print_matrix(&m);

	int *topLeft = access_item(&m, 0, 0);
	
	*topLeft = 5;
	print_matrix(&m);

	*topLeft = 3;
	print_matrix(&m);

	free(m.data);

	return 0;
}
