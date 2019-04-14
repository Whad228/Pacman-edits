#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

#include <SFML/Graphics.hpp>

#define N 25 //numbers os quads
#define X 40 //lenght of side

int score = 0;
int fail = 0;
int diss = 0;
//#include "Character.h"
#ifndef Character_h
#define Character_h

class Character
{
protected:
    int r;
    double x;
    double y;
    int xi;
    int yi;
    int count;
    int mov;
    double vel;
public:
    virtual void draw(sf::RenderWindow* window) = 0;
};

#endif /* Character_h */

//#include "Map.h"
#ifndef Map_h
#define Map_h

int MAP0[N][N] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 9, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

//int MAP[N][N] = {
//    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
//    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
//    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
//    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
//    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
//    {1, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
//    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
//    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
//    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
//    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
//};

class Map
{
public:
    const int wall = 1, pass = 0;
    const int height = N, width = N;
    
    
    int** MAP1;
    
    
    int map[N][N];
    Map();
    void draw(sf::RenderWindow* window);
    
    void createmaze(int ) {
        
    }
    
    void mazemake(int height, int width){
        int x, y, c, a;
        //bool b;
        
        MAP1 = new int*[height];
        for(int i = 0; i < height; i++)
            MAP1[i] = new int[width];
        //
        for(int i = 0; i < height; i++) // ћассив заполн€етс€ ноликами
            for(int j = 0; j < width; j++)
                MAP1[i][j] = wall;
        //
        x = 3; y = 3; a = 0; // “очка начала и счетчик
        while(a < 10000){ // ???????костыль
            MAP1[y][x] = pass;
            a++;
            while(1){ // Ѕесконечный цикл, который прерываетс€ только тупиком
                c = rand()%4; //  алгоритм проходит
                switch(c){  // по две клетки в одном направлении за прыжок
                    case 0: if(y != 1)
                        if(MAP1[y-2][x] == wall){ // ¬верх
                            MAP1[y-1][x] = pass;
                            MAP1[y-2][x] = pass;
                            y-=2;
                        }
                    case 1: if(y != height-2)
                        if(MAP1[y+2][x] == wall){ // ¬низ
                            MAP1[y+1][x] = pass;
                            MAP1[y+2][x] = pass;
                            y+=2;
                        }
                    case 2: if(x != 1)
                        if(MAP1[y][x-2] == wall){ // Ќалево
                            MAP1[y][x-1] = pass;
                            MAP1[y][x-2] = pass;
                            x-=2;
                        }
                    case 3: if(x != width-2)
                        if(MAP1[y][x+2] == wall){ // Ќаправо
                            MAP1[y][x+1] = pass;
                            MAP1[y][x+2] = pass;
                            x+=2;
                        }
                }
                if(deadend(x,y,MAP1,height,width))
                    break;
            }
            
            if(deadend(x,y,MAP1,height,width)) // ¬ытаскиваем алгоритм из тупика
                do {
                    x = 2*(rand()%((width-1)/2))+1;
                    y = 2*(rand()%((height-1)/2))+1;
                }
            while(MAP1[y][x] != pass);
        }
        
    };
    
    
    bool deadend(int x, int y, int** maze, int height, int width){
        int a = 0;
        
        if(x != 1){
            if(maze[y][x-2] == pass)
                a+=1;
        }
        else a+=1;
        
        if(y != 1){
            if(maze[y-2][x] == pass)
                a+=1;
        }
        else a+=1;
        
        if(x != width-2){
            if(maze[y][x+2] == pass)
                a+=1;
        }
        else a+=1;
        
        if(y != height-2){
            if(maze[y+2][x] == pass)
                a+=1;
        }
        else a+=1;
        
        if(a == 4)
            return 1;
        else
            return 0;
    }
};



Map::Map()
{
    //int** MAP1 = mazemake(<#int height#>, <#int width#>);
    //    for(int i = 0; i < N; i++)
    //    {
    //        for(int j = 0; j < N; j++)
    //        {
    //            MAP1[i][j] = **(mazemake(height, width));
    //        }
    //    }
    
    
    mazemake(height,width);
    
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            MAP0[i][j] = MAP1[i][j];
            map[i][j] = MAP1[i][j];
        }
    }
}

void Map::draw(sf::RenderWindow* window)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(map[i][j] == 1)
            {
                sf::RectangleShape shape;
                shape.setSize(sf::Vector2f(X - 1, X - 1));
                shape.setFillColor(sf::Color::Blue);
                shape.setPosition(X*i, X*j);
                window -> draw(shape);
            }
        }
    }
}

#endif /* Map_h */


//#include "Dots.h"
#ifndef Dots_h
#define Dots_h

class Dots
{
    int map[N][N];
public:
    Dots();
    void draw(sf::RenderWindow* window);
    void check(int i, int j);
};

Dots::Dots()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            map[i][j] = MAP0[i][j];
        }
    }
}

void Dots::draw(sf::RenderWindow* window)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(map[i][j] == 0)
            {
                sf::CircleShape shape;
                shape.setRadius(4);
                shape.setFillColor(sf::Color::Yellow);
                shape.setPosition(X*i + X/2, X*j + X/2);
                shape.setOrigin(4, 4);
                window -> draw(shape);
            }
        }
    }
}

void Dots::check(int i, int j)
{
    if(map[i][j] == 0)
    {
        ++score;
        if(score == 188)
        {
            fail = -1;
        }
        map[i][j] = 2;
    }
}

#endif /* Dots_h */

//#include "Pacman.h"
#ifndef Pacman_h
#define Pacman_h

class Pacman : public Character
{
    Dots* dots;
    sf::Texture texture[2];
public:
    Pacman(Dots* _dots);
    int get_xi();
    int get_yi();
    int get_x();
    int get_y();
    void draw(sf::RenderWindow* window);
    void move_left(int* move);
    void move_down(int* move);
    void move_right(int* move);
    void move_up(int* move);
    void move(int* move);
};

Pacman::Pacman(Dots* _dots): dots(_dots)
{
    x = N*X/2;
    xi = (N - 1)/2;
    y = N*X/2;
    yi = (N - 1)/2;
    r = X/2;
    count = 100;
    texture[0].loadFromFile("res/pacman.jpg", sf::IntRect(0, 0, 225, 225));
    texture[1].loadFromFile("res/pacman.jpg", sf::IntRect(260, 0, 225, 225));
    mov = 0;
    vel = 0.4;
}
int Pacman::get_xi()
{
    return xi;
}
int Pacman::get_yi()
{
    return yi;
}
int Pacman::get_x()
{
    return x;
}
int Pacman::get_y()
{
    return y;
}
void Pacman::draw(sf::RenderWindow* window)
{
    sf::CircleShape shape;
    shape.setRadius(r);
    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition(x, y);
    shape.setOrigin(r, r);
    shape.setTexture(&texture[(count/40)%2]);
    shape.rotate(90*mov);
    window -> draw(shape);
}
void Pacman::move_left(int* move)
{
    if(count > 0)
    {
        x -= vel;
        --count;
    }
    else
    {
        --xi;
        count = 100;
        dots -> check(xi, yi);
        *move = 0;
    }
    
}
void Pacman::move_down(int* move)
{
    if(count > 0)
    {
        y += vel;
        --count;
    }
    else
    {
        ++yi;
        count = 100;
        dots -> check(xi, yi);
        *move = 0;
    }
    
}
void Pacman::move_right(int* move)
{
    if(count > 0)
    {
        x += vel;
        --count;
    }
    else
    {
        ++xi;
        count = 100;
        dots -> check(xi, yi);
        *move = 0;
    }
    
}
void Pacman::move_up(int* move)
{
    if(count > 0)
    {
        y -= vel;
        --count;
    }
    else
    {
        --yi;
        count = 100;
        dots -> check(xi, yi);
        *move = 0;
    }
    
}
void Pacman::move(int* move)
{
    mov = *move;
    switch (*move) {
        case 2:
            if(MAP0[xi - 1][yi] != 1)
            {
                move_left(move);
            }
            else
            {
                *move = 0;
            }
            break;
        case 1:
            if(MAP0[xi][yi + 1] != 1)
            {
                move_down(move);
            }
            else
            {
                *move = 0;
            }
            break;
        case 4:
            if(MAP0[xi + 1][yi] != 1)
            {
                move_right(move);
            }
            else
            {
                *move = 0;
            }
            break;
        case 3:
            if(MAP0[xi][yi - 1] != 1)
            {
                move_up(move);
            }
            else
            {
                *move = 0;
            }
            break;
            
        default:
            break;
    }
}

#endif /* Pacman_h */

//#include "Enemy.h"
#ifndef Enemy_h
#define Enemy_h
//class CleverMonster : public Character {
//    sf::Texture texture;
//public:
//    CleverMonster();
//    void init(int _xi, int _yi);
//    void draw(sf::RenderWindow* window);
//    void move_left();
//    void move_down();
//    void move_right();
//    void move_up();
//    void move(int p_xi, int p_yi);
//    void check_fail(double p_x, double p_y);
//};
//
//CleverMonster::CleverMonster() {
//    r = X/2;
//    count = 100;
//    mov = 0;
//    texture.loadFromFile("/Users/vadimsorokin/Documents/pacman/res/ghost.jpeg", sf::IntRect(0, 0, 500, 500));
//}

class Enemy : public Character
{
private:
    //int ans[];
    int disgrace;
    bool looking();
    int pifagor(int p_xi, int p_yi, int dx, int dy);
    void move_left();
    void move_down();
    void move_right();
    void move_up();
    bool move_simple(int dr);
    sf::Texture texture1;
    sf::Texture texture2;
public:
    Enemy();
    int good_way(int p_xi, int p_yi, int n);
    void init(int _xi, int _yi);
    void draw(sf::RenderWindow* window);
    void move(int p_xi, int p_yi);
    void check_fail(double p_x, double p_y);
    
    void make_disgrace()
    {
        disgrace = 1000;
    }
};

Enemy::Enemy()
{
    r = X/2;
    count = 100;
    mov = 20;
    texture1.loadFromFile("res/ghost.jpeg", sf::IntRect(0, 0, 500, 500));
    texture2.loadFromFile("res/ghost2.jpeg", sf::IntRect(0, 0, 500, 500));
    disgrace = 0;
}
void Enemy::init(int _xi, int _yi)
{
    x = _xi*X + X/2;
    xi = _xi;
    y = _yi*X + X/2;
    yi = _yi;
    
    count = 100;
    mov = 21;
}


void Enemy::draw(sf::RenderWindow* window)
{
    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(2*r, 2*r));
    //shape.setFillColor(sf::Color::Red);
    shape.setPosition(x, y);
    shape.setOrigin(r, r);
    if (disgrace == 0)
        shape.setTexture(&texture1);
    else
        shape.setTexture(&texture2);
    window -> draw(shape);
}

void Enemy::move_left()
{
    if(count > 0)
    {
        x -= 0.4;
        --count;
    }
    else
    {
        --xi;
        count = 100;
        mov += 20;
    }
    //cout<<"done";
    
}
void Enemy::move_down()
{
    if(count > 0)
    {
        y += 0.4;
        --count;
    }
    else
    {
        ++yi;
        count = 100;
        mov += 20;
    }
    
}
void Enemy::move_right()
{
    if(count > 0)
    {
        x += 0.4;
        --count;
    }
    else
    {
        ++xi;
        count = 100;
        mov += 20;
    }
    
}
void Enemy::move_up()
{
    if(count > 0)
    {
        y -= 0.4;
        --count;
    }
    else
    {
        --yi;
        count = 100;
        mov += 20;
    }
    
}

bool Enemy::looking()
{
    bool rb = 1;
    if (((MAP0[xi - 1][yi] == 1) && (MAP0[xi + 1][yi] == 1)) && ((MAP0[xi][yi - 1] == 0) && (MAP0[xi][yi + 1] == 0))) rb = 0;
    if (((MAP0[xi - 1][yi] == 0) && (MAP0[xi + 1][yi] == 0)) && ((MAP0[xi][yi - 1] == 1) && (MAP0[xi][yi + 1] == 1))) rb = 0;
    return rb;
}

int Enemy::pifagor(int p_xi, int p_yi, int dx, int dy)
{
    int real_length;
    real_length = (p_xi - xi)*(p_xi - xi) + (p_yi - yi)*(p_yi - yi);
    int future_length;
    future_length = (p_xi - xi - dx)*(p_xi - xi - dx) + (p_yi - yi - dy)*(p_yi - yi - dy);
    return real_length - future_length;
}

int comp(const void *i, const void *j)
{
    return *(int*)i - *(int*)j;
}

int Enemy::good_way(int p_xi, int p_yi, int n)
{
    int dl = - 1e6;
    int ans[4];
    int pif[4];
    pif[0] =  pifagor(p_xi, p_yi, 0, - 1);
    pif[1] =  pifagor(p_xi, p_yi, 0,   1);
    pif[2] =  pifagor(p_xi, p_yi, 1,   0);
    pif[3] =  pifagor(p_xi, p_yi,-1,   0);
    
    for (int i = 0; i < 4; i ++)
        if (pif[i] > dl) {ans[0] = i + 1; dl = pif[i];}
    dl = - 1e6;
    for (int i = 0; i < 4; i ++)
        if ((pif[i] > dl) && (i != ans[0] - 1)) {ans[1] = i + 1; dl = pif[i];}
    dl = - 1e6;
    for (int i = 0; i < 4; i ++)
        if ((pif[i] > dl) && (i != ans[0] - 1) && (i != ans[1] - 1)) {ans[2] = i + 1; dl = pif[i];}
    dl = - 1e6;
    for (int i = 0; i < 4; i ++)
        if ((pif[i] > dl) && (i != ans[0] - 1) && (i != ans[1] - 1) && (i != ans[2] - 1)) {ans[3] = i + 1; dl = pif[i];}
    return ans[n];
}

bool Enemy::move_simple(int dr)
{
    bool ret = 0;
    if((dr == 1) && (MAP0[xi][yi - 1] != 1) && (MAP0[xi][yi - 1] != 9))
    {
        mov = 1;
        move_up();
        ret = 1;
    }
    if((dr == 2) && MAP0[xi][yi + 1] != 1 && MAP0[xi][yi + 1] != 9)
    {
        mov = 2;
        move_down();
        ret = 1;
    }
    if((dr == 3) && MAP0[xi + 1][yi] != 1 && MAP0[xi + 1][yi] != 9)
    {
        mov = 3;
        move_right();
        ret = 1;
    }
    if((dr == 4)  && MAP0[xi - 1][yi] != 1 && MAP0[xi - 1][yi] != 9)
    {
        mov = 4;
        move_left();
        ret = 1;
    }
    return ret;
    
}

void Enemy::move(int p_xi, int p_yi)
{
    if (disgrace == 0)
    {
        if (mov > 10)
        {
            if (looking() == 1)
            {
                bool a228 = 0;
                for (int i = 0; i < 4; i ++)
                    if (a228 == 0)
                    {
                        int gw = good_way(p_xi, p_yi, i);
                        a228 = move_simple(gw);
                    }
            }
            else
            {
                mov -= 10;
            }
        }
        else
        {
            switch (mov) {
                case 1:
                    move_up();
                    break;
                case 2:
                    move_down();
                    break;
                case 3:
                    move_right();
                    break;
                case 4:
                    move_left();
                    break;
                    
                default:
                    break;
            }
        }
    }
    else
    {
        disgrace--;
        if (mov > 10)
        {
            if (looking() == 1)
            {
                bool a228 = 0;
                while (a228 == 0)
                {
                    a228 = move_simple(rand()%4 + 1);
                }
            }
            else
            {
                mov -= 10;
            }
        }
        else
        {
            switch (mov) {
                case 1:
                    move_up();
                    break;
                case 2:
                    move_down();
                    break;
                case 3:
                    move_right();
                    break;
                case 4:
                    move_left();
                    break;
                    
                default:
                    break;
            }
        }
        
    }
}
void Enemy::check_fail(double p_x, double p_y)
{
    if(pow(p_x - x, 2) + pow(p_y - y, 2) < X*X/4)
    {
        if (disgrace == 0)
            fail = 1;
        else
            init((N - 1)/2, (N - 1)/2);
    }
}

#endif /* Enemy_h */


int main()
{
    srand((unsigned)time(NULL));
    sf::Clock clock;
    double time = 0;
    
    Map map;
    
    Dots dots;
    
    Pacman packman(&dots);
    int move = 0; // 1 - left, 2 - down, 3 - right, 4 - up
    
    int t50 = 0;
    int t100 = 0;
    int t150 = 0;
    
    int k = 2;
    Enemy enemy[5];
    enemy[0].init(1, 1);
    enemy[1].init(17, 17);
    
    sf::RenderWindow window(sf::VideoMode(X*N, X*N + 100), "Packman");
    
    sf::Font font;
    //    if (!font.loadFromFile("/Users/vadimsorokin/Documents/pacman/res/arial.ttf"))
    //    {
    //        return 1;
    //    }
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Blue);
    text.setPosition(X*N/2 - 100, X*N + 10);
    std::stringstream ss;
    
    while (window.isOpen())
    {
        sf::Event event;
        
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                    
                default:
                    break;
            }
        }
        
        if(move == 0)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                move = 2;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                move = 1;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                move = 4;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                move = 3;
            }
        }
        packman.move(&move);
        
        if(score >= 50 && t50 == 0)
        {
            t50 = 1;
            enemy[2].init((N - 1)/2, (N - 1)/2);
            ++k;
        }
        else if(score >= 100 && t100 == 0)
        {
            t100 = 1;
            enemy[3].init((N - 1)/2, (N - 1)/2);
            ++k;
        }
        else if(score >= 150 && t150 == 0)
        {
            t150 = 1;
            enemy[4].init((N - 1)/2, (N - 1)/2);
            ++k;
        }
        
        for(int i = 0; i < k; i++)
        {
            enemy[i].move(packman.get_xi(), packman.get_yi());
            enemy[i].check_fail(packman.get_x(), packman.get_y());
        }
        
        ss.str("");
        ss << "Score - " << score;
        text.setString(ss.str());
        
        window.clear();
        if(fail == 0)
        {
            dots.draw(&window);
            map.draw(&window);
            packman.draw(&window);
            for(int i = 0; i < k; i++)
            {
                enemy[i].draw(&window);
            }
            window.draw(text);
        }
        else if(fail == 1)
        {
            ss.str("");
            ss << "FAIL";
            text.setString(ss.str());
            window.draw(text);
            window.display();
            
            clock.restart();
            while(time < 1.0)
            {
                time = clock.getElapsedTime().asSeconds();
            }
            window.close();
            
        }
        else if(fail == -1)
        {
            ss.str("");
            ss << "WICTORY";
            text.setString(ss.str());
            window.draw(text);
            window.display();
            
            clock.restart();
            while(time < 3.0)
            {
                time = clock.getElapsedTime().asSeconds();
            }
            window.close();
        }
        window.display();
    }
    
    return 0;
}
