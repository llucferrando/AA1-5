#include <cstdio>
#include <iostream>

enum class EnemyType
{
	zombie, vampire, witch
};

struct Enemy
{
	int hp;
	int mp;
	EnemyType type;
	bool operator ==(const Enemy& enemy); //Passar l'operador a la struct i ara  ho farem
	bool operator>(const Enemy& enemy);
	Enemy operator++(int); //POSTFIX
	Enemy& operator++(); //PREFIX
};
//Diferent
bool Enemy::operator==(const Enemy& enemy)
{
	return this->type == enemy.type && this->hp == enemy.hp;
}

bool Enemy::operator>(const Enemy& enemy)
{
	return this->hp > enemy.hp;
}

Enemy Enemy::operator++(int) //POSTFIX
{
	std::cout << "PostFIx operator" << std::endl;
	Enemy enemy2 = *this;
	this->hp++;
	return enemy2;
}





//ES NECESSITEN ELS DOS
bool operator==(const Enemy& enemy1, const Enemy& enemy2)
{
	return enemy1.type == enemy2.type && enemy1.hp == enemy2.hp && enemy1.mp == enemy2.mp;
}
bool operator>(const Enemy& enemy1, const Enemy& enemy2)
{
	return enemy1.hp > enemy2.hp;
}
bool operator<(const Enemy& enemy1, const Enemy& enemy2)
{
	return enemy1.hp < enemy2.hp;
}
bool operator>=(const Enemy& enemy1, const Enemy& enemy2)
{
	return enemy1.hp >= enemy2.hp;
}

Enemy operator++(Enemy& enemy, int)
{
	std::cout << "PostFix operator" << std::endl;
	Enemy enemy2 = enemy;
	enemy.hp++;
	return enemy2;
}
Enemy operator++(Enemy& enemy)
{
	std::cout << "PreFix operator" << std::endl;
	++enemy.hp;
	return enemy;
}


bool equalEnemies(EnemyType enemy1, EnemyType enemy2)
{
	if(enemy1 == enemy2)
	{
		return true;
	}
}

int main()
{
	Enemy enemy1;
	Enemy enemy2;

	enemy1.type = EnemyType::zombie;
	enemy2.type = EnemyType::zombie;
	enemy1.hp = 10;
	enemy2.hp = 20;
	enemy1.mp = 50;
	enemy2.mp = 50;

	/*if (enemy1 == enemy2)
	{
		std::cout << "Son iguales" << std::endl;
	}

	else if(enemy1 > enemy2)
	{
		std::cout << " E1 es mayor que E2" << std::endl;
	
	}
	else if (enemy1 < enemy2)
	{
		std::cout << " E1 es menor que E2" << std::endl;

	}
	else if (enemy1 > enemy2 || enemy1 == enemy2)
	{
		std::cout << " E1 es mayor o igual que E2" << std::endl;

	}*/
	/*
	//POSTFIX -> Print the value post assigned
	std::cout << enemy1.hp << std::endl;
	enemy2 = enemy1++;
	std::cout << enemy2.hp << std::endl;
	std::cout << enemy1.hp << std::endl;

	std::cout << "-------------------" << std::endl;
	//POSTFIX -> Print the value before assigned
	enemy2 = ++enemy1;
	std::cout << enemy2.hp << std::endl;
	std::cout << enemy1.hp << std::endl;
	*/

	if(enemy1 ==enemy2)
	{
		std::cout << "Enemies are equals" << std::endl;
	
	}
	else 
	{
		std::cout << "Enemies are not equals" << std::endl;
	}

}