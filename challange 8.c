//algorithm//
Algorithm: GRIDWATCH

1. Start.
2. Declare the required variables and a 2D array.
3. Enter the grid size (3 to 6). If invalid, ask again.
4. Enter the risk scores for each cell (0 to 100).
5. Enter the threshold value (1 to 100).
6. Display the grid.
7. Find and display the total of each row and the highest row total.
8. Find and display the total of each column and the highest column total.
9. Find the highest risk score and its position.
10. Count the number of cells that meet the threshold.
11. Calculate the main and secondary diagonal totals and check whether they are equal.
12. Calculate and display the boundary total.
13. Find and display the local hotspots in the grid.
14. Display the final result as CRITICAL, WARNING or NORMAL.
15. Stop.

 
input : 
#include<stdio.h>
int main()
{
int a[6][6],n,t;
int i,j,sum;
int rmax=-1,cmax=-1;
int max=-1,count=0;
int d1=0,d2=0;
int b=0,h=0;
printf("enter size of grid : ");
scanf("%d",&n);
while(n<3||n>6)
{
printf("enter size between 3 and 5");
scanf("%d",&n);
}
printf("enter the risk value : \n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("enter value : ");
scanf("%d",&a[i][j]);
while(a[i][j]<0||a[i][j]>100)
{

printf("wroung value enter again : ");
scanf("%d",&a[i][j]);
}
}
}
printf("enter warning thrishold : ");
scanf("%d",&t);
while(t<1||t>100)
{
printf("enter threshold between 1 and 100 : ");
scanf("%d",&t);
}
printf("grid value :");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("%4d",a[i][j]);
}
printf("\n");
}
printf("row total :");
for(i=0;i<n;i++)
{
sum=0;
for(j=0;j<n;j++)
{
sum+=a[i][j];
}
printf("row%d=%d\n",i+1,sum);
if(sum>rmax)
{
rmax=sum;
}
}
printf("highest row : ");
for(i=0;i<n;i++)
{
sum=0;
for(j=0;j<n;j++)
{
sum+=a[i][j];
}
if(sum==rmax)
{
printf("%d",i+1);
}
}
printf("column total : ");
for(j=0;j<n;j++)
{
sum=0;
 for(i=0;i<n;i++)
{
sum+=a[i][j];
}
printf("column%d=%d\n",j+1,sum);
if(sum>cmax)
{
cmax=sum;
}
}
printf("highest column : ");
for(j=0;j<n;j++)
{
sum=0;
for(i=0;i<n;i++)
{
sum+=a[i][j];
}
if(sum==cmax)
{
printf("%d",j+1);
}
}
printf("maximum risk : ");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(a[i][j]>max)
{
max=a[i][j];
}
if(a[i][j]>=t)
{
count++;
}
}
}
printf("maximum value = %d\n",max);
printf("maximum value position : \n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(a[i][j]==max)
{
printf("row%dcolumn%d",i+1,j+1);
}
}
}
printf("threshold count=%d\n",count);
for(i=0;i<n;i++)
{
d1+=a[i][i];
d2+=a[i][n-1-i];
}
printf("main diagonal=%d\n",d1);
printf("secondary diagonal=%d\n",d2);
if(d1==d2)
{
printf("both diagonals are equal");
}
else
{
printf("both diagonals are not equal");
}
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(i==0||i==n-1||j==0||j==n-1)
{
b+=a[i][j];
}
}
}
printf("boundary total=%d\n",b);
printf("hotspots : ");
 for(i=1;i<n-1;i++)
{
for(j=1;j<n-1;j++)
{
if(a[i][j]>a[i-1][j]&&a[i][j]>a[i+1][j]&&a[i][j]>a[i][j-1]&&a[i][j]>a[i][j+1])
{
printf("hotspot at row %d column %d\n",i+1,j+1);
h++;
}
}
}
if(h==0)
{
printf("no hotspot found\n");
}
if(h>0)
{
printf("final result :");
}
else if(count>=n)
{
printf("warning\n");
}
else
{
printf("normal\n");
}
return 0;
}


"\\ out put \\"
gcc challenge8.c
sasank:~$ 1.  ./a.out
enter size of grid : 3
enter the risk value :
enter value : 1
enter value : 2
enter value : 3
enter value : 3
enter value : 2
enter value : 1
enter value : 0
enter value : 0
enter value : 0
enter warning thrishold : 50
grid value :   1   2   3
   3   2   1
   0   0   0
row total :row1=6
row2=6
row3=0
highest row : 12column total : column1=4
column2=4
column3=4
highest column : 123maximum risk : maximum value = 3
maximum value position :
row1column3row2column1threshold count=0
main diagonal=3
secondary diagonal=5
both diagonals are not equalboundary total=10
hotspots : no hotspot found
normal
2.  ./a.out
enter size of grid : 3
enter the risk value :
enter value : 10
enter value : 90
enter value : 10
enter value : 20
enter value : 90
enter value : 20
enter value : 10
enter value : 10
enter value : 10
enter warning thrishold : 50
grid value :  10  90  10
  20  90  20
  10  10  10
row total :row1=110
row2=130
row3=30
highest row : 2column total : column1=40
column2=190
column3=40
highest column : 2maximum risk : maximum value = 90
maximum value position :
row1column2row2column2threshold count=2
main diagonal=110
secondary diagonal=110
both diagonals are equalboundary total=180
hotspots : no hotspot found
normal
3,4.enter size of grid : 3
enter the risk value :
enter value : 1
enter value : 2
enter value : 3
enter value : 4
enter value : 5
enter value : 6
enter value : 7
enter value : 8
enter value : 9
enter warning thrishold : 50
grid value :   1   2   3
   4   5   6
   7   8   9
row total :row1=6
row2=15
row3=24
highest row : 3column total : column1=12
column2=15
column3=18
highest column : 3maximum risk : maximum value = 9
maximum value position :
row3column3threshold count=0
main diagonal=15
secondary diagonal=15
both diagonals are equalboundary total=40
hotspots : no hotspot found
normal
5. enter size of grid : 3
enter the risk value :
enter value : 1
enter value : 2
enter value : 1
enter value : 2
enter value : 9
enter value : 2
enter value : 1
enter value : 2
enter value : 1
enter warning thrishold : 50
grid value :   1   2   1
   2   9   2
   1   2   1
row total :row1=4
row2=13
row3=4
highest row : 2column total : column1=4
column2=13
column3=4
highest column : 2maximum risk : maximum value = 9
maximum value position :
row2column2threshold count=0
main diagonal=11
secondary diagonal=11
both diagonals are equalboundary total=12
hotspots : no hotspot found
normal
6. enter size of grid : 3
enter the risk value :
enter value : 10
enter value : 50
enter value : 60
enter value : 20
enter value : 40
enter value : 70
enter value : 0
enter value : 30
enter value : 50
enter warning thrishold : 50
grid value :  10  50  60
  20  40  70
   0  30  50
row total :row1=120
row2=130
row3=80
highest row : 2column total : column1=30
column2=120
column3=180
highest column : 3maximum risk : maximum value = 70
maximum value position :
row2column3threshold count=4
main diagonal=100
secondary diagonal=100
both diagonals are equalboundary total=290
hotspots : no hotspot found
warning
7.enter size of grid : 3
enter the risk value :
enter value : 60
enter value : 10
enter value : 10
enter value : 10
enter value : 10
enter value : 10
enter value : 10
enter value : 10
enter value : 10
enter warning thrishold : 50
grid value :  60  10  10
  10  10  10
  10  10  10
row total :row1=80
row2=30
row3=30
highest row : 1column total : column1=80
column2=30
column3=30
highest column : 1maximum risk : maximum value = 60
maximum value position :
row1column1threshold count=1
main diagonal=80
secondary diagonal=30
both diagonals are not equalboundary total=130
hotspots : no hotspot found
normal
8.enter size of grid : 2
enter size between 3 and 5
