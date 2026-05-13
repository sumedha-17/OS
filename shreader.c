#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main()
{
    int segment_id;
    char *shared_memory;
    struct shmid_ds shmbuffer;
    int segment_size;

    printf("Enter the shared memory id: ");
    scanf("%d", &segment_id);

    /* Reattach the shared memory segment at a specific address */
    shared_memory = (char *)shmat(segment_id, (void *)0x5000000, 0);

    if (shared_memory == (char *)-1)
    {
        printf("Error in attaching shared memory\n");
        return 1;
    }

    printf("Shared memory reattached at address %p\n", shared_memory);

    /* Print contents of shared memory */
    printf("The contents of the shared memory are:\n%s\n", shared_memory);

    /* Detach shared memory */
    shmdt(shared_memory);

    return 0;
}
