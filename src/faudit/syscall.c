/*
 * Copyright (C) 2014-2016 Firejail Authors
 *
 * This file is part of firejail project
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/
#include "faudit.h"

void syscall_helper(int argc, char **argv) {
	if (strcmp(argv[2], "mount") == 0) {
		mount(NULL, NULL, NULL, 0, NULL);
		printf("\nUGLY: mount syscall permitted.\n");
	}
	else if (strcmp(argv[2], "umount2") == 0) {
		umount2(NULL, 0);
		printf("\nUGLY: umount2 syscall permitted.\n");
	}
	else if (strcmp(argv[2], "ptrace") == 0) {
		ptrace(0, 0, NULL, NULL);
		printf("\nUGLY: ptrace syscall permitted.\n");
	}
	else if (strcmp(argv[2], "swapon") == 0) {
		swapon(NULL, 0);
		printf("\nUGLY: swapon syscall permitted.\n");
	}
	else if (strcmp(argv[2], "swapoff") == 0) {
		swapoff(NULL);
		printf("\nUGLY: swapoff syscall permitted.\n");
	}
	else if (strcmp(argv[2], "init_module") == 0) {
		init_module(NULL, 0, NULL);
		printf("\nUGLY: init_module syscall permitted.\n");
	}
	else if (strcmp(argv[2], "finit_module") == 0) {
		swapoff(0, NULL, 0);
		printf("\nUGLY: finit_module syscall permitted.\n");
	}
	else if (strcmp(argv[2], "delete_module") == 0) {
		delete_module(NULL, 0);
		printf("\nUGLY: delete_module syscall permitted.\n");
	}
	else if (strcmp(argv[2], "chroot") == 0) {
		int rv = chroot(NULL);
		(void) rv;
		printf("\nUGLY: chroot syscall permitted.\n");
	}
	else if (strcmp(argv[2], "pivot_root") == 0) {
		pivot_root(NULL, NULL);
		printf("\nUGLY: pivot_root syscall permitted.\n");
	}
	else if (strcmp(argv[2], "iopl") == 0) {
		iopl(0L);
		printf("\nUGLY: iopl syscall permitted.\n");
	}
	else if (strcmp(argv[2], "ioperm") == 0) {
		ioperm(0, 0, 0);
		printf("\nUGLY: ioperm syscall permitted.\n");
	}
	exit(0);
}

void syscall_run(const char *name) {
	assert(prog);
	
	pid_t child = fork();
	if (child < 0)
		errExit("fork");
	if (child == 0) {
		execl(prog, prog, "syscall", name, NULL);
		exit(1);
	}
		
	// wait for the child to finish
	waitpid(child, NULL, 0);
}