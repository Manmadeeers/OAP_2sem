#include "Check_if_leap.h"

bool check_if_leap(int year)
{
	bool is_leap;
	if ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0)) {
		is_leap = true;
	}
	else {
		is_leap = false;
	}
	return is_leap;
}