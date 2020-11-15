#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
   /*DEKLARACJA ZMIENNYCH*/
    int max_memory=atoi(argv[1]); 
    FILE *fp; /* potrzebne do odczytywania wartości pamięci zajmowanej przez proces*/
    int pid;
    char buffer[12]; /*potrzebne do zmiany int w tablicę char*/
    char command_for_memory[120]= "cat /proc/";
    const char *part2_of_command = "/status | grep \"^VmSize\" | awk '{print $2}'"; /*stworzymy polecenie bash odczytujące pamięć*/
    int process_memory;
    int *arr = malloc(sizeof(double)); 
        if (arr == NULL) {printf("malloc failed\n");} 


    /*pobieramy PID */
    fp = popen("pidof lab2skrypt01v2","r");
    fscanf(fp, "%d", &pid);
    fclose(fp); 

    /*tworzymy polecenie odczytujące pamięć zajmowaną przez proces */
    snprintf(buffer, 12, "%d", pid);
    strcat(command_for_memory, buffer);
    strcat(command_for_memory, part2_of_command);
    

    /*odczytujemy pamięć*/
    fp = popen(command_for_memory,"r");
    fscanf(fp, "%d", &process_memory);
    fclose(fp);

    printf("Process ID: %d  \n", pid);

       while (process_memory < max_memory-128){
	arr = malloc(128*sizeof(double));
	if (arr == NULL) {printf("malloc failed\n");}
	fp = popen(command_for_memory,"r");
        fscanf(fp, "%d", &process_memory);
        fclose(fp);
    }
    printf("Process %d memory usage: %d\n", pid, process_memory);
    printf("Press any key to continue.\n");
    getchar();
    return 0;
}


