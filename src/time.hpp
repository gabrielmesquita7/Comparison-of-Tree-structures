#ifndef TIME_HPP
#define TIME_HPP

#include <chrono>
#include "tools.hpp"

extern double binaryTime;
extern double AvlTime;
extern double RBTime;
extern double VectorTime;
extern double MapTime;
extern double UnorderedMapTime;

void resetTimes();
void measure_timeInsert(int qtd);
void measure_timeSearch();
void measure_timeRemove();
void measure_time();

#endif