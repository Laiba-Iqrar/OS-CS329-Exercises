//https://youtu.be/SRLxP_c4G1A link to understand this code
//LRU
#include <stdio.h>
void main(void)
{
int q[20],p[50],c=0,c1,d,f,i,j,k=0,n,r,t,b[20],c2[20]; 
/*c:no of page faults, c1:count for finding whether page fault has occured or not, k:keeping record of how many frames have been filled, q: the array of frames; p:the page no. in reference string; k: the frame number to be filled next; c2: array of count values associated with each frame for finding the LRU one, replace the one with the largest count value; b: array for sorting count values of frames.*/
printf("Enter no of pages:");
scanf("%d",&n);
printf("Enter the reference string:");
for(i=0;i<n;i++)
scanf("%d",&p[i]);
printf("Enter no of frames:");
scanf("%d",&f);
q[k]=p[k];
printf("\n\t%d\n",q[k]);
c++;
k++;
for(i=1;i<n;i++)//taken care of the 0th page, now moving onwards
{
c1=0;
for(j=0;j<f;j++)  //search for the page in all frames
{
if(p[i]!=q[j])  // 
c1++;
}
if(c1==f) // we don’t have the page in any frame
{
c++;//another page fault
if(k<f) //we do have frame available for the page which caused fault
{
q[k]=p[i];
k++;
for(j=0;j<k;j++)
printf("\t%d",q[j]);
printf("\n");
}
else //we don’t have frame available for the page which caused fault
{
for(r=0;r<f;r++)//for initializing c2 array
{
c2[r]=0;//frame location wise counter to base the decision on
for(j=i-1;j>=i-f;j--)
/*only comparison of the last f locations of the reference string will tell us which page to replace. 2 3 4 2 3 4 2 3 2 3 take this example reference string and f=2.  */
{
if(q[r]!=p[j])
c2[r]++;
else
break;//the later the page number is found, the more the c2 value.
}
}
for(r=0;r<f;r++)//copy the counter c2 array to array b
b[r]=c2[r];
for(r=0;r<f;r++)//sort the array so that b[0] contains the largest c2 value
{
for(j=r;j<f;j++)
{
if(b[r]<b[j])
{
t=b[r];
b[r]=b[j];
b[j]=t;
}
}
}
for(r=0;r<f;r++)
{
if(c2[r]==b[0])
q[r]=p[i];//the new page is placed in the frame which had the max c2 value
printf("\t%d",q[r]);
}
printf("\n");
}
}
}
printf("\nThe no of page faults is %d\n",c);
}
