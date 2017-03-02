#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <opencv2/opencv.hpp>

using namespace std;

ostream& operator<< (ostream& out, vector<long>& _vec)
{
	vector<long>::const_iterator it = _vec.begin();
	for (; it != _vec.end(); ++it)
		out << *it << "\t";
	return out;
}

ostream& operator<< (ostream& out, vector<double>& _vec)
{
	vector<double>::const_iterator it = _vec.begin();
	for (; it != _vec.end(); ++it)
		out << setprecision(3) << fixed << *it << endl;
	return out;
}

void initVector(vector<long> &v, bool doDisplay = true)
{
	vector<long>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
	{
		*it = rand();
	}
	if (doDisplay)
	{
		cout << v << endl;
	}
}

void mergeSort(vector<long> src, vector<long> &dst)
{
	long lengthSrc = src.size();

	if (lengthSrc <= 1)
	{
		dst = src;
	}
	else
	{
		long divivePos = lengthSrc / 2;

		vector<long> low(src.begin(), src.begin() + divivePos);
		vector<long> high(src.begin() + divivePos, src.end());

		mergeSort(low, low);
		mergeSort(high, high);

		dst.clear();
		dst.reserve(lengthSrc);
		long posLow = 0;
		long posHigh = 0;
		for (long i = 0; i < lengthSrc; i++) {

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


clock_t  ticTime;
void tic() {
	ticTime = clock();
}
double toc() {
	clock_t tocTime = clock();
	return (double)(tocTime - ticTime) / CLOCKS_PER_SEC;
}

template<typename T> void showProgress(T i, T total, long times = 100) {
	if (times > total)times = total;
	if ((i + 1) % (total / times) == 0) {
		cout << "\r"<<fixed<<setprecision(2) << (double)(i + 1) * 100 / total << "%";
	}
}

long main() 
{
	//const long length = 11;
	//vector<long> v(length);
	//cout << "原始数组：\n";
	//initVector(v);
	//mergeSort(v,v);
	//cout << v << endl;

	long num = 30;
	vector<double> y;
	y.reserve(num);
	for (long i = 1; i <= num; i++)
	{
		double timeUsed;
		vector<long> v(i * 100000);
		initVector(v, false);
		tic();
		mergeSort(v, v);
		timeUsed = toc();
		y.push_back(timeUsed);
		showProgress(i, num);
	}
	cout << endl << y << endl;

	return 0;
}