#include "Tank.h"
#include "bullet.h"
#include <iostream>
#include <stdlib.h>
myTank::myTank()//初始化我方坦克
{
	defense = 10;
	health = 10000;
	speed = 10;
	direction = up;
	cannon_direction = cannon_up;
	position.x = 600;
	position.y = 775;
}
void myTank::draw()//画出坦克
{
	rectangle(position.x - 25, position.y - 25, position.x + 25, position.y + 25);
	switch (cannon_direction)
	{
	case cannon_up:
		line(position.x, position.y, position.x, position.y - 45);
		break;
	case cannon_down:
		line(position.x, position.y, position.x, position.y + 45);
		break;
	case cannon_left:
		line(position.x, position.y, position.x - 45, position.y);
		break;
	case cannon_right:
		line(position.x, position.y, position.x + 45, position.y);
		break;
	}

}
void myTank::move()//坦克移动
{
	switch (direction)
	{
	case up:
		position.y -= speed;
		break;
	case down:
		position.y += speed;
		break;
	case left:
		position.x -= speed;
		break;
	case right:
		position.x += speed;
		break;
	}

}
enemy::enemy(int x,int y)//初始化敌方坦克
{
	defense = 10;
	num = 3;
	health = 100;
	speed = 1;
	direction = down;
	cannon_direction = cannon_down;
	position.x = x;
	position.y = y;
}
void enemy::draw() //画出敌方坦克
{
	rectangle(position.x - 25, position.y - 25, position.x + 25, position.y + 25);
	switch (cannon_direction)
	{
	case cannon_up:
		line(position.x, position.y, position.x, position.y - 45);
		break;
	case cannon_down:
		line(position.x, position.y, position.x, position.y + 45);
		break;
	case cannon_left:
		line(position.x, position.y, position.x - 45, position.y);
		break;
	case cannon_right:
		line(position.x, position.y, position.x + 45, position.y);
		break;
	}
}
void enemy::move()//敌方坦克移动
{

		switch (direction)
		{
		case up:
			position.y -= speed;
			break;
		case down:
			position.y += speed;
			break;
		case left:
			position.x -= speed;
			break;
		case right:
			position.x += speed;
			break;
	
		}
}
void enemy::aicontrol(myTank&mt)//敌方坦克AI控制
{
	if (mt.position.x >	position.x)
	{
		direction = right;
		cannon_direction = cannon_right;
	}
	else if (mt.position.x < position.x)
	{
		direction = left;
		cannon_direction = cannon_left;
	}
	else if (mt.position.y > position.y)
	{
		direction = down;
		cannon_direction = cannon_down;
	}
	else if (mt.position.y < position.y)
	{
		direction = up;
		cannon_direction = cannon_up;
	}

}
void healthjudge(std::vector<enemy>& enemies, int& num,myTank &mt)//判断坦克是否死亡
{
	bool live = false;
	for (auto it = enemies.begin(); it != enemies.end();)
	{
		if (it->health <= 0)
		{
			it = enemies.erase(it);
			if (num > 0)
			{
				live = true;
				--num;
			}
		}
		else
		{
			++it;
		}
	}
	if (live)
	{
		enemy new_enemy(rand()%3*575, 25);
		enemies.push_back(new_enemy);
	}
	if (num==0)
	{
		std::cout << "You win!" << std::endl;
		exit(0);
	}
	if (mt.health <= 0)
	{
		std::cout << "You lose!" << std::endl;
		exit(0);
	}

}

