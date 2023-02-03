# Lab 2
[Fork](https://docs.github.com/en/get-started/quickstart/fork-a-repo) this repo and clone it to your machine to get started!

## Team Members
- Jerry Appelhans
- n/a (worked individually)

## Lab Question Answers

Answer for Question 1: 
    With a 50% loss added to the UDP server, about half of the messages that the client tries to send to the server are lost.  When these messages are lost, they are completely dropped and therefore never arrive at the server.

Answer for Question 2:
    With a 50% loss added to the TCP server, the reliability is affected differently than the UDP link.  With TCP, every message that the client sends is eventually received by the server.  When a message is lost, it is retransmitted instead of just being dropped.  In this way, the reliability is much better than UDP, but the drawback is a slower speed.

Answer for Question 3:
    With the 50% loss, the speed of the TCP response is much slower.  This happens because when a message is dropped, TCP spends the extra time to retransmit the lost message before it attempts to send new messages.  The lost messages are able to be detected because TCP serializes each message unlike UDP.

