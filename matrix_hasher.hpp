#pragma once
#include <vector>

double hashVector(const std::vector<double> &flatBuffer);
bool approxEqual(double a, double b, double eps = 1e-3);