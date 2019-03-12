#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
void setrects(SDL_Rect* clip){
clip[0].x=0;
clip[0].y=0;
clip[0].w=256;
clip[0].h=256;

clip[1].x=256;
clip[1].y=0;
clip[1].w=256;
clip[1].h=256;

clip[2].x=506;
clip[2].y=0;
clip[2].w=256;
clip[2].h=256;

clip[3].x=756;
clip[3].y=0;
clip[3].w=256;
clip[3].h=256;

clip[4].x=1006;
clip[4].y=0;
clip[4].w=256;
clip[4].h=256;

clip[5].x=1256;
clip[5].y=0;
clip[5].w=256;
clip[5].h=256;

clip[6].x=1506;
clip[6].y=0;
clip[6].w=256;
clip[6].h=256;


}
int main(int argc,char** argv)
{
SDL_Init(SDL_INIT_EVERYTHING);
SDL_Surface*screen,*image;
screen=SDL_SetVideoMode(640,480,32,SDL_SWSURFACE);
int running=1;

SDL_Rect rect;
int frame=0;
rect.x=10;
rect.y=10;
rect.w=20;
rect.h=20;

image=IMG_Load("1.png");
SDL_Rect rects[7];
setrects(rects);
SDL_SetColorKey(image, SDL_SRCCOLORKEY, SDL_MapRGB(screen->format, 0x00, 0xff, 0xff));
while(running)
{

                SDL_Event event;
                while(SDL_PollEvent(&event)) {
                        switch(event.type) {
                                case SDL_QUIT:
                                        running = 0;
                                        break;
						}
					}
SDL_FillRect(screen,&screen->clip_rect,0x00);
SDL_FillRect(screen,&rect,0x00);
SDL_Rect rect;
rect.x=200;
rect.y=100;

SDL_BlitSurface(image,&rects[frame],screen,&rect);
SDL_Flip(screen);
frame++;
if(frame==6){
frame=0;
}

	SDL_Delay(250);


}

SDL_FreeSurface(image);
SDL_Quit();

return 0;
}
