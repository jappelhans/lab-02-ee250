# Lab 2
[Fork](https://docs.github.com/en/get-started/quickstart/fork-a-repo) this repo and clone it to your machine to get started!

## Team Members
- Jerry Appelhans
- n/a

## Lab Question Answers

Answer for Question 1: 
    With a 50% loss added to the UDP server, about half of the messages that the client try to send to the server are lost.  These messages are completely dropped, and they never arrive at the server.

Answer for Question 2:
    With a 50% loss added to the TCP server, the reliability of the communication link stays the same.  Every message that the client sends is eventually received by the server.  When a message is lost, it is retransmitted instead of just being dropped. 

Answer for Question 3:
    With the 50% loss, the speed of the TCP response is much slower.  This happens because when a message is dropped, TCP spends the extra time to retransmit the lost message before it attempts to send new messages.


...
