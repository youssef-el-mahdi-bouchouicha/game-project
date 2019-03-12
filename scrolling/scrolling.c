#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


int main()
{
SDL_Surface *ecran = NULL, *imageDeFond = NULL,*imageDePerso=NULL;
int x=0,y=0,i;


    SDL_Rect positionFond ,positionmilieu;

    positionFond.x = 0;
    positionFond.y = 0;
    positionFond.h =700;
    positionFond.w =1200;

    

    
    positionmilieu.x = 600;
    positionmilieu.y = 350 ;
     SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(1200, 700, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Chargement Backgroung", NULL);

    
    imageDeFond = IMG_Load("back3.png");
    imageDePerso = IMG_Load("cercle.png");
    

  SDL_BlitSurface(imageDeFond,&positionFond, ecran, NULL);
                SDL_BlitSurface(imageDePerso,NULL, ecran, &positionmilieu);
                
    SDL_Flip(ecran);
    
 
   
    int continuer = 1;
    SDL_Event event;
    SDL_EnableKeyRepeat(10, 10);
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer =0;
                break;
            case SDL_KEYDOWN:

        switch(event.key.keysym.sym)

        {

            case SDLK_RIGHT: // Flèche droite
            	
                if  (positionmilieu.x>800 && positionFond.x<=6255)
        
            positionFond.x +=10;
        else if (positionmilieu.x<=900) 
            positionmilieu.x +=10;
            
       
                SDL_BlitSurface(imageDeFond,&positionFond, ecran, NULL);
                SDL_BlitSurface(imageDePerso,NULL, ecran, &positionmilieu);
                
    SDL_Flip(ecran);

                break;

            case SDLK_LEFT: // Flèche gauche
            	if (positionmilieu.x<=400&& positionFond.x>=10)
        
            positionFond.x -= 10;
        
    else if (positionmilieu.x>=10)  
        positionmilieu.x -= 10;
         
                SDL_BlitSurface(imageDeFond,&positionFond, ecran, NULL);
				SDL_BlitSurface(imageDePerso,NULL, ecran, &positionmilieu);
                
    SDL_Flip(ecran);

                break;
         case SDLK_UP: // Flèche haut
            	if (positionmilieu.y<=100 && positionFond.y>=5)
        
            positionFond.y-= 10;
        
    else if (positionmilieu.y>=10)  
        positionmilieu.y -= 10;
         
                SDL_BlitSurface(imageDeFond,&positionFond, ecran, NULL);
		SDL_BlitSurface(imageDePerso,NULL, ecran, &positionmilieu);
                
    SDL_Flip(ecran);

                break;
       case SDLK_DOWN: // Flèche bas
            	
                if  (positionmilieu.y>=550&& positionFond.y<=40)
        
            positionFond.y+= 10;
        else if (positionmilieu.y<=650) 
            positionmilieu.y +=10;
            
       
                SDL_BlitSurface(imageDeFond,&positionFond, ecran, NULL);
                SDL_BlitSurface(imageDePerso,NULL, ecran, &positionmilieu);
                
    SDL_Flip(ecran);
              

        }

        break;    
        }

       
        
    SDL_Flip(ecran);
    }


    SDL_FreeSurface(imageDeFond); 
    SDL_Quit();

    return EXIT_SUCCESS;
}
