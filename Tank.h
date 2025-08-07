#pragma once
#include<graphics.h>
#include <iostream>
#include <vector>
#include <conio.h>
#include <stdlib.h>

struct tankwhere//坦克位置
{
	int x;
	int y;
};
enum dir
{
	up,
	down,
	left,
	right
};
enum cannon_dir
{
	cannon_up,
	cannon_down,
	cannon_left,
	cannon_right
};
class Tank//坦克类
{
public:
	int health;
	int defense;
	int speed;
	dir direction;
	struct tankwhere position;
	cannon_dir cannon_direction;
	virtual void draw() = 0;
	virtual void move() = 0;
	
};
class myTank :public Tank//我方坦克类
{
public:
	myTank();
	void draw() override;//画出坦克
	void move()override;//坦克移动
};
class enemy :public Tank//敌方坦克类
{
public:
	int num;
	enemy(int x,int y);
	void draw()  override;//画出敌方坦克
	void move()override;//敌方坦克移动
	void aicontrol(myTank&mt);//敌方坦克AI控制
	
	

};
void healthjudge(std::vector<enemy>& enemies, int& num,myTank&mt);//判断坦克是否死亡

