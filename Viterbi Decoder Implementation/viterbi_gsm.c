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

			C Code to perform deconvolution using Viterbi Algorithm (Control Channel)
	
-----------------------------------------------------------------------------------------------------------*/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main()
{
unsigned int input[228]={1,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,1,0,1,0,1,1,0,1,1,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,0,1,1,0,0,1,0,1,0,0,0,1,0,1,0,0,1,0,0,1,0,1,0,1,1,0,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,1,0,1,0,1,1,0,1,1,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,0,1,1,0,0,1,0,1,0,0,0,1,0,1,0,0,1,0,0,1,0,1,0,1,1,0,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,0,0,0,1,1,1,1,1,1,0,1,0,0,0,1,0,1,1,1,1,0,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,0,0,0,1,0,0,1,0,1,1,0,0,0,0,0}/*{1,0,1,1,0,1,0,1,0,0}*/, i,j,k, output[456] ={0};
	signed int soft_de[456] = {0}, branch_metrics[16][228]={0};
	signed int state_metrics[16][229]={0},t1,t2,state_metrics_s[16][229]={0};
	unsigned int state = 0x0, state_transition[229]={0}, state_decode[229]={0};
	clock_t start, end;
     	double cpu_time_used;

 start = clock();
printf("\n---------------------------------Viterbi algorithm control channel----------------------------\n");
printf("\n---------------------------------The consider input pair is :---------------------------------\n");
	for (i=0;i<228;i++)
	{
//		input[i] = 0x1&rand(); //feeding the array with random 228 input sequence bit
		printf("%d",input[i]);
	}
	
	printf("\n");
//**************************************/	
	for(i=0;i<228;i++)
	{
	if(state == 0x0)
		{
			if(input[i] == 0)
			{
			 output[i*2] = 0;
			 output[(i*2)+1] = 0;
			 state = 0x0;		
			}
			
		else//	if(input[i] == 1)
			{
			 output[i*2] = 1;
			 output[(i*2)+1] = 1;
			 state = 0x8;		
			}
		}

	else if(state == 0x1)
		{
			if(input[i] == 0)
			{
			 output[(i*2)] = 1;
			 output[(i*2)+1] = 1;
			 state = 0x0;		
			}
			
			else //if(input[i] == 1)
			{
			 output[(i*2)] = 0;
			 output[(i*2)+1] = 0;
			 state = 0x8;		
			}
		}

	 else if(state == 0x2)
		{
			if(input[i] == 0)
			{
			 output[(i*2)] = 1;
			 output[(i*2)+1] = 1;
			 state = 0x1;		
			}
			
		else	//if(input[i] == 1)
			{
			 output[(i*2)] = 0;
			 output[(i*2)+1] = 0;
			 state = 0x9;		
			}
		}

	else if(state == 0x3)
		{
			if(input[i] == 0)
			{
			 output[(i*2)] = 0;
			 output[(i*2)+1] = 0;
			 state = 0x1;		
			}
			
		else//	if(input[i] == 1)
			{
			 output[(i*2)] = 1;
			 output[(i*2)+1] = 1;
			 state = 0x9;		
			}
		}


	else if(state == 0x4)
		{
			if(input[i] == 0)
			{
			 output[(i*2)] = 0;
			 output[(i*2)+1] = 0;
			 state = 0x2;		
			}
			
		else//	if(input[i] == 1)
			{
			 output[(i*2)] = 1;
			 output[(i*2)+1] = 1;
			 state = 0xa;		
			}
		}

	else if(state == 0x5)
		{
			if(input[i] == 0)
			{
			 output[(i*2)] = 1;
			 output[(i*2)+1] = 1;
			 state = 0x2;		
			}
			
		else//	if(input[i] == 1)
			{
			 output[(i*2)] = 0;
			 output[(i*2)+1] = 0;
			 state = 0xa;		
			}
		}

	else if(state == 0x6)
		{
			if(input[i] == 0)
			{
			 output[(i*2)] = 1;
			 output[(i*2)+1] = 1;
			 state = 0x3;		
			}
			
		else//	if(input[i] == 1)
			{
			 output[(i*2)] = 0;
			 output[(i*2)+1] = 0;
			 state = 0xb;		
			}
		}

	else if(state == 0x7)
		{
			if(input[i] == 0)
			{
			 output[(i*2)] = 0;
			 output[(i*2)+1] = 0;
			 state = 0x3;		
			}
			
		else//	if(input[i] == 1)
			{
			 output[(i*2)] = 1;
			 output[(i*2)+1] = 1;
			 state = 0xb;		
			}
		}

	else if(state == 0x8)
		{
			if(input[i] == 0)
			{
			 output[(i*2)] = 0;
			 output[(i*2)+1] = 1;
			 state = 0x4;		
			}
			
		else//	if(input[i] == 1)
			{
			 output[(i*2)] = 1;
			 output[(i*2)+1] = 0;
			 state = 0xc;		
			}
		}

	else if(state == 0x9)
		{
			if(input[i] == 0)
			{
			 output[(i*2)] = 1;
			 output[(i*2)+1] = 0;
			 state = 0x4;		
			}
			
		else//	if(input[i] == 1)
			{
			 output[(i*2)] = 0;
			 output[(i*2)+1] = 1;
			 state = 0xc;		
			}
		}

	else if(state == 0xa)
		{
			if(input[i] == 0)
			{
			 output[(i*2)] = 1;
			 output[(i*2)+1] = 0;
			 state = 0x5;		
			}
			
		else//	if(input[i] == 1)
			{
			 output[(i*2)] = 0;
			 output[(i*2)+1] = 1;
			 state = 0xd;		
			}
		}

	else if(state == 0xb)
		{
			if(input[i] == 0)
			{
			 output[(i*2)] = 0;
			 output[(i*2)+1] = 1;
			 state = 0x5;		
			}
			
		else//	if(input[i] == 1)
			{
			 output[(i*2)] = 1;
			 output[(i*2)+1] = 0;
			 state = 0xd;		
			}
		}

	else if(state == 0xc)
		{
			if(input[i] == 0)
			{
			 output[(i*2)] = 0;
			 output[(i*2)+1] = 1;
			 state = 0x6;		
			}
			
		else//	if(input[i] == 1)
			{
			 output[(i*2)] = 1;
			 output[(i*2)+1] = 0;
			 state = 0xe;		
			}
		}


	else if(state == 0xd)
		{
			if(input[i] == 0)
			{
			 output[(i*2)] = 1;
			 output[(i*2)+1] = 0;
			 state = 0x6;		
			}
			
		else//	if(input[i] == 1)
			{
			 output[(i*2)] = 0;
			 output[(i*2)+1] = 1;
			 state = 0xe;		
			}
		}

	else if(state == 0xe)
		{
			if(input[i] == 0)
			{
			 output[(i*2)] = 1;
			 output[(i*2)+1] = 0;
			 state = 0x7;		
			}
			
		else//	if(input[i] == 1)
			{
			 output[(i*2)] = 0;
			 output[(i*2)+1] = 1;
			 state = 0xf;		
			}
		}

		else //if(state == 0xf)
		{
			if(input[i] == 0)
			{
			 output[(i*2)] = 0;
			 output[(i*2)+1] = 1;
			 state = 0x7;		
			}
			
			else//	if(input[i] == 1)
			{
			 output[(i*2)] = 1;
			 output[(i*2)+1] = 0;
			 state = 0xf;		
			}
		}


	} //end of for
//**************************************/
printf("\n-----------Encoded output pairs------\n");
	for (i=0;i<228;i++)
	{
		printf("(%d,%d) ",output[(i*2)],output[(i*2)+1]);
	if((i+1)%10==0){printf("\n");}
	}
	
	printf("\n");


//**************soft decision*******************/

for(i=0;i<456;i++)
	{
		if(output[(i)] == 0)
		{soft_de[(i)] = 3;}
	
		else
		{soft_de[(i)] = -4;}
	}


printf("\n-----------soft decision ideal ------\n");
for (i=0;i<228;i++)
	{
		printf("(%02d,%02d) ",soft_de[(i*2)],soft_de[(i*2)+1]);
	if((i+1)%10==0){printf("\n");}
	}
	
	printf("\n");

//**********************************************/

//**************branch Metrics*******************/

for(i=0;i<4;i++)
	{
		for(j=0;j<228;j++)
		{
			if(i==0)
			{
			 branch_metrics[i][j] = soft_de[(j*2)]+soft_de[(j*2)+1];
			}
			else if(i==1)
			{
			 branch_metrics[i][j] = (1*soft_de[(j*2)])+((-1)*soft_de[(j*2)+1]);
			}
			else if(i==2)
			{
			 branch_metrics[i][j] = ((-1)*soft_de[(j*2)])+(1*soft_de[(j*2)+1]);
			}
			else if(i==3)
			{
			 branch_metrics[i][j] = ((-1)*soft_de[(j*2)])+((-1)*soft_de[(j*2)+1]);
			}

		}
	}


printf("\n");
printf("\n-----------Branch Metrics------\n");
for(i=0;i<4;i++)
	{
		for(j=0;j<228;j++)
		{
			printf("%02d ",branch_metrics[i][j]);
		 if((j+1)%35==0){printf("\n");}
		}
	printf("\n");
	}
printf("\n");
//**********************************************/

//**************state Metrics*******************/
//state_metrics[0][0]=100;
//t1=t2=0;

printf("\n------set 00 state and 0 time position to any arbitary value i.e. 100 --------\n");
for(i=0;i<16;i++)
	{
		for (j=0;j<229;j++)
		{
		 state_metrics[i][j]=0;			
		}
	//printf("\n");
	}
//printf("\n");

state_metrics[0][0]=100;

//printf("\n--------------\n");
for(i=0;i<16;i++)
	{
		for (j=0;j<229;j++)
		{
		 printf("%04d ",state_metrics[i][j]);
		 if((j+1)%20==0){printf("\n");}			
		}
	printf("\n");
	}
printf("\n");

for(i=0;i<228;i++)
	{
		for (j=0;j<16;j++)
		{
		state_metrics[j][i+1] = 0;
		//*******************************************************/			
			if(j==0)					
			{
			 t1=t2=0;			
			 t1 = state_metrics[j][i] + branch_metrics[j][i];
			 t2 = state_metrics[j+1][i] + branch_metrics[j+3][i];

				if(t1>t2)
				{state_metrics[j][i+1]=t1;}
				else
				{state_metrics[j][i+1]=t2;}
			}
		//*******************************************************/			
			else if(j==1)					
			{
 			t1=t2=0;			
			 t1 = state_metrics[j+1][i] + branch_metrics[j+2][i];
			 t2 = state_metrics[j+2][i] + branch_metrics[j-1][i];

				if(t1>t2)
				{state_metrics[j][i+1]=t1;}
				else
				{state_metrics[j][i+1]=t2;}
			}
		//*******************************************************/			
			else if(j==2)					
			{
			t1=t2=0;			
			 t1 = state_metrics[j+2][i] + branch_metrics[j-2][i];
			 t2 = state_metrics[j+3][i] + branch_metrics[j+1][i];

				
				if(t1>t2)
				{state_metrics[j][i+1]=t1;}
				else
				{state_metrics[j][i+1]=t2;}
 			}
		//*******************************************************/			
			else if(j==3)					
			{
			t1=t2=0;			
			 t1 = state_metrics[j+3][i] + branch_metrics[j][i];
			 t2 = state_metrics[j+4][i] + branch_metrics[j-3][i];

				if(t1>t2)
				{state_metrics[j][i+1]=t1;}
				else
				{state_metrics[j][i+1]=t2;}
			}
		//*******************************************************/			
			else if(j==4)					
			{
			t1=t2=0;			
			 t1 = state_metrics[j+4][i] + branch_metrics[j-3][i];
			 t2 = state_metrics[j+5][i] + branch_metrics[j-2][i];

				if(t1>t2)
				{state_metrics[j][i+1]=t1;}
				else
				{state_metrics[j][i+1]=t2;}
			}
		//*******************************************************/			
			else if(j==5)					
			{
			t1=t2=0;			
			 t1 = state_metrics[j+5][i] + branch_metrics[j-3][i];
			 t2 = state_metrics[j+6][i] + branch_metrics[j-4][i];

				if(t1>t2)
				{state_metrics[j][i+1]=t1;}
				else
				{state_metrics[j][i+1]=t2;}
			}
		//*******************************************************/			
			else if(j==6)					
			{
			t1=t2=0;			
			 t1 = state_metrics[j+6][i] + branch_metrics[j-5][i];
			 t2 = state_metrics[j+7][i] + branch_metrics[j-4][i];

				if(t1>t2)
				{state_metrics[j][i+1]=t1;}
				else
				{state_metrics[j][i+1]=t2;}
			}
		//*******************************************************/			
			else if(j==7)					
			{
			t1=t2=0;			
			 t1 = state_metrics[j+7][i] + branch_metrics[j-5][i];
			 t2 = state_metrics[j+8][i] + branch_metrics[j-6][i];

				if(t1>t2)
				{state_metrics[j][i+1]=t1;}
				else
				{state_metrics[j][i+1]=t2;}
			}
		//*******************************************************/			
			else if(j==8)					
			{
			t1=t2=0;			
			 t1 = state_metrics[j-8][i] + branch_metrics[j-5][i];
			 t2 = state_metrics[j-7][i] + branch_metrics[j-8][i];

				if(t1>t2)
				{state_metrics[j][i+1]=t1;}
				else
				{state_metrics[j][i+1]=t2;}
			}
		//*******************************************************/			
			else if(j==9)					
			{
			t1=t2=0;			
			 t1 = state_metrics[j-7][i] + branch_metrics[j-9][i];
			 t2 = state_metrics[j-6][i] + branch_metrics[j-6][i];

				if(t1>t2)
				{state_metrics[j][i+1]=t1;}
				else
				{state_metrics[j][i+1]=t2;}
			}
		//*******************************************************/			
			else if(j==10)					
			{
			t1=t2=0;			
			 t1 = state_metrics[j-6][i] + branch_metrics[j-7][i];
			 t2 = state_metrics[j-5][i] + branch_metrics[j-10][i];

				if(t1>t2)
				{state_metrics[j][i+1]=t1;}
				else
				{state_metrics[j][i+1]=t2;}
			}
		//*******************************************************/			
			else if(j==11)					
			{
			t1=t2=0;			
			 t1 = state_metrics[j-5][i] + branch_metrics[j-11][i];
			 t2 = state_metrics[j-4][i] + branch_metrics[j-8][i];

				if(t1>t2)
				{state_metrics[j][i+1]=t1;}
				else
				{state_metrics[j][i+1]=t2;}
			}
		//*******************************************************/			
			else if(j==12)					
			{
			t1=t2=0;			
			 t1 = state_metrics[j-4][i] + branch_metrics[j-10][i];
			 t2 = state_metrics[j-3][i] + branch_metrics[j-11][i];

				if(t1>t2)
				{state_metrics[j][i+1]=t1;}
				else
				{state_metrics[j][i+1]=t2;}
			}
		//*******************************************************/			
			else if(j==13)					
			{
			t1=t2=0;			
			 t1 = state_metrics[j-3][i] + branch_metrics[j-12][i];
			 t2 = state_metrics[j-2][i] + branch_metrics[j-11][i];

				if(t1>t2)
				{state_metrics[j][i+1]=t1;}
				else
				{state_metrics[j][i+1]=t2;}
			}
		//*******************************************************/			
			else if(j==14)					
			{
			t1=t2=0;			
			 t1 = state_metrics[j-2][i] + branch_metrics[j-12][i];
			 t2 = state_metrics[j-1][i] + branch_metrics[j-13][i];

				if(t1>t2)
				{state_metrics[j][i+1]=t1;}
				else
				{state_metrics[j][i+1]=t2;}
			}
		//*******************************************************/			
			else if(j==15)					
			{
			t1=t2=0;			
			 t1 = state_metrics[j-1][i] + branch_metrics[j-14][i];
			 t2 = state_metrics[j][i] + branch_metrics[j-13][i];

				if(t1>t2)
				{state_metrics[j][i+1]=t1;}
				else
				{state_metrics[j][i+1]=t2;}
			}
		}
	}


printf("\n----------------The state Metrics are obtained as follows---------------\n");
for(i=0;i<16;i++)
	{
		for (j=0;j<229;j++)
		{
		 printf("%04d ",state_metrics[i][j]);
		state_metrics_s[i][j] = state_metrics[i][j];
	if((j+1)%20==0){printf("\n");} 			
		}
	printf("\n");
	}
printf("-----------------------------------------------------------------\n");
//*****************************************************************/

printf("\n----------------The highest value of path ---------------\n");

for(i=0;i<229;i++)
{
		
	/*	 for ( k= 0; k < 4; k++)
		 {
		 printf("%d\n", state_metrics[k][i]);
		 }
	*/
	/*   Bubble sorting begins */

	    for (k = 0; k < 16; k++)
	    {
		for (j = 0; j < (16 - k - 1); j++)
		{
		    if (state_metrics_s[j][i] > state_metrics_s[j+1][i])
		    {
		        t1 = state_metrics_s[j][i];

		        state_metrics_s[j][i] = state_metrics_s[j+1][i];

		        state_metrics_s[j+1][i] = t1;
		    }
		}

		if(k==15)
		{
		//printf("%d---\n", state_metrics[k][i]);
		state_transition[i] = state_metrics_s[k][i];
		}
	    } //end of sorting
	//----------	
}


for(i=0;i<229;i++)
{
		printf("%04d ", state_transition[i]);
	if((i+1)%20==0){printf("\n");}
}
printf("\n");
printf("\n----------------The state transitions---------------\n");
for(i=0;i<=228;i++)
{ //t1=t2=0;
	for(j=0;j<16;j++)
	{
		if(state_transition[(i)] == state_metrics[j][(i)])
		{
		 state_decode[i] = j;printf("%02d ",state_decode[i]);
		}
	
		if(state_transition[(i)+1] == state_metrics[j][(i)])
		{
		 state_decode[i+1] = j;printf("%02d ",state_decode[i+1]);
		}
	}
	if((i+1)%35==0){printf("\n");}
}
printf("\n");

//------------state decode----------------------/
printf("\n----------------The viterbi decoder output---------------\n");
for(i=0;i<(228);i++)
{
	if(((state_decode[i] == state_decode[i+1])&&(state_decode[i]==0))||(state_decode[i]>state_decode[i+1]))
	printf("%d",0);
	
	else
 	printf("%d",1);
} 
printf("\n");
//---------------------------------------------/*/
 end = clock();
printf("\n--------------------------------- Reprint consider input pair is :---------------------------------\n");
	for (i=0;i<228;i++)
	{
//		input[i] = 0x1&rand(); //feeding the array with random 228 input sequence bit
		printf("%d",input[i]);
	}
	
	printf("\n\n\n");
 cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
printf(" Viterbi decoder takes %f seconds to execute \n\n", cpu_time_used); 
} 


