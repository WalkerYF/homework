#include "array.hpp"
#include <algorithm>


array::array(size_t size)
{
	_size = size;
	_data = new data_type[_size];
}
  // destructor
array::~array()
{
	delete [] _data;
	_data = nullptr;
	_size = 0;
}
  // Capacity
  // Return maximum size
array::size_t array::max_size(void)
{
	return _size;
}
 
  // Element access
  // Access element
  // int& operator[](const int &i) {return data[i];}
  // Access element
array::data_type& array::at(const data_type& i)
{
	return this->_data[i];

}
  // Access first element
array::data_type& array::front()
{
	return this->_data[0];
  // Access last element
}
array::data_type& array::back(){
	return this->_data[_size-1];
}

  // Get pointer to data
array::pointer array::data()
{
	return _data;
}
 
  // Modifiers
  // Fill array with the same value
void array::fill(const data_type& value){
	for  (int i = 0; i < _size; i++){
		_data[i] = value;
	}
	return ;
}


  // Resize the array (newSize > oldSize)
void array::resize(int newSize){
	pointer new_data = new data_type[newSize+1];
	data_type old_size = _size;
	for (int i = 0; i < old_size; i++){
		new_data[i] = _data[i];
	}

	delete [] _data;
	_data = new_data;
	_size = newSize;
	return ;
}


  // Sort the array in the section [from, to)
void array::sort(int from, int to)
{
	std::sort(_data+from, _data+to);
	return ;
}