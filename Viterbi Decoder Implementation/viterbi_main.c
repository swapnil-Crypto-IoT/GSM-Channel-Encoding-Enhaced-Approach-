#include<stdio.h>
#include<stdlib.h>

int main()
{
	unsigned int input[10]={0}/*{1,0,1,1,0,1,0,1,0,0}*/, i,j,k, output[20] ={0};
	signed int soft_de[20] = {0}, branch_metrics[4][10]={0};
	signed int state_metrics[4][11]={0},t1,t2,state_metrics_s[4][11]={0};
	unsigned int state = 0x0, state_transition[11]={0}, state_decode[11]={0};

printf("\n---------------------------------The consider input pair is :---------------------------------\n");
	for (i=0;i<10;i++)
	{
		input[i] = 0x1&rand(); //feeding the array with random 10 input sequence bit
		printf(" %d ",input[i]);
	}
	
	printf("\n");
//**************************************/	
	for(i=0;i<10;i++)
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
			 state = 0x2;		
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
			 state = 0x2;		
			}
		}

	 else if(state == 0x2)
		{
			if(input[i] == 0)
			{
			 output[(i*2)] = 1;
			 output[(i*2)+1] = 0;
			 state = 0x1;		
			}
			
		else	//if(input[i] == 1)
			{
			 output[(i*2)] = 0;
			 output[(i*2)+1] = 1;
			 state = 0x3;		
			}
		}

	else if(state == 0x3)
		{
			if(input[i] == 0)
			{
			 output[(i*2)] = 0;
			 output[(i*2)+1] = 1;
			 state = 0x1;		
			}
			
		else//	if(input[i] == 1)
			{
			 output[(i*2)] = 1;
			 output[(i*2)+1] = 0;
			 state = 0x3;		
			}
		}

	} //end of for
//**************************************/
printf("\n-----------Encoded output pairs------\n");
	for (i=0;i<10;i++)
	{
		printf(" (%d,%d) ",output[(i*2)],output[(i*2)+1]);
	}
	
	printf("\n");


//**************soft decision*******************/

for(i=0;i<20;i++)
	{
		if(output[(i)] == 0)
		{soft_de[(i)] = 3;}
	
		else
		{soft_de[(i)] = -4;}
	}


printf("\n-----------soft decision ideal ------\n");
for (i=0;i<10;i++)
	{
		printf(" (%d,%d) ",soft_de[(i*2)],soft_de[(i*2)+1]);
	}
	
	printf("\n");

//**********************************************/

//**************branch Metrics*******************/

for(i=0;i<4;i++)
	{
		for(j=0;j<10;j++)
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
			else //if(i==3)
			{
			 branch_metrics[i][j] = ((-1)*soft_de[(j*2)])+((-1)*soft_de[(j*2)+1]);
			}
		}
	}


printf("\n");
printf("\n-----------Branch Metrics------\n");
for(i=0;i<4;i++)
	{
		for(j=0;j<10;j++)
		{
			printf(" %02d ",branch_metrics[i][j]);
		}
	printf("\n");
	}
printf("\n");
//**********************************************/

//**************state Metrics*******************/
//state_metrics[0][0]=100;
//t1=t2=0;

printf("\n------set 00 state and 0 time position to any arbitary value i.e. 100 --------\n");
for(i=0;i<4;i++)
	{
		for (j=0;j<11;j++)
		{
		 state_metrics[i][j]=0;			
		}
	//printf("\n");
	}
//printf("\n");

state_metrics[0][0]=100;

//printf("\n--------------\n");
for(i=0;i<4;i++)
	{
		for (j=0;j<11;j++)
		{
		 printf(" %03d ",state_metrics[i][j]);			
		}
	printf("\n");
	}
printf("\n");

for(i=0;i<10;i++)
	{
		for (j=0;j<4;j++)
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
		//*******************************************************//			
			else if(j==1)					
			{
 			t1=t2=0;			
			 t1 = state_metrics[j+1][i] + branch_metrics[j+2][i];
			 t2 = state_metrics[j+2][i] + branch_metrics[j][i];

				if(t1>t2)
				{state_metrics[j][i+1]=t1;}
				else
				{state_metrics[j][i+1]=t2;}
			}
		//*******************************************************/			
			else if(j==2)					
			{
			t1=t2=0;			
			 t1 = state_metrics[j-2][i] + branch_metrics[j+1][i];
			 t2 = state_metrics[j-1][i] + branch_metrics[j-2][i];

				
				if(t1>t2)
				{state_metrics[j][i+1]=t1;}
				else
				{state_metrics[j][i+1]=t2;}
 			}
		//*******************************************************/			
			else if(j==3)					
			{
			t1=t2=0;			
			 t1 = state_metrics[j-1][i] + branch_metrics[j-2][i];
			 t2 = state_metrics[j][i] + branch_metrics[j-1][i];

				if(t1>t2)
				{state_metrics[j][i+1]=t1;}
				else
				{state_metrics[j][i+1]=t2;}
			}
		}
	}


printf("\n----------------The state Metrics are obtained as follows---------------\n");
for(i=0;i<4;i++)
	{
		for (j=0;j<11;j++)
		{
		 printf(" %03d ",state_metrics[i][j]);
		state_metrics_s[i][j] = state_metrics[i][j]; 			
		}
	printf("\n");
	}
printf("-----------------------------------------------------------------\n");
//*****************************************************************/

printf("\n----------------The highest value of path ---------------\n");

for(i=0;i<11;i++)
{
		
	/*	 for ( k= 0; k < 4; k++)
		 {
		 printf("%d\n", state_metrics[k][i]);
		 }
	*/
	/*   Bubble sorting begins */

	    for (k = 0; k < 4; k++)
	    {
		for (j = 0; j < (4 - k - 1); j++)
		{
		    if (state_metrics_s[j][i] > state_metrics_s[j+1][i])
		    {
		        t1 = state_metrics_s[j][i];

		        state_metrics_s[j][i] = state_metrics_s[j+1][i];

		        state_metrics_s[j+1][i] = t1;
		    }
		}

		if(k==3)
		{
		//printf("%d---\n", state_metrics[k][i]);
		state_transition[i] = state_metrics_s[k][i];
		}
	    } //end of sorting
	//----------	
}


for(i=0;i<11;i++)
{
		printf(" %d ", state_transition[i]);
}
printf("\n");
printf("\n----------------The state transitions---------------\n");
for(i=0;i<=10;i++)
{ //t1=t2=0;
	for(j=0;j<4;j++)
	{
		if(state_transition[(i)] == state_metrics[j][(i)])
		{
		 state_decode[i] = j;printf(" %d ",state_decode[i]);
		}
	
		if(state_transition[(i)+1] == state_metrics[j][(i)])
		{
		 state_decode[i+1] = j;printf(" %d ",state_decode[i+1]);
		}
	}
}
printf("\n");

//------------state decode----------------------/
printf("\n----------------The viterbi decoder output---------------\n");
for(i=0;i<(10);i++)
{
	if(((state_decode[i] == state_decode[i+1])&&(state_decode[i]==0))||(state_decode[i]>state_decode[i+1]))
	printf("%d",0);
	
	else
 	printf("%d",1);
} 
printf("\n");
//---------------------------------------------/
} //end main
