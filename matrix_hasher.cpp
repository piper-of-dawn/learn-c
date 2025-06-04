
#include <cmath>
#include <iostream>
#include <vector>
#include <cassert>

constexpr float PI = M_PI;
constexpr float GOLDEN_RATIO = 1.618 * 1e5;

double roundToTwoDecimals(double &x)
{
    return std::round(x * 100.0) / 100.0;
}

double hashVector(const std::vector<double> &flatBuffer)
{
    double acc = 0.0;
    for (double x : flatBuffer)
    {
        double temp = std::fmod(x * M_PI + acc, GOLDEN_RATIO);

        acc = std::fmod(acc + temp, GOLDEN_RATIO);
    }
    return acc;
}

// mutate double by round to two decimal places in cpp

// void runTests()
// {
//     // 1) Empty vector → hash = 0.0
//     {
//         std::vector<double> data{};
//         double h = hashVector(data);
//         assert(approxEqual(h, 0.0));
//     }

//     // 2) Single-element vector: [ 1.0 ]
//     //    Expected: fmod(1 * π, GOLDEN_RATIO)
//     {
//         std::vector<double> data{1.0};
//         double expected = std::fmod(1.0 * M_PI, GOLDEN_RATIO);
//         double h = hashVector(data);
//         assert(approxEqual(h, expected));
//     }

//     {
//         std::vector<double> data1{7.5, 0.25, -1.2, 3.14};
//         std::vector<double> data2 = data1; // copy
//         double h1 = hashVector(data1);
//         double h2 = hashVector(data2);
//         assert(approxEqual(h1, h2));
//     }

//     // 6) Small perturbation changes hash
//     {
//         std::vector<double> base{1.0, 2.0, 3.0, 4.0};
//         std::vector<double> perturbed = base;
//         perturbed[2] += 1e-6; // tiny change
//         double h_base = hashVector(base);
//         double h_pert = hashVector(perturbed);
//         std::cout << h_base << std::endl;
//         std::cout << h_pert << std::endl;
//         assert(approxEqual(h_base, h_pert));
//     }

//     {

//         std::vector<double> base = million_random_doubles();
//         std::vector<double> perturbed(base.size());
//         double randomizer;
//         for (size_t i = 0; i < base.size(); i++)

//         {
//             randomizer = uniform_random_double(0, 1);
//             if (randomizer > 0.999)
//             {
//                 perturbed.push_back(base[i] + 1e-6);
//             }
//             else
//             {
//                 perturbed.push_back(base[i]);
//             }
//         };
//         // generate a uniform random double cpp
//         double h_base = hashVector(base);
//         double h_pert = hashVector(perturbed);
//         std::cout << h_base << std::endl;
//         std::cout << h_pert << std::endl;
//         assert(approxEqual(h_base, h_pert));
//         // write  a function in cpp that returns a vec of million random doubles
//     }

//     std::cout << "All tests passed.\n";
// }

int main()
{
    std::vector<double> test = {1.323, 3.33, 5.55};
    std::vector<double> test1 = {1.32300000001, 3.33332, 5.55};
    // reverse vec in cpp. I need somwthing like for(i in container)
    std::cout << hashVector(test) << std::endl;
    std::cout << hashVector(test1) << std::endl;

    // reverseVector(test1);
    // compile with debug symbols cpp
    std::cout << hashVector(test1) << std::endl;
    // runTests();
}
