/*
Distance Vector Routing in this program is implemented using Bellman Ford Algorithm:-
*/
#include<stdio.h>
#include<iostream>
using namespace std;
struct node
{
    //distance between one point to another
    unsigned dist[20];
    //this stores the via data or the from data
    unsigned from[20];
}router[10];

int main()
{
    //matrix to store the inital data provided
    int costmat[20][20];
    int nodes,i,j,k,count=0;
    printf("\nEnter the number of nodes : ");
    scanf("%d",&nodes);//Enter the nodes
    printf("\nEnter the cost matrix :\n");
    for(i=0;i<nodes;i++)
    {
        for(j=0;j<nodes;j++)
        {
            scanf("%d",&costmat[i][j]);
            costmat[i][i]=0;
            router[i].dist[j]=costmat[i][j];//initialise the distance equal to cost matrix
            router[i].from[j]=j;
        }
    }
        do
        {
            count=0;
            for(i=0;i<nodes;i++)//starting with a node
            //and add the distance from k to node j
            for(j=0;j<nodes;j++)
            for(k=0;k<nodes;k++)
                if(router[i].dist[j]>costmat[i][k]+router[k].dist[j])
                {//calculate the minimum distance
                    router[i].dist[j]=router[i].dist[k]+router[k].dist[j];
                    router[i].from[j]=k;
                    count++;
                }
        }while(count!=0);
        for(i=0;i<nodes;i++)
        {
            
            printf("\n\n For router %d\n",i+1);
            for(j=0;j<nodes;j++)
            {
                //printing the output
                printf("\t\nTo node %d via %d makes distance of %d ",j+1,router[i].from[j]+1,router[i].dist[j]);
            }
        }
    printf("\n\n");

}

