#include "vote.h"
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>

using namespace std;

vote::vote(const vector<candidate>& prefs) : prefs(prefs) {}

bool vote::spent() const {
	if (prefs.empty()) {
		return true;
	}
	else {
		return false;
	}
}

candidate vote::first_preference() const {
	if (spent() == false) {
		return prefs[0];
	}
	else {
		return 0;
	}
}

void vote::discard(candidate c) {
	prefs.erase(remove(prefs.begin(), prefs.end(), c), prefs.end());
}