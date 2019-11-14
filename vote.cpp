#include "vote.h"

vote::vote(const std::vector<candidate>& prefs) {}

const bool vote::spent()
{
	return false;
}

const candidate vote::first_preference()
{
	return candidate();
}

void vote::discard(candidate c)
{
}
