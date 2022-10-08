#ifndef TIME_HPP
#define TIME_HPP

#include <chrono>
#include "tools.hpp"

extern double binaryTime;
extern double AvlTime;
extern double RBTime;

void resetTimes();
void measure_timeInsert(int qtd);
void measure_timeSearch();
void measure_timeRemove();

#endif