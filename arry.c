/**
 * @file arry.c
 * Copyright(C)
 * For free
 * All right reserved
 * 
 */
/*
 * @brief 
 * @author TangWeiwei,331397964@qq.com
 * @version 0.1
 * @date 2012-11-14
 */
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/**
 * @name sen_node
 * @{  x,y,data */
/**  @} */
typedef struct
{
	int x;
	int y;
	int data;
}sen_node;

/**
 * @name str_save is use for save the num of arry
 * @{ len is the length of arry*/
/**		num is the num of arry@} */
typedef struct
{
	int dis;
	int num;
}sen_save;

/**
 * @brief g_arry is to save the arry
 *		  g_temp_arry is use for saving the arry for back
 */

typedef struct node
{
	sen_node arry;
	struct node *next;
	struct node *prior;
}dlink;

typedef struct asd
{
	sen_node arry;
	int bf;
	struct asd *lchild,*rchild;
}avlnode,*avltree;

sen_node g_arry[100];
sen_node g_temp_arry[100];



/**
 * @brief check_arry 
 *
 * @param a[]
 * @param len
 *
 * @return 
 */
int check_arry(sen_node a[], int len)
{
	int i,j;
	
	for(i=0; i<len; i++)
	{
		for(j=i+1; j<len; j++)
		{
			if(a[i].x==a[j].x)
				if(a[i].y==a[j].y)
					return 0;
		}
	}
	return 1;
}

void init_arry(sen_node a[], int len)
{

	int i;
	int n=0;
	int flag_init=0;
	int output_flag=0;
	printf("\n\n");
	printf("Welcome to use software\n\n\n");
	printf("***************************************\n");
	printf("Do you want to initial arry?\n");
	printf("1.Initial the arry.\n");
	printf("2.Quit the sorfware.\n");
	printf("***************************************\n");
	scanf("%d", &flag_init);
	while(!(1 == flag_init || 2 == flag_init))
	{
		printf("*****************************************\n");
		printf("Error:Invalid Input\n");
		printf("Please input again.\n");
		printf("\n\ndo you want to initial arry?\n");
		printf("1.Initial the arry.\n");
		printf("2.Quit the software.\n");
		printf("*****************************************\n");
		scanf("%d", &flag_init);
	}
	
	///////////////check_arry//////////////
	if(1 == flag_init)
	{
		while(!check_arry(g_arry, len))
		{
			printf("\nInitial the arry now...\n");
			srand((unsigned)(time(NULL)));
			for(i=0; i<len; i++)
			{
				g_arry[i].x = rand()%(1001);
				g_arry[i].y = rand()%(1001);
		 		g_arry[i].data = rand()%(101);
			}
		}

	    ////////////////output the arry/////////////
		printf("\ncheck the arry done...\n");
		printf("\n\n*****************************************\n");
		printf("Do you want output the origin arry?\n");
		printf("1.output the arry.\n");
		printf("2.no but i want to do others.\n");
		printf("*****************************************\n");
		scanf("%d",&output_flag);
		if(1 == output_flag)
		{
		printf("\n*******************************************************The Origin Arry******************************************************\n");
		for(i=0; i<len; i++)
		{
			g_temp_arry[i] = g_arry[i];
			if(i<10)
				printf("node[%d] (%4d,%4d)=%3d   ",i, g_arry[i].x, g_arry[i].y, g_arry[i].data);
			else
				printf("node[%d](%4d,%4d)=%3d   ",i, g_arry[i].x, g_arry[i].y, g_arry[i].data);
			n++;
			if(n%4 == 0)
				printf("\n");
		}
		printf("\n****************************************************************************************************************************\n");
		}
	}
	else
	{
		printf("\n\nThanks for your use..\n");
		printf("Quit the software..\n");
		exit(0);
	}
	
}

double get_time_val()
{
	struct timeval stTimeval;
	gettimeofday(&stTimeval, NULL);

	return stTimeval.tv_sec*1000000 + stTimeval.tv_usec;

}

/**
 * @brief quick_sort 
 *
 * @param a[]
 * @param first
 * @param end
 */
void quick_sort(sen_node a[], int first, int end)
{
	int i=first;
	int j=end;
	int key=a[first].data;
	int k;
	sen_node temp_arry;

	temp_arry=a[first];
	
	while(i<j)
	{
		while(i<j&&a[j].data>=key)
			j--;
		a[i]=a[j];
		while(i<j&&a[i].data<=key)
			i++;
		a[j]=a[i];
	}

	a[i]=temp_arry;
	
	if(first<i-1)
		quick_sort(a,first,i-1);
	if(end>i+1)
		quick_sort(a,i+1,end);
}

/**
 * @brief bubble_sort 
 *
 * @param a[]
 * @param len
 */
void bubble_sort(sen_node a[], int first, int end)
{
	int i,j;
	int len = (end - first + 1);
	sen_node stu_temp;

	for(i=first; i<end; i++)
	{
		for(j=i; j<len; j++)
		{
			if(a[i].data>a[j].data)
			{
				stu_temp=a[i];
				a[i]=a[j];
				a[j]=stu_temp;
			}
		}	
	}
}

/**
 * @brief shell_sort 
 *
 * @param a[]
 * @param len
 */
void shell_sort(sen_node a[], int first, int end)
{
	int len = (end -first + 1);
	int step = len;
	int i,j;
	sen_node stu_temp;

	while(step>0)
	{
		step = step/2;
		for(i = step; i<len; i++)
		{
			j = i - step;
			stu_temp = a[first + i];
	
			while((j >= 0)&&(a[first + j].data > stu_temp.data))
			{
				a[first + j + step] = a[j];
				j = j - step;
			}
	
			a[first + j + step] = stu_temp;
		}
	}
}

dlink * init_list(sen_node a[], int len)
{
	dlink *head,*p,*s;
	int i;
	p = head = (dlink *)malloc(sizeof(dlink));
	for(i=0; i < len; i++)
	{
		s = (dlink *)malloc(sizeof(dlink));
		s->arry = a[i];
		s->next = NULL;
		s->prior = p;
		p->next = s;
		p = s;
	}
	p->next = NULL;
	return head;
}

int kind_sort(sen_node a[], int first, int end, int kind)
{
		switch(kind)
		{	
			case 1:bubble_sort(a, first, end);printf("You choose the bubble_sort\n");break;
			case 2:quick_sort(a, first, end);printf("You choose the quick_sort\n");break;
			case 3:shell_sort(a, first, end);printf("You choose the shell_sort\n");break;
		}
	return 1;
	
}
void sort_arry(sen_node a[], int len)
{
	
	int i,j,n=0;
	int sort_choise = 0, output_flag = 0;
	double doubleT1,doubleT2;
	char *sort_string;
	dlink *head;

	//////////////////how to sort the arry/////////////////////////
	printf("\n***************************************************\n");
	printf("What kind of sort do you want?\n");
	printf("1.Bubble sort\n");
	printf("2.Quick sort\n");
	printf("3.Shell sort\n");
	printf("4.use the all kind of sort. and compress the result\n");
	printf("***************************************************\n");
	scanf("%d",&sort_choise);

	while(!((sort_choise == 1) || (sort_choise == 2) || (sort_choise == 3) || (sort_choise == 4)))
	{
		printf("\n****************************************************\n");
		printf("Error:Invaild Input\n");
		printf("Please input again\n");
		printf("\n\nWhat kind of sort do you want?\n");
		printf("1.Bubble sort\n");
		printf("2.Quick sort\n");
		printf("3.Shell sort\n");
		printf("4.use the all kind of sort. and compress the result\n");
		printf("******************************************************\n");
		scanf("%d",&sort_choise);
	}
	if((sort_choise == 1) || (sort_choise == 2) || (sort_choise == 3))
	{
		printf("***********************************************\n");
		doubleT1 = get_time_val();
		switch(sort_choise)
		{	
			case 1:bubble_sort(a, 0, len - 1);printf("You choose the bubble_sort\n");break;
			case 2:quick_sort(a, 0, len - 1);printf("You choose the quick_sort\n");break;
			case 3:shell_sort(a, 0, len - 1);printf("You choose the shell_sort\n");break;
		}
		doubleT2 = get_time_val();
		printf("\n   the time for sorting is = %f us\n",(double)(doubleT2 - doubleT1));
		printf("***********************************************\n");
	}
	else
	{
		printf("\n**********************************************************************\n");
		for(i=0; i<3 ;i++)
		{

			for(j=0; j<len; j++)
			{
				a[j]=g_temp_arry[j];
			}

			doubleT1 = get_time_val();
			if(0 == i)
			{
				bubble_sort(a, 0, len - 1);
			 	sort_string = "bubble";
			}
			if(1 == i)
			{
				quick_sort(a, 0, len - 1);
				sort_string = "quick";
			}
			if(2 == i)
			{
				shell_sort(a, 0, len - 1);
				sort_string = "shell";
			}
			doubleT2 = get_time_val();
			printf("\n  the time of %s sort is = %f us\n", sort_string, (double)(doubleT2 - doubleT1));
			
		}
		printf("\n*******************************************************************\n");
	}
	//////////////////////////output the sort arry/////////////////////
	printf("\n***************************************\n");
	printf("Do you want output the sort arry?\n");
	printf("1.output the sort arry\n");
	printf("2.no but i want to do others\n");
	printf("*****************************************\n");
	scanf("%d",&output_flag);
	while(!((output_flag == 1) || (output_flag == 2)))
	{
		printf("\n*********************************\n");
		printf("Error:Invaild input\n");
		printf("Please input again.\n");
		printf("\n\ndo you want output the sort arry?\n");
		printf("1.output the sort arry\n");
		printf("2.no but i want to do others\n");
		printf("*********************************\n");
		scanf("%d",&output_flag);
	}
	if(output_flag == 1)
	{
		printf("\n***********************************************************The Sort Arry***************************************************\n");
		for(i=0; i<len; i++)
		{
		if(i<10)
			printf("node[%d] (%4d,%4d)=%3d   ",i, g_arry[i].x, g_arry[i].y, g_arry[i].data);
		else
			printf("node[%d](%4d,%4d)=%3d   ",i,a[i].x,a[i].y,a[i].data);
		n++;
		if(n%4==0)
			printf("\n");
		}
	printf("\n*******************************************************************************************************************************\n");
	}
	printf("\n\nCreate the dlink Now.\n");
	printf(".\n");
	printf("..\n");
	printf("...done\n");
	head = init_list(a, len);
	printf("Create the dlink Completed\n\n");
}

void init_avltree(avltree *T)
{
	printf("\n\nInitia the tree.\n");
}
void delete_node(avltree *T)
{
	printf("\ndeleted.\n");
}

void pre_order_traverse(avltree T)
{
	printf("\npre_order_traverse.\n");
	
	if(T != NULL)
	{
		printf("%d",T -> arry.x );
		pre_order_traverse(T -> lchild);
		pre_order_traverse(T -> rchild);
	}
}

void in_order_traverse(avltree T)
{
	printf("\nin_order_traverse.\n");
	
	if(T != NULL)
	{
		in_order_traverse(T -> lchild);
		printf("%d",T -> arry.x );
		in_order_traverse(T -> rchild);
	}
}

void post_order_traverse(avltree T)
{
	printf("\npost_order_traverse.\n");
	
	if(T != NULL)
	{
		post_order_traverse(T -> lchild);
		post_order_traverse(T -> rchild);
		printf("%d",T -> arry.x );
	}
}

void avl_tree(avltree *T)
{
	int delete_flag = 0;
	int traverse_flag = 0;
	int kind_traverse_flag = 0;

	init_avltree(T);
	
	printf("\n\n*********************************\n");
	printf("do you want delete A[20]?\n");
	printf("1.Yes,delete it.\n");
	printf("2.No.but i want to do others.\n");
	printf("*************************************\n");
	scanf("%d",&delete_flag);
	while(!((1 == delete_flag) || (2 == delete_flag)))
	{
		printf("****************************************\n");
		printf("Error:Invalid input.\n");
		printf("Please input again.\n");
		printf("\n\ndo you want to delete A[20]?\n");
		printf("1.Yes,delete it.\n");
		printf("2.No.but i want to do others.\n");
		printf("****************************************\n");
		scanf("%d",&delete_flag);
	}

	if(1 == delete_flag)
	{
		delete_node(T);
	}

	printf("\n\n*********************************\n");
	printf("do you want traverse the tree?\n");
	printf("1.Yes,i want.\n");
	printf("2.No.but i want to do others.\n");
	printf("*************************************\n");
	scanf("%d",&traverse_flag);
	while(!((1 == traverse_flag) || (2 == traverse_flag)))
	{
		printf("****************************************\n");
		printf("Error:Invalid input.\n");
		printf("Please input again.\n");
		printf("\n\ndo you want traverse the tree?\n");
		printf("1.Yes,i want.\n");
		printf("2.No.but i want to do others.\n");
		printf("****************************************\n");
		scanf("%d",&traverse_flag);
	}

	if(1 == traverse_flag)
	{
		printf("\n\n*********************************\n");
		printf("what kind of traverse do you want?\n");
		printf("1.pre_order_traverse.\n");
		printf("2.in_order_traverse.\n");
		printf("3.post_order_traverse.\n");
		printf("*************************************\n");
		scanf("%d",&kind_traverse_flag);
		while(!((1 == kind_traverse_flag) || (2 == kind_traverse_flag) || (3 == kind_traverse_flag)))
		{
			printf("****************************************\n");
			printf("Error:Invalid input.\n");
			printf("Please input again.\n");
			printf("\n\nwhat kind of traverse do you want?\n");
			printf("1.pre_order_traverse\n");
			printf("2.in_order_traverse.\n");
			printf("3.post_order_traverse.\n");
			printf("****************************************\n");
			scanf("%d",&kind_traverse_flag);
		}
		switch(kind_traverse_flag)
		{
			case 1 : pre_order_traverse(*T);break;
			case 2 : in_order_traverse(*T);break;
			case 3 : post_order_traverse(*T);break;
			default : break;
		}
	}

}
/**
 * @brief find_node 
 *
 * @param a[]
 * @param len
 */
void find_node(sen_node a[], int len)
{
	int i,j,n=0;
	int flag=0;
	sen_save sen_dis[100];
	sen_save sen_temp_dis;
	int max_data_num,min_data_num,sum_data,temp_data_num;
	int max_data,min_data,average_data;
	int node_num=0;
	int temp_num[100];
	int temp_num_change;
	int find_choise;
	sum_data=0;


	printf("\n************************************\n");
	printf("you want to find the node in Block?\n");
	printf("1.Find the node\n");
	printf("2.No.I make my choise again.\n");
	printf("*************************************\n");
	scanf("%d",&find_choise);
	
	while(!((1 == find_choise) || (2 == find_choise)))
	{
		printf("\n************************************\n");
		printf("Error:Invalid input.\n");
		printf("Please input again.\n");
		printf("\n\nyou want to find the node in Block?\n");
		printf("1.Find the node\n");
		printf("2.No.I make my choise again.\n");
		printf("*************************************\n");
		scanf("%d",&find_choise);
	}
	
	if(1 == find_choise)
	{
		for(i=0; i<len; i++)
	{
		sen_dis[i].num=i;
		if(a[i].x<=500 && a[i].y<=500)
			sen_dis[i].dis=0;
		if(a[i].x<=500 && a[i].y>500)
			sen_dis[i].dis=a[i].y-500;
		if(a[i].x>500 && a[i].y<=500)
			sen_dis[i].dis=a[i].x-500;
		if(a[i].x>500 && a[i].y >500)
			sen_dis[i].dis=sqrt((a[i].x-500)*(a[i].x-500)+(a[i].y-500)*(a[i].y-500));
	}
///////////////////////////从小到大排序/////////////////////	
	for(i=0; i<10; i++)
	{
		for(j=i; j<len; j++)
		{
			////////////flag作为是否有node在区域内//////////////
			if(sen_dis[j].dis == 0)
			{
				flag = 1;
			}
			if(sen_dis[j].dis <= sen_dis[i].dis)
			{
				
				sen_temp_dis = sen_dis[j]; 
				sen_dis[j] = sen_dis[i];
				sen_dis[i] = sen_temp_dis;
			}
		}
	}
/////////////////////////////////temp_num用于存储结点下标///////////////////////
	for(i=0; i<len; i++)
	{
		if(sen_dis[i].dis == 0)
		{	
			temp_num[node_num]=sen_dis[i].num;
			node_num++;
		}	
	}
/////////////////////////////////////结点从小到大排列///////////////////////////
	for(i=0; i<node_num; i++)
	{
		for(j=i; j<node_num; j++)
		{
			if(temp_num[i]>temp_num[j])
			{
				temp_num_change=temp_num[i]; 
				temp_num[i]=temp_num[j];
				temp_num[j]=temp_num_change;
			}
		}
	}

	if(flag==1)
	{
		printf("\n******************************there is%3d node in the block.*******************************\n",node_num);
		for(i=0; i<node_num; i++)
		{
			int m;
			m=temp_num[i];
			if(m<10)
				printf("node[%d] (%4d,%4d)=%3d   ",m, a[m].x, a[m].y, a[m].data);
			else
				printf("node[%d](%4d,%4d)=%3d   ",m, a[m].x, a[m].y, a[m].data);
			n++;
			if(n%4==0)
				printf("\n");
		}

	}
	else 
	{
		printf("\n******************************there is no node in the block.***************************\n");
		
		temp_data_num=sen_dis[0].num;
		max_data=a[temp_data_num].data;
		min_data=a[temp_data_num].data;
		
		for(i=0; i<10; i++)
		{
			temp_data_num=sen_dis[i].num;
			sum_data += a[temp_data_num].data;
		
			if(a[temp_data_num].data>max_data)
				max_data=a[temp_data_num].data;
			if(a[temp_data_num].data<min_data)
				min_data=a[temp_data_num].data;
		}
		average_data=sum_data/10;

		printf("max_data=%4d    \nmin_data=%4d   \naverage_data=%4d \n",max_data,min_data,average_data);
	}
	printf("\n*******************************************************************************\n");
	}
}

/**
 * @brief main 
 *
 * @param argc
 * @param argv[]
 *
 * @return 
 */
int main(int argc,char *argv[])
{
	int len;
	int choise_flag = 0;
	avltree T = NULL;


	len=atoi(argv[1]);
	system("clear");	
	init_arry(g_arry,len);
	while(1)
	{
		printf("\n**********************************\n");
		printf("Now.What do you want to do?\n");
		printf("1.Sort the arry and creat a dlink.\n");
		printf("2.Creat a balance tree\n");
		printf("3.Find the Node in the block\n");
		printf("4.Quit the software\n");
		printf("***********************************\n");
		scanf("%d",&choise_flag);
		system("clear");
		while(!((choise_flag == 1) || (choise_flag == 2) || (choise_flag == 3) || (choise_flag == 4)))
		{
			system("clear");
			printf("\n************************************\n");
			printf("Error:Invaild Input\n");
			printf("Please input again\n");
			printf("\n\nWhat do you want to do?\n");
			printf("1.Sort the arry and creat a dlink.\n");
			printf("2.Creat a balance tree\n");
			printf("3.Find the Node in the block\n");
			printf("4.Quit the software\n");
			printf("*************************************\n");
			scanf("%d",&choise_flag);
		
		}
		switch(choise_flag)
		{
			case 1 : sort_arry(g_arry,len);break;
			case 2 : avl_tree(&T);break;
			case 3 : find_node(g_temp_arry,len);break;
			case 4 : {
						 printf("\n\nThanks for your use\n");
						 printf("Quit the sortware now....\n");
						 exit(0);
						 break;
					 }
		}
	}
}
