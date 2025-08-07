#include<graphics.h>
#include "Tank.h"
#include "bullet.h"
#include "block.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <stdlib.h>
#define WIDTH 1200
#define HEIGHT 800
int number = 8;

static void kbcontrol(myTank& t, std::vector<mybullet>& bullets)//控制坦克移动和开火，以及子弹的移动和消失
{
    if (_kbhit())
    {
        char ch = _getch();
        mybullet newBullet;
        switch (ch)
        {
        case 'w':
            t.direction = up;
            t.cannon_direction = cannon_up;
            t.move();
            break;
        case 's':
            t.direction = down;
            t.cannon_direction = cannon_down;
            t.move();
            break;
        case 'a':
            t.direction = left;
            t.cannon_direction = cannon_left;
            t.move();
            break;
        case 'd':
            t.direction = right;
            t.cannon_direction = cannon_right;
            t.move();
            break;
        case 'g':

            newBullet.bullet_position.x = t.position.x;
            newBullet.bullet_position.y = t.position.y;
            newBullet.bullet_direction = t.cannon_direction;
            bullets.push_back(newBullet);

            break;
        default:
            break;
        }
    }
    for (auto it = bullets.begin(); it != bullets.end();)//遍历子弹方法2
    {
        if (it->distance > it->range)
        {
            it = bullets.erase(it);
        }
        else
        {
            ++it;
        }
    }
   
}
//void aifire(enemy& en1, std::vector<enemybullet>& enemybullets)   //在这里也可以定义实现敌人子弹的移动和消失
int main()
{
    initgraph(WIDTH, HEIGHT, 1);//初始化窗口
    myTank player;
    enemy en1(600,25);
    enemy en2(25, 25);
    enemy en3(1175, 25);
    std::vector<enemybullet> enemybullets;
    std::vector<mybullet> bullets;
    std::vector<enemy>enemies;
    std::vector<block*> blocks;
	enemies.push_back(en1);
    enemies.push_back(en2);
    enemies.push_back(en3);
    initblocks(blocks);
    while (1)
    {
        BeginBatchDraw();
        kbcontrol(player, bullets);
        for (auto& bullet : bullets)
        {
           bullet.bullet_move();
        }
        aifire(enemies, enemybullets);
        
        for (auto& en : enemies)
        {
            en.move();
            en.draw();
            en.aicontrol(player);
           
        }
        healthjudge(enemies, number,player);
         hit(bullets,blocks,enemies,enemybullets,player);

        for (auto& new_en1_bullet : enemybullets)
        {
            new_en1_bullet.bullet_move();
        }
        
        FlushBatchDraw();
        Sleep(1);
        cleardevice();
        player.draw();

        block_draw(blocks);
        blockhealthjudge(blocks);
        for (auto& bullet : bullets)
        {
            bullet.bullet_draw();
        }
        for (auto& new_en1_bullet : enemybullets) // 绘制敌人子弹
        {
            new_en1_bullet.bullet_draw();
        }
    }
    closegraph();
    return 0;
}