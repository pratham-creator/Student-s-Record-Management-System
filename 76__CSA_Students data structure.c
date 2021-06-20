// Name :  Pratham Pandurang Ghule
// Roll No. :  76   Div. : CS_A     Batch : 02

// Title : Menu Driven program to add, modify, display and delete data related to student base on 'c' Structure.
// Description : This program basically contains a a user defined data type i.e. structure related to student data. Here we performing
// operations like add, modify, display and delete data using that student's structure.


// Input :  Since it is menu driven program, so input's are according to instructions.


// Output : Formated output based on users input

#include<stdio.h>
#include<string.h>
struct student      //creating student structure
{
    char name[50];
    int rollNo;
    float cgpa;
};

struct student s[100];          //declaration of functions and creating a pointer to point to record
int ptr=0;
void add_record();
void modify_record();
void delete_record();
void display_record();
void search_record();
void quick_sort();
void merge_sort();

int main()                   //main function
{
    int choice,c;
    printf("******************************************STUDENT'S RECORD MANAGEMENT SYSTEM******************************************\n\n");

    do{                                                                //do while loop
        printf("\t\t****************MENU*************\n\n");       //Menu of students management system
        printf("\t\t|\t1)ADD RECORD\t\t|\n");
        printf("\t\t|\t2)MODIFY RECORD\t\t|\n");
        printf("\t\t|\t3)DELETE RECORD\t\t|\n");
        printf("\t\t|\t4)DISPLAY RECORD\t|\n");
        printf("\t\t|\t5)SEARCH RECORD\t\t|\n");
        printf("\t\t|\t6)QUICK SORT\t\t|\n");
        printf("\t\t|\t7)MERGE SORT\t\t|\n\n");
        printf("\t\t*********************************\n");
        printf("\n\tPress required KEY to perform a operation\n\t");   // Asking for choice from user to do certain operations
        scanf("%d",&choice);

        switch(choice)          //switch case
        {
        case 1:
            add_record();    //call to add a record
            break;

        case 2:
            modify_record();        //call to modify a record
            break;

        case 3:
            delete_record();         //Call to delete a record
            break;

        case 4:
            display_record();        //call to display a record
            break;

        case 5:
            search_record();        //call to search a record
            break;

        case 6:
            quick_sort(0,ptr-1);     //call to sort record using quick sort
            display_record();       //display sorted record
            break;

        case 7:
            merge_sort(0,ptr-1);    //call to sort record using merge sort
            display_record();       //display sorted record
            break;

        default:                    //Displaying message if wrong option choosed
            printf("\tInvalid Key Entered!!\n\tPlease select correct operation");
        }

        printf("\n\tPress 1 to continue and 0 to exit.........  :");        //Press 0 to exit the loop
        scanf("%d",&c);
        printf("\n");
    }while(c);     //Continue loop until c==1
    return 0;
}

void add_record()       //function to add record
{
    int n;     //no. of record to add
    int countOfStd=1;           //variable to display serial no.
    printf("\n\tEnter no. of records you want to add: ");     //Enter no. of record to add
    scanf("%d",&n);
    for(int i=ptr;n>0;n--){    //loop to ask details of student

        printf("\n\tEnter detail of student %d: ",countOfStd);
        printf("\n\t\tEnter name of student: ");
        fflush(stdin);
        scanf("%[^\n]%*c",s[ptr].name);    //to take string with spaces
        printf("\t\tEnter roll no. of %s: ",&s[ptr].name);
        scanf("%d",&s[ptr].rollNo);
        printf("\t\tEnter CGPA of %s: ",&s[ptr].name);
        scanf("%f",&s[ptr].cgpa);
        i++;
        ptr++;                  //Increment record pointer
        countOfStd++;
    }
    printf("\n\t***********RECORD ADDED SUCCESSFULLY***********");

}

void modify_record()                //function to modify record
{
    int r;
    int choice;
    int f=0;            //flag to check  if record found or not
    int j=ptr;
    printf("\n\tEnter roll no. of student whose record you want to modify:");   //ask for roll no. to modify its data
    scanf("%d",&r);
    for(int i=0;j>=0;i++){       //loop to traverse in record
        if(s[i].rollNo==r){            //check if we are at required roll no.
            printf("\n\tEnter which data you want to modify of %s",s[i].name);
            printf("\n\t1)Name\n\t2)Roll No.\n\t3)CGPA\n\t4)Everything\n");     //Menu to modify certain details
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:         //T modify name
                printf("\n\tEnter new name of student:");
                scanf("%s",&s[i].name);
                printf("\n\t***********RECORD SUCCESSFULLY MODIFIED***********");
                break;

                case 2:             //to modify roll no.
                printf("\tEnter new roll No. of student:");
                scanf("%d",&s[i].rollNo);
                printf("\n\t***********RECORD SUCCESSFULLY MODIFIED***********");
                break;

                case 3:             //to modify cgpa
                printf("\tEnter new CGPA of student:");
                scanf("%f",&s[i].cgpa);
                printf("\n\t***********RECORD SUCCESSFULLY MODIFIED***********");
                break;

                case 4:             //to modify all data of student
                printf("\n\tEnter new name of student:");
                scanf("%s",&s[i].name);
                printf("\tEnter new roll No. of student:");
                scanf("%d",&s[i].rollNo);
                printf("\tEnter new CGPA of student:");
                scanf("%f",&s[i].cgpa);
                printf("\n\t***********RECORD SUCCESSFULLY MODIFIED***********");
                break;

                default:             //if wrong option pressed
                printf("\n\tPlease enter correct option");


            }
            display_record();            //display record if we modified the required record
            return;

        }


        j--;
    }
    printf("\n\tStudent with roll no. %d not found.",r);        //if required roll no. not found
}

void delete_record()        // function to delete record
{
    int rn;
    int i;


    printf("\n\tEnter the roll no. of student whose data you want to delete: ");   //ask for roll no. we want to delete
    scanf("%d",&rn);
    for(i=0;i<ptr;i++){         //loop to found the position of required student in record
        if(s[i].rollNo==rn){      //if record found we break th loop
            break;

        }
    }
    if(i>=ptr){     //if loop traversed up to the record pointer,it mean we didn't find the required record
        printf("\n\tStudent with roll No. %d not found",rn);
    }
    else{       //if we found the record

        for(int j=i;j<ptr;j++){     //for loop to move the record up to the record we want to delete
            strcpy(s[j].name,s[j+1].name);
            s[j].rollNo=s[j+1].rollNo;
            s[j].cgpa=s[j+1].cgpa;
        }
        ptr--;          //decrement the record pointer
        printf("\n\t***********RECORD DELETED SUCCESSFULLY***********");
        display_record();       //display the record
    }


}

void display_record()       //function to display record
{
    int i=ptr;
    printf("\n\tSR.No.\t\t\tName\t\t\tRoll No.\t\t\tCGPA");
    for (int j=0;i>0;j++)       //loop to display data until we reach end of record
    {

        printf("\n\t%d",j+1);
        printf("\t\t\t");
        printf("%s",s[j].name);
        printf("\t\t\t");
        printf("%d",s[j].rollNo);
        printf("\t\t\t");
        printf("%0.2f\n",s[j].cgpa);
        i--;
    }
}

void search_record()        //function to search record
{
    int i=0;
    int rn;
    printf("\n\tEnter the roll no. of student whose data you want to display: ");       //ask for roll no. to display record
    scanf("%d",&rn);
    for(i=0;i<ptr;i++){         //loop to found the position of required student in record
        if(s[i].rollNo==rn){        //break loop if we found our required record
            break;

        }
    }
    if(i>=ptr){         //if record not found
        printf("\n\tStudent with roll No. %d not found",rn);
    }
    else{           //if record found

        printf("\n\tSR.No.\t\t\tName\t\t\tRoll No.\t\t\tCGPA");           //display the record
        printf("\n\t1");
        printf("\t\t\t");
        printf("%s",s[i].name);
        printf("\t\t\t");
        printf("%d",s[i].rollNo);
        printf("\t\t\t");
        printf("%0.2f\n",s[i].cgpa);

    }
}

swap(int l,int h)
{
    struct student s1;
    strcpy(s1.name,s[l].name);
    strcpy(s[l].name,s[h].name);
    strcpy(s[h].name,s1.name);

    s1.rollNo=s[l].rollNo;
    s[l].rollNo=s[h].rollNo;
    s[h].rollNo=s1.rollNo;

    s1.cgpa=s[l].cgpa;
    s[l].cgpa=s[h].cgpa;
    s[h].cgpa=s1.cgpa;
}

int partition(int low,int high)
{

    int p=low;  //setting pivot position to first element
    int l=low;
    int h=high;
    while(l<h){ //iterate while pointer l and r don't cross each other
        while(s[l].rollNo<=s[p].rollNo && l<=high){ //iterate while element at l pointer position is less than pivot position element
            l++;
        }
        while(s[h].rollNo>s[p].rollNo && h>=low){   //iterate while element at r pointer position is less than pivot position element
            h--;
        }
        if(l<h){    //if l does'nt cross h  pointer swap elements at l and h position
            swap(l,h);
        }

    }
    swap(p,h);  //when l and h cross each other swap pivot and element at high position
    return h;   //return updated pivot position



}

void quick_sort(int low,int high)
{
    if(ptr==0){     //If their is no record
        printf("\n\tRecord is Empty");
        return;
    }

    if(low<high){   //check if lower bound is less than upper bound
        int pivot=partition(low,high);  //Finding pivot  element position
        quick_sort(low,pivot-1);  //sorting left subarray
        quick_sort(pivot+1,high);   //sorting right subarray

    }

}

void merge(int low,int mid,int high)
{
    int i=low,j=mid+1,k=0;  //i pointer to left subarray and j pointer to right subarray
    struct student a[ptr];  //temporary array to store sorted data
    while(i<=mid && j<=high){   //iterate while left and right array pointer does'nt go out of bounds
        if(s[i].rollNo<s[j].rollNo){    //if left subarray data is less than right array data
            strcpy(a[k].name,s[i].name);   //copy all the data of left array student to array a
            a[k].rollNo=s[i].rollNo;
            a[k].cgpa=s[i].cgpa;
            i++;
        }
        else{
            strcpy(a[k].name,s[j].name);    //copy all the data of right array student to array a
            a[k].rollNo=s[j].rollNo;
            a[k].cgpa=s[j].cgpa;
            j++;
        }
        k++;        //increment temporary array pointer
    }

        while(j<=high){     //copying remaining elements from right array
            strcpy(a[k].name,s[j].name);
            a[k].rollNo=s[j].rollNo;
            a[k].cgpa=s[j].cgpa;
            j++;
            k++;
        }


        while(i<=mid){  //copying remaining elements from left array
            strcpy(a[k].name,s[i].name);
            a[k].rollNo=s[i].rollNo;
            a[k].cgpa=s[i].cgpa;
            i++;
            k++;
        }

    int loc=low;
    for(int p=0;p<=high;p++){   //Copying all elements from array a to record array s
        strcpy(s[loc].name,a[p].name);
        s[loc].rollNo=a[p].rollNo;
        s[loc].cgpa=a[p].cgpa;

        loc++;
    }



}

void merge_sort(low,high)
{
    if(ptr==0){             //If their is no record
        printf("\n\tRecord is Empty");
        return;
    }

    if(low<high){           //check if lower bound is less than upper bound
        int mid=low+((high-low)/2);  //finding mid position
        merge_sort(low,mid);    //recursively calling merge sort by passing lower bound as low and upper as mid
        merge_sort(mid+1,high);  //recursively calling merge sort by passing lower bound as mid+1 and upper as high
        merge(low,mid,high);   //recursively calling merge function by passing low,mid and high
    }
}

