//PROJECT :: MARRIAGE(CARD GAME) POINT COLLECTION COUNTING


#include<stdio.h>
#include<stdlib.h>

struct player_info
{
	//int player_no;
	int point;
};

int count_points(int point, int total_points, int players);
int main()
{
	system("CLS");
	int players, point_value, total_point = 0, ender;
	int total_seen, total_unseen, seen_unseen;
	printf("\n");
	printf("---------------------------------------------------\n");
	printf("************ MARRIAGE POINT COUNTER ***************\n\n");
	int i = 1;
	while(1) // IF the player enter wrong data, give another chance. 
	{
		printf("Enter the total number of player: ");
		scanf("%d",&players);
		
		i += 1;
		//checking if the number of player is less than 1. In that case the game will not run
		if(players < 2)
		{
			printf("\nLess than two player cannot play this game");
			printf("\nPlease Enter the proper player number");
			printf("\n\n");
		}
		else
		{
			break;
		}
		
		//terminate the program if the user enter incorrect data more than three times
		if(i > 3)
		{
			exit(0);
		}
	}
	
	printf("\n\nEnter the value for each point: ");
	scanf("%d", &point_value);
	printf("\n");
	printf("---------------------------------------------------\n");
	printf("\n*** if the player has not seen enter -1 value***\n\n");
	//initiating the total player and gathering the information.
	struct player_info player[players];
	for(i = 0; i < players; i++)
	{		
		printf("Enter the point collected by player %d : ",i+1);
		scanf("%d",&player[i].point);// if the player has not seen the put -1 value
		/*if(seen_unseen == -1)
		{
			player[i].point = 0;
		}
		else
		{
			player[i].point = seen_unseen;
		}
		*/
	}
	
	for(i = 0; i < players; i++)
	{
		if(player[i].point >= 0)
		{
			total_point += player[i].point;
		}
		
	}
	
	printf("\nEnter the player number who had shown and finished the game : ");
	scanf("%d",&ender);
	
	player[ender -1].point += 3;
	total_seen = total_point + 3; // for players who have seen the Main card point.
	total_unseen = total_point +10;//  for player who haven't seen the Main card point.
	printf("\n---------------------------------------------------\n\n");
	printf("Total points for seen player is %d\n", total_seen);
	printf("Total points for unseen player is %d\n",total_unseen);
	printf("\n---------------------------------------------------\n");
	for( i = 0; i < players; i++)
	{
		int my_point = 0; // here my point is the value after the calculation
		if( ender == i+1)
		{
			continue;
		}
		else if(player[i].point == -1)
		{
			
			my_point = count_points( my_point, total_unseen, players); 
		}
		else
		{
			my_point = count_points(player[i].point, total_seen, players);
		}
		printf("\n\n");
		printf("\nTotal point player %d has win/loss is %d.", i+1, my_point); 
		printf("\nTotal point win/loss is Rs.%d", my_point * point_value);
		
	}
	printf("\n\n----THANK YOU!-----\n");
	return 0;
}

int count_points(int point, int total_points, int players)
{
	return (point * players - total_points);
}