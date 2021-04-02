#ifndef POINT2D_H
#define POINT2D_H

class Point2D
{
private:
	int m_x{};
	int m_y{};
public:
	Point2D(int, int);
	void set_point(int, int);
	int get_x_coord() const;
	int get_y_coord() const;
};

#endif
