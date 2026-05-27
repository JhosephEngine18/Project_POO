/*
Utilizare la siguiente nomenclatura:

	-Utilizare camelCase para mis variables
    -Utilizare PascalCase para las funciones y metodos
	-Mis los parametros utilizaran camelCase
	-Mis funciones siempre empezaran con la accion a hacer y despues a donde se lo voy a aplicar
    -Mis comentarios estaran en ingles

*/

#include <iostream>
#include <vector>
#include <limits>

class Capsule
{
private:
	std::string Name;
	//Healing = 1, Ki Recover = 2
	std::string Type;
	int value;

public:

	Capsule(std::string capsuleName, int capsuleType, int capsuleValue)
	{
		Name = capsuleName;
        value = capsuleValue;

		switch (capsuleType)
		{
		case 1:
			Type = "Healing";
			break;
		case 2:
			Type = "Energy";
            break;
		default:
			Type = "Unknown";
			break;
		}
	}

	//This is only to prints the properties of the capsule
	void ShowData()
	{
		std::cout << "Capsule: " << Name + "\n";
		std::cout << "Type: " << Type << "\n";
		std::cout << "Value: " << value << "\n";
	}

	void CapsuleSortedData()
	{
		std::cout << "Capsule: " << Name + "\n";
		std::cout << "Type: " << Type << "\n";
		std::cout << "Value: " << value << "\n";
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

    int GetCapsuleValue()
    {
        return value;
    }

};

class Character
{
protected:

	//Main properties
	int Life;
	int Ki;
	int Stamina;
    int Zeni = 700;
    int Level = 1;
    int Experience = 0;
	//Secondary properties
	std::vector<Capsule> inventory;

public:
	//Constructor that initializes the variable playerName
	Character(int initiallife, int initialKi, int initialStamina)
	{
		//Main properties
		Life = initiallife;
		Ki = initialKi;
		Stamina = initialStamina;
	}

	//Adds the object at the beginning of the vector
	void AddToInventory(Capsule item)
	{
		inventory.push_back(item);
	}

	//Method that shows in console all the items inside of the vector
	bool Showinventory()
	{
		if (inventory.size() < 1)
		{
			std::cout << "You dont have any item in your inventory" << std::endl;
			std::cout << "PRESS ENTER TO GO BACK TO THE MENU" << std::endl;
            std::cin.get();
            return false;
		}
		else
		{
			for (int i = 0; i < inventory.size(); i++)
			{
                std::cout << "------" << i + 1<< "------\n";
				inventory[i].CapsuleSortedData();
			}
			return true;
		}
	}

    Capsule GetCapsuleFromInventory(int selection)
    {
        return inventory[selection - 1];
    }

	//Gets the vectors size
	int GetInventorySize()
	{
		return inventory.size();
	}

	//This method increases stamina value every time is called
	void RecoverStamina()
	{
		if (Stamina != 4)
		{
			Stamina = Stamina + 1;
		}
	}

	//This method decreases Dodge value every time is called for game narrative
	void Dodge()
	{   
		if (Stamina >= 2)
		{
			Stamina = Stamina - 2;
		}
	}

	//This method prints into the console the value of Stamina and returns its value too;
	int GetStamina()
	{
		std::cout << "Stamina: " << Stamina << "\n";

		return Stamina;
	}

	//This method helps me to decrease Lifes Value
	void LoseLife(int Value)
	{
		if (Value > Life)
		{
			Value = Life;
		}
		
		Life = Life - Value;

		std::cout << "Life left: " << Life << "\n";
	}

	//This method prints Lifes Value into the console
	void PrintLife()
	{
		std::cout << "Life: " << Life << "\n";;
	}

	//This method gives to me the value of Life
	int GetLife()
	{
		return Life;
	}

    void SetLife(int value)
    {
        Life = value;
    }
	//This method helps me to decrease the value of Ki
	void LoseKi(int Value)
	{
		if (Value <= Ki)
		{
			Ki = Ki - Value;
		}
		
	}
	//This method prints in the console the value of Ki
	void PrintKi()
	{
		std::cout << "Ki: " << Ki << "\n";
	}

	//This method helps to me to control the value of Ki to increase it
	void RecoverKi(int Value)
	{
		Ki = Ki + Value;    
	}


	//This method gives to me the value of Ki
	int GetKi()
	{
		return Ki;
	}

    void HealCharacter(int value)
    {
        if (value == 100)
        {
            Life = 100;
        }
        
        Life += value;
    }

    void UseCapsule(Capsule Capsule)
    {
        if (Capsule.GetCapsuleType() == "Healing")
        {
            HealCharacter(Capsule.GetCapsuleValue());
        }
        else if (Capsule.GetCapsuleType() == "Energy")
        {
            RecoverKi(Capsule.GetCapsuleValue());
        }
        
    }

    //Method use to delete an item form the inventory
    void DeleteItem(int index)
    {
        inventory.erase(inventory.begin() + index);
    }

    int GetZeni()
    {
        return Zeni;
    }

    void UseZeni(int value)
    {
        Zeni -= value;
    }

    void LevelUp(int value)
    {
        Experience += value;
        if(Experience >= Level * 100)
        {
            Level++;
        }
    }

    int GetLevel()
    {
        return Level;
    }

    void GainZeni(int value)
    {
        Zeni += value;
    }

};

class Enemy : public Character
{


    public:
        Enemy(int initialLife, int initialKi, int initialStamina) 
            : Character(initialLife, initialKi, initialStamina)
        {
        }
        
        void EnemyPowerUp()
        {
            Level++;
            Life += 30;
            Ki += 2;
        }
};

class Store
{
private:
    std::vector<Capsule> capsulesInStore;
    std::vector<int>     amountOfCapsules;
    std::vector<int>     priceOfCapsules;
    std::vector<Capsule> selectedCapsules;
    std::vector<int>     selectedCapsulesAmount;
    std::vector<int>     selectedCapsulesPrice;

public:

    void AddCapsule(Capsule capsule, int amount, int price)
    {
        capsulesInStore.push_back(capsule);
        amountOfCapsules.push_back(amount);
        priceOfCapsules.push_back(price);
    }

    //Method called by BuyCapsule() to decrease the amount of capsules or delete them from the store
    void DeleteCapsule(std::string selected, Character& player)
    {
        for (int j = 0; j < (int)capsulesInStore.size(); j++)
        {
            if (capsulesInStore[j].GetCapsuleName() == selected)
            {
                player.AddToInventory(capsulesInStore[j]);

                if (amountOfCapsules[j] > 1)
                {
                    amountOfCapsules[j]--;
                }
                else
                {
                    capsulesInStore.erase(capsulesInStore.begin() + j);
                    amountOfCapsules.erase(amountOfCapsules.begin() + j);
                    priceOfCapsules.erase(priceOfCapsules.begin() + j);
                }
                break;
            }
        }
    }

    //Method to show the capsules that can be bought
    void ShowCapsulesInStore(int optionSelected)
    {
        std::string typeFilter;
        switch (optionSelected)
        {
            case 1: typeFilter = "Healing"; break;
            case 2: typeFilter = "Energy";  break;
            default: break;
        }

        selectedCapsules.clear();
        selectedCapsulesAmount.clear();
        selectedCapsulesPrice.clear();

        for (int i = 0; i < (int)capsulesInStore.size(); i++)
        {
            if (capsulesInStore[i].GetCapsuleType() == typeFilter)
            {
                selectedCapsules.push_back(capsulesInStore[i]);
                selectedCapsulesAmount.push_back(amountOfCapsules[i]);
                selectedCapsulesPrice.push_back(priceOfCapsules[i]);
            }
        }

        //If it did not find any capsule with that category
        if (selectedCapsules.empty())
        {
            std::cout << "There is no capsule of that category in stock\n";
        }
        //If it did find a capsule of that category
        else
        {
            for (int i = 0; i < (int)selectedCapsules.size(); i++)
            {
                std::cout << "--------------------" << i + 1 << "---------------------\n";
                selectedCapsules[i].CapsuleSortedData();
                std::cout << "Amount: " << selectedCapsulesAmount[i] << "\n";
                std::cout << "Price: "  << selectedCapsulesPrice[i]  << " Zeni\n";
            }
        }
    }

    //Method to buy the capsules and add them to the players inventory
    void BuyCapsule(Character& player)
    {
        system("cls");
        if (capsulesInStore.empty())
        {
            std::cout << "There is no capsules to buy at this moment" << std::endl;
            std::cin.get();
            std::cout << "PRESS ENTER TO GO BACK TO THE MENU" << std::endl;
            system("cls");
        }
        else
        {
            //Store logic
            while (true)
            {
                std::cout << "-------------------------------Store-------------------------------" << std::endl;
                std::cout << "Your Zeni: " << player.GetZeni() << "\n\n";
                int options = 0;
                while (true)
                {
                    std::cout << "Which Categories do u want to see" << std::endl;
                    std::cout << "1.Healing" << std::endl;
                    std::cout << "2.Energy" << std::endl;
                    std::cin >> options;
                    std::cin.ignore();

                    if (options > 2 || options <= 0)
                    {
                        system("cls");
                        std::cout << "You did not input a valid option" << std::endl;
                        std::cout << "PRESS ENTER TO RETRY" << std::endl;
                        std::cin.clear();
                        std::cin.ignore();
                        system("cls");
                    }
                    else
                    {
                        break;
                    }
                    if (std::cin.fail())
                    {
                        system("cls");
                        std::cout << "You did not input a valid option" << std::endl;
                        std::cout << "PRESS ENTER TO RETRY" << std::endl;
                        std::cin.clear();
                        std::cin.ignore();
                    }
                }
                ShowCapsulesInStore(options);
                std::cout << std::endl;
                std::cout << "INPUT 0 TO GET OUT OF THE STORE" << std::endl;
                std::cin >> options;
                std::cin.ignore();
                //If in valid input
                if (std::cin.fail())
                {
                    system("cls");
                    std::cout << "You did not input a valid option" << std::endl;
                    std::cout << "PRESS ENTER TO RETRY" << std::endl;
                    std::cin.clear();
                    std::cin.ignore();
                }
                else
                {
                    //Statement to get out of the menu Store
                    if (options == 0)
                    {
                        system("cls");
                        selectedCapsules.clear();
                        selectedCapsulesAmount.clear();
                        selectedCapsulesPrice.clear();
                        break;
                    }
                    else
                    {
                        //If the user input a Non-valid value
                        if (options > selectedCapsules.size())
                        {
                            std::cout << "You did not input a valid option" << std::endl;
                            std::cin.get();
                            std::cout << "PRESS ENTER TO RETRY" << std::endl;
                            system("cls");
                        }
                        //If does not have enough zeni
                        else if (player.GetZeni() < selectedCapsulesPrice[options - 1])
                        {
                            std::cout << "Not enough Zeni, please buy another capsule" << std::endl;
                            selectedCapsules.clear();
                            selectedCapsulesAmount.clear();
                            selectedCapsulesPrice.clear();
                            std::cin.get();
                            std::cout << "PRESS ENTER TO RETRY" << std::endl;
                            system("cls");
                        }
                        //If does have enough zeni
                        else if (player.GetZeni() >= selectedCapsulesPrice[options - 1])
                        {
                            system("cls");
                            std::cout << "You have bought 1 capsule of " << selectedCapsules[options - 1].GetCapsuleName() << std::endl;
                            player.UseZeni(selectedCapsulesPrice[options - 1]);
                            DeleteCapsule(selectedCapsules[options - 1].GetCapsuleName(), player);
                            selectedCapsules.clear();
                            selectedCapsulesAmount.clear();
                            selectedCapsulesPrice.clear();
                            std::cout << "PRESS ENTER TO GO BACK TO THE MENU" << std::endl;
                            std::cin.get();
                            system("cls");
                        }
                    }
                }
            }
        }
    }
};

//Player is an object from the class "Character" used for modify player stadistics
Character Player(100, 4, 4);
Enemy Cooler(180, 5, 5);
Store CapsuleStore;
// These variables are used to determine which direction the game will play
int Decision = 0;
int Race = 0;
//This Variable helps me to keep every text typed in this code, specifically to not lose the actual Case
std::string textVariable;

//This function simulates the way text boxes work in a video game and saves a few lines of code
void TextBox(std::string text)
{
    std::cout << text << "\n"; 
}

//This function is being used to represent the action options within the game
void SpecialTextBox(std::string text)
{
    std::cout << "|-------------------------------|\n";
    std::cout << text << "\n";
}

//This function sets the selected character apart from checking if the player actually selects a playable character
void CharacterSelection()
{
    bool Loop = true;
    while (Loop)
    {
        system("cls");
        TextBox("Choose your Character");
        SpecialTextBox("1-Saiyan");
        SpecialTextBox("2-Namekian");
        SpecialTextBox("3-Freezer Race");
        std::cin >> Race;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            system("cls");
        }
        
        if (Race <= 0 || Race >= 4)
        {
            system("cls");
            TextBox("You have not chosen any character");
            std::cin.ignore();
            std::cin.get();
        }
        
        if (Race > 0 && Race < 4)
        {
            Loop = false;
        }

    }
    
}

//This function shows to the player how to play
void Instructions()
{
    system("cls");
    SpecialTextBox("INSTRUCTIONS");
    TextBox("To play this game you will see a menu like this to select some options.");
    TextBox("To select an option, type on your keyboard only the number indicated on the left side of the option. If you type a number that is not within the options, it will be automatically rejected.");
    SpecialTextBox("1-(Example)");
    SpecialTextBox("2-(Example)");
    SpecialTextBox("3-(Example)");
    std::cin.get();
    std::cout << "//Press Enter to Continue//\n";
    system("cls");
    TextBox("To use the inventory you just need to input the value that is above the capsule name like in this example");
    TextBox("--- INVENTORY ---");
    std:: cout << "\n";
    TextBox("--- 1 ---");
    std::cout << "Capsule: " << "(Example\n";
	std::cout << "Type: " << "(Example)\n";
	std::cout << "Value: " << "(Example)\n";
    std:: cout << "\n";
    TextBox("In this example you will 1 to use that capsule");
    std::cin.get();
    std::cout << "//Press Enter to Continue//\n";

}

//Function that lets the player use its inventory
void OpenInventory(Character &targetPlayer)
{
    bool inInventory = true;

    while (inInventory)
    {
        system("cls");
        TextBox("--- INVENTORY ---");
        
        if (targetPlayer.GetInventorySize() == 0) {
            TextBox("Your inventory is empty.");
            TextBox("0- Go back");
        } else {
            targetPlayer.Showinventory();
            TextBox("0- Go back");
            std::cout << "Select a capsule to use: ";
        }

        int itemChoice;
        std::cin >> itemChoice;
        if (std::cin.fail()) 
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        if (itemChoice == 0) {
            inInventory = false;
        }
        else if (itemChoice > 0 && itemChoice <= targetPlayer.GetInventorySize())
        {
            Capsule selected = targetPlayer.GetCapsuleFromInventory(itemChoice);
            targetPlayer.UseCapsule(selected);
            std::cout << "\n>>> You used: " << selected.GetCapsuleName() << " <<<\n";
            targetPlayer.DeleteItem(itemChoice - 1);
            std::cout << "//Press Enter to Continue//\n";
            std::cin.ignore();
            std::cin.get();
        }
        else
        {
            TextBox("You input a non-valid option");
            std::cin.ignore();
            std::cin.get();
        }
    }
}

//This function automates the way of the selection boxes for actions are structured and its parameter is to keep the actual context of the game.
void CombatDecision(std::string text)
{
    bool Loop = true;
    while (Loop)
    {
        system("cls");
        Player.PrintLife();
        Player.PrintKi();
        Player.GetStamina();
        std::cout << "Player Level: " << Player.GetLevel() << "\n\n";
        std::cout << "Cooler's Life: " << Cooler.GetLife() << "\n\n";
        std::cout << "Cooler's Level: " << Cooler.GetLevel() << "\n\n";
        
        TextBox(text);
        TextBox("What do you want to do?");
        SpecialTextBox("1-Attack");
        SpecialTextBox("2-Attack from a distance");
        SpecialTextBox("3-Dodge");
        SpecialTextBox("4-Charge Ki");
        SpecialTextBox("5-Inventory");
        SpecialTextBox("6-Exit game");

        std::cin >> Decision;

        if (Decision == 5)
        {
            OpenInventory(Player);
        }
        

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            system("cls");
        }
        if (Decision <= 0 || Decision >= 7)
        {
            system("cls");
            TextBox("You have not selected any option");
            std::cin.ignore();
            std::cin.get();
        }
        else
        {
            Loop = false;
        }
    }
    system("cls");

}

//This function is called for the end of the story, specifically for special endings
void FinalDecision(std::string text)
{
    bool Loop = true;
    while (Loop)
    {
        system("cls");
        Player.PrintLife();
        Player.PrintKi();
        Player.GetStamina();
        
        TextBox(text);
        TextBox("What will you do?");
        SpecialTextBox("1-Combo Attack");
        SpecialTextBox("2-Super Ki Attack");
        SpecialTextBox("3-Sun");
        SpecialTextBox("4-Exit game");

        std::cin >> Decision;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            system("cls");
        }
        if (Decision <= 0 || Decision >= 6)
        {
            system("cls");
            TextBox("You have not selected any option");
            std::cin.ignore();
            std::cin.get();
        }
        else
        {
            Loop = false;
        }
    }
    system("cls");

}

void AttackScene1()
{
    // Attack SCENE #1

    textVariable = "Cooler lunges at you looking to connect a blow!!!!!";
    CombatDecision(textVariable);
    switch (Decision)
    {
    case 1:
        TextBox("You also attacked him, exchanging blows with great aggressiveness, causing a great damage to him, but also a little of damage to you.....");
        Player.LoseLife(25);
        Cooler.LoseLife(35);
        break;
    case 2:

        TextBox("You tried to launch ki blast at Cooler, but that was not enough to make him step back, causing Cooler to punch you in the face, sending you at a bunch of rocks, causing great damage");
        Player.LoseLife(30);
        Player.LoseKi(2);
        Player.PrintKi();
        break;
    case 3:
        TextBox("Cooler tried to punch you, but you dodge it to attack him from behind");
        Player.Dodge();
        break;
    case 4:
        TextBox("You made yourself stronger than before making your Ki go up, but same time making Cooler angrier");
        Player.RecoverKi(10);
        Player.PrintKi();
        break;

    case 6:
        exit(0);
        break;
    }
    std::cout << "//Press Enter to Continue//\n";
    std::cin.ignore();
    std::cin.get();
}

void CinematicScene1()
{
        
        //Cinematic SCENE #1

    switch (Decision)
    {
    case 1:
        textVariable = "Just for a moment you escape from Cooler to rest just a moment, but Cooler finds you and wants to Connect another attack!!!";
        TextBox(textVariable);
        break;
    case 2:
        textVariable = "You get recover from the attack and watch that Cooler wants to Keep punchin you!!";
        TextBox(textVariable);
        break;
    case 3:
        textVariable = "You Keep punching Cooler, but then Cooler Dodges one of your attacks and tries to punch you!!!";
        TextBox(textVariable);
        break;
    case 4:
        textVariable = "Cooler is getting closer to you!!!";
        TextBox(textVariable);
        break;
    case 6:
        exit(0);
        break;
    }
}

void AttackScene2()
{
        //Attack SCENE #2

    CombatDecision(textVariable);
    system("cls");

    switch (Decision)
    {
    case 1:
        textVariable = "You attacked him aswell, for luck you connect more hits than him, causing great damage to him!!!";
        TextBox(textVariable);
        Player.LoseLife(20);
        Cooler.LoseLife(40);
        Player.RecoverStamina();
        break;
    case 2:
        textVariable = "That is not effective on him, which causes him to keep hitting you, causing more damage.";
        TextBox(textVariable);
        Player.LoseLife(25);
        Player.LoseKi(2);
        Player.PrintKi();
        Player.RecoverStamina();
        break;
    case 3:
        textVariable = "You dodge him again to keep punching him";
        TextBox(textVariable);
        Player.Dodge();
        break;
    case 4:
        textVariable = "You decided to keep charging Ki causing that Cooler can punch you directly on the face, causing great damage";
        TextBox(textVariable);
        Player.RecoverKi(10);
        Player.PrintKi();
        Player.LoseLife(15);
        break;
    case 6:
        exit(0);
        break;
    }
    std::cout << "//Press Enter to Continue//\n";
    std::cin.ignore();
    std::cin.get();
    system("cls");
}

void CinematicScene2()
{
        //Cinematic SCENE #2

    switch (Decision)
    {
    case 1:   
        textVariable = "Cooler increases its power even further beyond decided to Kill you and he goes right to your position!!!";
        TextBox(textVariable);
        break;
    case 2:
        textVariable = "You get recover from the attack and watch that Cooler wants to Keep punchin you!!";
        TextBox(textVariable);
        break;
    case 3:
        textVariable = "You Keep punching Cooler, but then Cooler Dodges one of your attacks and tries to punch you again!!!";
        TextBox(textVariable);
        break;
    case 4:
        textVariable = "Cooler is getting closer to you to attack again!!!";
        TextBox(textVariable);
        break;
    case 6:
        exit(0);
        break;
    }
}

void AttackScene3()
{
    //Attack SCENE #3

    CombatDecision(textVariable);
    system("cls");

    switch (Decision)
    {
    case 1:
        textVariable = "You Keep attacking causing more damage, but causing a great damage to you!!!";
        TextBox(textVariable);
        Player.LoseLife(25);
        Cooler.LoseLife(45);
        Player.RecoverStamina();
        break;
    case 2:
        
        if (Player.GetKi() >= 15 )
        {
            textVariable = "You charged a great Ki attack causing great great damage against him";
            TextBox(textVariable);
            Player.LoseKi(15);
            Cooler.LoseLife(50);
            Player.PrintKi();
        }
        else if (Player.GetKi() >= 10 )
        {
            textVariable = "You charged a Ki attack causing great damage against him";
            TextBox(textVariable);
            Player.LoseKi(10);
            Cooler.LoseLife(35);
            Player.PrintKi();
        }
        else if (Player.GetKi() < 10)
        {
            textVariable = "You had not enough Ki to attack him so he punched again....";
            TextBox(textVariable);
            Player.LoseLife(20);
            Player.PrintKi();
            Player.RecoverStamina();
        }

        break;
    case 3:
        textVariable = "You dodge him again";
        TextBox(textVariable);
        Player.Dodge();
        break;
    case 4:
        textVariable = "You decided to charge Ki causing that Cooler can punch you directly on the face, causing great damage";
        TextBox(textVariable);
        Player.LoseLife(25);
        Player.RecoverKi(15);
        break;
    case 6:
        exit(0);
        break;
    }
    std::cout << "//Press Enter to Continue//\n";
    std::cin.ignore();
    std::cin.get();
    system("cls");
}

void CinematicScene3()
{
    //Cinematic SCENE #3

    switch (Decision)
    {
    case 1:   
        textVariable = "Cooler is getting tired of it, so he is disposed to destroy you with a powerfull attack!!!";
        TextBox(textVariable);
        break;
    case 2:
        textVariable = "Cooler is very mad at you and its disposed to destroy the planet only for kill you!!";
        TextBox(textVariable);
        break;
    case 3:
        
        textVariable = "Cooler gets angrier and increases its speed so you cant dodge him causing you a lot of damage";
        TextBox(textVariable);
        Player.LoseLife(20);
        break;

    case 4:
        textVariable = "Cooler Laughs at you and starts to creating a powerfull attack!!!";
        TextBox(textVariable);
        break;
    case 6:
        exit(0);
        break;
    }
    std::cout << "//Press Enter to Continue//\n";
    std::cin.get();
    system("cls");
}

void HandleEnding()
{
    // Final SCENE
    
    //Good Ending
    if (Player.GetLife() >= 45 && Cooler.GetLife() <= 0)
    {
        textVariable = "Cooler was trying to charge his super attack when you managed to attack him from behind sending him to the center of the planet where he dies disintegrated";
        TextBox(textVariable);
        std::cout << "//Press Enter to Continue//\n";
        std::cin.get();

        system("COLOR 0F");
        textVariable = "Thanks to you the time line is safe again helping Goku with Freezers brother and dont let him destroy the time line";
        TextBox(textVariable);
        std::cout << "//Press Enter to Continue//\n";
        std::cin.get();
        Player.LevelUp(50);
        Player.GainZeni(200);
    }
    //Special Endings
    else if (Player.GetLife() >= 35 && Player.GetLife() < 45 && Cooler.GetLife() <= 0) //Final Saiyan Race
    {
        if (Race == 1)
        {
            textVariable = "Somenthing deep inside of you starts to burn feeling so angry and you start to feeling stronger, a Golden aura starts to surround you....";
            TextBox(textVariable);
            std::cout << "//Press Enter to Continue//\n";
            std::cin.get();
            system("cls");
            system("COLOR 0E");
            textVariable = "You Transformed into a Super Saiyan!!!!";
            TextBox(textVariable);
            std::cout << "//Press Enter to Continue//\n";
            std::cin.get();
            system("cls");
            textVariable = "Cooler and Freezer looked at you terrified, the only thin you can think is destroy Cooler";
            TextBox(textVariable);
            std::cout << "//Press Enter to Continue//\n";
            std::cin.get();
            system("cls");
            textVariable = "This will be your final attack";
            FinalDecision(textVariable);
            switch (Decision)
            {
            case 1:   
                textVariable = "You attacked Cooler before he could launch its attack, with no mercy, you maked him fall to its dead inside of the planet";
                TextBox(textVariable);
                break;
            case 2:
                textVariable = "You charged a powerfull Kamehameha making the SuperNova of Cooler get back to him, eliminating him in the process";
                TextBox(textVariable);
                break;
            case 3:
                
                textVariable = "You attacked Cooler causing cancel its attack and you make him fly away, taking the oportunity to charge a Kamehameha and send him at the Sun";
                TextBox(textVariable);
                break;

            case 4:
                exit(0);
                break;
            }
            std::cout << "//Press Enter to Continue//\n";
            std::cin.ignore();
            std::cin.get();
            Player.GainZeni(300);
            system("cls");
        }
        else if (Race == 2) //Final Namekian Race
        {
            textVariable = "Somenthing deep inside of you starts to burn feeling so angry and you start to feeling stronger, aura starts to surround you....";
            TextBox(textVariable);
            std::cout << "//Press Enter to Continue//\n";
            std::cin.get();
            system("cls");
            system("COLOR 0C");
            textVariable = "You power has increased!!!";
            TextBox(textVariable);
            std::cout << "//Press Enter to Continue//\n";
            std::cin.get();
            system("cls");
            textVariable = "Cooler and Freezer looked at you terrified, the only thin you can think is destroy Cooler";
            TextBox(textVariable);
            std::cout << "//Press Enter to Continue//\n";
            std::cin.get();
            system("cls");
            textVariable = "This will be your final attack";
            FinalDecision(textVariable);
            switch (Decision)
            {
            case 1:   
                textVariable = "You attacked Cooler before he could launch its attack making him fly away into a portal";
                TextBox(textVariable);
                break;
            case 2:
                textVariable = "You charged a powerfull attack making the SuperNova of Cooler get back to him, eliminating him in the process";
                TextBox(textVariable);
                break;
            case 3:
                
                textVariable = "You attacked Cooler were way faster than Cooler to launch its attack, making Cooler fly away and crashing out against the sun";
                TextBox(textVariable);
                break;
            case 4:
                exit(0);
                break;
            }
            std::cout << "//Press Enter to Continue//\n";
            std::cin.ignore();
            std::cin.get();
            Player.GainZeni(300);
            system("cls");
        }
        else if (Race == 3) //Final Freezer Race
        {
            textVariable = "Somenthing deep inside of you starts to burn feeling so angry and you start to feeling stronger, aura starts to surround you....";
            TextBox(textVariable);
            std::cout << "//Press Enter to Continue//\n";
            std::cin.get();
            system("cls");
            system("COLOR 0D");
            textVariable = "You power has increased unmeasurely!!!";
            TextBox(textVariable);
            std::cout << "//Press Enter to Continue//\n";
            std::cin.get();
            system("cls");
            textVariable = "Cooler and Freezer looked at you terrified, the only thin you can think is destroy Cooler";
            TextBox(textVariable);
            std::cout << "//Press Enter to Continue//\n";
            std::cin.get();
            system("cls");
            textVariable = "This will be your final attack";
            FinalDecision(textVariable);
            switch (Decision)
            {
            case 1:   
                textVariable = "You did not let Cooler do anything against you, recieving multiple attacks until he disappeared";
                TextBox(textVariable);
                break;
            case 2:
                textVariable = "You charged a powerfull attack behind Coolers back making him get disintegrated";
                TextBox(textVariable);
                break;
            case 3:
                
                textVariable = "You Grabbed Cooler and started to fly into the space to making him fly away againts the sun and get disintegrated in the process";
                TextBox(textVariable);
                break;
            case 4:
                exit(0);
                break;
            }
            std::cout << "//Press Enter to Continue//\n";
            std::cin.ignore();
            std::cin.get();
            system("cls");
        }
        
        system("COLOR 0F");
        textVariable = "Thanks to you the time line is safe again helping Goku with Freezers brother and dont let him destroy the time line";
        Player.LevelUp(100);
        
        TextBox(textVariable);
        std::cout << "//Press Enter to Continue//\n";
        std::cin.get();
        Player.GainZeni(300);

    }
    //Bad Ending
    else if (Player.GetLife() < 35)
    {
        textVariable = "You tried everything you could to defeat him... But that was not enough... You lost against Cooler making him go stronger, making Goku lost against Freezer and his brother, corrupting the timeline....";
        TextBox(textVariable);
        Cooler.EnemyPowerUp();
        std::cout << "//Press Enter to Continue//\n";
        std::cin.get();
        Player.GainZeni(100);
    }

}

void AddCapsulesToStore()
{
    CapsuleStore.AddCapsule(Capsule("EnergyZ",1,100),2,300);
    CapsuleStore.AddCapsule(Capsule("EnergyM",1,25),5,100);
    CapsuleStore.AddCapsule(Capsule("MiniEnergy",1,10),8,40);
    CapsuleStore.AddCapsule(Capsule("PowerCapsule",2,3),3,150);
    CapsuleStore.AddCapsule(Capsule("KiBooster",2,5),3,200);
}

int main()
{
    AddCapsulesToStore();

    system("COLOR 0F");
    system("cls");
    TextBox("You are a time patroller whose duty is to prevent bad people from altering the main time line");
    TextBox("they called you to let you know that someone has broken into the sacred timeline in the year 762");
    TextBox("when you arrive at the place you get the surprise that Goku will not only face Freezer in the Namek fight");
    TextBox("his brother Cooler meets him ready to defeat him,");
    TextBox("however, it's not the only thing you notice...");
    std::cout << "\n";
    TextBox("You notice that Cooler and Freezer have an unusual increase in power.");
    TextBox("Your duty will be to help Goku defeat Cooler and weaken Freezer enough for Goku to defeat him.");
    std::cout << "\n";
    TextBox("But be careful if you make the mistake of not letting history fluctuate as it should, the consequences can be dire......");
    std::cout << "//Press Enter to Continue//\n";
    std::cin.get();
    Instructions();
    CharacterSelection();
    CapsuleStore.BuyCapsule(Player);
    system("cls");

    while (true)
    {
        while (Cooler.GetLife() > 0)
        {
            system("cls");
            AttackScene1();

            if (Cooler.GetLife() <= 0 || Player.GetLife() <= 0)
            {
                break;
            }

            system("cls");

            CinematicScene1();
            if (Cooler.GetLife() <= 0 || Player.GetLife() <= 0)
            {
                break;
            }

            AttackScene2();

            if (Cooler.GetLife() <= 0 || Player.GetLife() <= 0)
            {
                break;
            }
            CinematicScene2();

            if (Cooler.GetLife() <= 0 || Player.GetLife() <= 0)
            {
                break;
            }
            AttackScene3();

            if (Cooler.GetLife() <= 0 || Player.GetLife() <= 0)
            {
                break;
            }

            CinematicScene3();

        }
        
        HandleEnding();
        //This indicates the end of the game
        TextBox("Do you want to try again? Y = 1 / N = AnyValue");
        std::cin >> Decision;
        if (Decision == 1)
        {
            if (Player.GetLife() <= 0)
            {
                Player.SetLife(100);
            }
            else if ((Cooler.GetLife() <= 0))
            {
                Cooler.SetLife(180);
            }
            CapsuleStore.BuyCapsule(Player);
        }
        else
        {
            break;
        }
    }
    std::cin.get();
    
    return 0;
    
}