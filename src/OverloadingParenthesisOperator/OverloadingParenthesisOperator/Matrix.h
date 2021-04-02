#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
private:
	int m_matrix[25];

public:
	Matrix();
	
	int& operator() (int row, int col);
	void operator() ();
	const int operator() (int row, int col) const;
};

#endif