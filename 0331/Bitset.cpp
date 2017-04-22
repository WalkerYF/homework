#include "Bitset.h"
#include <cstring>
#define N 5
bitset::bitset()
{
	std::memset(a, 0, sizeof(a));
}

void bitset::set(int pos)
{
	int n = pos / 32;
	int r = pos % 32;
	a[n] |= (1 << (r));
}

void bitset::reset(int pos)
{
	int n = pos / 32;
	int r = pos % 32;
	a[n] &= ~(1 << (r));
}

int bitset::count() const
{
	int k = 0;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < 32; j++){
			if ((a[i] >> j) & 1)
				k++;
		}
	}
	return k;
}

bool bitset::test(int pos) const
{
	return (a[pos/32] >> (pos % 32 )) & 1;
}
bool bitset::any() const
{
	for (int i = 0; i < N ; i++){
		if ((a[i] | 0 ) != 0)
			return true;
	}

	return false; 

}
bool bitset::none() const
{
	return !any();
}

bool bitset::all() const
{
	if (count() == 5 * N)
		return true;
	return false;
}
bitset& bitset::operator&= (const bitset& b)
{
	for (int i = 0; i < N; i++){
		a[i] &= b.a[i];
	}
	return *this;
}
bitset& bitset::operator|= (const bitset& b)
{
	for (int i = 0; i < N; i++){
		a[i] |= b.a[i];
	}
	return *this;
}
bitset& bitset::operator^= (const bitset& b)
{
	for (int i = 0; i < N; i++){
		a[i] ^= b.a[i];
	}
	return *this;
}
bitset& bitset::operator= (const bitset& b)
{
	for (int i = 0; i < N; i++){
		a[i] = b.a[i];
	}
	return *this;
}
bitset& bitset::operator <<= (int pos)
{
	for (int i = 32 * N-1; i >= 0; i--){
			if (i - pos < 0){
				reset(i);
				continue;
			}
			if (test(i-pos)){
				set(i);
			}
			else
				reset(i);
	}
	return *this;
}
bitset& bitset::operator >>= (int pos)
{
	for (int i = 0; i < 32 * N; i++){
			if (i + pos > 32*N-1){
				set(i);
				continue;
			}
			if (test(i+pos))
				set(i);
			else
				reset(i);
	}
	return *this;
}
bitset bitset::operator~() const
{
	bitset t;
	for (int i = 0; i < N; i++){
		t.a[i] = ~a[i];
	}
	return t;
}
bitset bitset::operator&(const bitset& b) const
{
	bitset t;
	for (int i = 0; i < N; i++){
		t.a[i] =a[i] & b.a[i];
	}
	return t;
}
bitset bitset::operator|(const bitset& b) const
{
	bitset t;
	for (int i = 0; i < N; i++){
		t.a[i] =a[i] | b.a[i];
	}
	return t;
}
bitset bitset::operator^(const bitset& b) const
{
	bitset t = *this;
	t ^= b;
	return t;
}
bitset bitset::operator<<(int pos) const
{
	bitset t = *this;
	t <<= pos;
	return t;
}
bitset bitset::operator>>(int pos) const
{
	bitset t = *this;
	t >>= pos;
	return t;
}
bool bitset::operator== (const bitset& b) const
{	
	for (int i = 0; i < N; i++){
		if (a[i] != b.a[i]){
			return false;
		}
	}
	return true;	
}
bool bitset::operator!= (const bitset& b) const
{
	return !(*this == b);
}
bool bitset::operator[] (int pos) const
{
	return test(pos);
}