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

			C code for SACCH encoding (GSM communication System)  
	
-----------------------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
//#include"parity_addition.c"
//#include"trailing_reording.c"
#include"convolution.c"
#include"fire_code.c"
#include<time.h>

//****************************************************************************************************
unsigned int bits_184[228]={0};
unsigned int read_184()
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
    
	for(i=0;i<184;i++)
	{
		bits_184[i] = fgetc(fp)-'0';
	}
	printf("\n ------------------> 184bits sacch input bits <------------------ \n\n");
	for(i=0;i<184;i++)
	{
		printf("%d", bits_184[i]);
	}
	printf("\n -------------------------------------------------------------- \n\n");
	fclose(fp);
	
//	return(bits_184);
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
printf("\n********************************* SACCH encoding ************************************************\n");
	read_184();
	bits = fire_code(bits_184);	
	printf("\n ------------------> The firecode o/p 224+4 <------------------ \n\n");
	for(i=0;i<224;i++)
	{
		printf("%d", bits[i]);
	}
	printf("\n\n --------------------------------------------------------------  \n");
	for(i=0;i<224;i++)
	{
		bits_temp_456[i]=bits[i];
	}
	for(i=224;i<228;i++)
	{
		bits_temp_456[i]=0;
	}

	for(i=0;i<228;i++)
	{
		printf("%d", bits_temp_456[i]);
	}
	printf("\n\n --------------------------------------------------------------  \n");

//****************************************************************************************************
/*	bits = trailing_reording1(bits_184);
	printf("\n ------------------> The 50+3+132+4=189bits <------------------ \n\n");
	for(i=0;i<189;i++)
	{
		printf("%d", bits[i]);
	}
	printf("\n\n --------------------------------------------------------------  \n");
	for(i=0;i<189;i++)
	{
		bits_temp_456[i]=bits[i];
	}*/
//****************************************************************************************************
	bits = convolution(bits_temp_456);
	printf("\n ------------------> Convolution O/p 456bit <------------------ \n\n");
	for(i=0;i<456;i++)
	{
		printf("%d", bits[i]);
	}
	printf("\n\n --------------------------------------------------------------  \n");
	for(i=0;i<456;i++)
	{
		bits_temp_456[i]=bits[i];
	}

/*	for(i=0;i<456;i++)
	{
		printf("%d", bits_temp_456[i]);
	}
	printf("\n\n --------------------------------------------------------------  \n");
*/

//****************************************************************************************************
/*	for(i=378;i<456;i++) //update final with 456 bits
	{
		bits_temp_456[i]=bits_184[i-196];
	}
*/	printf("\n ------------------> 456bit I/p to in.leave <------------------ \n\n");
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
		printf("Block (%d) --> ", i);		
		for(j=0;j<57;j++)
		{
			//inter_block[j][i] = bits_temp_456[(j*8)+i];
			printf("%d", inter_block[j][i]);
		}
		printf("\n");
	}	
	printf("\n");
//****************************************************************************************************/

	printf("\n ------------------> Block Rectangular Interleaving <------------------ \n\n");
	for(i=0;i<8;i++)
	{
		printf("Block (%d) --> ", i);		
		for(j=0;j<57;j++)
		{
			printf("%d", inter_block[j][i]);
		}
		printf("\n"); 
		if(((i+1)%2)==0)
		printf("\n");
	}	
	printf("\n");

end = clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("Channel encoding(input:184 output:456) \ntakes %f seconds for complete execution \n", cpu_time_used);
	
} 
