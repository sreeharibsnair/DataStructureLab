#include<stdio.h>
#include<stdlib.h>

// Define structure using bit-field (each element occupies only 1 bit)
struct bit {unsigned char x:1;};

// Define universal set and its size
int uset[]={1,2,3,4,5,6,7,8,9},size=9;

void main()
{
    // Function declarations
    void readset(struct bit[],int n);
    void printset(struct bit []);
    void unionset(struct bit[],struct bit[],struct bit[]);
    void intersect(struct bit[],struct bit[],struct bit[]);
    void diffrence(struct bit[],struct bit[],struct bit[]);

    // Bit arrays for sets A, B, and C
    struct bit a[10]={0},b[10]={0},c[10]={0};
    int n;

    // Input and read Set A
    printf("No. of elements in set A : ");
    scanf("%d",&n);
    readset(a,n);

    // Input and read Set B
    printf("No. of elements in set B : ");
    scanf("%d",&n);
    readset(b,n);

    // Display input sets
    printf("Set A : ");printset(a);
    printf("Set B : ");printset(b);

    // Perform and display union
    unionset(a,b,c);
    printf("AUB = ");printset(c);

    // Perform and display intersection
    intersect (a,b,c);
    printf("A intersect B = ");printset(c);

    // Perform and display difference (A-B)
    diffrence(a,b,c);
    printf("A-B=");printset(c);
}

// to read a set and store as bit string
void readset(struct bit a[],int n)
{
    int i,x,k;
    printf("Enter %d elements : ",n);
    for(i=0;i<n;++i)
    {
        scanf("%d",&x);
        // Check if element x is in the universal set
        for(k=0;k<size;++k)
            if(uset[k]==x)  // if x is a member of universal set
            {               // set 1 corresponding to x in a[]
                a[k].x=1;
                break;
            }
    }
    return;
}

// to print a set from bit string representation 
void printset(struct bit a[])
{
    int k;
    printf("{");
    for(k=0;k<size;++k)
        if(a[k].x==1)       // print only elements marked as 1
            printf("%d",uset[k]);
    printf("}\n");
    return;
}

// to find union of two sets using bit string
void unionset (struct bit a[],struct bit b[],struct bit c[])
{
    int k;
    for(k=0;k<size;++k)
        c[k].x=a[k].x | b[k].x;   // bitwise OR for union
    return;
}

// to find intersection of two sets
void intersect(struct bit a[],struct bit b[],struct bit c[])
{
    int k;
    for(k=0;k<size;++k)
        c[k].x=a[k].x & b[k].x;   // bitwise AND for intersection
    return;
}

// to find difference of two sets
void diffrence(struct bit a[],struct bit b[],struct bit c[])
{
    int k;
    for(k=0;k<size;++k)
        if(a[k].x==1)             // check if element in A
            c[k].x=a[k].x^b[k].x; // XOR removes if also in B
    return;
}
