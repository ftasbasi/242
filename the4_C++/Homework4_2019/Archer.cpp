#include"Archer.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
int Archer::getAttackDamage() const{
    return attackDamage;
}

int Archer::getHealPower() const{
    return healPower;
}

int Archer::getMaxHP() const{
    return maxHP;
}
Archer::Archer(uint id, int x, int y, Team team):Player(id,x,y,team){
    HP=maxHP;

}
std::vector<Coordinate> Archer::getAttackableCoordinates() {

    std::vector<Coordinate> tmp;
    int xx=this->getCoord().x;
    int yy=this->getCoord().y;
    tmp.push_back(Coordinate(xx,yy+1));
    tmp.push_back(Coordinate(xx,yy-1));
    tmp.push_back(Coordinate(xx-1,yy));
    tmp.push_back(Coordinate(xx+1,yy));
    tmp.push_back(Coordinate(xx,yy+2));
    tmp.push_back(Coordinate(xx,yy-2));
    tmp.push_back(Coordinate(xx-2,yy));
    tmp.push_back(Coordinate(xx+2,yy));

    return tmp;
}

std::vector<Coordinate> Archer::getMoveableCoordinates() {


    std::vector<Coordinate> tmp;
    return tmp;
}
std::vector<Coordinate> Archer::getHealableCoordinates() {

//cannot heal
    std::vector<Coordinate> tmp;
    return tmp;
}

std::vector<Goal> Archer::getGoalPriorityList() {

//cannot heal
    std::vector<Goal> tmp;
    tmp.push_back(ATTACK);


    return tmp;
}
const std::string Archer::getClassAbbreviation() const {

    if(this->getTeam()==BARBARIANS){
        return "AR";
    }else
    {
        return "ar";
    }

}