#include <gtest/gtest.h>
#include <vector>
#include <cmath>
#include "../matrix_hasher.hpp" // adjust path as needed
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <random>

constexpr float PI = M_PI;
constexpr float GOLDEN_RATIO = 1.618 * 1e5;

double uniform_random_double(double min, double max)
{
    std::random_device rd{};
    std::mt19937 gen{rd()};
    std::uniform_real_distribution<> dis(min, max);
    return dis(gen);
};

bool approxEqual(double a, double b, double eps)
{
    return std::fabs(a - b) <= eps;
};

void reverseVector(std::vector<double> &vec)
{
    std::reverse(vec.begin(), vec.end());
};
std::vector<double> million_random_doubles()
{
    std::vector<double> result(10);
    std::random_device rd{};
    std::mt19937 gen{rd()};
    std::uniform_real_distribution<double> dist{0.0, 1.0};

    for (int i = 0; i < 10; ++i)
    {
        result[i] = dist(gen);
    }
    return result;
}

TEST(MatrixHasherTest, EmptyVectorReturnsZero)
{
    std::vector<double> data{};
    double h = hashVector(data);
    EXPECT_TRUE(approxEqual(h, 0.0));
}

TEST(MatrixHasherTest, SingleElementVectorHashesCorrectly)
{
    std::vector<double> data{1.0};
    double expected = std::fmod(1.0 * M_PI, GOLDEN_RATIO);
    double h = hashVector(data);
    EXPECT_TRUE(approxEqual(h, expected));
}

TEST(MatrixHasherTest, IdenticalVectorsProduceSameHash)
{
    std::vector<double> data1{7.5, 0.25, -1.2, 3.14};
    std::vector<double> data2 = data1;
    double h1 = hashVector(data1);
    double h2 = hashVector(data2);
    EXPECT_TRUE(approxEqual(h1, h2));
}

TEST(MatrixHasherTest, SmallPerturbationChangesHash)
{
    std::vector<double> base{1.0, 2.0, 3.0, 4.0};
    std::vector<double> perturbed = base;
    perturbed[2] += 1e-6;
    double h_base = hashVector(base);
    double h_pert = hashVector(perturbed);
    EXPECT_FALSE(approxEqual(h_base, h_pert));
}

TEST(MatrixHasherTest, HighVolumeRandomDataHashConsistency)
{
    std::vector<double> base = million_random_doubles();
    std::vector<double> perturbed;
    perturbed.reserve(base.size());

    for (size_t i = 0; i < base.size(); ++i)
    {
        double randomizer = uniform_random_double(0, 1);
        if (randomizer > 0.999)
        {
            perturbed.push_back(base[i] + 1e-6);
        }
        else
        {
            perturbed.push_back(base[i]);
        }
    }

    double h_base = hashVector(base);
    double h_pert = hashVector(perturbed);
    EXPECT_FALSE(approxEqual(h_base, h_pert));
}
