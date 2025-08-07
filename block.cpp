#include "block.h"
#include <graphics.h>
#include <vector>
steel::steel(int x,int y)
{
	this->x = x;
	this->y = y;
	health = 100;
	color = RGB(255,255,255);
}
brick::brick(int x, int y)
{
	this->x = x;
	this->y = y;
	health = 50;
	color = RGB(255, 0, 0);
}
water::water(int x, int y)
{
	this->x = x;
	this->y = y;
	health = 10;
	color = RGB(0, 0, 255);
}
grass::grass(int x, int y)
{
	this->x = x;
	this->y = y;
	health = 1;
	color = RGB(0, 255, 0);
}
void steel::draw()
{
	setfillcolor(color);
	solidrectangle(x, y, x + 50, y + 50);
}
void brick::draw()
{
	setfillcolor(color);
	solidrectangle(x, y, x + 50, y + 50);
}
void water::draw()
{
	setfillcolor(color);
	solidrectangle(x, y, x + 50, y + 50);
}
void grass::draw()
{
	setfillcolor(color);
	solidrectangle(x, y, x + 50, y + 50);
}
void block_draw(std::vector<block*>&blocks)
{
	for (auto& eblocks : blocks)
	{
		eblocks->draw();


	}



}
void blockhealthjudge(std::vector<block*>& blocks)
{
	for (auto it = blocks.begin(); it != blocks.end();)
	{
		if ((*it)->health <= 0)
		{
			it = blocks.erase(it);
			
		}
		else
		{
			++it;
		}
	}
}
void initblocks(std::vector<block*>& blocks)//weiwancheng!!!!!!!!!!!!!!
{

	blocks.push_back(new steel(100, 100));
	blocks.push_back(new steel(200, 100));
	blocks.push_back(new steel(300, 100));
	blocks.push_back(new steel(400, 100));
	blocks.push_back(new steel(500, 100));
	blocks.push_back(new steel(600, 100));
	blocks.push_back(new steel(700, 100));
	blocks.push_back(new steel(800, 100));

	blocks.push_back(new brick(200, 200));
	blocks.push_back(new water(300, 300));
	blocks.push_back(new grass(400, 400));

}