#include"Player.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

//Player();
Player::Player(uint id, int x, int y, Team team):id(id),coordinate(x,y),team(team) {}
uint Player::getID() const { return id;}
Coordinate Player::getCoord() const { return this->coordinate;}
int Player::getHP() const {
    return this->HP;
}
Team Player::getTeam() const { return team;}
std::string Player::getBoardID() {

    if((std::to_string(id)).length()<2){
        return "0"+std::to_string(id);
    }else{
        return std::to_string(id);
    }
}
bool Player::isDead() const {
    return (HP<=0);
}
/**
 * Move player to coordinate. Print the boardID of the player and the old and new
 * coordinates as below:
 * "Player 01 moved from (0/1) to (0/2)"
 * @Important before calling this method you must verify that this coordinate
 * is valid to move
 */

void Player::movePlayerToCoordinate(Coordinate c){

    std::vector<Coordinate> v;
    v=this->getMoveableCoordinates();

    if (std::count(v.begin(), v.end(), c)){
        int xx,yy;

        xx=coordinate.x;
        yy=coordinate.y;
        coordinate=coordinate+c;

        std::cout<<"Player "<< this->getBoardID() << " moved from " << "("<<xx<<"/"<<yy<<")" << " to " "("<<coordinate.x<<"/"<<coordinate.y<<")"<< std::endl;

    }

}

bool Player::attack(Player *enemy){
    if(this==enemy){ return false;}
    int result;

    result=enemy->getHP() - this->getAttackDamage();
    result=std::max(result,0);
    std::vector<Coordinate> v;
    v=this->getAttackableCoordinates();

    if (std::count(v.begin(), v.end(), enemy->getCoord())) {
        std::cout<< "\n RESULT : \n"<<result<<std::endl;
        enemy->setHP(result);

        std::cout << "Player " << this->getBoardID() << " attacked " << "Player " << enemy->getBoardID() << " ("
                  << enemy->getHP() << ")" << std::endl;
    }
    return enemy->isDead();
}

void Player::heal(Player *ally) {

    std::vector<Coordinate> v;
    v=this->getHealableCoordinates();

    if (std::count(v.begin(), v.end(), ally->getCoord())) {

        int tmp = 0;
        tmp = ally->getHP();

        tmp += this->getHealPower();

        if (tmp <= ally->getMaxHP()) {
            ally->setHP(tmp);
        } else {
            ally->setHP(ally->getMaxHP());
        }

        std::cout << "Player " << this->getBoardID() << " healed " << "Player " << ally->getBoardID() << std::endl;
    }
}
void Player::setHP(int HPin){

    HP=HPin;
}