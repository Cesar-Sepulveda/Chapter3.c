#include <stdio.h>
#include <string.h>

void expand(char s1[], char s2[]) {	//Exerxise 3.3
	char copy;
	int i, k;
	i = k = 0;

	while ((copy = s1[i]) != '\0') {
		++i;
		if (s1[i] == '-' && s1[i + 1] >= copy) {
			++i;
			while (copy < s1[i]) {
				s2[k] = copy;
				++copy;
				++k;
			}
		}
		else {
			s2[k] = copy;
			++k;
		}
	}
	s2[k] = '\0';
}


void itob(int n, char s[], int b) {	//Exercise 3.5
	int i, k, sign;
	i = 0;
	k = n % b;
	sign = n;

	if (n < 0) {
		n = -n;
	}
	do {
		if (k <= 9) {
			s[i] = k + '0';
			++i;
		}
		else {
			s[i] = k + 'a' - 10;
			++i;
		}
	}while (( n = n/10) > 0);
	if (sign < 0) {
		s[i] = '-';
		++i;
	}
	s[i] = '\0';
}

void itoa(int n, char s[], int b) {	//Exercise 3.6
	int i, sign;
	if ((sign = n) < 0) {
		n = -n;
	}
	i = 0;       
	do {                
		s[i++] = n % 10 + '0'; 
	} while ((n = n/ 10) > 0);       
	if (sign < 0) {
		s[i++] = '-';
	}
	while (i < b) {
		s[i] = ' ';
		++i;
	}
	s[i] = '\0';       
}


void test_exercises(char string1[], char string2[], int n, int b, char string3[]) {
	expand(string1, string2);
	printf("expand: string1: %s\t %s\n", string1, string2);
	itob(n, string3, b);
	printf("itob: string3: %s\n", string3);
	itoa(n, string3, b);
	printf("itoa: string3: %s\n", string3);
}


int main() {
	char string1[5] = "a-e";
	char string2[5];
	char string3[6] = "Hello";
	int n = 3;
	int b = 5;

	test_exercises(string1, string2, n, b, string3);

	return 0;
}
