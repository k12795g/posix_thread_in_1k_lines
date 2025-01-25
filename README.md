## Project Introduction

This project is developed based on the [Operating System in 1,000 Lines](https://operating-system-in-1000-lines.vercel.app/en/) tutorial, aiming to learn and build a simple RISC-V operating system.

### Current Features:
- Implemented a basic operating system (OS) as demonstrated in the tutorial.
- Provides a fundamental shell functionality for basic operations.
- Supports handling of certain system calls (syscalls).

### Future Development:
- Extend system functionality to support POSIX Thread interfaces, including but not limited to:
  - **Mutex**
  - **Condition Variables**
  - **Semaphores**
  - **Barriers**
- Address and design solutions for **Priority Inversion** issues.

This project aims to provide a deeper understanding of core operating system concepts and implementation details, applying theoretical knowledge to practical system development.


### Problem Regarding Thread Functionality

Current progress:
- Context switching between kernel threads has been implemented.
- The system supports creating threads in kernel mode, which can correctly execute the specified **user mode code**.

However, when the user mode code attempts to create a new thread via **syscall**, the newly created thread fails to execute its corresponding **user mode code** properly.

Confirmed findings:
1. The new thread has been successfully created in kernel mode.
2. The transition to user mode correctly utilizes the **sret** and **ret** instructions.
3. The user mode instruction address points to the correct user code.

Possible cause of the issue:
- **The new thread lacks a dedicated user stack**, leading to an inability to access user mode memory addresses, which subsequently causes errors.

### Next Steps for Improvement
- Allocate a separate **user stack** for each new thread created via syscall and properly initialize the stack pointer (SP) before transitioning to user mode.
- Test and verify the newly allocated user stack to ensure that user mode can correctly access its memory space and execute relevant operations.