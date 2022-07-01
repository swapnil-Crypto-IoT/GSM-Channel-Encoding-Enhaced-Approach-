			/*Project from NSCS to C R Rao AIMSCS Hyderabad
		     (Santion Letter No. NSCS/48/18/ dated 1st January 2017)
		  Research Center for researh in  Cryptography and Cryptanalysis
/*----------------------------------------------------------------------------------------------------------

			   Wireless Communication Group (WCS)
	
			Dr. Priyanka Mekala	Dr. Supriya Goel
			(Asst. Prof.) 			(RA)	
	
	Sriramudu	Swapnil Sutar	Kishor M.	Neeraja Neralla		Varun Penchala
	(SRF)		(SRF)		(SRF)		(JRF)			(Project Asst.)
			
/*----------------------------------------------------------------------------------------------------------

					C Code to perform TCH full rate encoding
	
-----------------------------------------------------------------------------------------------------------*/

/**********************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"parity_addition.c"
#include"trailing_reording.c"
#include"convolution.c"

//****************************************************************************************************
unsigned int bits_260[260]={0};
unsigned int read_260()
{
   char ch, file_name[25];
   FILE *fp;
   int i;
  // printf("\n Enter the file name : ");
   //gets(file_name);
   fp = fopen("file.txt", "r"); // read mode
   if (fp == NULL)
   {
      perror("\n file cannot be opened\n");
      exit(EXIT_FAILURE);
   }
    
	for(i=0;i<260;i++)
	{
		bits_260[i] = fgetc(fp)-'0';
	}
	printf("\n ------------------> 260bits codec O/p bits <------------------ \n\n");
	for(i=0;i<260;i++)
	{
		printf("%d", bits_260[i]);
	}
	printf("\n -------------------------------------------------------------- \n\n");
	fclose(fp);
	
//	return(bits_260);
}
//****************************************************************************************************

//****************************************************************************************************
unsigned int bits_temp_456[456]={0};
int main()
{
	unsigned int *bits, i,j;	
	unsigned int inter_block[57][8]={0};
 	clock_t start, end;
	double cpu_time_used;
	start = clock();
//****************************************************************************************************
printf("\n***************************** TCH Encoding (GSM) *******************************************\n");
	read_260();
	bits = parity_addition(bits_260);
	printf("\n ------------------> The 50 + 3 parity bits <------------------ \n\n");
	for(i=0;i<53;i++)
	{
		printf("%d", bits[i]);
	}
	printf("\n\n --------------------------------------------------------------  \n");
	for(i=0;i<53;i++)
	{
		bits_temp_456[i]=bits[i];
	}
//****************************************************************************************************
	bits = trailing_reording1(bits_260);
	printf("\n ------------------> The 50+3+132+4=189bits <------------------ \n\n");
	for(i=0;i<189;i++)
	{
		printf("%d", bits[i]);
	}
	printf("\n\n --------------------------------------------------------------  \n");
	for(i=0;i<189;i++)
	{
		bits_temp_456[i]=bits[i];
	}
//****************************************************************************************************
	bits = convolution(bits_temp_456);
	printf("\n ------------------> Convolution O/p 378bit <------------------ \n\n");
	for(i=0;i<378;i++)
	{
		printf("%d", bits[i]);
	}
	printf("\n\n --------------------------------------------------------------  \n");
	for(i=0;i<378;i++)
	{
		bits_temp_456[i]=bits[i];
	}
//****************************************************************************************************
	for(i=378;i<456;i++) //update final with 456 bits
	{
		bits_temp_456[i]=bits_260[i-196];
	}
	printf("\n ------------------> 456bit I/p to in.leave <------------------ \n\n");
	for(i=0;i<456;i++)
	{
		printf("%d", bits_temp_456[i]);
	}
	printf("\n\n --------------------------------------------------------------  \n");

//****************************************************************************************************
	for(i=0;i<8;i++)
	{
		for(j=0;j<57;j++)
		{
			inter_block[j][i] = bits_temp_456[(j*8)+i];
			//printf("%d, ", inter_block[j][i]);
		}
		//printf("\n");
	}	
	printf("\n");
	printf("\n ------------------> 456bit O/p of in.leave <------------------ \n\n");
	for(i=0;i<8;i++)
	{
		printf("Block (%d) --> ", i+1);		
		for(j=0;j<57;j++)
		{
			//inter_block[j][i] = bits_temp_456[(j*8)+i];
			printf("%d", inter_block[j][i]);
		}
		printf("\n");
	}	
	printf("\n");
//for block diagonal interleaving we required another sample of 260 bits then it is possible to make diagonal interleaving
//****************************************************************************************************
end = clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("TCH/FS encoding(parity,reordering & trailing, convolution,interleaving) \ntakes %f seconds for complete execution \n", cpu_time_used);
} 
