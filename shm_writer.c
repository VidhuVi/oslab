#include <stdio.h>
#include <stdlib.h>

#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main()
{
    // Generate an shmkey
    key_t shmkey = ftok("./shmkey", 'M');

    // Create shared memory segment
    int shmid = shmget(shmkey, SHM_SIZE, IPC_CREAT | 0666);

    // Attach to the newly created shm and get a pointer to a memory segment
    char *shm = shmat(shmid, NULL, 0);

    // Write to the SHM
    sprintf(shm, "Hello from the SHM");
    printf("Data written to SHM\n");

    // Detach the shared memory segment
    shmdt(shm);

    return 0;
}
