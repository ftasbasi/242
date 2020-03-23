#include"Board.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
Board::Board(uint _size, std::vector<Player*>* _players, Coordinate chest):size(_size),players(_players),chest(chest){}
/*
 	uint size;
	std::vector<Player*>* players;
	Coordinate chest;

 */

Board::~Board() {
    delete [] players;
}

/**
	 * @return true if the coordinate is in the board limits, false otherwise.
	 */
bool Board::isCoordinateInBoard(const Coordinate& c){

    if(c.x>=0 && c.x<size && c.y>=0 && c.y<size){
        return true;
    } else{
        return false;
    }

}
/**
 * @return true if there is a player on the given coordinate, false otherwise.
 */
bool Board::isPlayerOnCoordinate(const Coordinate& c){

    bool result= false;

    Player * tmp;



    while (tmp){

        if(tmp->getCoord()==c){
            result = true;
            break;
        }

        tmp+=1;
    }

    return result;
}
/**
 * @return pointer to the player at the given coordinate. Return NULL if no
 * player is there.
 */

Player* Board::operator[](const Coordinate &c) {

    if(!(isPlayerOnCoordinate(c))){
        return nullptr;
    }else
        {

            for(int i=0;i< (*players).size();i++)
            {
                if( (*players)[i]->getCoord() ==  c )
                    return (*players)[i];

            }
            return nullptr;
        }
}


/**
 * @return the chest coordinate
 */
Coordinate Board::getChestCoordinates(){

    return chest;
}
/**
 * Print the board with character ID's.
 * For each empty square print two underscore characters.
   * For the squares with a player on it, print the board id of the player.
   * For the square with the chest, print the string "Ch".
   * If a character is on the square with the chest, only print the ID of the
   * character.
   * For each row print a new line, for each column print a space character.
   * Example:
   * __ __ 01 __
   * __ 02 __ 05
   *	Ch __ __ 03
   *	__ __ __ __
 */
void Board::printBoardwithID(){

    for (int i = 0; i < size ; i++) {
        for (int j = 0; j < size; j++) {
            Coordinate tmp(i,j);
            Player* ptrPlayer;
            ptrPlayer=(*this)[tmp];

            if(ptrPlayer!= nullptr && tmp==chest){

                std::cout<<ptrPlayer->getID();

            }else if(ptrPlayer!= nullptr && tmp!=chest){

                std::cout<<ptrPlayer->getBoardID();

            }else if(tmp==chest){

                std::cout<<"Ch";

            } else{

                std::cout<<"__";

            }

            std::cout<<" ";
        }
        std::cout<<std::endl;
    }
}
/**
 * For each empty square print two underscore characters.
 * For the squares with a player on it, print the class abbreviation of the
 * player.
 * For the square with the chest, print the string "Ch".
 * If a character is on the square with the chest, only print the abbreviation
 * of the character.
 * To separate each row print a new line, to separate each column print a
 * space character.
 * Example:
 * __ __ PR __
 * __ ar __ TA
 * Ch __ __ fi
 * __ __ __ __
 */
void Board::printBoardwithClass(){


    for (int i = 0; i < size ; i++) {
        for (int j = 0; j < size; j++) {
            Coordinate tmp(i,j);
            Player* ptrPlayer;
            ptrPlayer=(*this)[tmp];

            if(ptrPlayer!= nullptr && tmp==chest){

                std::cout<<ptrPlayer->getClassAbbreviation();

            }else if(ptrPlayer!= nullptr && tmp!=chest){

                std::cout<<ptrPlayer->getClassAbbreviation();

            }else if(tmp==chest){

                std::cout<<"Ch";

            } else{

                std::cout<<"__";

            }

            std::cout<<" ";
        }
        std::cout<<std::endl;
    }

}