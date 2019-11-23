#include <stdio.h>

int main(){
   int aposta[6], resultado[6], acertos=0;

   for(int i = 0; i < 6; i++){
      scanf("%d", &aposta[i]);
   }
   for(int i = 0; i < 6; i++){
      scanf("%d", &resultado[i]);
   }
   for(int i = 0; i < 6; i++){
      int ok = 0;
      for(int j = 0; j < 6; j++){
         if( aposta[i]==resultado[j] ){
            ok = 1;
         }
      }
      if( ok==1 ){
         acertos++;
      }
   }
   if(acertos==3){
      printf("terno\n");
   }else if( acertos==4 ){
      printf("quadra\n");
   }else if( acertos==5 ){
      printf("quina");
   }else if( acertos==6 ){
      printf("sena");
   }else{
      printf("azar\n");
   }
}
