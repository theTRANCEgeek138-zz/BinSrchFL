//BINARY SEARCH FOR THE FIRST/LAST POSITION OF NUMBER with some bug even though some of 'em are fixed
//*******
//FILE INPUT STRUCTURE:
//- First line contains the integer N is the length of the integer array 
// and integer M is the number to search for
//*******
//- Second line contains all the elements of the array, in Ascending order, seperated by " "
//*******
//- Third line contains integer TestSw, allows TestIn function to start
// when set to 1 and vice versa; and integer MOpt is the number represents the searching options:
// 0 for the first position
// 1 for the last position
//*******
//INPUT FILE NAME: "BS2_In.txt"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int a[100];
int n;
int m;
int MOpt,TestSw;

//Input from File function
void FileIn(int *FError)
{
    //Execute file Input
    FILE *fin;
    fin= fopen ("BS2_In.txt","r");
    if (fin!=NULL)
    {
        //Input N, M and MOpt
        *FError= 0;
        fscanf (fin,"%d\n%d",&n,&m);
        int i;
        //Input Array
        for (i=0; i<n; i++) fscanf (fin,"%d",&a[i]);
        //Input TestSw
        fscanf (fin,"\n%d%d",&TestSw,&MOpt);
        fclose (fin);
    }
    else *FError=1;
}

//Test Input
void TestIn (int fswitch)
{
    int i;
    if (fswitch==0) return;
    printf ("N= %d, M= %d\n",n,m);
    for (i=0; i<n; i++) printf ("%d ",a[i]);
    printf ("\nMOpt= %d, TestSw= %d",MOpt,TestSw);
    printf ("\n");
}

//Modifined binary search 
int ModifiedBinS (int SOpt,int first, int last)
{
    int midP;
    switch (SOpt)
    {
        //First position
        case 0:
            while (first<last)
            {
                midP= first+(last-first)/2;
                if (a[midP] < m) first= midP+1;  
                else last= midP;
            }
            return last;
            break;

        //Last position
        case 1:
            while (first<last)
            {
                midP= last+(first-last)/2;
                if (a[midP] > m) last= midP-1;  
                else first= midP;
            }
            return last;
            break;

        default: return -1;
    }
    
}

int main()
{
    //Input
    int fe;
    FileIn (&fe);
    //Test Input
    if (fe==1) 
    {
        printf ("Input FAILED");
        return 1;
    }
    TestIn (TestSw);
    //During debugging, implementing TestIn (1) is highly recommended

    int resultP;
    //Execute ModifiedBinS function
    resultP= ModifiedBinS (MOpt,0,n-1);
    //Print result
    if ((a[resultP]==m) && (resultP!=-1)) printf ("%d was found at position no. %d\n",m,resultP);
    else printf ("%d not found\n",m);
    printf ("\nEnd of program");
    return 0;
}