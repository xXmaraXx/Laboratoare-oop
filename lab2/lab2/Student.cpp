#include "Student.h"


void Student::set_name(std::string name) {
	this->name = name;
}

void Student::set_math_grade(float math_grade) {
	this->math_grade = math_grade;
}

void Student::set_eng_grade(float eng_grade) {
	this->eng_grade = eng_grade;
}

void Student::set_hist_grade(float hist_grade) {
	this->hist_grade = hist_grade;
}

std::string Student::get_name() const
{
	return name;
}

float Student::get_math_grade() const
{
	return math_grade;
}

float Student::get_eng_grade() const
{
	return eng_grade;
}

float Student::get_hist_grade() const
{
	return hist_grade;
}

float Student::get_avg_grade() const
{
	return (math_grade + eng_grade + hist_grade) / 3;
}