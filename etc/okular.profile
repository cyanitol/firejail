# Firejail profile for okular
# This file is overwritten after every install/update
# Persistent local customizations
include /etc/firejail/okular.local
# Persistent global definitions
include /etc/firejail/globals.local

# blacklist /run/user/*/bus

noblacklist ~/.config/okularpartrc
noblacklist ~/.config/okularrc
noblacklist ~/.kde/share/apps/okular
noblacklist ~/.kde/share/config/okularpartrc
noblacklist ~/.kde/share/config/okularrc
noblacklist ~/.kde4/share/apps/okular
noblacklist ~/.kde4/share/config/okularpartrc
noblacklist ~/.kde4/share/config/okularrc
noblacklist ~/.local/share/okular

include /etc/firejail/disable-common.inc
include /etc/firejail/disable-devel.inc
include /etc/firejail/disable-passwdmgr.inc
include /etc/firejail/disable-programs.inc

include /etc/firejail/whitelist-var-common.inc

caps.drop all
# net none
netfilter
nodvd
nogroups
nonewprivs
noroot
nosound
notv
novideo
protocol unix
seccomp
shell none
tracelog

private-bin okular,kbuildsycoca4,kdeinit4,lpr
private-dev
private-etc alternatives,cups,fonts,machine-id
# private-tmp - on KDE we need access to the real /tmp for data exchange with thunderbird

# memory-deny-write-execute
noexec ${HOME}
noexec /tmp
