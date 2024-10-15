"""
This is a POC intended for initial testing of the entire application
The code here isn't for production purposes!
"""

import socket
import server_message_pb2 as server_message


with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client:
    client.connect(("localhost", 8080))

    while True:
        data = client.recv(1024)
        
        if not data:
            break

        message = server_message.ServerMessage()
        message.ParseFromString(data)

        if message.content.Is(server_message.ReportEventServerMessageContent.DESCRIPTOR):
            content = server_message.ReportEventServerMessageContent()
            message.content.Unpack(content)
            event = content.event
            print(f"Type={message.type}, Event: Action={event.action}, Name={event.devname}")
        else:
            print("Different type of message")
