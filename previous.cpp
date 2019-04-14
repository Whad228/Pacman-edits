#include <iostream>
#include <cmath>
#include <sstream>

#include <SFML/Graphics.hpp>

#define N 19 //numbers os quads
#define X 40 //lenght of side

int score = 0;
int fail = 0;

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


#ifndef Map_h
#define Map_h

int MAP[N][N] = {
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
    int map[N][N];
public:
    Map();
    void draw(sf::RenderWindow* window);
};

Map::Map()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            map[i][j] = MAP[i][j];
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
            map[i][j] = MAP[i][j];
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
            if(MAP[xi - 1][yi] != 1)
            {
                move_left(move);
            }
            else
            {
                *move = 0;
            }
            break;
        case 1:
            if(MAP[xi][yi + 1] != 1)
            {
                move_down(move);
            }
            else
            {
                *move = 0;
            }
            break;
        case 4:
            if(MAP[xi + 1][yi] != 1)
            {
                move_right(move);
            }
            else
            {
                *move = 0;
            }
            break;
        case 3:
            if(MAP[xi][yi - 1] != 1)
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

#ifndef Enemy_h
#define Enemy_h

class Enemy : public Character
{
    sf::Texture texture;
public:
    Enemy();
    void init(int _xi, int _yi);
    void draw(sf::RenderWindow* window);
    void move_left();
    void move_down();
    void move_right();
    void move_up();
    void move(int p_xi, int p_yi);
    void check_fail(double p_x, double p_y);
};

Enemy::Enemy()
{
    r = X/2;
    count = 100;
    mov = 0;
    texture.loadFromFile("res/ghost.jpeg", sf::IntRect(0, 0, 500, 500));
}
void Enemy::init(int _xi, int _yi)
{
    x = _xi*X + X/2;
    xi = _xi;
    y = _yi*X + X/2;
    yi = _yi;
}
void Enemy::draw(sf::RenderWindow* window)
{
    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(2*r, 2*r));
    //shape.setFillColor(sf::Color::Red);
    shape.setPosition(x, y);
    shape.setOrigin(r, r);
    shape.setTexture(&texture);
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
        mov = 0;
    }
    
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
        mov = 0;
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
        mov = 0;
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
        mov = 0;
    }
    
}
void Enemy::move(int p_xi, int p_yi)
{
    if(mov == 0)
    {
        if(p_yi - yi < 0 && MAP[xi][yi - 1] != 1)
        {
            mov = 1;
            move_up();
        }
        else if(p_yi - yi > 0 && MAP[xi][yi + 1] != 1)
        {
            mov = 2;
            move_down();
        }
        else if(p_xi - xi > 0 && MAP[xi + 1][yi] != 1)
        {
            mov = 3;
            move_right();
        }
        else if(p_xi - xi < 0 && MAP[xi - 1][yi] != 1)
        {
            mov = 4;
            move_left();
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
void Enemy::check_fail(double p_x, double p_y)
{
    if(pow(p_x - x, 2) + pow(p_y - y, 2) < X*X/4)
    {
        fail = 1;
    }
}

#endif /* Enemy_h */


int main()
{
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
    if (!font.loadFromFile("res/arial.ttf"))
    {
        return 1;
    }
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
    
    return EXIT_SUCCESS;
}


