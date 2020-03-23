#include"Tank.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
int Tank::getAttackDamage() const{
    return attackDamage;
}

int Tank::getHealPower() const{
    return healPower;
}

int Tank::getMaxHP() const{
    return maxHP;
}
Tank::Tank(uint id, int x, int y, Team team):Player(id,x,y,team) {
    HP=maxHP;
}
std::vector<Coordinate> Tank::getAttackableCoordinates() {


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

std::vector<Coordinate> Tank::getMoveableCoordinates() {


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
std::vector<Coordinate> Tank::getHealableCoordinates() {


    std::vector<Coordinate> tmp;

    return tmp;
}

std::vector<Goal> Tank::getGoalPriorityList() {

//{TO_ENEMY,ATTACK,CHEST}

    std::vector<Goal> tmp;
    tmp.push_back(CHEST);
    tmp.push_back(ATTACK);
    tmp.push_back(TO_ENEMY);

    return tmp;
}
const std::string Tank::getClassAbbreviation() const {

    if(this->getTeam()==BARBARIANS){
        return "TA";
    }else
    {
        return "ta";
    }

}