#include "utils.h"

void lowerize(char *str){
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] -= 'A';
			str[i] += 'a';
		}
		i++;
	}
}


bool is_number(char *val) {
	int i = 0;
	while (val[i] != '\0') {
		if (val[i] < '0' || val[i] > '9') {
			return 0;
		}
		i++;
	}
	return 1;
}