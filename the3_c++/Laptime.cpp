#include "Laptime.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/
Laptime::Laptime(){

}
Laptime::Laptime(int laptime){
	
	this->laptime=laptime;
}

Laptime::Laptime(const Laptime& rhs){

	this->laptime=rhs.laptime;
	this->next=rhs.next;
}
Laptime::~Laptime(){
	delete []next;
}

void Laptime::addLaptime(Laptime *next){
	Laptime* tmp;
	tmp=this->next;
	while (tmp)
	{
		tmp=tmp->next;
	}

	tmp=next;

}
bool Laptime::operator<(const Laptime& rhs) const{
	if(this->laptime < rhs.laptime){
		return true;
	}else
	{
	return false;
	}
}
bool Laptime::operator>(const Laptime& rhs) const{
	if(this->laptime > rhs.laptime){
		return true;
	}else
	{
	return false;
	}
}
Laptime& Laptime::operator+(const Laptime& rhs){
	this->laptime=this->laptime + rhs.laptime;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Laptime& laptime){

	int total,min,sec,milisec;

	total=laptime.laptime;
	min=total/60000;
	total=total-min*60000;
	sec=total/1000;
	total=total-sec*1000;
	milisec=total;

	os << min <<":"<<sec<<"."<<milisec;

	return os;
}
Laptime* Laptime::getNext(){
	return this->next;
}
int Laptime::getLaptime(){
	return this->laptime;
}