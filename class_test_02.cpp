#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

void ClearScreen()
{
  HANDLE                     hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 0, 0 };

  hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  if (hStdOut == INVALID_HANDLE_VALUE) return;

  /* Get the number of cells in the current buffer */
  if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  /* Fill the entire buffer with spaces */
  if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Fill the entire buffer with the current colors and attributes */
  if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Move the cursor home */
  SetConsoleCursorPosition( hStdOut, homeCoords );
}

#else // !_WIN32
#include <unistd.h>
#include <term.h>

void ClearScreen()
{
  if (!cur_term)
  {
     int result;
     setupterm( NULL, STDOUT_FILENO, &result );
     if (result <= 0) return;
  }

   putp( tigetstr( "clear" ) );
}
#endif

#include <stdio.h>

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
    void set_x(int i)
    {
        x = i;
    }
    void set_y(int i)
    {
        y = i;
    }
    int get_x()
    {
        return x;
    }
    int get_y()
    {
        return y;
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
    /**
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
    */
    Sprite *p = new Sprite("P", 37, 13);
    p->print();
    p->set_state();

    set_next_state();
    print_world();

// test to move the "character"
    for (int i = 1; i < 4; i++)
    {
        printf("Press enter to proceed.");
        getchar();
        initialize_world();
        p->set_y(p->get_y() - 1);
        p->set_x(p->get_x() - 1);
        p->set_state();
        set_next_state();
        ClearScreen();
        print_world();
    }
    /**
        getchar();
        initialize_world();
        p->set_x(5);
        p->set_y(4);
        p->print();
        p->set_state();
        set_next_state();
        print_world();
        delete p;
    */
    printf("Use arrow keys to navigate");

// supposed to use arrow-keys to navigate, but some trouble reading the input ... :(
    if (getchar() == '\033')
    {              // if the first value is esc
        getchar(); // skip the [
        switch (getchar())
        { // the real value
        case 'A':
            // code for arrow up decrement y-axis
            initialize_world();
            p->set_y(p->get_y() - 1);
            p->set_state();
            set_next_state();
            print_world();
            break;
        case 'B':
            // code for arrow down increment y-axis
            p->set_y(p->get_y() + 1);
            initialize_world();
            p->set_state();
            set_next_state();
            print_world();
            break;
        case 'C':
            // code for arrow right increment x-axis
            p->set_x(p->get_x() + 1);
            initialize_world();
            p->set_state();
            set_next_state();
            print_world();
            break;
        case 'D':
            // code for arrow left decrement x-axis
            p->set_x(p->get_x() - 1);
            initialize_world();
            p->set_state();
            set_next_state();
            print_world();
            break;
        }
    }
    delete p;
    return 0;
}