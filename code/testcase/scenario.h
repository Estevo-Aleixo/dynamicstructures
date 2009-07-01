#ifndef SCENARIO_H
#define SCENARIO_H



enum FindVerticesMethod{random_search,high_degree_search, highest_degree_search};

class Scenario
{
public:
    Scenario();
    int local_fight_points;
    int spanning_points;
    int spanMethod;
    int lfpMethod;

    unsigned int multiple_path_iterations;
    int type;

};

#endif // SCENARIO_H
