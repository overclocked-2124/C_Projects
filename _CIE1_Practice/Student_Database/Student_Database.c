#include<stdio.h>

struct student {
    int USN;
    char name[50];
    float marks;
};

int main(){
    struct student s[3];
    
    for (int i =0;i<3;i++){
        printf("Enter student %d's USN: ",i);
        scanf("%d",&s[i].USN);
        printf("Enter student %d's Name: ",i);
        scanf("%s",s[i].name);
        printf("Enter student %d's marks: ",i);
        scanf("%f",&s[i].marks);    
    }

    for (int i =0;i<3;i++){
        printf("student %d's USN: %d\n",i,s[i].USN);
        printf("student %d's Name: %s\n",i,s[i].name);
        printf("student %d's marks: %f\n",i,&s[i].marks); 
    }

    return(0);
}