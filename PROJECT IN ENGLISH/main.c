#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <strings.h>


char user[100][10], password[100][20], user1[10], password1[20], productChoice[100][20], Adress[4][30], number[100];
int attempts=0, totalUsers=0, paymentChoice, unidadeCoffee=0, unidadeCheeseBread=0, unidadePizza=0, unidadeFries=0, unidadeHamburguer=0, unidadeSoda=0, unidadeJuice=0;
float precoTotal=0, valordotroco, vtroco;


void menu()
{
    printf("\n\t\t\t******WELCOME******\n\n\t\t\t-TYPE 1 TO REGISTER USER.\n\t\t\t-TYPE 2 TO LOGIN.\n\t\t\t-TYPE EXIT TO END PROGRAM.\n\n");
    fflush(stdin);
    scanf("%[^\n]", number);
    int sexo=1;
    while(sexo==1)
    {if(strcmp(number,"1")==0)
        {cadastrar();
        return;
        }

    else if(strcmp(number,"2")==0)
        {login();
        return;
        }

    else if(stricmp(number,"exit")==0)
        {printf("\nPROGRAM ENDED\n");
        break;
        }

    else
        {printf("\nINVALID COMMAND, TYPE AGAIN\n");
         fflush(stdin);
         scanf("%[^\n]", number);
        }

    }

}

void cadastrar()
{int loop=0;
    while (loop==0)
    {
        printf("\nEnter a username to create your login (spacebar not allowed):\n\n");
        scanf(" %[^\n]", user[totalUsers]);

        if (strchr(user[totalUsers], ' ') != NULL)
        {
            printf("\nUsername can't contain spacebar...\n\n");
        }
        else
        {
            int duplicate = 0;

            for (int i = 0; i < totalUsers; i++)
            {
                if (strcmp(user[totalUsers], user[i]) == 0)
                {
                    printf("\nUsername already registered...\n\n");
                    duplicate = 1;
                    break;
                }
            }

            if (duplicate==0)
            {
                break;
            }
        }
    }
    printf("\nEnter a password:\n\n");
    scanf("%s", password[totalUsers]);
    totalUsers++;

    printf("\nWell Done! User and password successfully registered\n");
    printf("\nPress any key to return to menu...");
    getch();
    system("cls");
    menu();
}

void login()
{
    printf("\nEnter your username:\n\n");
    scanf("%s", user1);

    int achou=0;
    int indexuser;
    while (achou==0) {
        for (int i = 0; i < totalUsers; i++) {
            if (strcmp(user1,user[i])==0) {
                achou = 1;
                indexuser = i;
                break;
            }
        }

        if (achou==0) {
            printf("\nUser not registered, enter a valid user or press 3 to go back to menu:\n\n");
            scanf("%s", user1);
            if(strcmp(user1, "3")==0) {
                system("cls");
                menu();
                return;
            }
        }
    }

    printf("\nEnter your password:\n\n");
    scanf("%s", password1);

    while(strcmp(password[indexuser], password1)!=0)

        {   attempts++;
            if(attempts==1)
            {
            printf("\nACESSO DENIED, TRY AGAIN, 3 attempts left:\n\n");
            scanf("%s", password1);
            }
            if(attempts==2)
            {
            printf("\nACESSO DENIED, TRY AGAIN, 2 attempts left:\n\n");
            scanf("%s", password1);
            }
            if(attempts==3)
            {
            printf("\nACESSO DENIED, TRY AGAIN, 1 attempt left:\n\n");
            scanf("%s", password1);
            }
            if(attempts==4)
            {
            printf("\nACESS BLOCKED\n\n");
            return 0;
            }

    }

    printf("\nACESSO GRANTED!\n\n");
    printf("Press any key to acess the Virtual Cafeteria...\n\n");
    getch();
    menulanchonete();
}


void menulanchonete()
{
    system("cls");
    printf("\n\t******Welcome to Virtual Cafeteria******\n\n");

    printf(" 1.Coffee----------$5,00\n");
    printf(" 2.Cheese Bread----$4,00\n");
    printf(" 3.Pizza-----------$5,50\n");
    printf(" 4.Fries-----------$6,00\n");
    printf(" 5.Hamburguer------$5,00\n");
    printf(" 6.Soda------------$3,50\n");
    printf(" 7.Juice-----------$3,00\n\n");

    printf("Type in your order, one by one, type 0 to end your order and proceed to checkout or type 'back' to go back to main menu:\n\n");

    for(int i=1; i<=100000;i++)
    {fflush(stdin);
        scanf("%[^\n]", productChoice);
        if(strcmp(productChoice,"0")==0)
         {carrinho();
         return;
         }
         if(stricmp(productChoice,"coffee")==0 || strcmp(productChoice,"1")==0)
           {precoTotal+=5;
           unidadeCoffee++;
           }
         else if(stricmp(productChoice,"cheese bread")==0 || strcmp(productChoice,"2")==0)
         {precoTotal+=4;
         unidadeCheeseBread++;
         }
        else if(stricmp(productChoice,"pizza")==0 || strcmp(productChoice,"3")==0)
           {precoTotal+=5.5;
            unidadePizza++;
           }
        else if(stricmp(productChoice,"fries")==0 || strcmp(productChoice,"4")==0)
         {precoTotal+=6;
         unidadeFries++;
         }
        else if(stricmp(productChoice,"hamburguer")==0 || strcmp(productChoice,"5")==0)
           {precoTotal+=5;
            unidadeHamburguer++;
           }
        else if(stricmp(productChoice,"soda")==0 || strcmp(productChoice,"6")==0)
         {precoTotal+=3.5;
          unidadeSoda++;
         }
        else if(stricmp(productChoice,"juice")==0 || strcmp(productChoice,"7")==0)
           {precoTotal+=3;
           unidadeJuice++;
           }
        else if(stricmp(productChoice,"back")==0)
        {
            system("cls");
            menu();
        }
        else
        {
        printf("\nItem not registered, try again\n\n");
        }

      }

    }

void carrinho()
{
     if(unidadeCoffee==0 && unidadeCheeseBread==0 && unidadePizza==0 && unidadeFries==0 && unidadeHamburguer==0 && unidadeSoda==0 && unidadeJuice==0)
        {
         system("cls");
         printf("\nChoose at least 1 item to proceed to checkout:\n\n");
         printf("Press any key to go back to the cafeteria menu...");
         getch();
         menulanchonete();

        }
    system("cls");
    printf("\n***CART***\n");

    if(unidadeCoffee==1)
        printf("--%d Cup of Coffee\n", unidadeCoffee);
        else if(unidadeCoffee>1)
        printf("--%d Cups of Coffee\n", unidadeCoffee);

     if(unidadeCheeseBread==1)
        printf("--%d Cheese Bread\n", unidadeCheeseBread);
        else if(unidadeCheeseBread>1)
        printf("--%d Cheese Breads\n", unidadeCheeseBread);

     if(unidadePizza==1)
        printf("--%d Slice of Pizza\n", unidadePizza);
        else if(unidadePizza>1)
        printf("--%d Slices of Pizza\n", unidadePizza);

     if(unidadeFries==1)
        printf("--%d Portion of Fries\n", unidadeFries);
        else if(unidadeFries>1)
        printf("--%d Portions of Fries\n", unidadeFries);

     if(unidadeHamburguer==1)
        printf("--%d Hamburguer\n", unidadeHamburguer);
        else if(unidadeHamburguer>1)
        printf("--%d Hamburguers\n", unidadeHamburguer);

     if(unidadeSoda==1)
        printf("--%d Can of Soda\n", unidadeSoda);
        else if(unidadeSoda>1)
        printf("--%d Cans of Soda\n", unidadeSoda);

     if(unidadeJuice==1)
        printf("--%d Cup of Juice\n", unidadeJuice);
        else if(unidadeJuice>1)
        printf("--%d Cups of Juice\n", unidadeJuice);


        printf("\nTotal: $%.1f", precoTotal);
        printf("\n\n\nPayment Method:\n\n");
        printf("1-Cash\n2-Credit Card\n3-Debit Card\n\n");
        scanf("%d", &paymentChoice);
        while(paymentChoice<1 || paymentChoice>3)
        {
            printf("\nInvalid Number, choose a number according to your payment method:\n\n");
            printf("1-Cash\n2-Credit Card\n3-Debit Card\n\n");
            scanf("%d", &paymentChoice);

        }
        int troco;
        if(paymentChoice==1)
        {  int loop=1;
             while(loop==1)
            {printf("\n1-Change\n2-No Change\n\n");
             scanf("%d", &troco);
             if(troco==1)
             {
             printf("\nHow much do you have?($)\n");
              scanf("%f", &vtroco);
              while(vtroco<precoTotal)
              {
                  printf("\nNot enough money, type again\n");
                  scanf("%f", &vtroco);
              }
              valordotroco=vtroco-precoTotal;
              printf("\nChange: $%.2f\n", valordotroco);
              PedirEndereco();
              return;
             }
             if(troco==2)
                  {
                   PedirEndereco();
                   return;
                  }
             else
                printf("\nINVALID COMMAND, TRY AGAIN\n");

             }

            }

        PedirEndereco();

        }

void PedirEndereco()
{
    printf("\nType your adress:\n");
    printf("\nCITY: ");
    fflush(stdin);
    scanf("%[^\n]", Adress[0]);
    printf("DISTRICT: ");
    fflush(stdin);
    scanf("%[^\n]", Adress[1]);
    printf("STREET: ");
    fflush(stdin);
    scanf("%[^\n]", Adress[2]);
    printf("NUMBER: ");
    fflush(stdin);
    scanf("%[^\n]", Adress[3]);

    system("cls");

    printf("\nORDER PLACED!\n\n");
    printf("**Order Summary**\n");
    if(unidadeCoffee==1)
        printf("--%d cup of Coffee\n", unidadeCoffee);
        else if(unidadeCoffee>1)
        printf("--%d cups of Coffee\n", unidadeCoffee);

     if(unidadeCheeseBread==1)
        printf("--%d Cheese Bread\n", unidadeCheeseBread);
        else if(unidadeCheeseBread>1)
        printf("--%d Cheese Breads\n", unidadeCheeseBread);

     if(unidadePizza==1)
        printf("--%d slice of Pizza\n", unidadePizza);
        else if(unidadePizza>1)
        printf("--%d slices of Pizza\n", unidadePizza);

     if(unidadeFries==1)
        printf("--%d portion of Fries\n", unidadeFries);
        else if(unidadeFries>1)
        printf("--%d portions of Fries\n", unidadeFries);

     if(unidadeHamburguer==1)
        printf("--%d Hamburguer\n", unidadeHamburguer);
        else if(unidadeHamburguer>1)
        printf("--%d Hamburguers\n", unidadeHamburguer);

     if(unidadeSoda==1)
        printf("--%d can of Soda\n", unidadeSoda);
        else if(unidadeSoda>1)
        printf("--%d cans of Soda\n", unidadeSoda);

     if(unidadeJuice==1)
        printf("--%d cup of Juice\n", unidadeJuice);
        else if(unidadeJuice>1)
        printf("--%d cups of Juice\n", unidadeJuice);

printf("\nPayment Method:\n");
if(paymentChoice==1)
    printf("--Cash");
else if(paymentChoice==2)
    printf("--Credit Card");
else if(paymentChoice==3)
    printf("--Debit Card");
if(valordotroco>0)
    printf("\nTroco: $%.2f", valordotroco);

printf("\n\nAdress: %s, %s, %s, %s.\n\n", Adress[0], Adress[1], Adress[2], Adress[3]);

}

int main()

{

    menu();

}


