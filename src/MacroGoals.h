#ifndef MACROMIND_MACROGOALS_H
#define MACROMIND_MACROGOALS_H

#include "DailyLog.h"


class Macro_goals
{
private:
    double weight;
    std::string activity_level;
    std::string goal;

public:
    Macro_goals(double weight, std::string activity_level, std::string goal);
    int get_calorie_target() const;
    int get_protein_target() const;
    int get_fat_target() const;
    int get_carb_target() const;
    void compare_to_log(Daily_log &log) const;
};


#endif //MACROMIND_MACROGOALS_H
