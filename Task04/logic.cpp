// Сумма элементов столбцов с экстремальными элементами
// [The Sum of elements of columns with extreme elements]
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо разработать функцию (или программу), которая 
// высчитывает сумму элементов в тех столбцах заданной матрицы,
// которые содержат хотя бы один экстремальный элемент.

#include "logic.h"

int get_extreme_value(int** matrix, int n, int m, bool type) {
	int extreme = matrix[0][0];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (type ? matrix[i][j] > extreme: matrix[i][j] < extreme) {
				extreme = matrix[i][j];
			}
		}
	}
	return extreme;
}

bool is_extreme_value(int** matrix, int n, int column, int min, int max) {
	for (int i = 0; i < n; i++)
	{
		if (matrix[i][column] == min || matrix[i][column] == max) {
			return true;
		}
	}
	return false;
}

int sum_elements_of_columns_with_extreme_value(int** matrix, int n, int m) {
	if (matrix == nullptr || n <= 0 || m <= 0) {
		return 0;
	}
	int max = get_extreme_value(matrix, n, m, true);
	int min = get_extreme_value(matrix, n, m, false);

	int sum = 0;

	for (int j = 0; j < m; j++)
	{
		if (is_extreme_value(matrix,n,j,min,max)) {
			for (int i = 0; i < n; i++)
			{
				sum += matrix[i][j];
			}
		}
	}

	return sum;
}