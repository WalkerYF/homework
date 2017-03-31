// If the caculation is invalid, print like the following:

"invalid addition.\n"

"invalid substraction.\n"

invalid multiplication.\nand return an empty matrix


#include "Matrix.h"



Matrix::Matrix(string name, int height, int width, int** p)
{
	this->name = name;
	this->height = height;
	this->width = width;
	param = new int * [height];
	for (int i = 0; i < height; i++){
		param[i] = new int [width];
		for (int j = 0; j < width; j++)
			param[i][j] = p[i][j];
	}
}
Matrix::Matrix(const Matrix & t)
{
	this->name = t.name;
	this->height = t.height;
	this->width = t.width;
	param = new int * [height];
	for (int i = 0; i < height; i++){
		param[i] = new int [width];
		for (int j = 0; j < width; j++)
			param[i][j] = t.p[i][j];
	}

}
Matrix::~Matrix()
{
	for (int i = 0; i < height; i++)
		delete [] this->param[i];
	delete [] this->param;
}
bool Matrix::operator ==(const Matrix& t)
{
	if (height != t.height || width != t.height)
		return false;

	int flag = 1;
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++){
			if (param[i][j] != t.param[i][j]){
				flag = 0;
				break;
			}
		}
	if (flag == 1)
		return true;
	else
		return false;

}
bool Matrix::operator !=(const Matrix& t)
{
	if (*this == t)
		return false;
	else
		return true;
}
void Matrix::operator +=(const Matrix& t)
{
	if (height != t.height || width != t.height){
		cout << "invalid addition.\n";
		return ;
	}
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++){
			this->param[i][j] += t.param[i][j];
		}
	return ;
}
void Matrix::operator -=(const Matrix&)
{
	if (height != t.height || width != t.height){
		cout << "invalid substraction.\n";
		return ;
	}
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++){
			this->param[i][j] -= t.param[i][j];
		}
	return ;
}
Matrix Matrix::operator *(const Matrix& t)
{
	if (width != t.height){
		cout << "invalid multiplication.\n";
		return Matrix();
	}
	


}