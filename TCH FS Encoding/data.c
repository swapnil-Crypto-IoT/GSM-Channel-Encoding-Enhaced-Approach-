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

					C Code to perform data reading
	
-----------------------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>


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
/*	printf("\n******************* The 260 bits voice codec output is ******************* \n\n");
	for(i=0;i<260;i++)
	{
		printf("%d", bits_260[i]);
	}
	printf("\n\n************************************************************************** \n");
*/	fclose(fp);
	
//	return(bits_260);
}
