
#include<stdio.h>
#include<iostream>
using namespace std;
int a[100],b[100],i,j,len,k,count=0;
//g(x)=x^16+x^12+x^5+1
int gp[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
void div()
{
    for(i=0;i<k;i++)
    {
        if(a[i]==gp[0])
        {
            for(j=i;j<17+i;j++)
            a[j]=a[j]^gp[count++];
        }
        count=0;
    }
}
int main()
{
    cout<<"At sender side:\n";
    cout<<"\nEnter the length of Data Frame :";
    cin>>len;
    cout<<"\nEnter the Message :";
    for(i=0;i<len;i++)
        cin>>a[i];
    cout<<"Enter length of generator:";
    int glen;
    cin>>glen;

    int h=len+glen-1;
    cout<<"Enter the generator:";
    for(i=0;i<glen;i++)
        cin>>gp[i];
    //Append r(16) degree Zeros to Msg bits
    for(i=0;i<16;i++)
        a[len++]=0;
    for(i=0;i<len;i++)
        b[i]=a[i];
    //No of times to be divided ie. Msg Length
    k=len-16;
    div();
    for(i=0;i<h;i++)
        b[i]=b[i]^a[i]; //MOD 2 Subtraction
    cout<<"\nData to be transmitted from sender is : ";
    cout<<len<<endl;
    for(i=0;i<h;i++)
        cout<<b[i]<<" ";
    cout<<"\nAt receiver side: \n";
    cout<<"\n\nEnter the Data at receiver side: ";
    for(i=0;i<h;i++)
        cin>>a[i];
    div();
    for(i=0;i<h;i++)
        if(a[i]!=0)
        {
            cout<<"\nERROR in Received Data";
            return 0;
        }
    cout<<"\nThere is no error";
}







































/*

#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<string.h>
#define​ FSize 3
 typedef struct​ packet
 {
     ​int​ SeqNum; ​
     char​ Data[FSize+1];
}packet;
 struct​ packet *readdata, *transdata;
 int​ divide(​char​ *msg)
  {
      ​int​ msglen, NoOfPacket, i, j;
      msglen = strlen(msg);
      NoOfPacket = msglen/FSize;   ​
      if​ ((msglen%FSize)!=0) NoOfPacket++;
      readdata = (​struct​ packet *)malloc(​sizeof​(packet) * NoOfPacket);
      ​for​(i = 0; i < NoOfPacket; i++)
      {
          readdata[i].SeqNum = i + 1;      ​
          for​ (j = 0; (j < FSize) && (*msg != ​'\0'​); j++, msg++)
          readdata[i].Data[j] = *msg;
          readdata[i].Data[j] = ​'\0'​;
        }   printf(​"\nThe Message has been divided as follows\n"​);
        printf(​"\nPacket No.         Data\n\n"​);   ​
        for​ (i = 0; i < NoOfPacket; i++)
         printf(​"   %2d              %s\n"​, readdata[i].SeqNum,             readdata[i].Data);   ​
         return​ NoOfPacket;
}
 void​ shuffle(​int​ NoOfPacket)
 {
     ​int​ *Status;
     ​int​ i, j, trans;
    Status=(​int​ * )calloc(NoOfPacket, ​sizeof​(​int​));
     transdata = (​struct​ packet *)malloc(​sizeof​(packet) * NoOfPacket);
      ​for​ (i = 0; i < NoOfPacket;)
      {
          trans = rand()%NoOfPacket;
          ​if​ (Status[trans]!=1)
          {
              transdata[i].SeqNum = readdata[trans].SeqNum;
              strcpy(transdata[i].Data, readdata[trans].Data);
               i++;
               Status[trans] = 1;
            }
        }
        free(Status);
        }
 void​ sortframes(​int​ NoOfPacket)
  {   packet temp;
  ​int​ i, j;
   ​for​ (i = 0; i < NoOfPacket; i++)     ​
   for​ (j = 0; j < NoOfPacket – i-1; j++)
    ​if​ (transdata[j].SeqNum > transdata[j + 1].SeqNum)
     {      temp.SeqNum = transdata[j].SeqNum;
      strcpy(temp.Data, transdata[j].Data);
           transdata[j].SeqNum = transdata[j + 1].SeqNum;
                strcpy(transdata[j].Data, transdata[j + 1].Data);
                     transdata[j + 1].SeqNum = temp.SeqNum;
                        strcpy(transdata[j + 1].Data, temp.Data);
                                }
 }
 void​ receive(​int​ NoOfPacket)
 {   ​int​ i;
  printf(​"\nPackets received in the following order\n"​);
   ​for​ (i = 0; i < NoOfPacket; i++)
   printf(​"%4d"​, transdata[i].SeqNum);
    sortframes(NoOfPacket);
    printf(​"\n\nPackets in order after sorting..\n"​);
     ​for​ (i = 0; i < NoOfPacket; i++)
   printf(​"%4d"​, transdata[i].SeqNum);
    printf(​"\n\nMessage received is :\n"​);
     ​for​ (i = 0; i < NoOfPacket; i++)
      printf(​"%s"​, transdata[i].Data);
      }
 void​ main()
  {
       ​char​ *msg;
          ​int​ NoOfPacket;
           printf(​"\nEnter The message to be Transmitted :\n"​);
              scanf(​"%[^\n]"​, msg);
                NoOfPacket = divide(msg);
              shuffle(NoOfPacket);
               receive(NoOfPacket);
                free(readdata);
                 free(transdata); }
*/
