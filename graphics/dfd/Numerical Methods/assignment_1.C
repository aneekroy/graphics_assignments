#include<stdio.h>
#include<conio.h>
#include<math.h>
void read_matrix(float p[][10],int *row,int *col);
void printf_matrix(float p[][10],int row,int col);
void addition(float p[][10],int m,int n,float q[][10],int x,int y,float r[][10],int *f);
void subtraction(float p[][10],int row1,int col1,float q[][10],int row2,int col2,float r[][10],int *f);
void transpose(float p[][10],int row,int col,float r[][10],int *nrow,int *ncol);
void multiplication(float p[][10],int row1,int col1,float q[][10],int row2,int col2,float r[][10],int *row,int *col,int *f);
float determinant(float p[][10],int order);
void adjoint(float p[][10],int order,float r[][10]);
void inverse(float p[][10],int row,int col,float r[][10],int *order,int *f);
void main()
 {
  int i,j,k,m,n,p,q,row,col,flag,flag1,x,y,u,v,order;
  float a[10][10],b[10][10],c[10][10],d[10][10],e[10][10],f[10][10],g[10][10];
  float h[10][10],h1[10][10];
  clrscr();
  printf("read the first matrix\n");
  read_matrix(a,&m,&n);
  printf("read the second matrix\n");
  read_matrix(b,&p,&q);
  addition(a,m,n,b,p,q,c,&flag);
  subtraction(a,m,n,b,p,q,d,&flag1);
  if(flag==0 && flag1==0)
   {
    printf("\nthe addition of the given two matrices is");
    printf_matrix(c,m,n);
    printf("\nthe subtraction of the given two matrices is");
    printf_matrix(d,m,n);
   }
  else
   printf("\nthe addition or subtraction of matrices is impossible as they are not same order\n");
  transpose(a,m,n,e,&x,&y);
  printf("\nthe transpose of the first matrix is");
  printf_matrix(e,x,y);
  transpose(b,p,q,g,&u,&v);
  printf("\nthe transpose of the second matrix is");
  printf_matrix(g,u,v);
  multiplication(a,m,n,b,p,q,f,&row,&col,&flag);
  if(flag==0)
   {
    printf("\nthe multiplication of the given two matrices is");
    printf_matrix(f,row,col);
   }
  else
   printf("\nmatrix multiplication of the matrices is not possible as Col1 != row2\n");
  inverse(a,m,n,h,&order,&flag);
  if(flag==0)
   {
    printf("\nthe inverse of the first matrix is");
    printf_matrix(h,order,order);
   }
  else
   if(flag==1)
    printf("\nthe inverse of the first matrix is impossible as the matrix is not a square \n matrix\n");
   else
    printf("\nthe inverse of the first matrix is impossible as it is singular\n");
  inverse(b,p,q,h1,&order,&flag);
  if(flag==0)
   {
    printf("\nthe inverse of the second matrix is");
    printf_matrix(h1,order,order);
   }
  else
   if(flag==1)
    printf("\nthe inverse of the second matrix is impossible as the matrix is not a square \n matrix\n");
   else
    printf("\nthe inverse of the second matrix is impossible as it is singular\n");
  getch();
 }
 void addition(float p[][10],int row1,int col1,float q[][10],int row2,int col2,float r[][10],int *f)
  {
   int i,j;
   *f=0;
   if(row1==row2 && col1==col2)
    {
     for(i=0;i<row1;++i)
      for(j=0;j<col1;++j)
       r[i][j]=p[i][j]+q[i][j];
    }
   else
    *f=1;
  }
 void subtraction(float p[][10],int row1,int col1,float q[][10],int row2,int col2,float r[][10],int *f)
  {
   int i,j;
   *f=0;
   if(row1==row2 && col1==col2)
    {
     for(i=0;i<row1;++i)
      for(j=0;j<col1;++j)
       r[i][j]=p[i][j]-q[i][j];
    }
   else
    *f=1;
  }
 void transpose(float p[][10],int row,int col,float r[][10],int *nrow,int *ncol)
  {
   int i,j;
   for(j=0;j<col;++j)
    for(i=0;i<row;++i)
     r[j][i]=p[i][j];
   *nrow=col;
   *ncol=row;
  }
 void read_matrix(float a[][10],int *row,int *col)
  {
   int m,n,i,j;
   printf("enter the no.s of rows and column\n");
   scanf("%d%d",&m,&n);
   for(i=0;i<m;++i)
    {
     printf("enter the values of row %d   ",i);
     for(j=0;j<n;++j)
      scanf("%f",&a[i][j]);
    }
   *row=m;
   *col=n;
  }
 void multiplication(float p[][10],int row1,int col1,float q[][10],int row2,int col2,float r[][10],int *row,int *col,int *f)
  {
   int i,j,k;
   *f=0;
   if(col1==row2)
    {
     for(i=0;i<row1;++i)
      for(k=0;k<col2;++k)
       {
	r[i][k]=0;
	for(j=0;j<col1;++j)
	 r[i][k]=r[i][k]+p[i][j]*q[j][k];
       }
     *row=row1;
     *col=col2;
    }
   else
    *f=1;
  }
 void printf_matrix(float p[][10],int row,int col)
  {
   int i,j;
   for(i=0;i<row;++i)
    {
     printf("\n");
     for(j=0;j<col;++j)
      printf("%.2f  ",p[i][j]);
    }
  }
 float determinant(float p[][10],int order)
  {
   int i,j,k,l;
   float c,d,t,a[10][10],det=1.0;
   for(i=0;i<order;++i)
    for(j=0;j<order;++j)
     a[i][j]=p[i][j];
   for(k=0;k<order-1;++k)
    {
     if(a[k][k]==0.0)
      {
       for(l=k+1;l<order;++l)
	{
	 if(a[l][k]!=0.0)
	  {
	   for(j=0;j<order;++j)
	    {
	     t=a[k][j];
	     a[k][j]=a[l][j];
	     a[l][j]=t;
	    }
	   det=det*(-1);
	   break;
	  }
	}
      }
     if(a[k][k]!=0.0)
      {
       for(i=k+1;i<order;++i)
	{
	 d=a[k][k];
	 c=a[i][k];
	 for(j=k;j<order;++j)
	  a[i][j]=a[i][j]-(a[k][j]/d)*c;
	}
      }
     else
      {
       det=0.0;
       break;
      }
    }
   for(i=0;i<order;++i)
    det=det*a[i][i];
   return(det);
  }
 void adjoint(float p[][10],int order,float r[][10])
  {
   int i,j,l,k,x,y;
   float t[10][10];
   for(i=0;i<order;++i)
    for(j=0;j<order;++j)
     {
      x=0;
      for(k=0;k<order;++k)
       {
	y=0;
	for(l=0;l<order;++l)
	 {
	  if(k!=i && l!=j)
	   {
	    t[x][y]=p[k][l];
	    y++;
	    if(y==order-1)
	     x++;
	   }
	 }
       }
      r[j][i]=pow((-1),(i+j))*determinant(t,order-1);
     }
  }
 void inverse(float p[][10],int m,int n,float r[][10],int *order,int *f)
  {
   int i,j;
   float d,q[10][10];
   *f=0;
   if(m==n)
    {
     d=determinant(p,n);
     adjoint(p,n,q);
     if(d!=0.0)
      {
       for(i=0;i<n;++i)
	for(j=0;j<n;++j)
	 r[i][j]=q[i][j]/d;
      *order=n;
     }
    else
     *f=2;
    }
   else
    *f=1;
  }