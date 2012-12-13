#include "stdafx.h"
#include "Dice.h"
#include "Combat.h"
#include "Logger.h"
using namespace d20Logic;
using namespace std;
bool Combat::Fight(Character player, Character monster){
		int playerRoll, monsterRoll;
	Dice dice;

	while(player.getHitPoints() >= 0 && monster.getHitPoints() >= 0) {

		playerRoll = dice.roll_d20();
		int playerInitiative = playerRoll + player.getDexMod();
		monsterRoll = dice.roll_d20();
		int monsterInitiative = monsterRoll + monster.getDexMod();

		System::String^ monsterDexMod = System::Convert::ToString(monster.getDexMod());
		System::String^ playerDexMod = System::Convert::ToString(player.getDexMod());

		Logger::LogInfo(gcnew System::String("Player initiative roll: " + playerRoll + " +" + playerDexMod + " dexterity modifier"));
		Logger::LogInfo(gcnew System::String("Monster initiative roll: " + monsterRoll + " +" + monsterDexMod + " dexterity  modifier"));
		

		if (playerInitiative > monsterInitiative) {
			Logger::LogInfo(gcnew System::String("Player wins initiative roll"));
			player.attack(&monster);
			if(monster.getHitPoints()>0)
				monster.attack(&player);
			else
				return true; //Monster dead
		}

		else if (monsterInitiative > playerInitiative) {
			Logger::LogInfo(gcnew System::String("Monster wins initiative roll"));		
			monster.attack(&player);
			if(player.getHitPoints()>0)
				player.attack(&monster);
			else
				return false; //Player dead

		}

		else{
			Logger::LogInfo(gcnew System::String("Initiative rolls are equal, re-roll required"));
		}
	}
}