#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    int fd[2],i,status,t,y;
    char msg[13] = "Hello world!",c;
    
    if(pipe(fd)==-1)
    {
        printf("Error creating pipe \n");
        exit(1);
    }
    if(fork()) /*parent process is pipe writer */
    {
        close(fd[0]);
        printf("enter your option for printing: ");
        scanf("%i",&y);
        write(fd[1],&y,1);
        for(i =0;i<12;i++)
        {
            write(fd[1],&msg[i],1);
        }
        wait(&status);
    }
    else /* child process is  pipe reader */
    {
        close(fd[1]);
        read(fd[0],&t,1);
        if(t == 1)
        {
        for(i = 0;i<12;i++)
        {
            read(fd[0],&c,1);
            printf("%c",c);
        }
        }
        else
        {
        for(i = 0;i<12;i++)
        {
            read(fd[0],&c,1);
            printf("%i ",(int)c);
        }
        }
        
        printf("\n");
    }
    return 0;
}
        