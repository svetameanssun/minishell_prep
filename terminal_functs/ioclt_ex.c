#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>

/*Terminal Control (TTY)
TIOCSTI: Insert the given input into the terminal's input queue as if typed by the user.
TIOCSWINSZ: Set the terminal window size.
TIOCMBIS: Set the indicated modem bits.
TIOCMBIC: Clear the indicated modem bits.
TIOCMGET: Get the status of modem bits.
TIOCMSET: Set the status of modem bits.
File System Control
FIONREAD: Get the number of bytes available for reading.
FIONBIO: Set or clear non-blocking mode on a file descriptor.
Network Interface
SIOCGIFFLAGS: Get the flags of a network interface.
SIOCSIFFLAGS: Set the flags of a network interface.
SIOCGIFADDR: Get the address of a network interface.
SIOCSIFADDR: Set the address of a network interface.
SIOCGIFMTU: Get the MTU (Maximum Transmission Unit) size of a network interface.
SIOCSIFMTU: Set the MTU size of a network interface.
Sound and Multimedia
SNDCTL_DSP_RESET: Reset the sound device.
SNDCTL_DSP_SETFMT: Set the audio data format.
SNDCTL_DSP_CHANNELS: Set the number of audio channels (mono/stereo).
SNDCTL_DSP_SPEED: Set the sample rate.
Storage Devices
BLKGETSIZE: Get the size of a block device in sectors.
BLKSSZGET: Get the sector size of a block device.
BLKRRPART: Re-read the partition table.
BLKBSZGET: Get the block size for block device I/O operations.
BLKBSZSET: Set the block size for block device I/O operations.
General Purpose
MEMGETINFO: Get memory information.
VIDIOCGCAP: Get video capture device capabilities.*/
int main() {
    // Example using a file descriptor from a pipe
    int fds[2];
    if (pipe(fds) == -1) {
        perror("pipe");
        return 1;
    }

    // Write some data to the write end of the pipe
    char *message = "Hello, world!";
    write(fds[1], message, strlen(message));

    // Use FIONREAD to check available data for reading
    int bytes_available;
    if (ioctl(fds[0], FIONREAD, &bytes_available) == -1) {
        perror("ioctl FIONREAD");
        return 1;
    }
    printf("Bytes available to read: %d\n", bytes_available);
    // Clean up
    close(fds[0]);
    close(fds[1]);
    return 0;
}


/*int main() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    printf("lines %d\n", w.ws_row);
    printf("columns %d\n", w.ws_col);
    return 0;
}*/