%{
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

  typedef struct Game {
    int npure;
    int nmix;
    int nplayer;
    Player players[MAXPLAYER];
  } Game;

  Game games[MAXGAME];
  int ngame = 0;
  int current_player;
  Strategies temp;
  Payoff tempp;

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
%}

%token LBRACE RBRACE LBRAK RBRAK COLON COMMA DOT ARROW
%token GAME PLAYER STRATEGY PAYOFF
%token VARIABLE
%token INTEGER

%%

program:
	game program
	|
	;

game:
	GAME COLON gamebody	{ printgame(); ngame++; }
	;

gamebody:
	VARIABLE LBRACE player strategy payoff RBRACE	{ ; }
	;

player:
	PLAYER COLON players
	;

players:
	VARIABLE			{ addplayer($1); }
	| players COMMA VARIABLE	{ addplayer($3); }
	;

strategy:
	STRATEGY COLON strategies	{ buildpayoff(); }
	;

strategies:
	pls
	| strategies pls
	;

pls:
	VARIABLE LBRACE sset RBRACE	{ addstrtoplayer($1); temp.n=0; }
	;

sset:
	VARIABLE			{ addstrategy($1); }
	| sset COMMA VARIABLE		{ addstrategy($3); }
	;

payoff:
	PAYOFF COLON payoffs
	;

payoffs:
	pmatrix
	| payoffs pmatrix
	;

pmatrix:
	VARIABLE LBRACE pbody RBRACE	{ appendpayoff($1); }
	;

pbody:
	pfunc
	| pbody pfunc
	;

pfunc:
	LBRAK VARIABLE DOT VARIABLE COMMA VARIABLE DOT VARIABLE RBRAK ARROW INTEGER { addpayoff($2,$4,$6,$8,$11); }
	;
%%

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

void printgame() {
  fprintf(stdout, "Game #%d:\n",ngame+1);
  fprintf(stdout, "Player:%c,%c\n",games[ngame].players[0].name+'A',games[ngame].players[1].name+'A');
  fprintf(stdout, "Player %c:\n",games[ngame].players[0].name+'A');
  fprintf(stdout, "%d strategies.\n",games[ngame].players[0].s.n);
  fprintf(stdout, "%d %d",games[ngame].players[1].p.v[1][1],games[ngame].players[1].nother);
  fprintf(stdout, "Game #%d has following Nash Equlibrium:\n",ngame+1);
  if(games[ngame].npure > 0) {
    fprintf(stdout, "%d pure strategy Nash Equlibrium is found:\n",games[ngame].npure);
    fprintf(stdout, " ");
  }
  else {
    fprintf(stdout, "No pure strategy Nash Equlibrium is found.\n");
  }
  if(games[ngame].nmix > 0) {
    fprintf(stdout, "%d mixed strategy Nash Equlibrium is found:\n",games[ngame].nmix);
    fprintf(stdout, " ");
  }
  else {
    fprintf(stdout, "No mixed strategy Nash Equlibrium is found.\n");
  }
}

void yyerror(char *s) {
  fprintf(stderr, "%s\n", s);
  exit(-1);
}

int main(void) {
  yyparse();
  return 0;
}
