#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#include <stdlib.h>
#include <string.h>

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20070509

#define YYEMPTY (-1)
#define yyclearin    (yychar = YYEMPTY)
#define yyerrok      (yyerrflag = 0)
#define YYRECOVERING (yyerrflag != 0)

extern int yyparse(void);

static int yygrowstack(void);
#define YYPREFIX "yy"
#line 2 "game.y"
  #include <stdio.h>
  #define MAXGAME 10
  #define MAXSTR 10
  #define MAXPLAYER 2

  typedef struct Strategies {
    int n;
    int str[MAXSTR];
  } Strategies;

  typedef struct Payoff {
    int v[MAXSTR][MAXSTR];
  } Payoff;

  typedef struct Player {
    int name;
    int nother;
    Strategies s;
    Payoff p;
  } Player;

  typedef struct NE{
    int p1;
    int p2;
    int s1;
    int s2;
  } NE;

  typedef struct Game {
    int npure;
    int nmix;
    int nplayer;
    Player players[MAXPLAYER];
    NE ne[MAXSTR];
  } Game;

  typedef struct Max {
    int m;
    int n;
    int max[MAXSTR][MAXSTR];
  } Max;

  Game games[MAXGAME];
  int ngame = 0;
  int current_player;
  Strategies temp;
  Payoff tempp;
  Max ma,mb;

  int yylex(void);
  int findplayer(Game*,int);
  int findstrategy(Strategies*,int);
  void addplayer(int);
  void addstrategy(int);
  void addstrtoplayer(int);
  void buildpayoff();
  void cleanpayoff();
  void addpayoff(int,int,int,int,int);
  void appendpayoff(int);
  void yyerror(char*);
  void printgame();
  void cleanmax();
  void cacl_ne();
#line 87 "y.tab.c"
#define LBRACE 257
#define RBRACE 258
#define LBRAK 259
#define RBRAK 260
#define COLON 261
#define COMMA 262
#define DOT 263
#define ARROW 264
#define GAME 265
#define PLAYER 266
#define STRATEGY 267
#define PAYOFF 268
#define VARIABLE 269
#define INTEGER 270
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,    1,    2,    3,    6,    6,    4,    7,    7,
    8,    9,    9,    5,   10,   10,   11,   12,   12,   13,
};
short yylen[] = {                                         2,
    2,    0,    3,    6,    3,    1,    3,    3,    1,    2,
    4,    1,    3,    3,    1,    2,    4,    1,    2,   11,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    1,    0,    3,    0,    0,    0,
    0,    0,    0,    6,    0,    0,    0,    0,    0,    0,
    0,    9,    0,    4,    7,    0,   10,    0,    0,   15,
   12,    0,    0,   16,   11,    0,    0,    0,   18,   13,
    0,   17,   19,    0,    0,    0,    0,    0,    0,    0,
    0,   20,
};
short yydgoto[] = {                                       2,
    3,    7,   10,   13,   18,   15,   21,   22,   32,   29,
   30,   38,   39,
};
short yysindex[] = {                                   -262,
 -256,    0, -262, -263,    0, -250,    0, -255, -253, -254,
 -260, -251, -252,    0, -248, -249, -246, -241, -247, -245,
 -249,    0, -244,    0,    0, -243,    0, -239, -244,    0,
    0, -258, -240,    0,    0, -242, -238, -257,    0,    0,
 -235,    0,    0, -237, -233, -236, -229, -234, -230, -228,
 -232,    0,
};
short yyrindex[] = {                                     21,
    0,    0,   21,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -227,    0,    0,    0,    0,    0,
 -231,    0,    0,    0,    0,    0,    0,    0, -219,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
short yygindex[] = {                                     20,
    0,    0,    0,    0,    0,    0,    0,    3,    0,    0,
   12,    0,    4,
};
#define YYTABLESIZE 42
short yytable[] = {                                      35,
   42,   37,    1,   36,    4,    6,    8,   11,   14,   16,
    9,   26,   12,   19,   23,   17,   24,   33,   37,   20,
    2,   25,    5,   27,   28,   31,   40,   44,   46,   50,
   41,   45,   47,   48,   49,   51,    8,   52,   14,    5,
   34,   43,
};
short yycheck[] = {                                     258,
  258,  259,  265,  262,  261,  269,  257,  261,  269,  261,
  266,  257,  267,  262,  261,  268,  258,  257,  259,  269,
    0,  269,    3,   21,  269,  269,  269,  263,  262,  260,
  269,  269,  269,  263,  269,  264,  268,  270,  258,  267,
   29,   38,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 270
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"LBRACE","RBRACE","LBRAK","RBRAK",
"COLON","COMMA","DOT","ARROW","GAME","PLAYER","STRATEGY","PAYOFF","VARIABLE",
"INTEGER",
};
char *yyrule[] = {
"$accept : program",
"program : game program",
"program :",
"game : GAME COLON gamebody",
"gamebody : VARIABLE LBRACE player strategy payoff RBRACE",
"player : PLAYER COLON players",
"players : VARIABLE",
"players : players COMMA VARIABLE",
"strategy : STRATEGY COLON strategies",
"strategies : pls",
"strategies : strategies pls",
"pls : VARIABLE LBRACE sset RBRACE",
"sset : VARIABLE",
"sset : sset COMMA VARIABLE",
"payoff : PAYOFF COLON payoffs",
"payoffs : pmatrix",
"payoffs : payoffs pmatrix",
"pmatrix : VARIABLE LBRACE pbody RBRACE",
"pbody : pfunc",
"pbody : pbody pfunc",
"pfunc : LBRAK VARIABLE DOT VARIABLE COMMA VARIABLE DOT VARIABLE RBRAK ARROW INTEGER",
};
#endif
#ifndef YYSTYPE
typedef int YYSTYPE;
#endif
#if YYDEBUG
#include <stdio.h>
#endif

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 500

int      yydebug;
int      yynerrs;
int      yyerrflag;
int      yychar;
short   *yyssp;
YYSTYPE *yyvsp;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* variables for the parser stack */
static short   *yyss;
static short   *yysslim;
static YYSTYPE *yyvs;
static int      yystacksize;
#line 136 "game.y"

int findstrategy(Strategies* s, int name) {
  int i;
  for(i = 0; i < s->n; i++) {
    if(s->str[i] == name) {
      return i;
    }
  }
  return -1;
}

int findplayer(Game* g, int name) {
  int i;
  for(i = 0; i < g->nplayer; i++) {
    if(g->players[i].name==name) {
      return i;
    }
  }
  return -1;
}

void addplayer(int name) {
  //fprintf(stdout,"player:%d\n",name);
  if(findplayer(&games[ngame], name) != -1) {
    yyerror("Duplicate player name!");
  }
  else {
    games[ngame].players[games[ngame].nplayer].name = name;
    games[ngame].nplayer++;
  }
}

void addstrategy(int name) {
  //fprintf(stdout,"strategy:%d\n",name);
  if(findstrategy(&temp,name) != -1) {
    yyerror("Duplicate strategy name!");
  }
  else {
    temp.str[temp.n] = name;
    temp.n++;
  }
}

void addstrtoplayer(int name) {
  //fprintf(stdout,"add to p:%d\n",name);
  int i = findplayer(&games[ngame],name);
  if(i == -1) {
    yyerror("Assign Strategy to none-exist player!");
  }
  else {
    games[ngame].players[i].s = temp;
  }
}

void buildpayoff() {
  if(games[ngame].nplayer != 2) {
    yyerror("Must have 2 player!");
  }
  else {
    games[ngame].players[0].nother = games[ngame].players[1].s.n;
    games[ngame].players[1].nother = games[ngame].players[0].s.n;
  }
}

void cleanpayoff() {
  int i,j;
  for(i=0;i<MAXSTR;i++) {
    for(j=0;j<MAXSTR;j++) {
      tempp.v[i][j]=0;
    }
  }  
}

void addpayoff(int pname1,int sname1,int pname2,int sname2,int value) {
  //  fprintf(stdout,"p1:%d,s1:%d,p2:%d,s2:%d,value:%d\n",pname1,sname1,pname2,sname2,value);
  int p1,p2,s1,s2;
  p1 = findplayer(&games[ngame],pname1);
  p2 = findplayer(&games[ngame],pname2);
  if( p1 != 0 || p2 != 1 ) {
    yyerror("None exist player!");
  }
  else {
    s1 = findstrategy(&games[ngame].players[p1].s,sname1);
    s2 = findstrategy(&games[ngame].players[p2].s,sname2);
    if( s1 == -1 || s2 == -1 ) {
      yyerror("None exist strategy!");
    }
    else {
      tempp.v[s1][s2] = value;
    }
  }
}

void appendpayoff(int name) {
  int p = findplayer(&games[ngame],name);
  if( p == -1 ) {
    yyerror("Player doesn't exist!");
  }
  else {
    games[ngame].players[p].p = tempp;
  }
}

void cleanmax() {
  ma.m = 0;
  ma.n = 0;
  mb.m = 0;
  mb.n = 0;
  int i,j;
  for(i=0;i<MAXSTR;i++) {
    for(j=0;j<MAXSTR;j++) {
      ma.max[i][j] = 0;
      mb.max[i][j] = 0;
    }
  }
}

void cacl_ne(){
  cleanmax();
  ma.m = games[ngame].players[0].s.n;
  ma.n = games[ngame].players[1].s.n;
  mb.m = games[ngame].players[0].s.n;
  mb.n = games[ngame].players[1].s.n;
  int i,j;
  int max;

  for(j=0;j<ma.n;j++) {
    max = games[ngame].players[0].p.v[0][j];
    for(i=0;i<ma.m;i++) {
      if(games[ngame].players[0].p.v[i][j] > max) {
	max = games[ngame].players[0].p.v[i][j];
      }
    }
    for(i=0;i<ma.m;i++) {
      if(games[ngame].players[0].p.v[i][j] == max) {
	ma.max[i][j] = 1;
      }
    }
  }

  for(i=0;i<mb.m;i++) {
    max = games[ngame].players[1].p.v[i][0];
    for(j=0;j<mb.n;j++) {
      if(games[ngame].players[1].p.v[i][j] > max) {
	max = games[ngame].players[1].p.v[i][j];
      }
    }
    for(j=0;j<ma.m;j++) {
      if(games[ngame].players[1].p.v[i][j] == max) {
	mb.max[i][j] = 1;
      }
    }
  }

  for(i=0;i<ma.m;i++) {
    for(j=0;j<ma.n;j++) {
      if(ma.max[i][j] && mb.max[i][j]) {
	games[ngame].ne[games[ngame].npure].p1 = games[ngame].players[0].name;
	games[ngame].ne[games[ngame].npure].p2 = games[ngame].players[1].name;
	games[ngame].ne[games[ngame].npure].s1 = games[ngame].players[0].s.str[i];
	games[ngame].ne[games[ngame].npure].s2 = games[ngame].players[i].s.str[j];
	games[ngame].npure++;
      }
    }
  }
}

void printgame() {
  //fprintf(stdout, "Game #%d:\n",ngame+1);
  //fprintf(stdout, "Player:%c,%c\n",games[ngame].players[0].name+'A',games[ngame].players[1].name+'A');
  //fprintf(stdout, "Player %c:\n",games[ngame].players[0].name+'A');
  //fprintf(stdout, "%d strategies.\n",games[ngame].players[0].s.n);
  //fprintf(stdout, "%d %d\n",games[ngame].players[1].p.v[1][1],games[ngame].players[1].nother);
  cacl_ne();
  fprintf(stdout, "Game #%d has following Nash Equlibrium:\n",ngame+1);
  if(games[ngame].npure > 0) {
    fprintf(stdout, "%d pure strategy Nash Equlibrium is found:\n",games[ngame].npure);
    int i;
    for(i=0;i<games[ngame].npure;i++) {
      fprintf(stdout, "%c.%c,%c.%c\n",games[ngame].ne[i].p1+'A',games[ngame].ne[i].s1+'A',games[ngame].ne[i].p2+'A',games[ngame].ne[i].s2+'A');
    }
  }
  else {
    fprintf(stdout, "No pure strategy Nash Equlibrium is found.\n");
  }
  /*if(games[ngame].nmix > 0) {
    fprintf(stdout, "%d mixed strategy Nash Equlibrium is found:\n",games[ngame].nmix);
    fprintf(stdout, " ");
  }
  else {
    fprintf(stdout, "No mixed strategy Nash Equlibrium is found.\n");
    }*/
}

void yyerror(char *s) {
  fprintf(stderr, "%s\n", s);
  exit(-1);
}

int main(void) {
  yyparse();
  return 0;
}
#line 439 "y.tab.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(void)
{
    int newsize, i;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = yyssp - yyss;
    newss = (yyss != 0)
          ? (short *)realloc(yyss, newsize * sizeof(*newss))
          : (short *)malloc(newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    yyss  = newss;
    yyssp = newss + i;
    newvs = (yyvs != 0)
          ? (YYSTYPE *)realloc(yyvs, newsize * sizeof(*newvs))
          : (YYSTYPE *)malloc(newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    yyvs = newvs;
    yyvsp = newvs + i;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
}

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse(void)
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yysslim && yygrowstack())
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

#ifdef lint
    goto yyerrlab;
#endif

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yyvsp[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 3:
#line 80 "game.y"
{ printgame(); ngame++; }
break;
case 4:
#line 84 "game.y"
{ ; }
break;
case 6:
#line 92 "game.y"
{ addplayer(yyvsp[0]); }
break;
case 7:
#line 93 "game.y"
{ addplayer(yyvsp[0]); }
break;
case 8:
#line 97 "game.y"
{ buildpayoff(); }
break;
case 11:
#line 106 "game.y"
{ addstrtoplayer(yyvsp[-3]); temp.n=0; }
break;
case 12:
#line 110 "game.y"
{ addstrategy(yyvsp[0]); }
break;
case 13:
#line 111 "game.y"
{ addstrategy(yyvsp[0]); }
break;
case 17:
#line 124 "game.y"
{ appendpayoff(yyvsp[-3]); }
break;
case 20:
#line 133 "game.y"
{ addpayoff(yyvsp[-9],yyvsp[-7],yyvsp[-5],yyvsp[-3],yyvsp[0]); }
break;
#line 660 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    return (1);

yyaccept:
    return (0);
}
