#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <numbers...>" << std::endl;
        return 1;
    }
    if (argc > 3001)
    {
        std::cerr << "Usage: invalid numbers"  << std::endl;
        return 1;
    }
    std::vector<int> input;
    try
    {
        input = parseInput(argc, argv);
    } 
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    std::vector<int> vec = input;
    std::list<int> lst(input.begin(), input.end());
    std::cout << "Before: ";
    for (size_t i = 0; i < input.size(); ++i)
        std::cout << input[i] << (i + 1 < input.size() ? " " : "");
    std::cout << std::endl;

    std::vector<int> checkDup = input;
    std::sort(checkDup.begin(), checkDup.end());
    for (size_t i = 1; i < checkDup.size(); ++i)
    {
        if (checkDup[i-1] == checkDup[i])
        {
            std::cerr << "Error: input contains duplicate numbers" << std::endl;
            return 1;
        }
    }

    bool sorted = true;
    for (size_t i = 1; i < input.size(); ++i)
    {
        if (input[i-1] > input[i])
        {
            sorted = false;
            break;
        }
    }
    if (sorted)
    {
        std::cerr << "Error: input is already sorted" << std::endl;
        return 1;
    }
    clock_t start = clock();
    fordJohnsonSort(vec);
    clock_t end = clock();
    double vecTime = 1000000.0 * (end - start) / CLOCKS_PER_SEC;
    start = clock();
    fordJohnsonSort(lst);
    end = clock();
    double listTime = 1000000.0 * (end - start) / CLOCKS_PER_SEC;
    std::cout << "After:  ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << (i + 1 < vec.size() ? " " : "");
    std::cout << std::endl;
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << lst.size() << " elements with std::list   : " << listTime << " us" << std::endl;
    return 0;
}