// If the caculation is invalid, print like the following:

// "invalid addition.\n"

// "invalid substraction.\n"

// invalid multiplication.\nand return an empty matrix


#include "Matrix.h"

//  by wang wei
// Matrix::Matrix(string n, int h, int w, int**p)
// {
// 	name=n;
// 	width=w;
// 	height=h;
// 	param=new int*[height];
// 	for(int i=0;i<height;i++)
// 	{
// 		param[i]=new int[width];
// 		for(int j=0;j<width;j++)
// 		{
// 			param[i][j]=p[i][j];
// 		}
// 	}
// }

// Matrix::Matrix(const Matrix &a)
// {
// 	name=a.name;
// 	width=a.width;
// 	height=a.height;
// 	param=new int*[height];
// 	for(int i=0;i<height;i++)
// 	{
// 		param[i]=new int[width];
// 		for(int j=0;j<width;j++)
// 		{
// 			param[i][j]=a.param[i][j];
// 		}
// 	}
// }

// Matrix::~Matrix()
// {
// 	for(int i=0;i<height;i++)
// 		delete []param[i];
// 	delete []param;
// }

// bool Matrix::operator ==(const Matrix&a)
// {
// 	for(int i=0;i<height;i++)
// 	{
// 		for(int j=0;j<width;j++)
// 		{
// 			if(param[i][j]!=a.param[i][j])
// 			{
// 				return false;
// 			}
// 		}
// 	}
// 	return true;
// }

// bool Matrix::operator !=(const Matrix&a)
// {
// 	if(this->operator ==(a) )
// 		return false;
// 	else
// 		return true;
// }

// void Matrix::operator +=(const Matrix&a)
// {
// 	if(width!=a.width||height!=a.height)
// 		cout<<"invalid addition."<<endl;
// 	else
// 	{
// 	for(int i=0;i<height;i++)
// 	{
// 		for(int j=0;j<width;j++)
// 		{
// 			param[i][j]+=a.param[i][j];
// 		}
// 	}
// 	}
// }

// void Matrix::operator -=(const Matrix&a)
// {
// 	if(width!=a.width||height!=a.height)
// 		cout<<"invalid substraction."<<endl;
// 	else
// 	{
// 	for(int i=0;i<height;i++)
// 	{
// 		for(int j=0;j<width;j++)
// 		{
// 			param[i][j]-=a.param[i][j];
// 		}
// 	}
// 	}
// }

// Matrix Matrix::operator *(const Matrix&a)
// {
// 	Matrix b;
// 	if(width!=a.height)
// 	{
// 		cout<<"invalid multiplication."<<endl;
// 	}
// 	else
// 	{
// 	b.name="newMat";
// 	b.param=new int*[height];
// 	for(int i=0;i<height;i++)
// 		b.param[i]=new int[width];
// 	for(int i=0;i<height;i++)
// 	{
// 		for(int j=0;j<a.width;j++)
// 		{
// 			b.param[i][j]=0;
// 			for(int k=0;k<width;k++)
// 				b.param[i][j]+=param[i][k]*a.param[k][j];
// 		}
// 	}
// 	}
// 	return b;
// }

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
			param[i][j] = t.param[i][j];
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
void Matrix::operator -=(const Matrix& t)
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
	int t_height = height;
	int t_width = t.width;
	int ** p = new int *[height];
	for (int i = 0; i < t_height; i++){
		p[i] = new int [t_width];
	}

	for (int i = 0; i < t_height; i++){
		for (int j = 0; j < t_width; j++){
			int sum = 0;
			for (int ii = 0; ii < this->width; ii++)
				sum += this->param[i][ii] * t.param[ii][j];
			p[i][j] = sum;
		}
	}
	Matrix ans = Matrix("newMat", t_height, t_width, p);

	for (int i = 0; i < t_height; i++)
		delete [] p[i];
	delete [] p;

	return ans;
}