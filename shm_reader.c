#include <stdio.h>
#include <stdlib.h>

#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main()
{
    // Generate THE SAME KEY an shmkey
    key_t shmkey = ftok("./shmkey", 'M');

    // Locate shared memory segment
    int shmid = shmget(shmkey, SHM_SIZE, 0666);

    // Attach to the existing shm and get a pointer to a memory segment
    char *shm = shmat(shmid, NULL, 0);

    // Read from the shm
    printf("The message from the SHM is:\n%s\n", shm);

    // Detach the shared memory segment
    shmdt(shm);

    // Mark the SHM as to be deleted
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
