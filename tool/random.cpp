std::mt19937 rng_engine{randutils::auto_seed_128{}.base()};
std::uniform_int_distribution<int> dist{1, 1000};//1-1000 inclusive
int rand_integer = dist(rng_engine);
