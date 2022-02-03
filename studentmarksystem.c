 #include<stdio.h>
struct student{
 int rollno;
 int mark;
}stu[50],temp,maxa;
struct student* reheapup(int i)
{
 int parent;
    if(i!=0)
    {
     parent =(i-1)/2;
     if(stu[i].mark > stu[parent].mark)
       {
      temp=stu[parent];
         stu[parent]=stu[i];
         stu[i]=temp;
         reheapup(parent);
       }
    }
    return stu;
}
struct  heap* reheapdown(int i,int n)
{
    int leftkey,rightkey,largechild,largechildindex;
    if((i*2+1)<=n)
    {
        leftkey=stu[i*2+1].mark;
        if((i*2+2)<=n)
        {
            rightkey=stu[i*2+2].mark;
        }
        else{
            rightkey=NULL;
        }
        if(leftkey>rightkey)
        {
            largechild=leftkey;
            largechildindex=i*2+1;
        }
        else{
            largechild=rightkey;
            largechildindex=i*2+2;
        }
        if(stu[i].mark<largechild)
        {
            temp=stu[i];
            stu[i]=stu[largechildindex];
            stu[largechildindex]=temp;
            reheapdown(largechildindex,n);

        }
    }

};
int prioritymax(int n)
{
    if(n<0)
    {
        return NULL;
    }
    maxa = stu[0];
    printf("\n");
     printf("%d\t%d",maxa.rollno,maxa.mark);
    stu[0]=stu[n];
     n--;
  reheapdown(0,n);
};
int main()
{
 int i,n,k=0;
 printf("Enter the total no. of students:");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  printf("Enter the roll.no:");
  scanf("%d",&stu[i].rollno);
  printf("Enter the marks");
  scanf("%d",&stu[i].mark);
 }
 for(i=0;i<n;i++)
 {

  reheapup(i);

}
 for(i=0;i<n;i++)
 {

  prioritymax(n);

}


}

