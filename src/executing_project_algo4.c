#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEBUG 1
#define ACTIVITIES 6
#define SKILLS 7
#define RESOURCES 14
#define MANDAYS 60

int main(void) {

	// Project Characteristics
	int I=ACTIVITIES; 	// activities iEI

	// Resources Characteristics
	int J=SKILLS; 	// skills jEJ
	int K=RESOURCES;  	// resources kEK

	// Periods of measured work (eg. Mandays)
	int P=MANDAYS;  	// # periods p or mandays, workweeks, workmonths pEJ


	// Input Data set for the problem
	int st[ACTIVITIES] = {0,0,0,0,0,0}; 				// st[i], start time of individual activities
	int d[ACTIVITIES] = {0,0,0,0,0,0};                 // d[i],  duration of individual activities
	int rd[ACTIVITIES] = {0,0,0,0,0,0};                 // rd[i],  real duration of individual activities

	/* ----------              Tables of specific inputs data set        -----------*/
	/* ----------     1. Table s[i][j] - Required mandays of skills needed per activity  -----------*/
	int s[ACTIVITIES][SKILLS] =
	{
			{5,3,0,0,2,0,0},
			{3,5,5,2,2,0,0},
			{2,10,40,20,5,0,0},
			{2,3,50,10,0,10,0},
			{3,0,10,2,0,5,3},
			{3,0,2,0,0,0,3}
	};  	// s[i,j],  required mandays per skill needed

	/* ----------     2. Table r[k][j] - Resource multi-skills  -----------*/
	int r[RESOURCES][SKILLS] =
	{
			{1,0,0,0,0,0,0},
			{1,0,0,0,0,0,0},
			{0,1,0,0,0,0,0},
			{0,0,1,0,0,0,0},
			{0,0,1,0,0,0,0},
			{0,0,1,0,0,0,0},
			{0,0,0,1,0,0,0},
			{0,0,0,1,0,0,0},
			{0,0,0,0,1,0,0},
			{0,0,0,0,1,0,0},
			{0,0,0,0,0,1,0},
			{0,0,0,0,0,1,0},
			{0,0,0,0,0,0,1},
			{0,0,0,0,0,0,1}
	};      		// r[i,j], Table #1: multi-skilled resources, actually used as boolean values

	/* ----------     3. Table a[k][p] - Solution with given availability and resource skill   -----------*/
	int a[RESOURCES][MANDAYS] =
	{
			{1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	}; // a[k,p], Scarce availability of resources, actually used as boolean values

	/* ---------- Initialize critical counters/params of activities to 0 -----------*/
	int total_project_duration=0;  	// total project duration (sum of activities)
	int last_day_counted=0;
	for (int i=0;i<I;i++)
		d[i]=0;


	/* ----------     PRESENT INPUT DATA SET     -----------*/
	printf("\tPRESENT INPUT DATA SET\n");
	/* ----------     1. Table s[i][j] - Required mandays of skills needed per activity  -----------*/
	printf("\n1. Table s[i][j] - Required mandays of skills needed per activity\n");
	printf("\t\t     Skill \n");
	for (int i=0; i<I; i++)
	{
		printf("\t Activity %2d: ", i+1); // space in each rows
		for (int j=0; j<J; j++)
		{
			printf("%2d ", s[i][j]);
		}
		printf("\n"); // New line after each row
	}

	/* ----------     2. Table r[k][j] - Resource multi-skills  -----------*/
	printf("\n2. Table r[k][j] - Resource multi-skills\n");
	printf("\t\t     Skill \n");
	for (int k=0; k<K; k++)
	{
		printf("\t Resource %2d: ", k+1); // space in each rows
		for (int j=0; j<J; j++)
		{
			printf("%2d ", r[k][j]);
		}
		printf("\n"); // New line after each row
	}

	/* ----------     3. Table a[k][p] - Solution with given availability and resource skill   -----------*/
	printf("\n3. Table a[k][p] - Solution with given availability and resource skill\n");
	printf("\t\t     Mandays \n");
	for (int k=0; k<K; k++)
	{
		printf("\t Resource %2d: ", k+1); // space in each rows
		for (int p=0; p<P; p++)
		{
			printf("%2d ", a[k][p]);
		}
		printf("\n"); // New line after each row
	}

	/* ----------     ALGORITHM RUNNING     -----------*/
	//---------------- Start calculating --------------
	//       calculation of individual activities
	printf("\n\n\tALGORITHM RUNNING\n");

	for (int i=0; i<I; i++)
	{
		printf("\n[DEBUG] Activity %d starts (manday): %d \n", i, st[i]);
		for (int p=st[i]; p<P; p++)
		{
		  for (int k=0; k<K; k++){
			 if (a[k][p]==1){  							//ckeck resource availability
				 for (int j=0; j<J; j++){
					 if ((r[k][j]==1) && (s[i][j]>0))  // if resource has the skill and if skill is needed
					   {
						  if (i>0)
						  	  d[i]++;      				// add manday/period of work
						  s[i][j]--;      				// reduce required effort from work to be done
						  printf("[DEBUG] inside loop #%d: - availability hit:  a[%d,%d], r[%d,%d], s[%d,%d]\n",i,k,p,k,j,i,j);
						  last_day_counted=p;
						  break;
					   }}}}
		}
		printf("[DEBUG] Loop #%d: Last Day counted for d%d: %d\n",i,i,last_day_counted);

		// Proper calculation
		d[i] = last_day_counted; 				    // aligned with start numbering days at Day 0
		d[i]++; 									// to align with start numbering days at Day 1
		st[i+1] = last_day_counted;
		st[i+1]++;
	}

	//result duration of activities of Project P
	printf("\n\tRESULTS PRESENTATION");
	printf("\nProject comprises of %d consecutive activities:",I);

	for (int i=0;i<I;i++)
	{
		if (i==0)
			{
				printf(" \n => Activity d[%d]=d%d real duration: %d mandays", i, i+1, d[i]);
				rd[i] = d[i];
			}
		else
			{
				printf(" \n => Activity d[%d]=d%d real duration: %d mandays", i, i+1, d[i]-d[i-1]);
				rd[i] = d[i]-d[i-1];
			}
	}
	for (int i=0;i<I;i++)
	{
		total_project_duration = total_project_duration + rd[i];
	}

	printf("\n =====>  Total Project duration: %d mandays\n",total_project_duration);
	return EXIT_SUCCESS;
}
