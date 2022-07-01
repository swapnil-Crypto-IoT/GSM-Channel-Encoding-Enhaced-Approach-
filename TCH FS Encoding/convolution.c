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

					C Code to perform Convolution
	
-----------------------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>


unsigned int bits_378[378]={0};
unsigned int *convolution(unsigned int *bits_260)
{
	unsigned int G0[4] ={0,0,0,0},G1[4] = {0,0,0,0};
	unsigned int output1,output2;
	int i,j;
	unsigned int temp1,temp2;
//	unsigned int *bits_189_in ;	
	
//	printf("the Generator polynomials are:\n");
//	bits_189_in = trailing_reording1();

/*	printf("\n******************* trailing & re-ordering 189 ****************************** \n\n");
	for(i=0;i<189;i++)
	{
		printf("%d", bits_189_in[i]);
	}
	printf("\n\n************************************************************************** \n");
   //  printf("\n");
 */   
	 for(j=0;j<189;j++)
     {
	
	// printf("input message bit  is:%d\n",bits_189_in[j]);
	// printf("\n");

	 /*taping the register */
	 temp1=G0[2]^G0[3]^bits_260[j];
      temp2=G1[0]^G1[2]^G1[3]^bits_260[j];
      output1=temp1&0x1;
	 output2=temp2&0x1;

	bits_378[j*2]= output1;
	bits_378[(j*2)+1] = output2;


	/*update the contents of sift register*/
	    //G0[5]=G0[4];
	    //G0[4]=G0[3];
	    G0[3]=G0[2];
	    G0[2]=G0[1];
	    G0[1]=G0[0];
	    G0[0]= bits_260[j];  
	
		//G1[5]=G1[4];
		//G1[4]=G1[3];
		G1[3]=G1[2];
		G1[2]=G1[1];
		G1[1]=G1[0];
		G1[0]= bits_260[j];
  }

/*	printf("\n******************* 378 bits  convolution prg output  ****************************** \n\n");
	for(i=0;i<378;i++)
	{
		printf("%d", bits_378[i]);
	}
	printf("\n\n************************************************************************** \n");
*/
return(bits_378);

}
