#include <cassert>
#include "Matrix.h"

Matrix::Matrix()
{
	/*
		Initialize with default values
	*/
	for (int i = 0; i < 25; i++)
	{
		m_matrix[i] = i + 1;
	}
}

int& Matrix::operator()(int row, int col)
{
	// Assert if rows and columns are in bounds
	assert(row >= 0 && row < 5);
	assert(col >= 0 && col < 5);

	return m_matrix[(row * 5) + col];
}

/*
	Resetting the matrix
*/
void Matrix::operator()()
{
	for (int i = 0; i < 25; i++)
	{
		m_matrix[i] = 0;
	}
}

const int Matrix::operator()(int row, int col) const
{
	// Assert if rows and columns are in bounds
	assert(row >= 0 && row < 5);
	assert(col >= 0 && col < 5);

	return m_matrix[(row * 5) + col];
}
