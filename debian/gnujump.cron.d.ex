#
# Regular cron jobs for the gnujump package
#
0 4	* * *	root	[ -x /usr/bin/gnujump_maintenance ] && /usr/bin/gnujump_maintenance
