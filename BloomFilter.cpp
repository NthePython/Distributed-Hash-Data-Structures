#include "bloom_filter.hpp"
#include <iostream>
#include <string>

int main()
{
    // Bloom Filter parameters
    bloom_parameters params;

    // Anticipated number of items
    params.projected_element_count = 1000;

    // Allowable false positive rate
    params.false_positive_probability = 0.0001;

    // Setting random seed
    params.random_seed = 0xB6B6B6B6;
    params.compute_optimal_parameters();

    // Initializing Bloom Filter
    bloom_filter bfilter(params);

    std::string items_to_insert[] = { "item1", "item2", "item3" };

    // Adding items to Bloom Filter
    {
        // Adding strings
        for (std::size_t i = 0; i < (sizeof(items_to_insert) / sizeof(std::string)); ++i)
        {
            bfilter.insert(items_to_insert[i]);
        }

        // Adding numbers
        for (std::size_t i = 0; i < 100; ++i)
        {
            bfilter.insert(i);
        }
    }

    // Testing Bloom Filter
    {
        // Checking strings' presence
        for (std::size_t i = 0; i < (sizeof(items_to_insert) / sizeof(std::string)); ++i)
        {
            if (bfilter.contains(items_to_insert[i]))
            {
                std::cout << "BF includes: " << items_to_insert[i] << std::endl;
            }
        }

        // Checking numbers' presence
        for (std::size_t i = 0; i < 100; ++i)
        {
            if (bfilter.contains(i))
            {
                std::cout << "BF includes: " << i << std::endl;
            }
        }

        // Checking invalid numbers
        for (int i = -1; i > -100; --i)
        {
            if (bfilter.contains(i))
            {
                std::cout << "False positive in BF: " << i << std::endl;
            }
        }
    }

    return 0;
}
