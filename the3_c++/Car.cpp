#include "Car.h"
#include "Utilizer.h"
/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/
#include <iostream>
#include <sstream>
Car::Car(std::string driver_name){//
	
	this->performance=Utilizer::generatePerformance();
	this->driver_name=driver_name;
}
Car::~Car(){//
	Laptime* node = this->head;
    while (node) {
		Laptime* tmp = node;
        node = node->getNext();
        delete tmp;
    }
    head = nullptr;

}
Car::Car(const Car& rhs){//
	this->driver_name=rhs.getDriverName();
	this->performance=rhs.getPerformance();
	this->head=new Laptime;

}
std::string Car::getDriverName() const{//
	
	return this->driver_name;
}
double Car::getPerformance() const{//

	return this->performance;
}

void Car::addCar(Car *next){//

	this->next=next;
}
bool Car::operator<(const Car& rhs) const{//

	int totalLeft,totalRight;
	totalLeft=0;
	totalRight=0;
	Laptime *ptrThis;
	Laptime *ptrRhs=NULL;
	ptrThis=this->head;

	while (ptrThis!=NULL)
	{
		totalLeft+=ptrThis->getLaptime();
		ptrThis=ptrThis->getNext();
	}
	while (ptrRhs!=NULL)
	{
		totalRight+=ptrRhs->getLaptime();
		ptrRhs=ptrRhs->getNext();
	}

	if(totalLeft<totalRight){
		return true;
	}else{
		return false;
	}
}
bool Car::operator>(const Car& rhs) const{//

	int totalLeft,totalRight;
	totalLeft=0;
	totalRight=0;
	Laptime *ptrThis=NULL;
	Laptime *ptrRhs=NULL;
	ptrThis=this->head;

	while (ptrThis!=NULL)
	{
		totalLeft+=ptrThis->getLaptime();
		ptrThis=ptrThis->getNext();
	}
	while (ptrRhs!=NULL)
	{
		totalRight+=ptrRhs->getLaptime();
		ptrRhs=ptrRhs->getNext();
	}

	if(totalLeft>totalRight){
		return true;
	}else{
		return false;
	}
}
Laptime Car::operator[](const int lap) const{//
	Laptime * tmp;
	int counter=0;
	tmp=this->head;

	while(counter<lap){
		tmp=tmp->getNext();
		counter+=1;
	}

	return *tmp;
}


/**
     * Stream overload.
     *
     * What to stream:
     * First Three letters of the drivers surname(Capitalized)--Latest Laptime--Fastest Laptime--Total Laptime
     * Example:
     * For Lewis Hamilton
     * HAM--1:19.235--1:18.832--90:03.312
     *
     * @Important: for lap numbers smaller in size you have to put zeros as much as neccasary
     * @Important: you can use Laptime ostream when neccessary
     * 
     * @param os Stream to be used.
     * @param car Car to be streamed.
     * @return The current Stream.
     */
std::string getLastName(std::string s)
{
    std::istringstream iss (s);
    while(iss >> s);
    return s;
}

std::ostream& operator<<(std::ostream& os, const Car& car){

	std::string lastnameDriver;



	lastnameDriver=getLastName(car.getDriverName());

	int lenName=lastnameDriver.length();

	if(lenName<3){
		lastnameDriver=lastnameDriver.substr(0,lenName); 
	}else{
		lastnameDriver=lastnameDriver.substr(0,3);
	}

	for(auto& x: lastnameDriver)
        x = toupper(x);

	Laptime* tmp;
	tmp=car.head;

	int fastestLaptime=INT_MAX;
	int LatestLaptime=INT_MIN;
	int TotalLaptime=0;

	while (tmp)
	{
		TotalLaptime+=tmp->getLaptime();

		if(fastestLaptime>tmp->getLaptime()){
			fastestLaptime=tmp->getLaptime();
		}

		if(LatestLaptime<tmp->getLaptime()){
			LatestLaptime=tmp->getLaptime();
		}
				
		tmp=tmp->getNext();
	}

	Laptime latestnode(LatestLaptime);
	Laptime fastestnode(fastestLaptime);

	os << lastnameDriver << "--" <<latestnode<<"--"<<fastestnode<<"--"<<TotalLaptime;

	return os;

}

	
	
