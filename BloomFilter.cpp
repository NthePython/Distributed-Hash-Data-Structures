bloom_parameters parameters;
parameters.projected_element_count = 1000;
parameters.false_positive_probability = 0.0001;
parameters.random_seed = 0xA5A5A5A5;
parameters.compute_optimal_parameters();
bloom_filter filter(parameters);

std::string str_list[] = { "AbC", "iJk", "XYZ" };
for (std::size_t i = 0; i < (sizeof(str_list) / sizeof(std::string)); ++i)
{
   filter.insert(str_list[i]);
}
