#pragma once

#include <string>

class Student {
public:

	void set_name(std::string name);
	void set_math_grade(float math_grade);
	void set_eng_grade(float eng_grade);
	void set_hist_grade(float hist_grade);

	std::string get_name() const;
	float get_math_grade() const;
	float get_eng_grade() const;
	float get_hist_grade() const;
	float get_avg_grade() const;

private:
	std::string name;
	float math_grade{};
	float eng_grade{};
	float hist_grade{};
};


