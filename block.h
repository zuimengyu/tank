#pragma once
#include<graphics.h>
#include<vector>
class block
{
public:
	int x; 
	int y;
	int health;
	COLORREF color;
	virtual void draw() = 0;

};
class steel :public block
{
public:
	steel(int x,int y);
	void draw() override;
};
class brick :public block
{
public:
	brick(int x,int y);
	void draw() override;
};
class water :public block
{
public:
	water(int x,int y);
	void draw() override;
};
class grass :public block
{
public:
	grass(int x,int y);
	void draw() override;
};

void block_draw(std::vector<block*>& blocks);
void blockhealthjudge(std::vector<block*>& blocks);
void initblocks(std::vector<block*>& blocks);
