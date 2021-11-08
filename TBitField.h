#pragma once
#include <iostream>
#include <string>
typedef unsigned int uint32;
using namespace std;
class TBitField
{private:
	unsigned int* mem;
	int size;

public:
	TBitField(int n = 10) {
		size = n / ((8 * sizeof(*mem))) + 1;
		mem = new uint32[size];
		for (int i = 0; i < size; i++) {
			mem[i] = 0;
		}
	}
	~TBitField() {
		delete[] mem;
	}
	TBitField(const TBitField &tmp) {
		size = tmp.size;
		mem = new uint32[size];
		for (int i = 0; i < size; i++) {
			mem[i] = tmp.mem[i];
		}
	}
	TBitField &operator=(const TBitField &tmp) {
		if (size != tmp.size) {
			delete[] mem;
			size = tmp.size;
			mem = new uint32[size];
		}
		for (int i = 0; i < size; i++) {
				mem[i] = tmp.mem[i];

		}
		
	   return *this;
	}
	int GetBit(int k) {
		return ((k - 1) % (8 * sizeof(*mem)));
		
	}
	int GetNumberMem(int n) {
		return((n -1)/ (8 * sizeof(*mem)));
	}
	void Add(int n) {
		int i = GetNumberMem(n);
		mem[i] = mem[i] | (1 << GetBit(n));
	}
	string TString(int um, string sep =",") {
		string str;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < 8 * sizeof(*mem); j++) {
				if ((mem[i] & (1 << j)) > 0) {
					int k = i * (8 * sizeof(*mem)) + j + 1;
					if (k <= um) {
						str += (to_string(k) + sep);
					}
				}
			}
		}
		if (str.size() >= 2) {
			str = str.substr(0, str.size() - sep.length());
		}
		return str;
	}
	TBitField operatorV(const TBitField &tmp) {
		TBitField res((8*sizeof(*mem))*(size-1));
		for (int i = 0; i < size; i++) {
			res.mem[i] =mem[i] | tmp.mem[i];
		}
		return res;
	}
	TBitField operatorv(const TBitField &tmp) {
		TBitField res((8 * sizeof(*mem)) * (size - 1));
		for (int i = 0; i < size; i++) {
			res.mem[i] = mem[i] & tmp.mem[i];
		}
		return res;
	}
	TBitField operator~() {
		TBitField res((8 * sizeof(*mem)) * (size - 1));
		for (int i = 0; i < size; i++) {
			res.mem[i] = ~mem[i];
		}
		return res;
	}
	//void Del_elem(int k) {
	//	int i=GetNumberMem(k);
	//	mem[i] = mem[i] & (~(1 << GetBit(k)));
	//}
};