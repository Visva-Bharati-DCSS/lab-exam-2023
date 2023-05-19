# lab-exam-2023
You can login to an external server loaned for today. The IP address is 185.201.8.160.

command for login :
ssh 185.201.8.160 -l <username>. #your usernames are prob1, prob2, prob3, prob4, prob5, prob6 or prob7 as the given problem number.
password : dse3-prob1/dse3-prob2/dse3-prob3 ...  #for groups having problem 1, problem 2, problem 3 ...  
  
Copying files from local machine to the external server in the home directory :
scp filename username@185.201.8.160:~
password : password as given for ssh.

You can run your client or server program in the external server.
  
The files supplied as examples to 
  - run timers using poll() function,
  - using system() function to run shell commands from a C program
  
To change MSS of the client side TCP :
  requested_mss = 800;
  n = setsockopt(sockfd, IPPROTO_TCP, TCP_MAXSEG, &requested_mss, sizeof(requested_mss));
  
  
