class Point{

protected:
double _x,_y;
public:
Point():_x(0),_y(0){}
Point(double x,double y):_x(x),_y(y){}
Point(Point& pt):Point(pt._x, pt._y){}
double getx()
{
	return _x;
}
double gety()
{
	return _y;
}

};





class Rectangle : public Point{
private:
	double _len, _wei;
public:
	Rectangle():Point(),_len(0),_wei(0) {}
	Rectangle(double x, double y, double len, double wei):
		Point(x,y), _len(len), _wei(wei) {}
	Rectangle(Rectangle & r):Rectangle(r.getx(), r.gety(), r._len, r._wei) {}

	int position(Point & pt);

};


int Rectangle::position(Point & pt)
{
	if (_x < pt.getx() && pt.getx() < _x + _len 
		&& _y < pt.gety() && pt.gety() < _y + _wei)
		return -1;

	if (_x <= pt.getx() &&  pt.getx() <= _x + _len && 
		(pt.gety() == _y || pt.gety() == _y + _wei))
		return 0;

	if (_y <= pt.gety() && pt.gety() <= _y + _wei && 
		(pt.getx() == _x || pt.getx() == _x + _len))
		return 0;

	return 1;
}

class Circle : public Point{
private:
	double _radius;
public:
	Circle():Point(),_radius(0) {}
	Circle(double x, double y, double radius):
		Point(x,y), _radius(radius) {}
	Circle(Circle & c):Circle(c.getx(), c.gety(), c._radius) {}

	int position(Point & pt);

};

int Circle::position(Point & pt)
{
	double dist_square = (pt.getx() - _x)*(pt.getx() - _x) + (pt.gety() - _y)*(pt.gety() - _y);
	if (dist_square < _radius * _radius)
		return -1;
	if (dist_square == _radius * _radius)
		return 0;
	return 1;
}