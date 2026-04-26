/*
Utilizare la siguiente nomenclatura:

	-Utilizare camelCase para mis variables
	-Mis parametros en funciones no tendran ningun tipo de nomenclatura extra
	-Mis funciones siempre empezaran con la accion a hacer y despues a donde se lo voy a aplicar

*/

#include <iostream>
#include <vector>

class Capsule
{
private:
	std::string Name;
	//Healing = 1, Ki Recover = 2
	std::string Type;
	int Duration;

public:

	Capsule(std::string capsuleName, int capsuleType, int capsuleDuration)
	{
		Name = capsuleName;

		switch (capsuleType)
		{
		case 1:
			Type = "Healing";
			break;
		case 2:
			Type = "Energy";
		default:
			Type = "Unknown";
			break;
		}
		Duration = capsuleDuration;
	}

	//This is only to prints the properties of the capsule
	void ShowData()
	{
		std::cout << "Capsule: " << Name + "\n";
		std::cout << "Type: " << Type << "\n";
		std::cout << "Duration: " << Duration << "s" << "\n";
	}

	void GetInventoryData()
	{
		std::cout << "Capsule: " << Name + "\n";
		std::cout << "Type: " << Type << "\n";
		std::cout << "Duration: " << Duration << "s" << "\n";
		std::cout << "----------------------------------------------\n";
	}
	//This returns the name of the capsule referenced
	std::string GetCapsuleName()
	{
		return Name;
	}
	//This function returns the type of capsule
	std::string GetCapsuleType()
	{
		return Type;
	}
};

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

	//Secondary properties
	std::vector<Capsule> inventory;

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

	//Adds the object at the beginning of the vector
	void AddToInventory(Capsule item)
	{
		inventory.push_back(item);
	}

	//Method that shows in console all the items inside of the vector
	void Showinventory()
	{
		if (inventory.size() < 1)
		{
			system("cls");
			std::cout << "You dont have any item in your inventory" << std::endl;
			std::cout << "PRESS ENTER TO GO BACK TO THE MENU" << std::endl;
		}
		else
		{
			system("cls");
			for (int i = 0; i < inventory.size(); i++)
			{
				inventory[i].GetInventoryData();
			}
			std::cout << "PRESS ENTER TO GO BACK TO THE MENU" << std::endl;
		}
		std::cin.get();
		system("cls");
	}

	//Gets the vectors size
	int GetInventorySize()
	{
		return inventory.size();
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

class Player : public Character
{
private:
	int zeni;
public:
	//Constructor that initializes the variables
	Player(std::string name, int life, int ki, int kiBlast, int beam, int specialAttack) : 
	Character(name, life, ki, kiBlast, beam, specialAttack){}
};


int main()
{
	return 0;
}
