#include "EnemyCounter.h"
/*Thiss class is prepared to implement futher and getting a textfield that updates enemies that has been killed*/
EnemyCounter::EnemyCounter(std::string startValue, SDL_Texture* txtr_ptr, int x, int y, int width, int height) : TextField(startValue, txtr_ptr, x, y, width, height){

}

void EnemyCounter::increment(){
	enemiesKilled++;
}

int EnemyCounter::getEnemiesKilled(){
	return enemiesKilled;
}

EnemyCounter::~EnemyCounter(){

}