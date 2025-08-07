#pragma once
#include <graphics.h>
#include "Tank.h"
#include "block.h"
#include <vector>
struct bulletwhere
{
	int x;
	int y;
};

class bullet//子弹抽象类
{
public:
	int speed;
	int damage;
	int range;
	int distance;
	bulletwhere bullet_position;
	cannon_dir bullet_direction; // 添加方向成员变量
	virtual void bullet_move() = 0;
	virtual void bullet_draw() = 0;
	//virtual void hit(std::vector<mybullet>& bullets) = 0;
};

class mybullet : public bullet//我的子弹
{
public:
	mybullet();
	
	void bullet_move() override;
	void bullet_draw() override;
	//void hit(std::vector<mybullet>& bullets, std::vector<block*>& blocks, std::vector<enemy>& enemies);
};

class enemybullet : public bullet//敌人的子弹
{
public:
	enemybullet();
	void bullet_draw() override;
	void bullet_move() override;
	//void hit(std::vector<enemybullet>& bullets) ;
};
void aifire(std::vector<enemy>&enemies, std::vector<enemybullet>& enemybullets);//敌人开火函数
void hit(std::vector<mybullet>& bullets, std::vector<block*>& blocks, std::vector<enemy>& enemies, 
	std::vector<enemybullet>& enemy_bullets, myTank& mt);//判断是否击中函数

