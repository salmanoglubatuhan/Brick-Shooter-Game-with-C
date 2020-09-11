#include <stdio.h> 
#include <stdlib.h> 
  
int main() 
{ 
    int satir,sutun,satirsayac=0,sutunsayac=0, i, j, count=0,cord1,cord2,cordx,cordy,toplam,contx,conty,renksayac=1,scoresum=0,gamecont=0; 
  char a,b,c,renk;
  float kulx=0,kuly=0,cordfx,cordfy;

   scanf("%d %d",&sutun,&satir);
    satir=satir+1;
    char **arr = (char **)malloc(satir * sizeof(char *)); 
    for (i=0; i<satir; i++) 
         arr[i] = (char *)malloc(sutun * sizeof(char)); 
    
  
  while (satirsayac < satir)
    {
        if (satirsayac == 0)
        {  
            while (sutunsayac < sutun)
            {
                if(sutunsayac==0 || sutunsayac==(sutun-1))
                arr[satirsayac][sutunsayac]='|';
                else arr[satirsayac][sutunsayac] = '~';

                sutunsayac++;
            }
        }
        else if (satirsayac == (satir - 1))
        {
            while (sutunsayac < sutun)
            {
                arr[satirsayac][sutunsayac] = ' ';
                sutunsayac++;
            }
        }
        else
        {
            sutunsayac = 0;
            while (sutunsayac < sutun)
            {
                if (sutunsayac == 0)
                {
                    arr[satirsayac][sutunsayac] = '|';
                    sutunsayac++;
                }
                else if (sutunsayac == (sutun - 1))
                {
                    arr[satirsayac][sutunsayac] = '|';
                    sutunsayac++;
                }
                else
                {
                    arr[satirsayac][sutunsayac] = ' ';
                    sutunsayac++;
                }
            }
        }
        sutunsayac = 0;
        satirsayac++;
    }
  scanf("%c",&a);
  satirsayac=1;
   sutunsayac=1;
          while(a!='e')
{   
    if(sutunsayac==(sutun-1))
    {
        satirsayac++;
        sutunsayac=1;
    }
   
   switch (a)
   {
      case 'Y':
        arr[satirsayac][sutunsayac]='Y';
        sutunsayac++;
         break;

         case 'G':
        arr[satirsayac][sutunsayac]='G';
        sutunsayac++;
         break;
      
      case 'R':
         arr[satirsayac][sutunsayac]='R';
         sutunsayac++;
         break;
         
      case 'B':
         arr[satirsayac][sutunsayac]='B';
         sutunsayac++;
      break;
      
      case ' ':
         sutunsayac++;
         count++;
         break;

   }
   scanf("%c",&a);
}          
scanf("%c%c",&c,&b);
scanf("%d %d",&cord1,&cord2);
arr[cord2][cord1]='_';
 for (i = 0; i <  satir-1; i++) 
      {
         for (j = 0; j < sutun; j++) 
         printf("%c",arr[i][j]); 
      printf("\n");
      }      
      printf("\n");
scanf(" %c",&renk);
 scanf("%f %f",&kulx,&kuly);
while(renk != 'q')
{
    cordfy=cord2;
    cordfx=cord1;
     while(1)
     {
         
        contx=cordfx;
        conty=cordfy;
        cordfx+=kulx/100;
        cordfy+=kuly/100;
        cordy=cordfy;
        cordx=cordfx;

        if(arr[cordy][cordx]=='|')
        {
            kulx=kulx*(-1);
            if((kulx==kuly) || (kulx*-1==kuly))
            {if(kulx>0)
           cordfx+=0.0001;
            else if(kulx<0)
           cordfx-=0.0001;
                }        }
        if(arr[cordy][cordx]=='Y' || arr[cordy][cordx]=='R' ||  arr[cordy][cordx]=='B' || arr[cordy][cordx]=='~')
        {
            while(arr[cordy][cordx]!=' ')
            {
                if(((kulx<5 && kulx>0) || (kulx>-5 && kulx<0)) && ((kulx!=kuly) || (kulx*-1!=kuly)))
                cordfx-=kulx/10;
                else
                cordfx-=kulx/100;
                if(((kuly<5 && kuly>0) || (kuly>-5 && kuly<0)) && ((kulx!=kuly) || (kulx*-1!=kuly)))
                cordfy-=kuly/10;
                else
                cordfy-=kuly/100;
                
               
                cordy=cordfy;
                cordx=cordfx;
            }
            arr[cordy][cordx]=renk;
            if(arr[cordy-1][cordx-1]==renk)
            renksayac++;
            if(arr[cordy-1][cordx]==renk)
            renksayac++;
            if(arr[cordy-1][cordx+1]==renk)
            renksayac++;
            if(arr[cordy][cordx-1]==renk)
            renksayac++;
            if(arr[cordy][cordx+1]==renk)
            renksayac++;
            if(arr[cordy+1][cordx-1]==renk)
            renksayac++;
            if(arr[cordy+1][cordx]==renk)
            renksayac++;
            if(arr[cordy+1][cordx+1]==renk)
            renksayac++;
            if(renksayac>=3)
            {
            arr[cordy][cordx]=' ';
            if(arr[cordy-1][cordx-1]==renk)
            arr[cordy-1][cordx-1]=' ';
            if(arr[cordy-1][cordx]==renk)
            arr[cordy-1][cordx]=' ';
            if(arr[cordy-1][cordx+1]==renk)
            arr[cordy-1][cordx+1]=' ';
            if(arr[cordy][cordx-1]==renk)
            arr[cordy][cordx-1]=' ';
            if(arr[cordy][cordx+1]==renk)
            arr[cordy][cordx+1]=' ';
            if(arr[cordy+1][cordx-1]==renk)
            arr[cordy+1][cordx-1]=' ';
            if(arr[cordy+1][cordx]==renk)
            arr[cordy+1][cordx]=' ';
            if(arr[cordy+1][cordx+1]==renk)
            arr[cordy+1][cordx+1]=' ';
            }
            if(renksayac==3)
            {
            scoresum+=30;
            printf("You got 30 points. Score: %d\n",scoresum);
            }
            if(renksayac==4)
            {
                scoresum+=40;
                printf("You got 40 points. Score: %d\n",scoresum);
            }
            if(renksayac>4)
            {
                scoresum+=100;
                printf("You got 100 points. Score: %d\n",scoresum);
            }
            for (i = 0; i <  satir-1; i++) 
        {
               for (j = 0; j < sutun; j++) 
              printf("%c",arr[i][j]); 
         printf("\n");
        }
        printf("\n");

        
            renksayac=1;
            break;
        }

     }
        gamecont=0;
        for (i = 0; i <  satir; i++) 
        {
               for (j = 0; j < sutun; j++) 
               {
              if(arr[i][j]=='Y' || arr[i][j]=='G' || arr[i][j]=='R' || arr[i][j]=='B')
               gamecont++;
               }
        }
        if(gamecont==0)
        break;
    scanf(" %c",&renk);
     scanf("%f %f",&kulx,&kuly);
}
    printf("Game is over. Your score is %d!",scoresum);
   return 0; 
} 
