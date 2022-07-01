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

			C code to create 40 bit remainder using FIRE CODE Polynomial  
	
-----------------------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<unistd.h>

unsigned int inputseq[224]={0};
unsigned int *fire_code(unsigned int *bits_184)
//int main()
{
//struct timeval start, end;

unsigned int poly[41]={1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1};
unsigned int temp[40]={0},i,j;
unsigned int rem[40]={0};



	//position indicator
//	printf("\n the polynomial is:\n");
//	for (i=0;i<41;i++)
//	{
//		printf("%d ",poly[i]);
//	} 
	
	//fill 189 with random value
//	printf("\n");
	for (i=0;i<224;i++)
	{
		if(i<=183)		
		//inputseq[i] = 0x1&rand();
		inputseq[i] = bits_184[i];
		else
		inputseq[i] = 0x0;
	}
//	printf("\n");

//printf("\n the 224 bits are:\n");
/*for (i=0;i<224;i++)
	{
 //printf("\n%d---%d\n",(223-i),inputseq[i]);
	printf("%d ",inputseq[i]);
	}
	printf("\n\n\n");
*/
//gettimeofday(&start, NULL);
	for (i=0;i<224;i++)
	{
	
		for(j=0;j<40;j++)
		{
			
		if(j==0)
		{rem[39-j] = inputseq[i]^temp[0];}
		
			 	else if((j==3)||(j==17)||(j==23)||(j==26)||(j==40))
				{
					rem[39-j] = temp[(39-j)+1]^temp[0];
				}
				else
				{
					rem[39-j] = temp[(39-j)+1]^0;
				}
			
		}


		for (j=0;j<40;j++)
		{
			temp[j] = rem[j];
			printf("%d",rem[j]);		
		}
		if(i<=222)
		printf("---- %d \n",i);
		
		if(i==223)
		printf("<---- %d (Remainder)\n",i);
		//delay(1000000);
	}//224

/*		for (j=0;j<40;j++)
		{
//			temp[j] = rem[j];
			printf("%d",rem[j]);		
		}
printf("\n");
*/
		for (j=0;j<40;j++)
		{
			inputseq[184+j] = rem[j];
//			printf("%d",inputseq[184+j]);		
		}
//printf("\n");

/*		for (j=0;j<224;j++)
		{
			printf("%d",inputseq[j]);		
		}
*/
/*gettimeofday(&end, NULL);
long seconds = (end.tv_sec - start.tv_sec);
long micros = ((seconds*1000000) + end.tv_usec) - (start.tv_usec);
printf("\n Execution time for division is %ld seconds and %ld microseconds\n\n", seconds, micros);
*/
return(inputseq);
}//end main
