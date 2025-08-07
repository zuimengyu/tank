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

class bullet//�ӵ�������
{
public:
	int speed;
	int damage;
	int range;
	int distance;
	bulletwhere bullet_position;
	cannon_dir bullet_direction; // ��ӷ����Ա����
	virtual void bullet_move() = 0;
	virtual void bullet_draw() = 0;
	//virtual void hit(std::vector<mybullet>& bullets) = 0;
};

class mybullet : public bullet//�ҵ��ӵ�
{
public:
	mybullet();
	
	void bullet_move() override;
	void bullet_draw() override;
	//void hit(std::vector<mybullet>& bullets, std::vector<block*>& blocks, std::vector<enemy>& enemies);
};

class enemybullet : public bullet//���˵��ӵ�
{
public:
	enemybullet();
	void bullet_draw() override;
	void bullet_move() override;
	//void hit(std::vector<enemybullet>& bullets) ;
};
void aifire(std::vector<enemy>&enemies, std::vector<enemybullet>& enemybullets);//���˿�����
void hit(std::vector<mybullet>& bullets, std::vector<block*>& blocks, std::vector<enemy>& enemies, 
	std::vector<enemybullet>& enemy_bullets, myTank& mt);//�ж��Ƿ���к���

