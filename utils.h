/* 
 * File:   utils.h
 * Author: Bas
 *
 * Created on 17 januari 2014, 14:14
 */


#ifndef UTILS_H
#define	UTILS_H
using namespace std;
#include <vector>
#include <list>

int maxIndex(vector<int> v);

int maxOccurences(list<int> v);

int indexOf(int value, vector<int> list);

vector<float> takeSample(vector<float> v);

void cmndf(float *array, int length);
float average(float *array, int begin, int end);
void normalize(float* array, int length);
float sum(float* array, int length);

#endif	/* UTILS_H */

