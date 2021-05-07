#include <iostream>
#include <string>
#include <cstring>

#define WORLDWIDTH 39
#define WORLDHEIGHT 20

#define CHAR_ALIVE 'O'
#define CHAR_DEAD ' '
#define ALIVE 1
#define DEAD 0

static int world[WORLDWIDTH][WORLDHEIGHT];
static int nextstates[WORLDWIDTH][WORLDHEIGHT];

char str_chr(std::string s);

class Sprite
{
    std::string name;
    int x, y;

public:
    Sprite();
    Sprite(std::string s);
    Sprite(int i, int j);
    Sprite(std::string s, int i, int j);

    void print()
    {
        std::cout << name << "\t: {" << x << ", " << y << "}" << std::endl;
    }

    void set_state()
    {
        nextstates[x][y] = ALIVE;
    }
};

Sprite::Sprite()
{
    name = "!";
    x = 10;
    y = 10;
}
Sprite::Sprite(std::string s)
{
    name = s;
    x = 0;
    y = 0;
}
Sprite::Sprite(int i, int j)
{
    name = "?";
    x = i;
    y = j;
}
Sprite::Sprite(std::string s, int i, int j)
{
    name = s;
    x = i;
    y = j;
}

void initialize_world()
{
    int i, j;

    for (i = 0; i < WORLDWIDTH; i++)
    {
        for (j = 0; j < WORLDHEIGHT; j++)
        {
            world[i][j] = nextstates[i][j] = DEAD;
        }
    }
}

void set_next_state()
{
    int i, j;
    for (i = 0; i < WORLDWIDTH; i++)
    {
        for (j = 0; j < WORLDHEIGHT; j++)
        {
            world[i][j] = nextstates[i][j];
        }
    }
}

char str_chr(std::string s)
{
    int n = s.length();
    char cname[n + 1];
    strcpy(cname, s.c_str());
    return cname[0];
}

void print_world()
{
    char worldstr[2 * WORLDWIDTH + 2];
    int i, j;

    worldstr[2 * WORLDWIDTH + 1] = '\0';
    worldstr[0] = '+';
    for (i = 1; i < 2 * WORLDWIDTH; i++)
        worldstr[i] = '-';
    worldstr[2 * WORLDWIDTH] = '+';
    puts(worldstr);
    for (i = 0; i <= 2 * WORLDWIDTH; i += 2)
        worldstr[i] = '|';
    for (i = 0; i < WORLDHEIGHT; i++)
    {
        for (j = 0; j < WORLDWIDTH; j++)
            worldstr[2 * j + 1] = world[j][i] == ALIVE ? CHAR_ALIVE : CHAR_DEAD;
        puts(worldstr);
    }
    worldstr[0] = '+';
    for (i = 1; i < 2 * WORLDWIDTH; i++)
        worldstr[i] = '-';
    worldstr[2 * WORLDWIDTH] = '+';
    puts(worldstr);
}

int main()
{
    initialize_world();
    Sprite s1("J", 1, 2);
    s1.print();
    s1.set_state();

    Sprite s2;
    s2.print();
    s2.set_state();

    Sprite s3("M");
    s3.print();
    s3.set_state();

    Sprite s4(3, 5);
    s4.print();
    s4.set_state();

    Sprite *p = new Sprite("P", 37, 13);
    p->print();
    p->set_state();
    delete p;

    set_next_state();
    print_world();

    return 0;
}