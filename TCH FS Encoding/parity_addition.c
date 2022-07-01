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

			C Code to Systematic Block coding and Parity addition
	
-----------------------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
//#include"data.c"

//unsigned int read_260();
//unsigned int *parity_addition();
unsigned int bits_50[53] = {0};
unsigned int *parity_addition(unsigned int *bits_260)
{
	unsigned int parity_bits[3] = {0}, temp[3] = {0};	
	int i,j;		
	
/*	printf("\n******************* The 260 bits voice codec output is ******************* \n\n");
	for(i=0;i<260;i++)
	{
		printf("%d", bits_260[i]);
	}
	printf("\n\n************************************************************************** \n");
*/
	for(i=0;i<50;i++)
	{
		bits_50[i] = bits_260[i]; // assigning 50 bits to process parity addition 
	}
	
	printf("\n ------------------> The 50 + 0 parity bits <------------------ \n\n");
	for(i=0;i<53;i++)
	{
		printf("%d", bits_50[i]);
	}
	printf("\n -------------------------------------------------------------- \n\n");

	// logic to add parity bits here
		
	for(j=0;j<3;j++)
		{		
			temp[j] = 0;
			parity_bits[j] = 0;
		}

	for (i=0;i<53;i++)
	{
	  parity_bits[2] = bits_50[i]  ^ temp[0];
	  parity_bits[1] = temp[2] ^ temp[0];
	  parity_bits[0] = 0 ^ temp[1];			
		for (j=0;j<3;j++)
		{
			temp[j] = parity_bits[j];
	//		printf(" %d ",parity_bits[j]);		
		}
		
	//	if(i<=51)
	//	printf("---- %d \n",i);
		
	//	if(i==52)
	//	printf("<---- %d (Remainder)\n",i);
		//delay(1000000);
	}

	for(j=0;j<3;j++)
	{
		bits_50[50+j] = parity_bits[j];
	}


/*	printf("\n******************* The 50 + 3 parity bits  ****************************** \n\n");
	for(i=0;i<53;i++)
	{
		printf("%d", bits_50[i]);
	}
	printf("\n\n************************************************************************** \n");
*/

return (bits_50);
}
