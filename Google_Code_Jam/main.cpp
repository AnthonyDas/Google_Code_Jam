#include <iostream>

#include "QualificationRound2016.h"
#include "QualificationRoundAfrica2010.h"

int main() {

	/*
	QualificationRoundAfrica2010A("small");
	QualificationRoundAfrica2010A("large");
	QualificationRoundAfrica2010B("small");
	QualificationRoundAfrica2010B("large");
	QualificationRoundAfrica2010C("small");
	QualificationRoundAfrica2010C("large");
	*/

	QualificationRound2016A("small");
	QualificationRound2016A("large");
	QualificationRound2016B("small");
	QualificationRound2016B("large");
	QualificationRound2016C("small");
	QualificationRound2016C("large");

	// Missing question
	// QualificationRound2016D("small"); 
	// QualificationRound2016D("large");

	int dummy;
	std::cin >> dummy;
	return EXIT_SUCCESS;
}
