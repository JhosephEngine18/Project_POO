/*
Utilizare la siguiente nomenclatura:

	-Utilizare camelCase para mis variables
	-Mis parametros en funciones no tendran ningun tipo de nomenclatura extra
	-Mis funciones siempre empezaran con la accion a hacer y despues a donde se lo voy a aplicar

*/

#include <iostream>
#include <vector>


class Character
{
private:

	//Main properties
	std::string characterName = "";
	int characterLife;
	int characterKi;
	//Combat properties
	int kiBlastDamage;
	int beamDamage;
	int specialAttackDamage;

public:
	//Constructor that initializes the variable playerName
	Character(std::string name, int life, int Ki, int kiblast, int beam, int specialAttack)
	{
		//Main properties
		characterName = name;
		characterLife = life;
		characterKi = Ki;
		//Combat properties
		kiBlastDamage = kiblast;
		beamDamage = beam;
		specialAttackDamage = specialAttack;
	}
	//This returns the name of the player
	std::string GetCharacterName()
	{
		if (characterName == "")
		{
			return "Character name not assigned";
		}
		return characterName;
	}

	//Returns the current life of the character
	int GetLife()
	{
		return characterLife;
	}

	//Returns the damage of character's KiBlast
	int GetKiBlastDamage()
	{
		return kiBlastDamage;
	}

	//Returns the damage of character's Beam
	int GetBeamDamage()
	{
		return beamDamage;
	}

	//Returns the damage of character's KiBlast
	int GetSpecialAttackDamage()
	{
		return specialAttackDamage;
	}

};


int main()
{
	return 0;
}
