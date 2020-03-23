#include"Fighter.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

int Fighter::getAttackDamage() const{
    return attackDamage;
}

int Fighter::getHealPower() const{
    return healPower;
}

int Fighter::getMaxHP() const{
    return maxHP;
}
Fighter::Fighter(uint id, int x, int y, Team team):Player(id,x,y,team) {
    HP=maxHP;
}
std::vector<Coordinate> Fighter::getAttackableCoordinates() {

    std::vector<Coordinate> tmp;
    int xx=this->getCoord().x;
    int yy=this->getCoord().y;

    tmp.push_back(Coordinate(xx,yy+1));
    tmp.push_back(Coordinate(xx,yy-1));
    tmp.push_back(Coordinate(xx-1,yy));
    tmp.push_back(Coordinate(xx+1,yy));

    return tmp;
}

std::vector<Coordinate> Fighter::getMoveableCoordinates() {


    std::vector<Coordinate> tmp;
    int xx=this->getCoord().x;
    int yy=this->getCoord().y;

    tmp.push_back(Coordinate(xx,yy+1));
    tmp.push_back(Coordinate(xx,yy-1));
    tmp.push_back(Coordinate(xx-1,yy));
    tmp.push_back(Coordinate(xx+1,yy));

    return tmp;
}
std::vector<Coordinate> Fighter::getHealableCoordinates() {

//cannot heal
    std::vector<Coordinate> tmp;
    return tmp;
}

std::vector<Goal> Fighter::getGoalPriorityList() {

//cannot heal
std::vector<Goal> tmp;

    tmp.push_back(CHEST);
    tmp.push_back(TO_ENEMY);
    tmp.push_back(ATTACK);


return tmp;
}
const std::string Fighter::getClassAbbreviation() const {

    if(this->getTeam()==BARBARIANS){
        return "FI";
    }else
    {
        return "fi";
    }

}