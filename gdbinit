handle SIGINT pass nostop noprint
handle SIGQUIT pass nostop noprint
handle SIGUSR1 pass nostop noprint
handle SIGUSR2 pass nostop noprint
set $_exitcode = -1
run
if $_exitcode != -1 
    quit
end
backtrace