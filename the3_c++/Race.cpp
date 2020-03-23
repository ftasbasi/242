#include "Race.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/
Race::Race(std::string race_name){
	this->race_name=race_name;

	this->average_laptime=0;

	this->head=NULL;
}

Race::Race(const Race& rhs){
	this->race_name=rhs.getRaceName();
	Laptime* tmp;
	tmp=new Laptime(rhs.average_laptime);
	this->average_laptime=*tmp;
	Car* tmpcar=new Car
}