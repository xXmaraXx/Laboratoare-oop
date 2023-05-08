#include "Student.h"
#include "Compare.h"
#include <iostream>

int main() {

	

	Student s1, s2;
	s1.set_name("Cleopatra");
	s1.set_math_grade(8.0f);
	s1.set_eng_grade(9.7f);
	s1.set_hist_grade(4.0f);

	s2.set_name("Marinica");
	s2.set_math_grade(4.5f);
	s2.set_eng_grade(10.0f);
	s2.set_hist_grade(4.0f);

	int name_cmp = compare_names(s1, s2);
	std::cout << "Name comparison: " << name_cmp << "\n";

	int math_cmp = compare_math_grades(s1, s2);
	std::cout << "Math grade comparison: " << math_cmp << "\n";

	int eng_cmp = compare_eng_grades(s1, s2);
	std::cout << "English grade comparison: " << eng_cmp << "\n";

	int hist_cmp = compare_hist_grades(s1, s2);
	std::cout << "History grade comparison: " << hist_cmp << "\n";

	int avg_cmp = compare_avg_grades(s1, s2);
	std::cout << "Average grade comparison: " << avg_cmp << "\n";

	return 0;

}

