#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
int main(int argc, char *argv[])
{
    int i=0;
    SDL_Event event;
TTF_Font *police = NULL;
SDL_Color couleurNoire = {0, 0, 0};
SDL_Color couleurrouge = {217, 10, 4};
SDL_Color couleurvert={197,64,37};
SDL_Color couleurgold={251,208,119};
SDL_Surface *play,*texte=NULL,*texte2=NULL,*texte3=NULL,*texte4=NULL,*ecran = NULL,*imageDeFond0=NULL,*imageDeFond1,*texte5,*texte6,*texte7,*texte8,*textep,*textec,*textes,*textee,*texte_nom1,*texte_nom2,*texte_nom3,*texte_nom4,*texte_nom5,*texte_nom6,*texte11,*text22,*texte33,*texte111,*text222,*texte333,*texte11s,*text22s,*texte33s,*texte111s,*text222s,*texte333s,*textea,*texteb,*texteas,*textebs,*texteag,*textebg,*textey,*texteh,*textec1,*textef,*textem,*textehe,*texteys,*textehs,*textec1s,*textefs,*textems,*textehes;
SDL_Rect positionFond;
SDL_Rect position;
int continuer=1;
int x1=0,y1=0,z=0,a=0;
int x=0;
int y=0;
SDL_Init(SDL_INIT_VIDEO);
ecran  = SDL_SetVideoMode(1920, 1080, 32,
                                        SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_WM_SetCaption("Chargement d'images en SDL", NULL);
if(TTF_Init() == -1)
{
fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n",
TTF_GetError());
exit(EXIT_FAILURE);
}
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
    printf("%s",Mix_GetError());
}
Mix_Music*music;
music=Mix_LoadMUS("Funny Background Music  Funny Music Instrumental Comedy.mp3");
Mix_PlayMusic(music,-1);
imageDeFond0=IMG_Load("backx.png");

police = TTF_OpenFont("theme.ttf", 120);
texte = TTF_RenderText_Blended(police, "PLAY",couleurNoire);
texte4 = TTF_RenderText_Blended(police, "EXIT ",couleurNoire);
texte2 = TTF_RenderText_Blended(police, "SETTINGS ",couleurNoire);
texte3= TTF_RenderText_Blended(police, "CREDITS ",couleurNoire);
texte5= TTF_RenderText_Blended(police, "PLAY ",couleurvert);
texte8 = TTF_RenderText_Blended(police, "EXIT ",couleurvert);
texte7 = TTF_RenderText_Blended(police, "SETTINGS ",couleurvert);
texte6= TTF_RenderText_Blended(police, "CREDITS ",couleurvert);
textep=TTF_RenderText_Blended(police, "PLAY",couleurgold);
textes=TTF_RenderText_Blended(police, "SETTINGS",couleurgold);
textec=TTF_RenderText_Blended(police, "CREDITS",couleurgold);
textee=TTF_RenderText_Blended(police, "EXIT",couleurgold);
texte11=TTF_RenderText_Blended(police, "NEW GAME",couleurgold);
text22=TTF_RenderText_Blended(police, "LOAD GAME",couleurgold);
texte33=TTF_RenderText_Blended(police, "MUTLIPLAYER",couleurgold);
texte111=TTF_RenderText_Blended(police, "NEW GAME",couleurvert);
text222=TTF_RenderText_Blended(police, "LOAD GAME",couleurvert);
texte333=TTF_RenderText_Blended(police, "MUTLIPLAYER",couleurvert);
texte333s=TTF_RenderText_Blended(police, "MUTLIPLAYER",couleurNoire);
texte11s=TTF_RenderText_Blended(police, "NEW GAME",couleurNoire);
text22s=TTF_RenderText_Blended(police, "LOAD GAME",couleurNoire);
texte33s=TTF_RenderText_Blended(police, "MUTLIPLAYER",couleurNoire);
texte111s=TTF_RenderText_Blended(police, "NEW GAME",couleurNoire);
text222s=TTF_RenderText_Blended(police, "LOAD GAME",couleurNoire);
texteas=TTF_RenderText_Blended(police, "AUDIO",couleurNoire);
textebs=TTF_RenderText_Blended(police, "NAVIGATION MODE",couleurNoire);
textea=TTF_RenderText_Blended(police, "AUDIO",couleurrouge);
texteb=TTF_RenderText_Blended(police, "NAVIGATION MODE",couleurrouge);
textebg=TTF_RenderText_Blended(police, "NAVIGATION MODE",couleurgold);
texteag=TTF_RenderText_Blended(police, "AUDIO",couleurgold);
textey=TTF_RenderText_Blended(police, "YOUSSEF EL MAHDI",couleurvert);
texteh=TTF_RenderText_Blended(police, "HAZEM DAWAHI",couleurvert);
textec1=TTF_RenderText_Blended(police, "YASSMINE CHABLBI",couleurvert);
textef=TTF_RenderText_Blended(police, "FEDY SAID GHOURABI",couleurvert);
textem=TTF_RenderText_Blended(police, "MED AZIZ GHORBEL",couleurvert);
textehe=TTF_RenderText_Blended(police, "HAJER AMARI",couleurvert);
texteys=TTF_RenderText_Blended(police, "YOUSSEF EL MAHDI",couleurNoire);
textehs=TTF_RenderText_Blended(police, "HAZEM DAWAHI",couleurNoire);
textec1s=TTF_RenderText_Blended(police, "YASSMINE CHABLBI",couleurNoire);
textefs=TTF_RenderText_Blended(police, "FEDY SAID GHOURABI",couleurNoire);
textems=TTF_RenderText_Blended(police, "MED AZIZ GHORBEL",couleurNoire);
textehes=TTF_RenderText_Blended(police, "HAJER AMARI",couleurNoire);
positionFond.x=0;
positionFond.y= 0;
SDL_BlitSurface(imageDeFond0, NULL, ecran, &positionFond);
SDL_Flip(ecran);
position.x=1425;
position.y=278;
SDL_BlitSurface(texte, NULL, ecran, &position);
position.x=1413;
position.y=288;
SDL_BlitSurface(texte5, NULL, ecran, &position);
position.x=1255;
position.y=428;
SDL_BlitSurface(texte2, NULL, ecran, &position);
position.x=1248;
position.y=442;
SDL_BlitSurface(texte7, NULL, ecran, &position);
position.x=1306;
position.y=578;
SDL_BlitSurface(texte3, NULL, ecran, &position);
position.x=1299;
position.y=592;
SDL_BlitSurface(texte6, NULL, ecran, &position);
position.x=1409;
position.y=724;
SDL_BlitSurface(texte4, NULL, ecran, &position);
position.x=1402;
position.y=738;
SDL_BlitSurface(texte8, NULL, ecran, &position);
SDL_Flip(ecran);
while(continuer)
{
    while(SDL_PollEvent(&event))
{
switch(event.type)
{

    case SDL_QUIT:

        continuer=0;
        break;

    case SDL_KEYDOWN:
if (event.key.keysym.sym==SDLK_ESCAPE)
    {
        Mix_Music*music;
music=Mix_LoadMUS("Funny Background Music  Funny Music Instrumental Comedy.mp3");
Mix_PlayMusic(music,-1);
imageDeFond0=IMG_Load("backx.png");
positionFond.x=0;
positionFond.y= 0;
SDL_BlitSurface(imageDeFond0, NULL, ecran, &positionFond);

police = TTF_OpenFont("theme.ttf", 120);
texte = TTF_RenderText_Blended(police, "PLAY",couleurNoire);
texte4 = TTF_RenderText_Blended(police, "EXIT ",couleurNoire);
texte2 = TTF_RenderText_Blended(police, "SETTINGS ",couleurNoire);
texte3= TTF_RenderText_Blended(police, "CREDITS ",couleurNoire);
texte5= TTF_RenderText_Blended(police, "PLAY ",couleurvert);
texte8 = TTF_RenderText_Blended(police, "EXIT ",couleurvert);
texte7 = TTF_RenderText_Blended(police, "SETTINGS ",couleurvert);
texte6= TTF_RenderText_Blended(police, "CREDITS ",couleurvert);
textep=TTF_RenderText_Blended(police, "PLAY",couleurgold);
textes=TTF_RenderText_Blended(police, "SETTINGS",couleurgold);
textec=TTF_RenderText_Blended(police, "CREDITS",couleurgold);
textee=TTF_RenderText_Blended(police, "EXIT",couleurgold);
position.x=1425;
position.y=278;
SDL_BlitSurface(texte, NULL, ecran, &position);
position.x=1413;
position.y=288;
SDL_BlitSurface(texte5, NULL, ecran, &position);
position.x=1255;
position.y=428;
SDL_BlitSurface(texte2, NULL, ecran, &position);
position.x=1248;
position.y=442;
SDL_BlitSurface(texte7, NULL, ecran, &position);
position.x=1306;
position.y=578;
SDL_BlitSurface(texte3, NULL, ecran, &position);
position.x=1299;
position.y=592;
SDL_BlitSurface(texte6, NULL, ecran, &position);
position.x=1409;
position.y=724;
SDL_BlitSurface(texte4, NULL, ecran, &position);
position.x=1402;
position.y=738;
SDL_BlitSurface(texte8, NULL, ecran, &position);
SDL_Flip(ecran);
    }

if(event.key.keysym.sym==SDLK_DOWN)
{
    i++;
}if (i==4)
    {
        i=0;
    }
else if (event.key.keysym.sym==SDLK_UP)

    {
        i--;
    }
if (i==-1)
{
    i=3;
}


    if (i==0)
    {
        if ((event.key.keysym.sym==SDLK_RETURN ))
{

SDL_FreeSurface(imageDeFond0);

    texte = TTF_RenderText_Blended(police, "",couleurNoire);
texte4 = TTF_RenderText_Blended(police, " ",couleurNoire);
texte2 = TTF_RenderText_Blended(police, " ",couleurNoire);
texte3= TTF_RenderText_Blended(police, " ",couleurNoire);
texte5= TTF_RenderText_Blended(police, " ",couleurvert);
texte8 = TTF_RenderText_Blended(police, " ",couleurvert);
texte7 = TTF_RenderText_Blended(police, " ",couleurvert);
texte6= TTF_RenderText_Blended(police, " ",couleurvert);
textep=TTF_RenderText_Blended(police, "",couleurgold);
textes=TTF_RenderText_Blended(police, "",couleurgold);
textec=TTF_RenderText_Blended(police, "",couleurgold);
textee=TTF_RenderText_Blended(police, "",couleurgold);

        imageDeFond0=IMG_Load("back3.png");
    position.x=0;
position.y=0;
SDL_BlitSurface(imageDeFond0, NULL, ecran, &position);

SDL_Flip(ecran);
}
if((event.key.keysym.sym==SDLK_DOWN)||(event.key.keysym.sym==SDLK_UP))
{
Mix_Chunk *son;
son = Mix_LoadWAV("button-3.wav");
Mix_PlayChannel(1, son, 0);
position.x=1425;
position.y=278;
SDL_BlitSurface(texte, NULL, ecran, &position);
position.x=1413;
position.y=288;
SDL_BlitSurface(textep, NULL, ecran, &position);
position.x=1255;
position.y=428;
SDL_BlitSurface(texte2, NULL, ecran, &position);
position.x=1248;
position.y=442;
SDL_BlitSurface(texte7, NULL, ecran, &position);
position.x=1306;
position.y=578;
SDL_BlitSurface(texte3, NULL, ecran, &position);
position.x=1299;
position.y=592;
SDL_BlitSurface(texte6, NULL, ecran, &position);
position.x=1409;
position.y=724;
SDL_BlitSurface(texte4, NULL, ecran, &position);
position.x=1402;
position.y=738;
SDL_BlitSurface(texte8, NULL, ecran, &position);
SDL_Flip(ecran);
}
}
if (i==1)
{

        if ((event.key.keysym.sym==SDLK_RETURN ))
{



    texte = TTF_RenderText_Blended(police, "",couleurNoire);
texte4 = TTF_RenderText_Blended(police, " ",couleurNoire);
texte2 = TTF_RenderText_Blended(police, " ",couleurNoire);
texte3= TTF_RenderText_Blended(police, " ",couleurNoire);
texte5= TTF_RenderText_Blended(police, " ",couleurvert);
texte8 = TTF_RenderText_Blended(police, " ",couleurvert);
texte7 = TTF_RenderText_Blended(police, " ",couleurvert);
texte6= TTF_RenderText_Blended(police, " ",couleurvert);
textep=TTF_RenderText_Blended(police, "",couleurgold);
textes=TTF_RenderText_Blended(police, "",couleurgold);
textec=TTF_RenderText_Blended(police, "",couleurgold);
textee=TTF_RenderText_Blended(police, "",couleurgold);
        imageDeFond0=IMG_Load("fenetre menu.jpg");
    position.x=0;
position.y=0;
SDL_BlitSurface(imageDeFond0, NULL, ecran, &position);
position.x=847;
position.y=327;
SDL_BlitSurface(texteas, NULL, ecran, &position);
position.x=487;
position.y=447;
SDL_BlitSurface(textebs, NULL, ecran, &position);
position.x=840;
position.y=313;
SDL_BlitSurface(textea, NULL, ecran, &position);
position.x=480;
position.y=434;
SDL_BlitSurface(texteb, NULL, ecran, &position);
SDL_Flip(ecran);

}


if((event.key.keysym.sym== SDLK_DOWN)||(event.key.keysym.sym==SDLK_UP))
{
Mix_Chunk *son;
son = Mix_LoadWAV("button-3.wav");
Mix_PlayChannel(1, son, 0);

position.x=1425;
position.y=278;
SDL_BlitSurface(texte, NULL, ecran, &position);
position.x=1413;
position.y=288;
SDL_BlitSurface(texte5, NULL, ecran, &position);
position.x=1255;
position.y=428;
SDL_BlitSurface(texte2, NULL, ecran, &position);
position.x=1248;
position.y=442;
SDL_BlitSurface(textes, NULL, ecran, &position);
position.x=1306;
position.y=578;
SDL_BlitSurface(texte3, NULL, ecran, &position);
position.x=1299;
position.y=592;
SDL_BlitSurface(texte6, NULL, ecran, &position);
position.x=1409;
position.y=724;
SDL_BlitSurface(texte4, NULL, ecran, &position);
position.x=1402;
position.y=738;
SDL_BlitSurface(texte8, NULL, ecran, &position);
SDL_Flip(ecran);
}
}
if (i==2)
{

        if ((event.key.keysym.sym==SDLK_RETURN ))
{



    texte = TTF_RenderText_Blended(police, "",couleurNoire);
texte4 = TTF_RenderText_Blended(police, " ",couleurNoire);
texte2 = TTF_RenderText_Blended(police, " ",couleurNoire);
texte3= TTF_RenderText_Blended(police, " ",couleurNoire);
texte5= TTF_RenderText_Blended(police, " ",couleurvert);
texte8 = TTF_RenderText_Blended(police, " ",couleurvert);
texte7 = TTF_RenderText_Blended(police, " ",couleurvert);
texte6= TTF_RenderText_Blended(police, " ",couleurvert);
textep=TTF_RenderText_Blended(police, "",couleurgold);
textes=TTF_RenderText_Blended(police, "",couleurgold);
textec=TTF_RenderText_Blended(police, "",couleurgold);
textee=TTF_RenderText_Blended(police, "",couleurgold);
        imageDeFond0=IMG_Load("fenetre menu.jpg");
    position.x=0;
position.y=0;
SDL_BlitSurface(imageDeFond0, NULL, ecran, &position);
position.x=447;
position.y=206;
SDL_BlitSurface(texteys, NULL, ecran, &position);
position.x=447;
position.y=320;
SDL_BlitSurface(textehs, NULL, ecran, &position);
position.x=447;
position.y=426;
SDL_BlitSurface(textec1s, NULL, ecran, &position);
position.x=447;
position.y=526;
SDL_BlitSurface(textefs, NULL, ecran, &position);
position.x=447;
position.y=626;
SDL_BlitSurface(textems, NULL, ecran, &position);
position.x=447;
position.y=726;
SDL_BlitSurface(textehes, NULL, ecran, &position);
position.x=440;
position.y=227;
SDL_BlitSurface(textey, NULL, ecran, &position);
position.x=440;
position.y=316;
SDL_BlitSurface(texteh, NULL, ecran, &position);
position.x=440;
position.y=440;
SDL_BlitSurface(textec1, NULL, ecran, &position);
position.x=440;
position.y=540;
SDL_BlitSurface(textef, NULL, ecran, &position);
position.x=440;
position.y=646;
SDL_BlitSurface(textem, NULL, ecran, &position);
position.x=440;
position.y=750;
SDL_BlitSurface(textehe, NULL, ecran, &position);
SDL_Flip(ecran);

}
if((event.key.keysym.sym==SDLK_DOWN)||(event.key.keysym.sym==SDLK_UP))
{
Mix_Chunk *son;
son = Mix_LoadWAV("button-3.wav");
Mix_PlayChannel(1, son, 0);
position.x=1425;
position.y=278;
SDL_BlitSurface(texte, NULL, ecran, &position);
position.x=1413;
position.y=288;
SDL_BlitSurface(texte5, NULL, ecran, &position);
position.x=1255;
position.y=428;
SDL_BlitSurface(texte2, NULL, ecran, &position);
position.x=1248;
position.y=442;
SDL_BlitSurface(texte7, NULL, ecran, &position);
position.x=1306;
position.y=578;
SDL_BlitSurface(texte3, NULL, ecran, &position);
position.x=1299;
position.y=592;
SDL_BlitSurface(textec, NULL, ecran, &position);
position.x=1409;
position.y=724;
SDL_BlitSurface(texte4, NULL, ecran, &position);
position.x=1402;
position.y=738;
SDL_BlitSurface(texte8, NULL, ecran, &position);
SDL_Flip(ecran);
}
}

if (i==3)
{

        if ((event.key.keysym.sym==SDLK_RETURN ))
{


SDL_Quit();
}
if((event.key.keysym.sym==SDLK_DOWN)||(event.key.keysym.sym==SDLK_UP))
{
Mix_Chunk *son;
son = Mix_LoadWAV("button-3.wav");
Mix_PlayChannel(1, son, 0);
 position.x=1425;
position.y=278;
SDL_BlitSurface(texte, NULL, ecran, &position);
position.x=1413;
position.y=288;
SDL_BlitSurface(texte5, NULL, ecran, &position);
position.x=1255;
position.y=428;
SDL_BlitSurface(texte2, NULL, ecran, &position);
position.x=1248;
position.y=442;
SDL_BlitSurface(texte7, NULL, ecran, &position);
position.x=1306;
position.y=578;
SDL_BlitSurface(texte3, NULL, ecran, &position);
position.x=1299;
position.y=592;
SDL_BlitSurface(texte6, NULL, ecran, &position);
position.x=1409;
position.y=724;
SDL_BlitSurface(texte4, NULL, ecran, &position);
position.x=1402;
position.y=738;
SDL_BlitSurface(textee, NULL, ecran, &position);
SDL_Flip(ecran);

}
}

break;
case SDL_MOUSEBUTTONDOWN:
switch(event.button.button)
{

case SDL_BUTTON_LEFT:
position.x=1413;
position.y=288;
x = event.button.x;
y = event.button.y;
   if ( ( x >= position.x ) && ( x <= position.x + position.w ) && ( y >=position.y ) && ( y <=position.y + position.h ) )
   {
       x1=1;

texte = TTF_RenderText_Blended(police, "",couleurNoire);
texte4 = TTF_RenderText_Blended(police, " ",couleurNoire);
texte2 = TTF_RenderText_Blended(police, " ",couleurNoire);
texte3= TTF_RenderText_Blended(police, " ",couleurNoire);
texte5= TTF_RenderText_Blended(police, " ",couleurvert);
texte8 = TTF_RenderText_Blended(police, " ",couleurvert);
texte7 = TTF_RenderText_Blended(police, " ",couleurvert);
texte6= TTF_RenderText_Blended(police, " ",couleurvert);
textep=TTF_RenderText_Blended(police, "",couleurgold);
textes=TTF_RenderText_Blended(police, "",couleurgold);
textec=TTF_RenderText_Blended(police, "",couleurgold);
textee=TTF_RenderText_Blended(police, "",couleurgold);
SDL_FreeSurface(imageDeFond0);
        imageDeFond0=IMG_Load("back3.png");
    position.x=0;
position.y=0;
SDL_BlitSurface(imageDeFond0, NULL, ecran, &position);

   }


position.x=1248;
position.y=442;
x = event.button.x;
y = event.button.y;

  if ( ( x >= position.x ) && ( x <= position.x + position.w ) && ( y >=position.y ) && ( y <=position.y + position.h ) )
  {

      y1=1;
texte = TTF_RenderText_Blended(police, "",couleurNoire);
texte4 = TTF_RenderText_Blended(police, " ",couleurNoire);
texte2 = TTF_RenderText_Blended(police, " ",couleurNoire);
texte3= TTF_RenderText_Blended(police, " ",couleurNoire);
texte5= TTF_RenderText_Blended(police, " ",couleurvert);
texte8 = TTF_RenderText_Blended(police, " ",couleurvert);
texte7 = TTF_RenderText_Blended(police, " ",couleurvert);
texte6= TTF_RenderText_Blended(police, " ",couleurvert);
textep=TTF_RenderText_Blended(police, "",couleurgold);
textes=TTF_RenderText_Blended(police, "",couleurgold);
textec=TTF_RenderText_Blended(police, "",couleurgold);
textee=TTF_RenderText_Blended(police, "",couleurgold);
SDL_FreeSurface(imageDeFond0);

         imageDeFond0=IMG_Load("fenetre menu.jpg");
    position.x=0;
position.y=0;
SDL_BlitSurface(imageDeFond0, NULL, ecran, &position);
position.x=847;
position.y=327;
SDL_BlitSurface(texteas, NULL, ecran, &position);
position.x=487;
position.y=447;
SDL_BlitSurface(textebs, NULL, ecran, &position);
position.x=840;
position.y=313;
SDL_BlitSurface(textea, NULL, ecran, &position);
position.x=480;
position.y=434;
SDL_BlitSurface(texteb, NULL, ecran, &position);
SDL_Flip(ecran);
}
else
{

        y1=0;

}

position.x=1299;
position.y=592;
x = event.button.x;
y = event.button.y;
  if ( ( x >= position.x ) && ( x <= position.x + position.w ) && ( y >=position.y ) && ( y <=position.y + position.h ) )
  {
z=1;
      texte = TTF_RenderText_Blended(police, "",couleurNoire);
texte4 = TTF_RenderText_Blended(police, " ",couleurNoire);
texte2 = TTF_RenderText_Blended(police, " ",couleurNoire);
texte3= TTF_RenderText_Blended(police, " ",couleurNoire);
texte5= TTF_RenderText_Blended(police, " ",couleurvert);
texte8 = TTF_RenderText_Blended(police, " ",couleurvert);
texte7 = TTF_RenderText_Blended(police, " ",couleurvert);
texte6= TTF_RenderText_Blended(police, " ",couleurvert);
textep=TTF_RenderText_Blended(police, "",couleurgold);
textes=TTF_RenderText_Blended(police, "",couleurgold);
textec=TTF_RenderText_Blended(police, "",couleurgold);
textee=TTF_RenderText_Blended(police, "",couleurgold);
SDL_FreeSurface(imageDeFond0);

               imageDeFond0=IMG_Load("fenetre menu.jpg");
    position.x=0;
position.y=0;
SDL_BlitSurface(imageDeFond0, NULL, ecran, &position);
position.x=447;
position.y=206;
SDL_BlitSurface(texteys, NULL, ecran, &position);
position.x=447;
position.y=320;
SDL_BlitSurface(textehs, NULL, ecran, &position);
position.x=447;
position.y=426;
SDL_BlitSurface(textec1s, NULL, ecran, &position);
position.x=447;
position.y=526;
SDL_BlitSurface(textefs, NULL, ecran, &position);
position.x=447;
position.y=626;
SDL_BlitSurface(textems, NULL, ecran, &position);
position.x=447;
position.y=726;
SDL_BlitSurface(textehes, NULL, ecran, &position);
position.x=440;
position.y=227;
SDL_BlitSurface(textey, NULL, ecran, &position);
position.x=440;
position.y=316;
SDL_BlitSurface(texteh, NULL, ecran, &position);
position.x=440;
position.y=440;
SDL_BlitSurface(textec1, NULL, ecran, &position);
position.x=440;
position.y=540;
SDL_BlitSurface(textef, NULL, ecran, &position);
position.x=440;
position.y=646;
SDL_BlitSurface(textem, NULL, ecran, &position);
position.x=440;
position.y=750;
SDL_BlitSurface(textehe, NULL, ecran, &position);
SDL_Flip(ecran);
SDL_Flip(ecran);
  }
else
{
    z=0;
}

position.x=1402;
position.y=738;
x = event.button.x;
y = event.button.y;
 if ( ( x >= position.x ) && ( x <= position.x + position.w ) && ( y >=position.y ) && ( y <=position.y + position.h ) )
  {
a=1;
    texte = TTF_RenderText_Blended(police, "",couleurNoire);
texte4 = TTF_RenderText_Blended(police, " ",couleurNoire);
texte2 = TTF_RenderText_Blended(police, " ",couleurNoire);
texte3= TTF_RenderText_Blended(police, " ",couleurNoire);
texte5= TTF_RenderText_Blended(police, " ",couleurvert);
texte8 = TTF_RenderText_Blended(police, " ",couleurvert);
texte7 = TTF_RenderText_Blended(police, " ",couleurvert);
texte6= TTF_RenderText_Blended(police, " ",couleurvert);
textep=TTF_RenderText_Blended(police, "",couleurgold);
textes=TTF_RenderText_Blended(police, "",couleurgold);
textec=TTF_RenderText_Blended(police, "",couleurgold);
textee=TTF_RenderText_Blended(police, "",couleurgold);
SDL_FreeSurface(imageDeFond0);

               imageDeFond0=IMG_Load("fenetre menu.jpg");
    position.x=0;
position.y=0;
SDL_BlitSurface(imageDeFond0, NULL, ecran, &position);
SDL_Flip(ecran);
  }
  else
  {
      a=0;
  }

    break;
    }


case SDL_MOUSEMOTION:





position.x=1413;
position.y=288;
x = event.motion.x;
y = event.motion.y;
if( ( x >= position.x ) && ( x <= position.x + position.w ) && ( y >=position.y ) && ( y <=position.y + position.h ) )
{

Mix_Chunk *son;
son = Mix_LoadWAV("button-3.wav");
Mix_PlayChannel(1, son,1);
position.x=1425;
position.y=278;
SDL_BlitSurface(texte, NULL, ecran, &position);
position.x=1413;
position.y=288;
SDL_BlitSurface(textep, NULL, ecran, &position);
position.x=1255;
position.y=428;
SDL_BlitSurface(texte2, NULL, ecran, &position);
position.x=1248;
position.y=442;
SDL_BlitSurface(texte7, NULL, ecran, &position);
position.x=1306;
position.y=578;
SDL_BlitSurface(texte3, NULL, ecran, &position);
position.x=1299;
position.y=592;
SDL_BlitSurface(texte6, NULL, ecran, &position);
position.x=1409;
position.y=724;
SDL_BlitSurface(texte4, NULL, ecran, &position);
position.x=1402;
position.y=738;
SDL_BlitSurface(texte8, NULL, ecran, &position);

SDL_Flip(ecran);
}
position.x=0;
position.y=0;
x = 0;
y = 0;
position.x=1248;
position.y=442;
x = event.motion.x;
y = event.motion.y;
if( ( x >= position.x ) && ( x <= position.x + position.w ) && ( y >=position.y ) && ( y <=position.y + position.h ) )
{
Mix_Chunk *son;
son = Mix_LoadWAV("button-3.wav");
Mix_PlayChannel(1, son, 1);
position.x=1425;
position.y=278;
SDL_BlitSurface(texte, NULL, ecran, &position);
position.x=1413;
position.y=288;
SDL_BlitSurface(texte5, NULL, ecran, &position);
position.x=1255;
position.y=428;
SDL_BlitSurface(texte2, NULL, ecran, &position);
position.x=1248;
position.y=442;
SDL_BlitSurface(textes, NULL, ecran, &position);
position.x=1306;
position.y=578;
SDL_BlitSurface(texte3, NULL, ecran, &position);
position.x=1299;
position.y=592;
SDL_BlitSurface(texte6, NULL, ecran, &position);
position.x=1409;
position.y=724;
SDL_BlitSurface(texte4, NULL, ecran, &position);
position.x=1402;
position.y=738;
SDL_BlitSurface(texte8, NULL, ecran, &position);
SDL_Flip(ecran);
position.x=0;
position.y=0;
x = 0;
y = 0;
             }

position.x=1299;
position.y=592;
x = event.motion.x;
y = event.motion.y;
if( ( x >= position.x ) && ( x <= position.x + position.w ) && ( y >=position.y ) && ( y <=position.y + position.h ) )
    {     Mix_Chunk *son;
son = Mix_LoadWAV("button-3.wav");
Mix_PlayChannel(1, son, 1);
position.x=1425;
position.y=278;
SDL_BlitSurface(texte, NULL, ecran, &position);
position.x=1413;
position.y=288;
SDL_BlitSurface(texte5, NULL, ecran, &position);
position.x=1255;
position.y=428;
SDL_BlitSurface(texte2, NULL, ecran, &position);
position.x=1248;
position.y=442;
SDL_BlitSurface(texte7, NULL, ecran, &position);
position.x=1306;
position.y=578;
SDL_BlitSurface(texte3, NULL, ecran, &position);
position.x=1299;
position.y=592;
SDL_BlitSurface(textec, NULL, ecran, &position);
position.x=1409;
position.y=724;
SDL_BlitSurface(texte4, NULL, ecran, &position);
position.x=1402;
position.y=738;
SDL_BlitSurface(texte8, NULL, ecran, &position);
SDL_Flip(ecran);
position.x=0;
position.y=0;
x = 0;
y = 0;
             }
position.x=1402;
position.y=738;
x = event.motion.x;
y = event.motion.y;
if ( ( x >= position.x ) && ( x <= position.x + position.w ) && ( y >=position.y ) && ( y <=position.y + position.h ) )
{
    Mix_Chunk *son;
son = Mix_LoadWAV("button-3.wav");
Mix_PlayChannel(1, son, 1);
 position.x=1425;
position.y=278;
SDL_BlitSurface(texte, NULL, ecran, &position);
position.x=1413;
position.y=288;
SDL_BlitSurface(texte5, NULL, ecran, &position);
position.x=1255;
position.y=428;
SDL_BlitSurface(texte2, NULL, ecran, &position);
position.x=1248;
position.y=442;
SDL_BlitSurface(texte7, NULL, ecran, &position);
position.x=1306;
position.y=578;
SDL_BlitSurface(texte3, NULL, ecran, &position);
position.x=1299;
position.y=592;
SDL_BlitSurface(texte6, NULL, ecran, &position);
position.x=1409;
position.y=724;

SDL_BlitSurface(texte4, NULL, ecran, &position);
position.x=1402;
position.y=738;
SDL_BlitSurface(textee, NULL, ecran, &position);
SDL_Flip(ecran);

}
position.x=0;
position.y=0;
x = 0;
y = 0;

position.x=0;
position.y=0;
x = 0;
y = 0;
position.x=1413;
position.y=288;
x = event.motion.x;
y = event.motion.y;
        if (! ( x >= position.x ) && ( x <= position.x + position.w ) && ( y >=position.y ) && ( y <=position.y + position.h ) )
{

position.x=1425;
position.y=278;
SDL_BlitSurface(texte, NULL, ecran, &position);
position.x=1413;
position.y=288;
SDL_BlitSurface(texte5, NULL, ecran, &position);
position.x=1255;
position.y=428;
SDL_BlitSurface(texte2, NULL, ecran, &position);
position.x=1248;
position.y=442;
SDL_BlitSurface(texte7, NULL, ecran, &position);
position.x=1306;
position.y=578;
SDL_BlitSurface(texte3, NULL, ecran, &position);
position.x=1299;
position.y=592;
SDL_BlitSurface(texte6, NULL, ecran, &position);
position.x=1409;
position.y=724;
SDL_BlitSurface(texte4, NULL, ecran, &position);
position.x=1402;
position.y=738;
SDL_BlitSurface(texte8, NULL, ecran, &position);
SDL_Flip(ecran);
position.x=0;
position.y=0;
x = 0;
y = 0;

             }


position.x=1250;
position.y=590;
x = event.motion.x;
y = event.motion.y;
        if( !( x >= position.x ) && ( x <= position.x + position.w ) && ( y >=position.y ) && ( y <=position.y + position.h ) )
             {

position.x=1248;
position.y=442;
x = event.motion.x;
y = event.motion.y;
position.x=1425;
position.y=278;
SDL_BlitSurface(texte, NULL, ecran, &position);
position.x=1413;
position.y=288;
SDL_BlitSurface(texte5, NULL, ecran, &position);
position.x=1255;
position.y=428;
SDL_BlitSurface(texte2, NULL, ecran, &position);
position.x=1248;
position.y=442;
SDL_BlitSurface(texte7, NULL, ecran, &position);
position.x=1306;
position.y=578;
SDL_BlitSurface(texte3, NULL, ecran, &position);
position.x=1299;
position.y=592;
SDL_BlitSurface(texte6, NULL, ecran, &position);
position.x=1409;
position.y=724;
SDL_BlitSurface(texte4, NULL, ecran, &position);
position.x=1402;
position.y=738;
SDL_BlitSurface(texte8, NULL, ecran, &position);
SDL_Flip(ecran);
position.x=0;
position.y=0;
x = 0;
y = 0;
             }


position.x=1299;
position.y=592;
x = event.motion.x;
y = event.motion.y;
if( !( x >= position.x ) && ( x <= position.x + position.w ) && ( y >=position.y ) && ( y <=position.y + position.h ) )
             {

position.x=1425;
position.y=278;
SDL_BlitSurface(texte, NULL, ecran, &position);
position.x=1413;
position.y=288;
SDL_BlitSurface(texte5, NULL, ecran, &position);
position.x=1255;
position.y=428;
SDL_BlitSurface(texte2, NULL, ecran, &position);
position.x=1248;
position.y=442;
SDL_BlitSurface(texte7, NULL, ecran, &position);
position.x=1306;
position.y=578;
SDL_BlitSurface(texte3, NULL, ecran, &position);
position.x=1299;
position.y=592;
SDL_BlitSurface(texte6, NULL, ecran, &position);
position.x=1409;
position.y=724;
SDL_BlitSurface(texte4, NULL, ecran, &position);
position.x=1402;
position.y=738;
SDL_BlitSurface(texte8, NULL, ecran, &position);
SDL_Flip(ecran);
position.x=0;
position.y=0;
x = 0;
y = 0;
             }
position.x=1402;
position.y=738;
x = event.motion.x;
y = event.motion.y;
if ( !( x >= position.x ) && ( x <= position.x + position.w ) && ( y >=position.y ) && ( y <=position.y + position.h ) )
             {

   position.x=1425;
position.y=278;
SDL_BlitSurface(texte, NULL, ecran, &position);
position.x=1413;
position.y=288;
SDL_BlitSurface(texte5, NULL, ecran, &position);
position.x=1255;
position.y=428;
SDL_BlitSurface(texte2, NULL, ecran, &position);
position.x=1248;
position.y=442;
SDL_BlitSurface(texte7, NULL, ecran, &position);
position.x=1306;
position.y=578;
SDL_BlitSurface(texte3, NULL, ecran, &position);
position.x=1299;
position.y=592;
SDL_BlitSurface(texte6, NULL, ecran, &position);
position.x=1409;
position.y=724;
SDL_BlitSurface(texte4, NULL, ecran, &position);
position.x=1402;
position.y=738;
SDL_BlitSurface(texte8, NULL, ecran, &position);
SDL_Flip(ecran);
position.x=0;
position.y=0;
x = 0;
y = 0;
}
    break;
}
}
}
SDL_FreeSurface(texte);
SDL_FreeSurface(texte2);
SDL_FreeSurface(texte3);
SDL_FreeSurface(texte4);
SDL_FreeSurface(texte5);
SDL_FreeSurface(texte6);
SDL_FreeSurface(texte7);
SDL_FreeSurface(texte8);
SDL_FreeSurface(textec);
SDL_FreeSurface(textee);
SDL_FreeSurface(textep);
SDL_FreeSurface(textes);
SDL_FreeSurface(imageDeFond0);
Mix_FreeMusic(music);
TTF_Quit();
SDL_Quit();
return EXIT_SUCCESS;
}




