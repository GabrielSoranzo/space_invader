/*
 JEU DE SPACE INVADER
 */

#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
    #include<conio.h>
    #include<windows.h>
    #define COLOR_BLACK 0
    #define COLOR_RED 12
    #define COLOR_GREEN 10
    #define COLOR_YELLOW 14
    #define COLOR_BLUE 9
    #define COLOR_MAGENTA 13
    #define COLOR_CYAN 11
    #define COLOR_WHITE 15
#endif
#ifdef unix
    #include <ncurses.h>
    #define putch(x) addch(x);refresh();
    #include <unistd.h>
    #define Sleep(x) (usleep(x*1000.0))
#endif



/*-------------------------------------------------------------*/
/* GESTION DU TERMINAL */
/*-------------------------------------------------------------*/
void gotoxy(int x, int y);

void initScreen();

void closeScreen();

void color(int cT, int cF);

char nbgetch();

/*-------------------------------------------------------------*/

/*-------------------------------------------------------------*/
/* GESTION DU JEU */
/*-------------------------------------------------------------*/




/*-------------------------------------------------------------*/

/*-------------------------------------------------------------*/
/* FONCTION PRINCIPALE */
/*-------------------------------------------------------------*/
int main()
{

    initScreen();
    
    gotoxy(10,10);

    putch('a');

    getch();

    closeScreen();
  
    return 0;
}




/*-------------------------------------------------------------*/
/* FONCTIONS DE GESTION D'ECRAN */
/*-------------------------------------------------------------*/

/*****************************************/
/*  POSITIONNEMENT DU CURSEUR SUR L'ECRAN
    x est la colonne et y est la ligne   */
/*****************************************/
void gotoxy(int x, int y)
{
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hConsole, pos);
#endif
#ifdef unix
    move(y,x);
#endif
}

/*****************************************/
/*    INITIALISA1TION DE L'ECRAN         */
/*****************************************/   
void initScreen()
{
#ifdef _WIN32
    system("mode con lines=50 cols=200");
    // Here to hide cursor
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
#endif
#ifdef unix
    initscr();
    start_color();
    cbreak();
    noecho();
    curs_set(0);
#endif
}

/*************************************/
/*       FERMETURE DE L'ECRAN        */
/*************************************/
void closeScreen()
{
#ifdef unix
    endwin();
#endif
}

/*************************************/
/*    TOUCHE PRESSEE SANS ATTENTE    */
/*************************************/
char nbgetch()
{
#ifdef _WIN32
    if (kbhit()==1){
        return getch();
    } 
    return -1;
#endif
#ifdef unix
    timeout(0);
    return getch(); // return ERR ie -1 if nothing
#endif
}

/************************************************************/
/*  Choix des couleurs de la police et de la fen�tre CONSOLE
    cT correspond � la couleur du texte
    cF correspond � la couleur de fond   
    Voir les couleurs définis dans l'en-tête                */
/************************************************************/
void color(int cT,int cF)
{
#ifdef _WIN32
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,cF*16+cT);
#endif
#ifdef unix
    init_pair(1,cT,cF);
    attron(COLOR_PAIR(1));
#endif
}

/*-------------------------------------------------------------*/
/*-------------------------------------------------------------*/

