#pragma once
#include<graphics.h>
#include <iostream>
#include <vector>
#include <conio.h>
#include <stdlib.h>

struct tankwhere//̹��λ��
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
class Tank//̹����
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
class myTank :public Tank//�ҷ�̹����
{
public:
	myTank();
	void draw() override;//����̹��
	void move()override;//̹���ƶ�
};
class enemy :public Tank//�з�̹����
{
public:
	int num;
	enemy(int x,int y);
	void draw()  override;//�����з�̹��
	void move()override;//�з�̹���ƶ�
	void aicontrol(myTank&mt);//�з�̹��AI����
	
	

};
void healthjudge(std::vector<enemy>& enemies, int& num,myTank&mt);//�ж�̹���Ƿ�����

