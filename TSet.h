#pragma once
#include "TBitField.h"
class TSet
{
private:
	int USize;
	TBitField tb;

	
	void StringToWords(string str, string seps, int& k, string* w) {
		k = 0;
		w[0] = "";
		str += " ";

		for (int i = 0; i < str.length(); i++) {
			
			if (seps.find(str[i]) == -1) {
				w[k] += str[i];
			}
			else {
				if (w[k].length() > 0) {
					w[++k] = "";
				}
			}
		}
	}

	

public:
	TSet(int USize = 0, string str = "") {
		this->USize = USize;
		tb = TBitField(USize);
		string* w;
		w = new string[str.length() + 2];
		int k;

		StringToWords(str, ", ", k, w);
		for (int i = 0; i < k; i++) {
			int n = stoi(w[i]);
			if (n >= 1 && n <= USize) {
				tb.Add(n);
			}
		}
	}

	TSet(const TSet& tmp) {
		USize = tmp.USize;
		tb = tmp.tb;
	}

	TSet& operator=(const TSet& tmp) {
		if (USize != tmp.USize) {
			USize = tmp.USize;
		}
		tb = tmp.tb;
		return *this;
	}

	~TSet() {
	}

	
	void Add(int k) {
		if (k >= 0 && k <= USize) {
			tb.Add(k);
		}
	}

	string TSetToString(string sep = ",") {
		return tb.TString(USize, sep);
	}

	TSet operatorV(const TSet& tmp) {
		if (tmp.USize != USize) {
			throw "USize should be equal";
		}

		TSet res(USize);
		res.tb = tb.operatorV(tmp.tb);
		return res;
	}

	TSet operatorv(const TSet& tmp) {
		if (tmp.USize != USize) {
			throw "USize should be equal";
		}

		TSet res(USize);
		res.tb = tb.operatorv(tmp.tb);
		return res;
	}

	TSet operator~() {
		TSet res(USize);
		res.tb = tb.operator~();
		return res;
	}
};

