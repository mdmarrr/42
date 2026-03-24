*This project has been created as part of the 42 curriculum by magomez-*

# Born2beRoot

## Table of contents

- Description
- Project Description
- Resources

---

## Description

**Born2beRoot** is a system administration project that introduces you to the world of virtualization and secure server configuration.
The goal is to create and configure a Linux virtual machine (VM) using **VirtualBox**, and implement strict rules regarding partitioning, user management, password policies, services, and system monitoring.

---

## Project Description

### Commands

Users and groups:

- whoami: Shows the current user.
- id: Displays user ID, group ID and groups.
- groups: Lists the groups of the current user.
- adduser <user>: Creates a new user.
- deluser <user>: Deletes a user.
- addgroup <group>: Creates a new group.
- usermod -aG <group> <user>: Adds a user to a group without removing existing groups.

Permissions and Ownership:

- ls -l: Shows file permissions and ownership.
- chmod 755 <file>: Changes file permissions using numeric mode.
- chmod u+x <file>: Adds execute permission to the user.
- chown <user> <file>: Changes file owner.
- chgrp <group> <file>: Changes file group.

Sudo:

- sudo <command>: Executes a command with superuser privileges.
- sudo -l: Lists allowed sudo commands for the user.
- visudo: Safely edits the sudoers configuration file.

Services:

- systemctl status <service>: Checks service status.
- systemctl start <service>: Starts a service.
- systemctl stop <service>: Stops a service.
- systemctl restart <service>: Restarts a service.
- systemctl enable <service>: Enables service at boot.

SSH:

- ssh user@ip: Connects to a remote machine via SSH.
- ssh -p <port> user@ip: Connects using a custom SSH port.
- Configuration file: /etc/ssh/sshd_config

Firewall (UFW):

- ufw status: Shows firewall status.
- ufw enable: Enables the firewall.
- ufw allow <port>: Allows traffic on a port.
- ufw deny <port>: Blocks traffic on a port.

Disks and Partitions:

- lsblk: Displays block devices and partitions.
- df -h: Shows disk usage.
- mount: Displays mounted filesystems.
- cat /etc/fstab: Shows filesystem mount configuration.

Password Policy:

- passwd: Changes user password.
- chage -l <user>: Displays password aging information.

Cron:

- crontab -l: Lists scheduled cron jobs.
- crontab -e: Edits cron jobs.

---

## Resources

Debian documentation:
https://www.debian.org/doc/
VirtualBox Manual:
https://www.virtualbox.org/manual/UserManual.html

AI Usage: AI was used to understand some concepts and commands. No AI was used to complete configuration or write scripts.
