//
//  main.cpp
//  KWP
//
//  Created by Kainnyp on 16/3/31.
//  Copyright © 2016年 Kainnyp. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 int i //index of Target
 construct   for a next[]   P-= count-next[COUNT+1]+1 T
 P FROM 1-M
 
 
 
 NEXT 1~M //FOR  NEXT[I] ->1-I-1
 NEXT[1]=0 NEXT[2]=1
 IF P[2]==P[NEXT[2]] NEXT[3]++
 IF P[I-1]==P[NEXT[I-1]] NEXT[I]++
 */
void get_string(char *P,int *next){
    next[1]=0;
    int i=2;int k=0;int r=0;
    while(i<=strlen(P)){
        if(k==0||P[i-2]==P[k-1]) {
            k+=1;
            if(P[i-2]==P[i-1]) ;
            else{
            r=k;
            }
            next[i]=r;
            i++;
        }
        else  k=next[k];
    }
}



int main(){
    char *T,*P;//target & pattern string
    int *next;
    int i=0,j=0;//index & count
    next=(int *)malloc(256*sizeof(int));
    T=(char *)malloc(256*sizeof(char));//指针分配空间的必要性
    P=(char *)malloc(256*sizeof(char));
    printf("please construct pattern string :\n");
    scanf("%s",P);
    printf("please construct targer string :\n");
    scanf("%s",T);
    get_string(P,next);
    for(int x=0;x<strlen(P);x++) printf("%d",*++next);
    while(i<(int)strlen(T)&&j<(int)strlen(P)){// or i<strlen(T)
        if(j==-1||T[i]==P[j]){
            i++;
            j++;
        }
        else {
            j=next[j+1]-1;
            //printf("back step\n");
        }
        if(j>=(int)strlen(P)) {printf("MATCH FROM INDEX %d %d %d!\n",i,j,i-(int)strlen(P)+1);return 0;}
    }
    printf("NO MATCH!\n");
    return 0;
}