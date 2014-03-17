/* 
 * File:   HistogramBuffer.cpp
 * Author: Bas
 * 
 * Created on 20 februari 2014, 16:34
 */

#include "HistogramBuffer.h"
#include <deque>
#include <map>

using namespace std;

HistogramBuffer::HistogramBuffer() {
    maxSize = 30;
}

HistogramBuffer::HistogramBuffer(int i) {
    maxSize = i;
}

HistogramBuffer::HistogramBuffer(const HistogramBuffer& orig) {
}

HistogramBuffer::~HistogramBuffer() {
}

void HistogramBuffer::put(int i) {
    buffer.push_back(i);
    if (buffer.size() > maxSize)
        buffer.pop_front();
}

int HistogramBuffer::get() {
    // make histogram
    map<int, int> bufferMap;
    for (int i = 0; i < buffer.size(); i++) {
        if (bufferMap.count(buffer[i]) > 0)
            bufferMap[buffer[i]] += 1;
        else
            bufferMap[buffer[i]] = 1;
    }

    // find maximum in histogram
    int maxVal = 0;
    int maxI = 0;
    for (map<int, int>::iterator it = bufferMap.begin(); it != bufferMap.end(); it++) {
        if (it->second > maxVal) {
            maxVal = it->second;
            maxI = it->first;
        }
    }
    return maxI;
}

void HistogramBuffer::drop(){
    if(buffer.size() > 0)
        buffer.pop_front();
}

void HistogramBuffer::clear() {
    buffer.clear();
}

void HistogramBuffer::setMaxSize(int i) {
    maxSize = i;
}

int HistogramBuffer::getMaxSize() {
    return maxSize;
}