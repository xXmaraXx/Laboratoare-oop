#include "Compare.h"

int compare_names(const Student& s1, const Student& s2){
	
	return s1.get_name().compare(s2.get_name());
}

int compare_math_grades(const Student& s1, const Student& s2) {

	if (s1.get_math_grade() == s2.get_math_grade()) {
		return 0;
	} 
	else if (s1.get_math_grade() > s2.get_math_grade()) {
		return 1;
	}
	else {
		return -1;
	}
}

int compare_eng_grades(const Student& s1, const Student& s2) {

	if (s1.get_eng_grade() == s2.get_eng_grade()) {
		return 0;
	}
	else if (s1.get_eng_grade() > s2.get_eng_grade()) {
		return 1;
	}
	else {
		return -1;
	}
}

int compare_hist_grades(const Student& s1, const Student& s2) {

	if (s1.get_hist_grade() == s2.get_hist_grade()) {
		return 0;
	}
	else if (s1.get_hist_grade() > s2.get_hist_grade()) {
		return 1;
	}
	else {
		return -1;
	}
}

int compare_avg_grades(const Student& s1, const Student& s2) {

	if (s1.get_avg_grade() == s2.get_avg_grade()) {
		return 0;
	}
	else if (s1.get_avg_grade() > s2.get_avg_grade()) {
		return 1;
	}
	else {
		return -1;
	}
}