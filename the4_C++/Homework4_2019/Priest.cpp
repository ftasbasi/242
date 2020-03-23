#include"Priest.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
int Priest::getAttackDamage() const{
    return attackDamage;
}

int Priest::getHealPower() const{
    return healPower;
}

int Priest::getMaxHP() const{
    return maxHP;
}
Priest::Priest(uint id, int x, int y, Team team):Player(id,x,y,team){
    HP=maxHP;
}

std::vector<Coordinate> Priest::getAttackableCoordinates() {

    std::vector<Coordinate> tmp;

    return tmp;
}

std::vector<Coordinate> Priest::getMoveableCoordinates() {


    std::vector<Coordinate> tmp;

    int xx=this->getCoord().x;
    int yy=this->getCoord().y;

    tmp.push_back(Coordinate(xx,yy+1));
    tmp.push_back(Coordinate(xx,yy-1));
    tmp.push_back(Coordinate(xx-1,yy));
    tmp.push_back(Coordinate(xx+1,yy));
    tmp.push_back(Coordinate(xx+1,yy+1));
    tmp.push_back(Coordinate(xx-1,yy+1));
    tmp.push_back(Coordinate(xx+1,yy-1));
    tmp.push_back(Coordinate(xx-1,yy-1));


    return tmp;
}
std::vector<Coordinate> Priest::getHealableCoordinates() {


    std::vector<Coordinate> tmp;

    int xx=this->getCoord().x;
    int yy=this->getCoord().y;

    tmp.push_back(Coordinate(xx,yy+1));
    tmp.push_back(Coordinate(xx,yy-1));
    tmp.push_back(Coordinate(xx-1,yy));
    tmp.push_back(Coordinate(xx+1,yy));
    tmp.push_back(Coordinate(xx+1,yy+1));
    tmp.push_back(Coordinate(xx-1,yy+1));
    tmp.push_back(Coordinate(xx+1,yy-1));
    tmp.push_back(Coordinate(xx-1,yy-1));


    return tmp;
}

std::vector<Goal> Priest::getGoalPriorityList() {

//{HEAL,TO_ALLY,CHEST}

    std::vector<Goal> tmp;
    tmp.push_back(CHEST);
    tmp.push_back(TO_ALLY);
    tmp.push_back(HEAL);

    return tmp;
}
const std::string Priest::getClassAbbreviation() const {

    if(this->getTeam()==BARBARIANS){
        return "PR";
    }else
    {
        return "pr";
    }

}