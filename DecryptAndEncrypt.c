#include <stdio.h>
#include <string.h>

#define MAX_BUF  256

unsigned char getBit(unsigned char, int);
unsigned char setBit(unsigned char, int);
unsigned char clearBit(unsigned char, int);
unsigned char skipx(unsigned char, unsigned char);
unsigned char rotr(unsigned char);


int main()
{
  char str[8];
  int  choice;
  //let the user choose encrypt or decrypt
  printf("\nYou may:\n");
  printf("  (1) Encrypt a message \n");
  printf("  (2) Decrypt a message \n");
  printf("\n  what is your seletion: ");
  //input choice
  fgets(str, sizeof(str), stdin);
  sscanf(str, "%d", &choice);
  unsigned char key;
  switch (choice) {
  unsigned char plaintext[MAX_BUF];
  unsigned char encrypted[MAX_BUF];
  unsigned char key;//key for encryption
  int intKey;
    case 1:// when user chose to encrypt
     { printf("enter a plaintext message:\n");
      fgets(plaintext,sizeof(plaintext),stdin);
      plaintext[strlen(plaintext)-1]='\0';//input plaintext message
       printf("enter a numeric key(0~255):\n");
       scanf("%d",&intKey);//input key
       key=intKey;
       int a;//for for loop
       for(a=0;a<strlen(plaintext);a++)
     {
      printf("%d ",skipx(plaintext[a],key));
      key=rotr(key);
     }
      break;
    }
//when user chose decryption
    case 2:
{
	printf("enter a ciphertext message:\n");
	int i=0;//index
  	int b=0;
	while(scanf("%d",&b)!=-1&&b!=-1)

	{
	
	encrypted[i]=b;
	i++;
	}	
        encrypted[i]='\n';
        //ask user to input key
	printf("enter a numeric key(0~255):\n");
        scanf("%d",&intKey);
        key=intKey;
        int a=0;
	 while(a<i)
	{
	 //print out the output
	 printf("%c",skipx(encrypted[a],key));
	key=rotr(key);
	a++;
	}
       
	
	 
      break;
}
    default:

      break;
  }

  return 0;
}

//skipx function
unsigned char skipx(unsigned char c, unsigned char key)
{
 unsigned char resulting=c;
int i;
 
  for (i=7;i>=1;i-=2)
{
//loop over every odd-numbered bit of the source byte, starting at bit position 7
//perform xor operation
   if((getBit(c,i)^getBit(key,i-1))==1)
{
   resulting=setBit(resulting,i);
}
else
{
  resulting=clearBit(resulting,i);
}
}
return resulting;
}
//rotr function
unsigned char rotr(unsigned char c)
{
// shift all the bits one position to the right

c=(c>>1)|(c<<7);


return c;

}

/*
  Function:  getBit
  Purpose:   retrieve value of bit at specified position
       in:   character from which a bit will be returned
       in:   position of bit to be returned
   return:   value of bit n in character c (0 or 1)
*/
unsigned char getBit(unsigned char c, int n)   
{ 
  return (c&(1<<n))>>n;
}

/*
  Function:  setBit
  Purpose:   set specified bit to 1
       in:   character in which a bit will be set to 1
       in:   position of bit to be set to 1
   return:   new value of character c with bit n set to 1
*/
unsigned char setBit(unsigned char c, int n)   
{ 
  return c | (1<<n);
}

/*
  Function:  clearBit
  Purpose:   set specified bit to 0
       in:   character in which a bit will be set to 0
       in:   position of bit to be set to 0
   return:   new value of character c with bit n set to 0
*/
unsigned char clearBit(unsigned char c, int n) 
{ 
return c&(~(1<<n));

}


