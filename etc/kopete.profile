# Firejail profile for kopete
# This file is overwritten after every install/update
# Persistent local customizations
include /etc/firejail/kopete.local
# Persistent global definitions
include /etc/firejail/globals.local

noblacklist ~/.kde/share/apps/kopete
noblacklist ~/.kde/share/config/kopeterc
noblacklist ~/.kde4/share/apps/kopete
noblacklist ~/.kde4/share/config/kopeterc

include /etc/firejail/disable-common.inc
include /etc/firejail/disable-devel.inc
include /etc/firejail/disable-passwdmgr.inc
include /etc/firejail/disable-programs.inc

include /etc/firejail/whitelist-var-common.inc

caps.drop all
netfilter
nodvd
nogroups
nonewprivs
noroot
notv
protocol unix,inet,inet6,netlink
seccomp

private-dev
private-tmp

noexec ${HOME}
noexec /tmp
