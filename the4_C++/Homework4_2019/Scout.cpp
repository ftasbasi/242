#include"Scout.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
int Scout::getAttackDamage() const{
    return attackDamage;
}

int Scout::getHealPower() const{
    return healPower;
}

int Scout::getMaxHP() const{
    return maxHP;
}
Scout::Scout(uint id, int x, int y, Team team):Player(id,x,y,team) {
    HP=maxHP;
}
std::vector<Coordinate> Scout::getAttackableCoordinates() {


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

std::vector<Coordinate> Scout::getMoveableCoordinates() {


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
std::vector<Coordinate> Scout::getHealableCoordinates() {


    std::vector<Coordinate> tmp;

    return tmp;
}

std::vector<Goal> Scout::getGoalPriorityList() {

//{CHEST,TO_ALLY,ATTACK}

    std::vector<Goal> tmp;
    tmp.push_back(ATTACK);
    tmp.push_back(TO_ALLY);
    tmp.push_back(CHEST);

    return tmp;
}
const std::string Scout::getClassAbbreviation() const {

    if(this->getTeam()==BARBARIANS){
        return "SC";
    }else
    {
        return "sc";
    }

}