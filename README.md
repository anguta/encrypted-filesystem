# Filesystem and Encyption
In this assignment you will be be updating the xv6 filesystem to encrypt and decrypt files.  You will add the encrypted status to the inode structures.  You will also modify the user applications to take this into account and not perform operations on encrypted files.

## Kernel Mode

### int encrypt(  int fd, uint8 key )
This system call will encrypt the file represented by the file descriptor, fd.  The system call will perform a byte-by-byte XOR encryption on the file using the provided key. 

Attempting to encrypt a file that is already encrypted will return -1 and no change will be made to the file.

### int decrypt(  int fd, uint8 key )
This system call will decrypt the file represented by the file descriptor, fd.  The system call will perform a byte-by-byte XOR decryption on the file using the provided key.  

Attempting to decrypt a file that is not encrypted will return -1 and no change will be made to the file.

### struct file and struct (file.c/h)
You will update the file structure and the in-memory inode structure to track if a file has been encrypted in a uint8.  Unecrypted status is a value of 0.  Encrypted status is a value of 1.  

### iupdate() and ilock() (fs.c)
Copy the encrypted status to and from the inode

### iget() (fs.c)
Initialize the encrypted status 

### stati() (fs.c)
Copy the encrypted status from the inode

### stat
Update the stat struct to add the encrypted status of the given file.

## User Space

### cat
Update cat.c so that encrypted files will not be printed. If cat is passed an encrypted file it should print: "Error: File is encrypted.". Ensure the print statement is exactly as specified. On failure a -1 will be returned.

### grep
Update grep.c so that encrypted file will not be search. If grep is passed an encrypted file it should return: "Error: File is encrypted.". Ensure the print statement is exactly as specified.  On failure a -1 will be returned.

### wc
Update wc.c so that encrypted file will not be processed. If wc is passed an encrypted file it should return: "Error: File is encrypted.". Ensure the print statement is exactly as specified. On failure a -1 will be returned.


## SUBMITTING

Push all your changes to your main branch.  

## BUILDING AND RUNNING XV6

### Setting up the cross-compiling environment
```
source source_me.sh
```

### To build the kernel:
```
make
```

### To build the userspace applications and run the OS
```
make qemu
```

### To exit xv6
```
ctrl-a x
```
