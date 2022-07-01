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

				C Code to perform Trailing and Reordering
	
-----------------------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
//#include "data.c"
//#include "parity_addition.c"

unsigned int d[189] = {0};
unsigned int *trailing_reording1(unsigned int *bits_260)
{
	unsigned int  bits_132[136]={0}, u[189]={0};
	int i;
/*	p_add = parity_addition(); // p_add is array of 53 bits holding parity added 53 bits
	printf("\n******************* The 50 + 3 parity bits  ****************************** \n\n");
	for(i=0;i<53;i++)
	{
		printf("%d", p_add[i]);
	}
	printf("\n\n************************************************************************** \n");
*/

	//logic to read class 1b 132 bits
	// trailing 4 bits zeroes are already added to the position
	//read_260();
	
	for(i=50;i<182;i++)
	{
		bits_132[i-50]= bits_260[i];
	}

/*	printf("\n******************* The 132 bits + 4 trailing zeroe = 136  ******************* \n\n");
	for(i=0;i<136;i++)
	{
		printf("%d", bits_132[i]);
	}
	printf("\n\n************************************************************************** \n");
*/
	// logic for reordering 
	// u[189] is bit array filled with 50+3+132+4
		
	for(i=0;i<53;i++)
	{
		u[i] = bits_260[i];		//filled all the bits 50+3+132+4
	}
	
	for(i=53;i<189;i++)
	{
		u[i] = bits_132[i-53];  //filled all the bits 50+3+132+4
	}

/*	printf("\n******************* 189 bits 50+3+132+4  ******************* \n\n");
	for(i=0;i<189;i++)
	{
		printf("%d", u[i]);
	}
	printf("\n\n************************************************************************** \n");
*/	

	for(i=0;i<91;i++)
	{
		d[i] = u[2*i];
		d[184-i] = u[(2*i)+1];
	}

	for(i=0;i<3;i++)
	{
		d[91+i] = bits_260[50+i];	
	}

/*	printf("\n******************* ordered d[189] bits 50+3+132+4  ******************* \n\n");
	for(i=0;i<189;i++)
	{
		printf("%d", d[i]);
	}
	printf("\n\n************************************************************************** \n");
*/
return (d);
}
