/*
** EPITECH PROJECT, 2021
** Libfox
** File description:
** List of entries for possible errno values
*/

/*
** This file is an EPITECH compliant import of errlist.h
** from the official glibc repository.
** See https://sourceware.org/git/?p=glibc.git;a=blob;f=sysdeps/gnu/errlist.h
** For the original file.
**
** Docstrings here are reformated and copied from the original header.
** Some values are undocumented, and I chose to keep it that way, as most
** of the undocumented errors you will not encounter or are self explainatory.
**
** NEVER include this header yourself unless you know what you are doing.
** It WILL break your code if not used properly.
** If you want to access the errno string definitions, include `fox_strerror()`
** from fox_io.
*/

#ifndef TXT
    #define TXT(x) (x)
#endif

// START ENTRY DEFINITIONS //

ERRNO_ENTRY(0, TXT("Success"))

/*
** Only the owner of the file (or other resource)
** or processes with special privileges can perform the operation.
*****************************************************************************/
#ifdef EPERM
ERRNO_ENTRY(EPERM, TXT("Operation not permitted"))
#endif


/*
** This is a ``file doesn't exist'' error
** for ordinary files that are referenced in contexts where they are
** expected to already exist.
*****************************************************************************/
#ifdef ENOENT
ERRNO_ENTRY(ENOENT, TXT("No such file or directory"))
#endif


/*
** No process matches the specified process ID.
*****************************************************************************/
#ifdef ESRCH
ERRNO_ENTRY(ESRCH, TXT("No such process"))
#endif


/*
** An asynchronous signal occurred and prevented
** completion of the call.  When this happens, you should try the call
** again.
**
** You can choose to have functions resume after a signal that is handled,
** rather than failing with @code{EINTR}; see @ref{Interrupted
** Primitives}.
*****************************************************************************/
#ifdef EINTR
ERRNO_ENTRY(EINTR, TXT("Interrupted system call"))
#endif


/*
** Usually used for physical read or write errors.
*****************************************************************************/
#ifdef EIO
ERRNO_ENTRY(EIO, TXT("Input/output error"))
#endif


/*
** The system tried to use the device
** represented by a file you specified, and it couldn't find the device.
** This can mean that the device file was installed incorrectly, or that
** the physical device is missing or not correctly attached to the
** computer.
*****************************************************************************/
#ifdef ENXIO
ERRNO_ENTRY(ENXIO, TXT("No such device or address"))
#endif


/*
** Used when the arguments passed to a new program
** being executed with one of the @code{exec} functions (@pxref{Executing a
** File}) occupy too much memory space.  This condition never arises on
** @gnuhurdsystems{}.
*****************************************************************************/
#ifdef E2BIG
ERRNO_ENTRY(E2BIG, TXT("Argument list too long"))
#endif


/*
** Invalid executable file format.  This condition is detected by the
** @code{exec} functions; see @ref{Executing a File}.
*****************************************************************************/
#ifdef ENOEXEC
ERRNO_ENTRY(ENOEXEC, TXT("Exec format error"))
#endif


/*
** For example, I/O on a descriptor that has been
** closed or reading from a descriptor open only for writing (or vice
** versa).
*****************************************************************************/
#ifdef EBADF
ERRNO_ENTRY(EBADF, TXT("Bad file descriptor"))
#endif


/*
** This error happens on operations that are
** supposed to manipulate child processes, when there aren't any processes
** to manipulate.
*****************************************************************************/
#ifdef ECHILD
ERRNO_ENTRY(ECHILD, TXT("No child processes"))
#endif


/*
** Allocating a system resource would have resulted in a
** deadlock situation.  The system does not guarantee that it will notice
** all such situations.  This error means you got lucky and the system
** noticed; it might just hang.  @xref{File Locks}, for an example.
*****************************************************************************/
#ifdef EDEADLK
ERRNO_ENTRY(EDEADLK, TXT("Resource deadlock avoided"))
#endif


/*
** The system cannot allocate more virtual memory
** because its capacity is full.
*****************************************************************************/
#ifdef ENOMEM
ERRNO_ENTRY(ENOMEM, TXT("Cannot allocate memory"))
#endif


/*
** The file permissions do not allow the attempted operation.
*****************************************************************************/
#ifdef EACCES
ERRNO_ENTRY(EACCES, TXT("Permission denied"))
#endif


/*
** An invalid pointer was detected.
** On @gnuhurdsystems{}, this error never happens; you get a signal instead.
*****************************************************************************/
#ifdef EFAULT
ERRNO_ENTRY(EFAULT, TXT("Bad address"))
#endif


/*
** A file that isn't a block special file was given in a situation that
** requires one.  For example, trying to mount an ordinary file as a file
** system in Unix gives this error.
*****************************************************************************/
#ifdef ENOTBLK
ERRNO_ENTRY(ENOTBLK, TXT("Block device required"))
#endif


/*
** A system resource that can't be shared is already in use.
** For example, if you try to delete a file that is the root of a currently
** mounted filesystem, you get this error.
*****************************************************************************/
#ifdef EBUSY
ERRNO_ENTRY(EBUSY, TXT("Device or resource busy"))
#endif


/*
** An existing file was specified in a context where it only
** makes sense to specify a new file.
*****************************************************************************/
#ifdef EEXIST
ERRNO_ENTRY(EEXIST, TXT("File exists"))
#endif


/*
** An attempt to make an improper link across file systems was detected.
** This happens not only when you use @code{link} (@pxref{Hard Links}) but
** also when you rename a file with @code{rename} (@pxref{Renaming Files}).
*****************************************************************************/
#ifdef EXDEV
ERRNO_ENTRY(EXDEV, TXT("Invalid cross-device link"))
#endif


/*
** The wrong type of device was given to a function that expects a
** particular sort of device.
*****************************************************************************/
#ifdef ENODEV
ERRNO_ENTRY(ENODEV, TXT("No such device"))
#endif


/*
** A file that isn't a directory was specified when a directory is required.
*****************************************************************************/
#ifdef ENOTDIR
ERRNO_ENTRY(ENOTDIR, TXT("Not a directory"))
#endif


/*
** You cannot open a directory for writing,
** or create or remove hard links to it.
*****************************************************************************/
#ifdef EISDIR
ERRNO_ENTRY(EISDIR, TXT("Is a directory"))
#endif


/*
** This is used to indicate various kinds of problems
** with passing the wrong argument to a library function.
*****************************************************************************/
#ifdef EINVAL
ERRNO_ENTRY(EINVAL, TXT("Invalid argument"))
#endif


/*
** The current process has too many files open and can't open any more.
** Duplicate descriptors do count toward this limit.
**
** In BSD and GNU, the number of open files is controlled by a resource
** limit that can usually be increased.  If you get this error, you might
** want to increase the @code{RLIMIT_NOFILE} limit or make it unlimited;
** @pxref{Limits on Resources}.
*****************************************************************************/
#ifdef EMFILE
ERRNO_ENTRY(EMFILE, TXT("Too many open files"))
#endif


/*
** There are too many distinct file openings in the entire system.  Note
** that any number of linked channels count as just one file opening; see
** @ref{Linked Channels}.  This error never occurs on @gnuhurdsystems{}.
*****************************************************************************/
#ifdef ENFILE
ERRNO_ENTRY(ENFILE, TXT("Too many open files in system"))
#endif


/*
** Inappropriate I/O control operation, such as trying to set terminal
** modes on an ordinary file.
*****************************************************************************/
#ifdef ENOTTY
ERRNO_ENTRY(ENOTTY, TXT("Inappropriate ioctl for device"))
#endif


/*
** An attempt to execute a file that is currently open for writing, or
** write to a file that is currently being executed.  Often using a
** debugger to run a program is considered having it open for writing and
** will cause this error.  (The name stands for ``text file busy''.)  This
** is not an error on @gnuhurdsystems{}; the text is copied as necessary.
*****************************************************************************/
#ifdef ETXTBSY
ERRNO_ENTRY(ETXTBSY, TXT("Text file busy"))
#endif


/*
** The size of a file would be larger than allowed by the system.
*****************************************************************************/
#ifdef EFBIG
ERRNO_ENTRY(EFBIG, TXT("File too large"))
#endif


/*
** Write operation on a file failed because the
** disk is full.
*****************************************************************************/
#ifdef ENOSPC
ERRNO_ENTRY(ENOSPC, TXT("No space left on device"))
#endif


/*
** Invalid seek operation (such as on a pipe).
*****************************************************************************/
#ifdef ESPIPE
ERRNO_ENTRY(ESPIPE, TXT("Illegal seek"))
#endif


/*
** An attempt was made to modify something on a read-only file system.
*****************************************************************************/
#ifdef EROFS
ERRNO_ENTRY(EROFS, TXT("Read-only file system"))
#endif


/*
** The link count of a single file would become too large.
** @code{rename} can cause this error if the file being renamed already has
** as many links as it can take (@pxref{Renaming Files}).
*****************************************************************************/
#ifdef EMLINK
ERRNO_ENTRY(EMLINK, TXT("Too many links"))
#endif


/*
** There is no process reading from the other end of a pipe.
** Every library function that returns this error code also generates a
** @code{SIGPIPE} signal; this signal terminates the program if not handled
** or blocked.  Thus, your program will never actually see @code{EPIPE}
** unless it has handled or blocked @code{SIGPIPE}.
*****************************************************************************/
#ifdef EPIPE
ERRNO_ENTRY(EPIPE, TXT("Broken pipe"))
#endif


/*
** Used by mathematical functions when an argument value does
** not fall into the domain over which the function is defined.
*****************************************************************************/
#ifdef EDOM
ERRNO_ENTRY(EDOM, TXT("Numerical argument out of domain"))
#endif

/*
** Used by mathematical functions when the result value is
** not representable because of overflow or underflow.
*****************************************************************************/
#ifdef ERANGE
ERRNO_ENTRY(ERANGE, TXT("Numerical result out of range"))
#endif


/*
** The call might work if you try again
** later.  The macro @code{EWOULDBLOCK} is another name for @code{EAGAIN};
** they are always the same in @theglibc{}.
**
** This error can happen in a few different situations:
**
** @itemize @bullet
** @item
** An operation that would block was attempted on an object that has
** non-blocking mode selected.  Trying the same operation again will block
** until some external condition makes it possible to read, write, or
** connect (whatever the operation).  You can use @code{select} to find out
** when the operation will be possible; @pxref{Waiting for I/O}.
**
** @strong{Portability Note:} In many older Unix systems, this condition
** was indicated by @code{EWOULDBLOCK}, which was a distinct error code
** different from @code{EAGAIN}.  To make your program portable, you should
** check for both codes and treat them the same.
**
** @item
** A temporary resource shortage made an operation impossible.  @code{fork}
** can return this error.  It indicates that the shortage is expected to
** pass, so your program can try the call again later and it may succeed.
** It is probably a good idea to delay for a few seconds before trying it
** again, to allow time for other processes to release scarce resources.
** Such shortages are usually fairly serious and affect the whole system,
** so usually an interactive program should report the error to the user
** and return to its command loop.
** @end itemize
*****************************************************************************/
#ifdef EAGAIN
ERRNO_ENTRY(EAGAIN, TXT("Resource temporarily unavailable"))
#endif


/*
** An operation that cannot complete immediately was initiated on an object
** that has non-blocking mode selected.  Some functions that must always
** block (such as @code{connect}; @pxref{Connecting}) never return
** @code{EAGAIN}.  Instead, they return @code{EINPROGRESS} to indicate that
** the operation has begun and will take some time.  Attempts to manipulate
** the object before the call completes return @code{EALREADY}.  You can
** use the @code{select} function to find out when the pending operation
** has completed; @pxref{Waiting for I/O}.
*****************************************************************************/
#ifdef EINPROGRESS
ERRNO_ENTRY(EINPROGRESS, TXT("Operation now in progress"))
#endif


/*
** An operation is already in progress on an object that has non-blocking
** mode selected.
*****************************************************************************/
#ifdef EALREADY
ERRNO_ENTRY(EALREADY, TXT("Operation already in progress"))
#endif


/*
** A file that isn't a socket was specified when a socket is required.
*****************************************************************************/
#ifdef ENOTSOCK
ERRNO_ENTRY(ENOTSOCK, TXT("Socket operation on non-socket"))
#endif


/*
** The size of a message sent on a socket was larger than the supported
** maximum size.
*****************************************************************************/
#ifdef EMSGSIZE
ERRNO_ENTRY(EMSGSIZE, TXT("Message too long"))
#endif


/*
** The socket type does not support the requested communications protocol.
*****************************************************************************/
#ifdef EPROTOTYPE
ERRNO_ENTRY(EPROTOTYPE, TXT("Protocol wrong type for socket"))
#endif


/*
** You specified a socket option that doesn't make sense for the
** particular protocol being used by the socket.  @xref{Socket Options}.
*****************************************************************************/
#ifdef ENOPROTOOPT
ERRNO_ENTRY(ENOPROTOOPT, TXT("Protocol not available"))
#endif


/*
** The socket domain does not support the requested communications protocol
** (perhaps because the requested protocol is completely invalid).
** @xref{Creating a Socket}.
*****************************************************************************/
#ifdef EPROTONOSUPPORT
ERRNO_ENTRY(EPROTONOSUPPORT, TXT("Protocol not supported"))
#endif


/*
** The socket type is not supported.
*****************************************************************************/
#ifdef ESOCKTNOSUPPORT
ERRNO_ENTRY(ESOCKTNOSUPPORT, TXT("Socket type not supported"))
#endif


/*
** The operation you requested is not supported.  Some socket functions
** don't make sense for all types of sockets, and others may not be
** implemented for all communications protocols.  On @gnuhurdsystems{}, this
** error can happen for many calls when the object does not support the
** particular operation; it is a generic indication that the server knows
** nothing to do for that call.
*****************************************************************************/
#ifdef EOPNOTSUPP
ERRNO_ENTRY(EOPNOTSUPP, TXT("Operation not supported"))
#endif


/*
** The socket communications protocol family you requested is not supported.
*****************************************************************************/
#ifdef EPFNOSUPPORT
ERRNO_ENTRY(EPFNOSUPPORT, TXT("Protocol family not supported"))
#endif


/*
** The address family specified for a socket is not supported; it is
** inconsistent with the protocol being used on the socket.  @xref{Sockets}.
*****************************************************************************/
#ifdef EAFNOSUPPORT
ERRNO_ENTRY(EAFNOSUPPORT, TXT("Address family not supported by protocol"))
#endif


/*
** The requested socket address is already in use.  @xref{Socket Addresses}.
*****************************************************************************/
#ifdef EADDRINUSE
ERRNO_ENTRY(EADDRINUSE, TXT("Address already in use"))
#endif


/*
** The requested socket address is not available; for example, you tried
** to give a socket a name that doesn't match the local host name.
** @xref{Socket Addresses}.
*****************************************************************************/
#ifdef EADDRNOTAVAIL
ERRNO_ENTRY(EADDRNOTAVAIL, TXT("Cannot assign requested address"))
#endif


/*
** A socket operation failed because the network was down.
*****************************************************************************/
#ifdef ENETDOWN
ERRNO_ENTRY(ENETDOWN, TXT("Network is down"))
#endif


/*
** A socket operation failed because the subnet containing the remote host
** was unreachable.
*****************************************************************************/
#ifdef ENETUNREACH
ERRNO_ENTRY(ENETUNREACH, TXT("Network is unreachable"))
#endif


/*
** A network connection was reset because the remote host crashed.
*****************************************************************************/
#ifdef ENETRESET
ERRNO_ENTRY(ENETRESET, TXT("Network dropped connection on reset"))
#endif


/*
** A network connection was aborted locally.
*****************************************************************************/
#ifdef ECONNABORTED
ERRNO_ENTRY(ECONNABORTED, TXT("Software caused connection abort"))
#endif


/*
** A network connection was closed for reasons outside the control of the
** local host, such as by the remote machine rebooting or an unrecoverable
** protocol violation.
*****************************************************************************/
#ifdef ECONNRESET
ERRNO_ENTRY(ECONNRESET, TXT("Connection reset by peer"))
#endif


/*
** The kernel's buffers for I/O operations are all in use.  In GNU, this
** error is always synonymous with @code{ENOMEM}; you may get one or the
** other from network operations.
*****************************************************************************/
#ifdef ENOBUFS
ERRNO_ENTRY(ENOBUFS, TXT("No buffer space available"))
#endif


/*
** You tried to connect a socket that is already connected.
** @xref{Connecting}.
*****************************************************************************/
#ifdef EISCONN
ERRNO_ENTRY(EISCONN, TXT("Transport endpoint is already connected"))
#endif


/*
** The socket is not connected to anything.  You get this error when you
** try to transmit data over a socket, without first specifying a
** destination for the data.  For a connectionless socket (for datagram
** protocols, such as UDP), you get @code{EDESTADDRREQ} instead.
*****************************************************************************/
#ifdef ENOTCONN
ERRNO_ENTRY(ENOTCONN, TXT("Transport endpoint is not connected"))
#endif


/*
** No default destination address was set for the socket.  You get this
** error when you try to transmit data over a connectionless socket,
** without first specifying a destination for the data with @code{connect}.
*****************************************************************************/
#ifdef EDESTADDRREQ
ERRNO_ENTRY(EDESTADDRREQ, TXT("Destination address required"))
#endif


/*
** The socket has already been shut down.
*****************************************************************************/
#ifdef ESHUTDOWN
ERRNO_ENTRY(ESHUTDOWN, TXT("Cannot send after transport endpoint shutdown"))
#endif


#ifdef ETOOMANYREFS
ERRNO_ENTRY(ETOOMANYREFS, TXT("Too many references: cannot splice"))
#endif


/*
** A socket operation with a specified timeout received no response during
** the timeout period.
*****************************************************************************/
#ifdef ETIMEDOUT
ERRNO_ENTRY(ETIMEDOUT, TXT("Connection timed out"))
#endif


/*
** A remote host refused to allow the network connection (typically because
** it is not running the requested service).
*****************************************************************************/
#ifdef ECONNREFUSED
ERRNO_ENTRY(ECONNREFUSED, TXT("Connection refused"))
#endif


/*
** Too many levels of symbolic links were encountered in looking up a file
name. ** This often indicates a cycle of symbolic links.
*****************************************************************************/
#ifdef ELOOP
ERRNO_ENTRY(ELOOP, TXT("Too many levels of symbolic links"))
#endif


/*
** Filename too long (longer than @code{PATH_MAX}; @pxref{Limits for
** Files}) or host name too long (in @code{gethostname} or
** @code{sethostname}; @pxref{Host Identification}).
*****************************************************************************/
#ifdef ENAMETOOLONG
ERRNO_ENTRY(ENAMETOOLONG, TXT("File name too long"))
#endif


/*
** The remote host for a requested network connection is down.
*****************************************************************************/
#ifdef EHOSTDOWN
ERRNO_ENTRY(EHOSTDOWN, TXT("Host is down"))
#endif


/*
** The remote host for a requested network connection is not reachable.
*****************************************************************************/
#ifdef EHOSTUNREACH
ERRNO_ENTRY(EHOSTUNREACH, TXT("No route to host"))
#endif


/*
** Directory not empty, where an empty directory was expected.  Typically,
** this error occurs when you are trying to delete a directory.
*****************************************************************************/
#ifdef ENOTEMPTY
ERRNO_ENTRY(ENOTEMPTY, TXT("Directory not empty"))
#endif


/*
** The file quota system is confused because there are too many users.
** @c This can probably happen in a GNU system when using NFS.
*****************************************************************************/
#ifdef EUSERS
ERRNO_ENTRY(EUSERS, TXT("Too many users"))
#endif


/*
** The user's disk quota was exceeded.
*****************************************************************************/
#ifdef EDQUOT
ERRNO_ENTRY(EDQUOT, TXT("Disk quota exceeded"))
#endif


/*
** This indicates an internal confusion in the
** file system which is due to file system rearrangements on the server host
** for NFS file systems or corruption in other file systems.
** Repairing this condition usually requires unmounting, possibly repairing
** and remounting the file system.
*****************************************************************************/
#ifdef ESTALE
ERRNO_ENTRY(ESTALE, TXT("Stale file handle"))
#endif


/*
** An attempt was made to NFS-mount a remote file system with a file name
** that already specifies an NFS-mounted file. TRANS (This is an error on
** some operating systems, but we expect it to work ** properly on
** @gnuhurdsystems{}, making this error code impossible.)
*****************************************************************************/
#ifdef EREMOTE
ERRNO_ENTRY(EREMOTE, TXT("Object is remote"))
#endif


/*
** This is used by the file locking facilities; see
** @ref{File Locks}.  This error is never generated by @gnuhurdsystems{},
** but it can result from an operation to an NFS server running another
** operating system.
*****************************************************************************/
#ifdef ENOLCK
ERRNO_ENTRY(ENOLCK, TXT("No locks available"))
#endif


/*
** This indicates that the function called is
** not implemented at all, either in the C library itself or in the
** operating system.  When you get this error, you can be sure that this
** particular function will always fail with @code{ENOSYS} unless you
** install a new version of the C library or the operating system.
*****************************************************************************/
#ifdef ENOSYS
ERRNO_ENTRY(ENOSYS, TXT("Function not implemented"))
#endif


/*
** While decoding a multibyte character the function came along an invalid
** or an incomplete sequence of bytes or the given wide character is invalid.
*****************************************************************************/
#ifdef EILSEQ
ERRNO_ENTRY(EILSEQ, TXT("Invalid or incomplete multibyte or wide character"))
#endif


#ifdef EBADMSG
ERRNO_ENTRY(EBADMSG, TXT("Bad message"))
#endif


#ifdef EIDRM
ERRNO_ENTRY(EIDRM, TXT("Identifier removed"))
#endif


#ifdef EMULTIHOP
ERRNO_ENTRY(EMULTIHOP, TXT("Multihop attempted"))
#endif


#ifdef ENODATA
ERRNO_ENTRY(ENODATA, TXT("No data available"))
#endif


#ifdef ENOLINK
ERRNO_ENTRY(ENOLINK, TXT("Link has been severed"))
#endif


#ifdef ENOMSG
ERRNO_ENTRY(ENOMSG, TXT("No message of desired type"))
#endif


#ifdef ENOSR
ERRNO_ENTRY(ENOSR, TXT("Out of streams resources"))
#endif


#ifdef ENOSTR
ERRNO_ENTRY(ENOSTR, TXT("Device not a stream"))
#endif


#ifdef EOVERFLOW
ERRNO_ENTRY(EOVERFLOW, TXT("Value too large for defined data type"))
#endif


#ifdef EPROTO
ERRNO_ENTRY(EPROTO, TXT("Protocol error"))
#endif


#ifdef ETIME
ERRNO_ENTRY(ETIME, TXT("Timer expired"))
#endif


/*
** An asynchronous operation was canceled before it
** completed.  @xref{Asynchronous I/O}.  When you call @code{aio_cancel},
** the normal result is for the operations affected to complete with this
** error; @pxref{Cancel AIO Operations}.
*****************************************************************************/
#ifdef ECANCELED
ERRNO_ENTRY(ECANCELED, TXT("Operation canceled"))
#endif


#ifdef EOWNERDEAD
ERRNO_ENTRY(EOWNERDEAD, TXT("Owner died"))
#endif


#ifdef ENOTRECOVERABLE
ERRNO_ENTRY(ENOTRECOVERABLE, TXT("State not recoverable"))
#endif


#ifdef ERESTART
ERRNO_ENTRY(ERESTART, TXT("Interrupted system call should be restarted"))
#endif


#ifdef ECHRNG
ERRNO_ENTRY(ECHRNG, TXT("Channel number out of range"))
#endif


#ifdef EL2NSYNC
ERRNO_ENTRY(EL2NSYNC, TXT("Level 2 not synchronized"))
#endif


#ifdef EL3HLT
ERRNO_ENTRY(EL3HLT, TXT("Level 3 halted"))
#endif


#ifdef EL3RST
ERRNO_ENTRY(EL3RST, TXT("Level 3 reset"))
#endif


#ifdef ELNRNG
ERRNO_ENTRY(ELNRNG, TXT("Link number out of range"))
#endif


#ifdef EUNATCH
ERRNO_ENTRY(EUNATCH, TXT("Protocol driver not attached"))
#endif


#ifdef ENOCSI
ERRNO_ENTRY(ENOCSI, TXT("No CSI structure available"))
#endif


#ifdef EL2HLT
ERRNO_ENTRY(EL2HLT, TXT("Level 2 halted"))
#endif


#ifdef EBADE
ERRNO_ENTRY(EBADE, TXT("Invalid exchange"))
#endif


#ifdef EBADR
ERRNO_ENTRY(EBADR, TXT("Invalid request descriptor"))
#endif


#ifdef EXFULL
ERRNO_ENTRY(EXFULL, TXT("Exchange full"))
#endif


#ifdef ENOANO
ERRNO_ENTRY(ENOANO, TXT("No anode"))
#endif


#ifdef EBADRQC
ERRNO_ENTRY(EBADRQC, TXT("Invalid request code"))
#endif


#ifdef EBADSLT
ERRNO_ENTRY(EBADSLT, TXT("Invalid slot"))
#endif


#ifdef EBFONT
ERRNO_ENTRY(EBFONT, TXT("Bad font file format"))
#endif


#ifdef ENONET
ERRNO_ENTRY(ENONET, TXT("Machine is not on the network"))
#endif


#ifdef ENOPKG
ERRNO_ENTRY(ENOPKG, TXT("Package not installed"))
#endif


#ifdef EADV
ERRNO_ENTRY(EADV, TXT("Advertise error"))
#endif


#ifdef ESRMNT
ERRNO_ENTRY(ESRMNT, TXT("Srmount error"))
#endif


#ifdef ECOMM
ERRNO_ENTRY(ECOMM, TXT("Communication error on send"))
#endif


#ifdef EDOTDOT
ERRNO_ENTRY(EDOTDOT, TXT("RFS specific error"))
#endif


#ifdef ENOTUNIQ
ERRNO_ENTRY(ENOTUNIQ, TXT("Name not unique on network"))
#endif


#ifdef EBADFD
ERRNO_ENTRY(EBADFD, TXT("File descriptor in bad state"))
#endif


#ifdef EREMCHG
ERRNO_ENTRY(EREMCHG, TXT("Remote address changed"))
#endif


#ifdef ELIBACC
ERRNO_ENTRY(ELIBACC, TXT("Can not access a needed shared library"))
#endif


#ifdef ELIBBAD
ERRNO_ENTRY(ELIBBAD, TXT("Accessing a corrupted shared library"))
#endif


#ifdef ELIBSCN
ERRNO_ENTRY(ELIBSCN, TXT(".lib section in a.out corrupted"))
#endif


#ifdef ELIBMAX
ERRNO_ENTRY(ELIBMAX, TXT("Attempting to link in too many shared libraries"))
#endif


#ifdef ELIBEXEC
ERRNO_ENTRY(ELIBEXEC, TXT("Cannot exec a shared library directly"))
#endif


#ifdef ESTRPIPE
ERRNO_ENTRY(ESTRPIPE, TXT("Streams pipe error"))
#endif


#ifdef EUCLEAN
ERRNO_ENTRY(EUCLEAN, TXT("Structure needs cleaning"))
#endif


#ifdef ENOTNAM
ERRNO_ENTRY(ENOTNAM, TXT("Not a XENIX named type file"))
#endif


#ifdef ENAVAIL
ERRNO_ENTRY(ENAVAIL, TXT("No XENIX semaphores available"))
#endif


#ifdef EISNAM
ERRNO_ENTRY(EISNAM, TXT("Is a named type file"))
#endif


#ifdef EREMOTEIO
ERRNO_ENTRY(EREMOTEIO, TXT("Remote I/O error"))
#endif


#ifdef ENOMEDIUM
ERRNO_ENTRY(ENOMEDIUM, TXT("No medium found"))
#endif


#ifdef EMEDIUMTYPE
ERRNO_ENTRY(EMEDIUMTYPE, TXT("Wrong medium type"))
#endif


#ifdef ENOKEY
ERRNO_ENTRY(ENOKEY, TXT("Required key not available"))
#endif


#ifdef EKEYEXPIRED
ERRNO_ENTRY(EKEYEXPIRED, TXT("Key has expired"))
#endif


#ifdef EKEYREVOKED
ERRNO_ENTRY(EKEYREVOKED, TXT("Key has been revoked"))
#endif


#ifdef EKEYREJECTED
ERRNO_ENTRY(EKEYREJECTED, TXT("Key was rejected by service"))
#endif


#ifdef ERFKILL
ERRNO_ENTRY(ERFKILL, TXT("Operation not possible due to RF-kill"))
#endif


#ifdef EHWPOISON
ERRNO_ENTRY(EHWPOISON, TXT("Memory page has hardware error"))
#endif


#ifdef EBADRPC
ERRNO_ENTRY(EBADRPC, TXT("RPC struct is bad"))
#endif


/*
** The file was the wrong type for the
** operation, or a data file had the wrong format.
**
** On some systems @code{chmod} returns this error if you try to set the
** sticky bit on a non-directory file; @pxref{Setting Permissions}.
*****************************************************************************/
#ifdef EFTYPE
ERRNO_ENTRY(EFTYPE, TXT("Inappropriate file type or format"))
#endif


#ifdef EPROCUNAVAIL
ERRNO_ENTRY(EPROCUNAVAIL, TXT("RPC bad procedure for program"))
#endif


#ifdef EAUTH
ERRNO_ENTRY(EAUTH, TXT("Authentication error"))
#endif


/*
** On @gnuhurdsystems{}, opening a file returns this error when the file is
** translated by a program and the translator program dies while starting
** up, before it has connected to the file.
*****************************************************************************/
#ifdef EDIED
ERRNO_ENTRY(EDIED, TXT("Translator died"))
#endif


#ifdef ERPCMISMATCH
ERRNO_ENTRY(ERPCMISMATCH, TXT("RPC version wrong"))
#endif


/*
** You did @strong{what}?
*****************************************************************************/
#ifdef EGREGIOUS
ERRNO_ENTRY(EGREGIOUS, TXT("You really blew it this time"))
#endif


/*
** This means that the per-user limit on new process would be exceeded by
** an attempted @code{fork}.  @xref{Limits on Resources}, for details on
** the @code{RLIMIT_NPROC} limit.
*****************************************************************************/
#ifdef EPROCLIM
ERRNO_ENTRY(EPROCLIM, TXT("Too many processes"))
#endif


/*
** This error code has no purpose.
*****************************************************************************/
#ifdef EGRATUITOUS
ERRNO_ENTRY(EGRATUITOUS, TXT("Gratuitous error"))
#endif


/*
** A function returns this error when certain parameter
** values are valid, but the functionality they request is not available.
** This can mean that the function does not implement a particular command
** or option value or flag bit at all.  For functions that operate on some
** object given in a parameter, such as a file descriptor or a port, it
** might instead mean that only @emph{that specific object} (file
** descriptor, port, etc.) is unable to support the other parameters given;
** different file descriptors might support different ranges of parameter
** values.
**
** If the entire function is not available at all in the implementation,
** it returns @code{ENOSYS} instead.
*****************************************************************************/
#if defined(ENOTSUP) && ENOTSUP != EOPNOTSUPP
ERRNO_ENTRY(ENOTSUP, TXT("Not supported"))
#endif


#ifdef EPROGMISMATCH
ERRNO_ENTRY(EPROGMISMATCH, TXT("RPC program version wrong"))
#endif


/*
** On @gnuhurdsystems{}, servers supporting the @code{term} protocol return
** this error for certain operations when the caller is not in the
** foreground process group of the terminal.  Users do not usually see this
** error because functions such as @code{read} and @code{write} translate
** it into a @code{SIGTTIN} or @code{SIGTTOU} signal.  @xref{Job Control},
** for information on process groups and these signals.
*****************************************************************************/
#ifdef EBACKGROUND
ERRNO_ENTRY(EBACKGROUND, TXT("Inappropriate operation for background process"))
#endif


/*
** Go home and have a glass of warm, dairy-fresh milk.
**
**
**
**
**
** @c Okay.  Since you are dying to know, I'll tell you.
** @c This is a joke, obviously.  There is a children's song which begins,
** @c "Old McDonald had a farm, e-i-e-i-o."  Every time I see the (real)
** @c errno macro EIO, I think about that song.  Probably most of my
** @c compatriots who program on Unix do, too.  One of them must have stayed
** @c up a little too late one night and decided to add it to Hurd or Glibc.
** @c Whoever did it should be castigated, but it made me laugh.
** @c  --jtobey@channel1.com
** @c
** @c "bought the farm" means "died".  -jtobey
** @c
** @c Translators, please do not translate this litteraly, translate it into
** @c an idiomatic funny way of saying that the computer died.
*****************************************************************************/
// This docstring is from the original header where GNU error srtings are
// defined. I swear you can't make this up.
// This is pure concentrated genius.
#ifdef EIEIO
ERRNO_ENTRY(EIEIO, TXT("Computer bought the farm"))
#endif


/*
** In @theglibc{}, this is another name for @code{EAGAIN} (above).
** The values are always the same, on every operating system.
**
** C libraries in many older Unix systems have @code{EWOULDBLOCK} as a
** separate error code.
*****************************************************************************/
#if defined(EWOULDBLOCK) && EWOULDBLOCK != EAGAIN
ERRNO_ENTRY(EWOULDBLOCK, TXT("Operation would block"))
#endif


#ifdef ENEEDAUTH
ERRNO_ENTRY(ENEEDAUTH, TXT("Need authenticator"))
#endif


/*
** The experienced user will know what is wrong.
** @c This error code is a joke.  Its perror text is part of the joke.
** @c Don't change it.
*****************************************************************************/
#ifdef ED
ERRNO_ENTRY(ED, TXT("?"))
#endif


#ifdef EPROGUNAVAIL
ERRNO_ENTRY(EPROGUNAVAIL, TXT("RPC program not available"))
#endif


//  END ENTRY DEFINITIONS  //
