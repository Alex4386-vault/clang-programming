bool isLowerCase(char a) {
	if (65 <= a && a <= 90) {
		return true;
	}
	return false;
}

bool isUpperCase(char a) {
	if (97 <= a && a <= 122) {
		return true;
	}
	return false;
}

char toUpperCase(char a) {
	if (isLowerCase(a)) {
		return a+26+7;
	}
	return a;
}

char toLowerCase(char a) {
	if (isUpperCase(a)) {
		return a - 26 - 7;
	}
	return a;
}

bool isAlphabet(char a) {
	if (65 <= a && a <= 90) {
		return true;
	} else if (97 <= a && a <= 122) {
		return true;
	}
	return false;
}