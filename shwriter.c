#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    int segment_id;
    char *shared_memory;
    struct shmid_ds shmbuffer;
    int segment_size;
    const int shared_segment_size = 0x6400;

    /* Allocate a shared memory segment */
    segment_id = shmget(IPC_PRIVATE, shared_segment_size,
                        IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);

    if (segment_id == -1)
    {
        printf("Error creating shared memory\n");
        return 1;
    }

    printf("Shared memory segment ID is %d\n", segment_id);

    /* Attach the shared memory segment */
    shared_memory = (char *)shmat(segment_id, 0, 0);

    if (shared_memory == (char *)-1)
    {
        printf("Error attaching shared memory\n");
        return 1;
    }

    printf("Shared memory attached at address %p\n", shared_memory);

    /* Determine the segment size */
    shmctl(segment_id, IPC_STAT, &shmbuffer);
    segment_size = shmbuffer.shm_segsz;
    printf("Segment size: %d\n", segment_size);

    /* Write a string to the shared memory */
    strcpy(shared_memory, "Hello, world.");

    /* Detach the shared memory segment */
    shmdt(shared_memory);

    printf("Wrote Hello, world. to the shared memory segment\n");

    return 0;
}
