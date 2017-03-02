#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

using namespace std;

const int length = 11;
vector<int> v(length);

ostream& operator<< (ostream& out, vector<int>& _vec)
{
	vector<int>::const_iterator it = _vec.begin();
	for (; it != _vec.end(); ++it)
		out << *it << "\t";
	return out;
}

void initVector(vector<int> &v, bool doDisplay = true)
{
	vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
	{
		*it = rand()%100;
	}
	if (doDisplay)
	{
		cout << v << endl;
	}
}

void mergeSort(vector<int> src, vector<int> &dst)
{
	int lengthSrc = src.size();

	if (lengthSrc <= 1)
	{
		dst = src;
	}
	else
	{
		int divivePos = lengthSrc / 2;

		vector<int> low(src.begin(), src.begin() + divivePos);
		vector<int> high(src.begin() + divivePos, src.end());

		mergeSort(low, low);
		mergeSort(high, high);

		dst.clear();
		dst.reserve(lengthSrc);
		int posLow = 0;
		int posHigh = 0;
		for (int i = 0; i < lengthSrc; i++) {

			if (low[posLow] < high[posHigh])
			{
				dst.push_back(low[posLow]);
				posLow++;
			}
			else
			{
				dst.push_back(high[posHigh]);
				posHigh++;
			}

			if (posLow >= low.size())
			{
				for (; posHigh< high.size(); posHigh++)
				{
					dst.push_back(high[posHigh]);
				}
				break;
			}
			else if (posHigh >= high.size())
			{
				for (; posLow < low.size(); posLow++)
				{
					dst.push_back(low[posLow]);
				}
				break;
			}
		}

	}
}

int main() 
{
	cout << "原始数组：\n";
	initVector(v);
	mergeSort(v,v);
	cout << v << endl;

	return 0;
}