#include "bullet.h"
#include"Tank.h"
#include<vector>
mybullet::mybullet()
{
	speed = 10;
	damage = 10;
	range = 1000;
	distance = 0;
	bullet_position.x = 0;
	bullet_position.y = 0;
	bullet_direction = cannon_up;
}
void mybullet::bullet_move()
{
	switch (bullet_direction)
	{
	case cannon_up:
		bullet_position.y -= speed;
		break;
	case cannon_down:
		bullet_position.y += speed;
		break;
	case cannon_left:
		bullet_position.x -= speed;
		break;
	case cannon_right:
		bullet_position.x += speed;
		break;
	}
	distance = distance + speed;
}
void mybullet::bullet_draw()
{
	circle(bullet_position.x, bullet_position.y, 1);
}
void hit(std::vector<mybullet>& bullets, std::vector<block*>& blocks, std::vector<enemy>& enemies,
	std::vector<enemybullet>& enemy_bullets, myTank& mt)
{
	for(auto it=bullets.begin();it!=bullets.end();)
	{
		bool hit = false;
		for (auto &eblock:blocks)
		{
			if (it->bullet_position.x >= eblock->x && it->bullet_position.x <= eblock->x + 50 &&
				it->bullet_position.y >= eblock->y && it->bullet_position.y <= eblock->y + 50)
			{
				eblock->health -= it->damage;
				//if (block->health <= 0)
				//{
				//	blocks.erase(std::remove(blocks.begin(), blocks.end(), block), blocks.end());
				//	delete block;

				//}
				it=bullets.erase(it);
				hit = true;
				break;
			}
		}

		if (hit)
			continue;

		// 检查子弹与敌方坦克的碰撞
		for (auto& enemy : enemies)
		{
			if (it->bullet_position.x >= enemy.position.x - 25 && it->bullet_position.x <= enemy.position.x + 25 &&
				it->bullet_position.y >= enemy.position.y - 25 && it->bullet_position.y <= enemy.position.y + 25)
			{
				enemy.health -= it->damage;
				it = bullets.erase(it);
				
				hit = true;
				break;
			}
		}

		if (!hit)
		{
			++it;
		}
	}
	for (auto it = enemy_bullets.begin(); it != enemy_bullets.end();)
	{
		bool ehit = false;
		for (auto& eblock : blocks)
		{
			if (it->bullet_position.x >= eblock->x && it->bullet_position.x <= eblock->x + 50 &&
				it->bullet_position.y >= eblock->y && it->bullet_position.y <= eblock->y + 50)
			{
				eblock->health -= it->damage;
				//if (block->health <= 0)
				//{
				//	blocks.erase(std::remove(blocks.begin(), blocks.end(), block), blocks.end());
				//	delete block;

				//}
				it = enemy_bullets.erase(it);
				ehit = true;
				break;
			}
		}

		if (ehit)
			continue;

		// 检查子弹与敌方坦克的碰撞
		for (auto& enemy : enemies)
		{
			if (it->bullet_position.x >= mt.position.x - 25 && it->bullet_position.x <= mt.position.x + 25 &&
				it->bullet_position.y >= mt.position.y - 25 && it->bullet_position.y <= mt.position.y + 25)
			{
				mt.health -= it->damage;
				it = enemy_bullets.erase(it);

				ehit = true;
				break;
			}
		}

		if (!ehit)
		{
			++it;
		}
	}


}	

enemybullet::enemybullet()
{
	speed = 10;
	damage = 10;
	range = 1000;
	distance = 0;
	bullet_position.x = 0;
	bullet_position.y = 0;
	bullet_direction = cannon_down;
}
void enemybullet::bullet_draw()
{
	circle(bullet_position.x, bullet_position.y, 1);
}
void enemybullet::bullet_move()
{
	switch (bullet_direction)
	{
	case cannon_up:
		bullet_position.y -= speed;
		break;
	case cannon_down:
		bullet_position.y += speed;
		break;
	case cannon_left:
		bullet_position.x -= speed;
		break;
	case cannon_right:
		bullet_position.x += speed;
		break;
	}
	distance = distance + speed;
}

void aifire(std::vector<enemy>&enemies, std::vector<enemybullet>& enemybullets)
{
	if (rand() % 75 == 0)
	{
		for (auto& en1 : enemies)
		{
			enemybullet new_en1_bullet;
			new_en1_bullet.bullet_position.x = en1.position.x;
			new_en1_bullet.bullet_position.y = en1.position.y;
			new_en1_bullet.bullet_direction = en1.cannon_direction;
			enemybullets.push_back(new_en1_bullet);
		}
	}
	for (auto it = enemybullets.begin(); it != enemybullets.end();)
	{
		if (it->distance > it->range)
		{
			it = enemybullets.erase(it);
		}
		else
		{
			++it;
		}
	}
}
